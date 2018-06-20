#pragma once
#ifndef INCLUDED_CURL_BODY_MESSAGE
#define INCLUDED_CURL_BODY_MESSAGE

#include <string>
#include <vector>

#include "BodyParams.h"

class CurlBodyMessage 
{
   std::string req;
   std::vector<BodyParams> params;

public:
   ~CurlBodyMessage()= default;
   CurlBodyMessage()= default;

   void appendBodyMessage(const BodyParams& msg) { params.push_back(msg); }

   const char* bodyRequest() {
      req= std::string();

      if (params.size())
         for (auto param : params)
            req.append(param.bodyParamRequest().append("&"));

      if (req.length() - 1 == '&')
         req.erase(req.at(req.length() - 1));

      return req.c_str();
   }
};

#endif // !INCLUDED_CURL_BODY_MESSAGE
