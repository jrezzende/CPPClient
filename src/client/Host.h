#pragma once
#ifndef INCLUDED_HOST_H
#define INCLUDED_HOST_H

#include <string>
#include "QueryString.h"

namespace { const unsigned short HTTP = 80; const unsigned short HTTPS = 443; }

class Host
{
   std::string url;

   void appendPort();
   void appendRoute();
   void appendQuery();

public:
   ~Host()= default;

   unsigned short port;

   QueryString* queryString;

   const char* route;
   const char* address;

   const char* composeHost();
};

#endif // !INCLUDED_HOST_H