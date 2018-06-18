#include "HTTPMethods.h"
#include <string>

std::string* header;

std::size_t HTTPMethods::bodyCallBack(const char* data, std::size_t size, std::size_t nmemb, void* userData)
{  
   if (!header)
      header= new std::string("");
   header->append(std::string(data, nmemb*size));
   return size * nmemb;;
}

std::size_t HTTPMethods::headerCallBack(const char* data, std::size_t size, std::size_t nmemb, void* userData)
{
   auto response= reinterpret_cast<Response*>(userData);
   if (header) {
      response->appendHeaderParam(*header);
      delete header;
      header= nullptr;
   }
   response->appendBodyParam(std::string(data, nmemb*size));

   return size* nmemb;
}

Response HTTPMethods::answer(Request& req)
{
   CURLcode res;

   curl_easy_setopt(curl, CURLOPT_URL, req.host());
   curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req.header());

   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bodyCallBack);
   curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, headerCallBack);

   res= curl_easy_perform(curl);

   if (res == CURLcode::CURLE_OK) {
      CURLcode status;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
      content.setStatusCode(status);

      curl_easy_cleanup(curl);
      return content;
   }
   
   Response badResponse;
   badResponse.setStatusCode(res);

   return badResponse;
}
