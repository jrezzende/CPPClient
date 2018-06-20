#include "UserAgent.h"
#include "HTTPMethods.h"

Response UserAgent::require(HTTPMethods* method)
{
   try {
      Response& resp= method->answer(request);
      return resp;
   } catch (CURLcode code) {
      throw code;
   }
}