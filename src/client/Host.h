#pragma once
#ifndef INCLUDED_HOST_H
#define INCLUDED_HOST_H

#include <string>

namespace { const unsigned short HTTPDEFAULT = 80; const unsigned short HTTPS = 443; }

class Host
{
   std::string url;

   void appendPort();
   void appendRoute();
   void appendQuery();

public:
   ~Host()= default;

   unsigned short port;

   const char* queryString;

   const char* route= nullptr;
   const char* hostAddress= nullptr;
   const char* composeHost();
};

#endif // !INCLUDED_HOST_H