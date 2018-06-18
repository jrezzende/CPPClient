#pragma once
#ifndef INCLUDED_HTTP_POST_METHOD_H
#define INCLUDED_HTTP_POST_METHOD_H

#include "HTTPMethods.h"

class HTTPPostMethod : public HTTPMethods
{
public:
   ~HTTPPostMethod()= default;
   HTTPPostMethod()= default;

   Response answer(Request& request) override;
};

#endif // !INCLUDED_HTTP_POST_METHOD_H
