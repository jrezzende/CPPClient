#pragma once
#ifndef INCLUDED_HTTPMETHODS_H
#define INCLUDED_HTTPMETHODS_H

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
   Response content;

   static std::size_t bodyCallBack(const char* ptr, std::size_t size, std::size_t nmemb, void* data);
   static std::size_t headerCallBack(const char* ptr, std::size_t size, std::size_t nmemb, void* data);

public:
   virtual ~HTTPMethods()= default;
   HTTPMethods()= default;

   virtual Response request(Request& req);
};

#endif // !INCLUDED_HTTPMETHODS_H
