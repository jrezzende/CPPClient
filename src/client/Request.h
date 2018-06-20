#pragma once
#ifndef INCLUDED_REQUEST_H
#define INCLUDED_REQUEST_H

#include "Host.h"
#include "CurlBodyMessage.h"
#include "CurlHeaderMessage.h"

class Request
{
   Host requestHost;

   CurlBodyMessage bodyMsg;
   CurlHeaderMessage headerMsg;

 public:
   ~Request()= default;
   Request()= default;

   void setHost(const char* host) { requestHost.hostAddress= host; }
   void setPort(const unsigned short port) { requestHost.port= port; }
   void setRoute(const char* route) { requestHost.route= route;}
   void setQuery(const char* query) { requestHost.queryString= query; }

   void addBodyParam(BodyParams& content) { bodyMsg.appendBodyMessage(content); }
   void addHeaderParam(HeaderParams& content) { headerMsg.appendHeaderMessage(content); }
   
   const char* host() { return requestHost.composeHost(); }
   const char* body() { return bodyMsg.bodyRequest(); }
   const curl_slist* header() { return headerMsg.headersRequests(); }
};

#endif // !INCLUDED_REQUEST_H