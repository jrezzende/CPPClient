#pragma
#ifndef INCLUDED_CURLE_THROWER_H
#define INCLUDED_CURLE_THROWER_H

#include <curl\curl.h>
#include <string>
#include <stdexcept>

struct Except : public std::exception {
   std::string curlString;
   virtual const char* what() { return curlString.c_str(); }
};

namespace CurleThrower {
   Except newException(CURLcode code) { 
      Except except; except.curlString= curl_easy_strerror(code); 
      return except;
   }
} // namespace CurleThrower

#endif // !INCLUDED_CURLE_THROWER