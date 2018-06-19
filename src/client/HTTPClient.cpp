#include "HTTPClient.h"
#include "MessageComposer.h"
#include "QueryString.h"
#include "HTTPGetMethod.h"
#include "HTTPPostMethod.h"

HTTPClient::HTTPClient(const char* host) : WebRequestClient(host)
{
   request.addHeaderParam(MessageComposer("Accept", "application/json", MessageType::HEADER).formatMessage());
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
   request.addHeaderParam(MessageComposer(key, value, MessageType::HEADER).formatMessage());
   return *this;
}

HTTPClient& HTTPClient::bodyParams(const char * key, const char * value)
{
   request.addBodyParam(MessageComposer(key, value, MessageType::BODY).formatMessage());
   return *this;
}

Response& HTTPClient::get(const char* query)
{
   if (query)
      request.setQuery(QueryString(*query));

   return require(new HTTPGetMethod());
}

Response& HTTPClient::post()
{
   return require(new HTTPPostMethod());
}
