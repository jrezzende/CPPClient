#pragma once
#ifndef INCLUDED_HTTP_GET_METHOD_H
#define INCLUDED_HTTP_GET_METHOD_H

#include "HTTPMethods.h"

class HTTPGetMethod : public HTTPMethods
{
public:
   ~HTTPGetMethod()= default;
   HTTPGetMethod()= default;

   Response answer(Request& request) override;
};

#endif // !INCLUDED_HTTP_GET_METHOD_H
