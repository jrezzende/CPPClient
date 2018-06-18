#include <iostream>

#include "HTTPPostMethod.h"
#include "CurleThrower.h"

Response HTTPPostMethod::answer(Request& request)
{
   Response resp;
   curl= curl_easy_init();

   if (curl) {
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "Post Method");
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request.body());
      
      resp= HTTPMethods::answer(request);
   }

   if(!resp.statusCode())
      return resp;
   else
      throw CurleThrower::newException(resp.statusCode());
}