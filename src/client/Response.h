#pragma once
#ifndef INCLUDED_RESPONSE_H
#define INCLUDED_RESPONSE_H

#include <string>

class Response
{
   unsigned short status;
   
   std::string headerData;
   std::string bodyData;

public:
   ~Response()= default;
   Response()= default;

   void appendHeaderParam(const std::string& param) { headerData.append(param.c_str()); }
   void appendBodyParam(const std::string& param) { bodyData.append(param.c_str()); }
   void setStatusCode(unsigned short code) { status= code; }

   unsigned short statusCode() { return status; }

   const std::string& header() { return headerData; }
   const std::string& body() { return bodyData; }

};

#endif // !INCLUDED_RESPONSE_H