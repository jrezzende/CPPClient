#pragma once
#ifndef INCLUDED_BODY_PARAMS_H
#define INCLUDED_HEADER_PARAMS_H

#include <string>

class BodyParams
{
   const char* key;
   const char* value;

public:
   ~BodyParams()= default;
   BodyParams(const char* _key, const char* _value) : key(_key), value(_value) {}

   std::string bodyParamRequest() { return std::string(key).append("=").append(value).c_str(); }
};

#endif // !INCLUDED_HEADER_PARAMS_H
