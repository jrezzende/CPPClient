#include <iostream>

#include "HTTPGetMethod.h"

Response HTTPGetMethod::answer(Request& request)
{
   Response* resp;
   curl= curl_easy_init();

   if (curl) {
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");

      resp= &HTTPMethods::answer(request);
   }

   if (!resp->statusCode())
      return *resp;
   else
      throw resp->statusCode();
}
