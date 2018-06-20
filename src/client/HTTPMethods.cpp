#include "HTTPMethods.h"
#include <string>

namespace {
   std::size_t writeBody(void *contents, size_t size, size_t nmemb, void *userp) {
      auto buffer = reinterpret_cast<Response*>(userp);
      buffer->appendBodyParam(std::string((char*)contents));
      return size * nmemb;
   }
}

Response HTTPMethods::answer(Request& req)
{
   CURLcode res;

   curl_easy_setopt(curl, CURLOPT_URL, req.host().url());
   curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req.header());

   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeBody);
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
   
   res= curl_easy_perform(curl);

   if (res == CURLcode::CURLE_OK) {
      CURLcode status;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
      content->setStatusCode(status);

      curl_easy_cleanup(curl);
      return *content;
   }
   
   Response* badResponse;
   badResponse->setStatusCode(res);

   return *badResponse;
}
