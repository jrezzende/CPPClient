#pragma once
#ifndef INCLUDED_USER_AGENT_H
#define INCLUDED_USER_AGENT_H

#include "Request.h"
#include "Response.h"

class HTTPMethods;

class UserAgent
{
protected:
   Request request;
   Response require(HTTPMethods* method);

   UserAgent(const char* host) { request.host(); }

public:
   virtual ~UserAgent()= default;
   
   virtual UserAgent& port(unsigned short _port) = 0;
   virtual UserAgent& route(const char* route) = 0;
   virtual UserAgent& headerParams(const char* key, const char* value) = 0;
   virtual UserAgent& bodyParams(const char* key, const char* value) = 0;

   virtual Response& get(const char* query) = 0;
   virtual Response& post() = 0;
};

#endif // !INCLUDED_USER_AGENT_H
