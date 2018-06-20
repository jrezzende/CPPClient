#include "HTTPClient.h"
#include "HeaderParams.h"
#include "BodyParams.h"
#include "HTTPGetMethod.h"
#include "HTTPPostMethod.h"

HTTPClient::HTTPClient(const char* hostAddress) : UserAgent(hostAddress)
{
   request.addHeaderParam(HeaderParams("Accept", "application/json"));
}

HTTPClient& HTTPClient::port(unsigned short port)
{
   request.setPort(port);
   return *this;
}

HTTPClient& HTTPClient::route(const char* route)
{
   request.setRoute(route);
   return *this;
}

HTTPClient& HTTPClient::headerParams(const char * key, const char * value)
{
   request.addHeaderParam(HeaderParams(key, value));
   return *this;
}

HTTPClient& HTTPClient::bodyParams(const char * key, const char * value)
{
   request.addBodyParam(BodyParams(key, value));
   return *this;
}

Response& HTTPClient::get(const char* query)
{
   if (query)
      request.setQuery(query);

   request.composeURL();
   return require(new HTTPGetMethod());
}

Response& HTTPClient::post()
{
   return require(new HTTPPostMethod());
}
