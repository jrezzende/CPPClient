#pragma once
#ifndef INCLUDED_HTTP_METHODS_H
#define INCLUDED_HTTP_METHODS_H

#include "curl\curl.h"
#include "Response.h"
#include "Request.h"

enum class METHOD {
   GET= 1,
   POST
};

class HTTPMethods
{
protected:
   CURL* curl;
   Response* content;

public:
   virtual ~HTTPMethods()= default;
   HTTPMethods() { content= new Response(); }
   virtual Response answer(Request& req);
};

#endif // !INCLUDED_HTTP_METHODS_H
