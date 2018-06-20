#pragma once
#ifndef INCLUDED_WEB_REQUEST_CLIENT_H
#define INCLUDED_WEB_REQUEST_CLIENT_H

#include "Request.h"
#include "Response.h"

class HTTPMethods;

class WebRequestClient
{
protected:
   Request request;
   Response require(HTTPMethods* method);

   WebRequestClient(const char* host) { request.host(); }

public:
   virtual ~WebRequestClient()= default;
   
   virtual WebRequestClient& port(unsigned short _port) = 0;
   virtual WebRequestClient& route(const char* route) = 0;
   virtual WebRequestClient& headerParams(const char* key, const char* value) = 0;
   virtual WebRequestClient& bodyParams(const char* key, const char* value) = 0;

   virtual Response& get(const char* query) = 0;
   virtual Response& post() = 0;
};

#endif // !INCLUDED_WEB_REQUEST_CLIENT_H
