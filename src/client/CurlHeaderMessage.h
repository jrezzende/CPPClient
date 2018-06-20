#pragma once
#ifndef INCLUDED_CURL_HEADER_MESSAGE_H
#define INCLUDED_CURL_HEADER_MESSAGE_H

#include "HeaderParams.h"
#include "curl\curl.h"

struct curl_slist;

class CurlHeaderMessage
{
  struct curl_slist* headers;

public:
   ~CurlHeaderMessage() { curl_slist_free_all(headers); }
   CurlHeaderMessage() { headers= nullptr; }

   void appendHeaderMessage(HeaderParams& params) { headers= curl_slist_append(headers, params.headerParamRequest().c_str());}
   curl_slist* headersRequests() { return headers; }
};

#endif // INCLUDED_CURL_HEADER_MESSAGE_H
