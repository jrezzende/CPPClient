#include "WebRequestClient.h"
#include "HTTPMethods.h"
//#include "CurleThrower.h"

Response WebRequestClient::require(HTTPMethods* method)
{
   try {
      Response& resp= method->answer(request);
      return resp;
   } catch (CURLcode code) {
      throw code;
      //throw CurleThrower::newException(code);
   }
}