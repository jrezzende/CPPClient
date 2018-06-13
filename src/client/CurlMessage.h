#pragma once
#ifndef INCLUDED_CURLMESSAGE_H
#define INCLUDED_CURLMESSAGE_H

#include "curl\curl.h"

#include <vector>
#include <string>

class CurlMessage
{
   struct curl_slist* headers;

   std::vector<std::string> bodyParams;

public:
   ~CurlMessage() { curl_slist_free_all(headers); }
   CurlMessage()= default;

   void appendHeader(const std::string& data) { headers= curl_slist_append(headers, data.c_str()); }
   void appendBodyParam(const std::string& parameter) { bodyParams.push_back(parameter); }

   curl_slist* headersRequests() { return headers; }

   const char* bodyRequest() {
      std::string req;
      for (auto param : bodyParams)
         req.append(param).append("&");
      req.erase(req.at(req.length() - 1));
      return req.c_str();
   }
};

#endif // !INCLUDED_CURLMESSAGE_H
