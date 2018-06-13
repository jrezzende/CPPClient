#pragma once
#ifndef INCLUDED_HTTPHEADER_H
#define INCLUDED_HTTPHEADER_H

#include <map>

class Header
{
   std::map<const char*, const char*> parameters;

public:
   ~Header()= default;
   Header()= default;

   void newParameter(const char* key, const char* value) { parameters.insert(std::make_pair(key, value)); }
   std::map<const char*, const char*> params() { return parameters; }
};

#endif // !INCLUDED_HTTPHEADER_H
