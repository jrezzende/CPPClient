#pragma once
#ifndef INCLUDED_METHODREQUEST_H
#define INCLUDED_METHODREQUEST_H

#include <curl\curl.h>
#include "Response.h"
#include "Request.h"

enum class METHOD { GET, POST };

class MethodRequest
{
   CURL* curl;
   Response response;

public:
   virtual ~MethodRequest()= default;
   MethodRequest()= default;

   virtual Response request(Request& request);

};

#endif // !INCLUDED_METHODREQUEST_H
