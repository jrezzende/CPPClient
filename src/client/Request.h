#pragma once
#ifndef INCLUDED_REQUEST_H
#define INCLUDED_REQUEST_H

#include "Host.h"
#include "CurlMessage.h"

class Request
{
   Host requestHost;
   CurlMessage curlmsg;

 public:
   ~Request()= default;
   Request()= default;

   void setHost(const char* host) { requestHost.address= host; }
   void setPort(const unsigned short port) { requestHost.port= port; }
   void setRoute(const char* route) { requestHost.route= route;}
   void setQuery(QueryString& query) { requestHost.queryString= &query; }

   void addBodyParam(const std::string& data) { curlmsg.appendBodyParam(data); }
   void addHeaderParam(const std::string& data) { curlmsg.appendHeader(data); }
   
   const char* host() { return requestHost.composeHost(); }
   const char* body() { return curlmsg.bodyRequest(); }
   const curl_slist* header() { return curlmsg.headersRequests; }
};

#endif // !INCLUDED_REQUEST_H