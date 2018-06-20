#pragma once
#ifndef INCLUDED_HEADERPARAMS_H
#define INCLUDED_HEADERPARAMS_H

#include <string>

class HeaderParams
{
   const char* key;
   const char* value;

public:
   ~HeaderParams()= default;
   HeaderParams(const char* _key, const char* _value) : key(_key), value(_value) {}

   std::string headerParamRequest() { return std::string(key).append(": ").append(value).c_str(); }
};

#endif // INCLUDED_HEADERPARAMS_H