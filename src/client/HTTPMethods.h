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
   Response content;

   static std::size_t bodyCallBack(const char* ptr, std::size_t size, std::size_t nmemb, void* data);
   static std::size_t headerCallBack(const char* ptr, std::size_t size, std::size_t nmemb, void* data);

public:
   virtual ~HTTPMethods()= default;
   HTTPMethods()= default;

   virtual Response answer(Request& req);
};

#endif // !INCLUDED_HTTP_METHODS_H
