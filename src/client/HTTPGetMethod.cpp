#include <iostream>

#include "HTTPGetMethod.h"
#include "CurleThrower.h"

Response HTTPGetMethod::answer(Request& request)
{
   Response resp;
   curl= curl_easy_init();

   if (curl) {
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "Get method.");

      resp= HTTPMethods::answer(request);
   }

   if (!resp.statusCode())
      return resp;
   else
      throw CurleThrower::newException(resp.statusCode());
}
