#pragma once
#ifndef INCLUDED_HTTP_CLIENT_H
#define INCLUDED_HTTP_CLIENT_H

#include "WebRequestClient.h"

class HTTPClient : public WebRequestClient
{
public:
   ~HTTPClient()= default;
   HTTPClient(const char* host);

   HTTPClient& port(unsigned short port) override;
   HTTPClient& route(const char* route) override;
   HTTPClient& headerParams(const char* key, const char* value) override;
   HTTPClient& bodyParams(const char* key, const char * value) override;

   Response& get(const char* query) override;
   Response& post() override;
};

#endif // INCLUDED_HTTP_CLIENT_H