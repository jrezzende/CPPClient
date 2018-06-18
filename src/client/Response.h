#pragma once
#ifndef INCLUDED_RESPONSE_H
#define INCLUDED_RESPONSE_H

#include <curl/curl.h>
#include <string>

class Response
{
   CURLcode status;
   
   std::string headerData;
   std::string bodyData;

public:
   ~Response()= default;
   Response()= default;

   void appendHeaderParam(const std::string& param) { headerData.append(param.c_str()); }
   void appendBodyParam(const std::string& param) { bodyData.append(param.c_str()); }
   void setStatusCode(CURLcode code) { status= code; }

   CURLcode statusCode() { return status; }

   const std::string& header() { return headerData; }
   const std::string& body() { return bodyData; }
};

#endif // !INCLUDED_RESPONSE_H