#pragma once
#ifndef INCLUDED_QUERY_STRING_H
#define INCLUDED_QUERY_STRING_H

#include <map>

class QueryString
{
   const char* queryStr;

public:
   ~QueryString()= default;
   QueryString(const char& _query) : queryStr(&_query) {}

   const char* query() { return queryStr; }
};

#endif // INCLUDED_QUERY_STRING_H