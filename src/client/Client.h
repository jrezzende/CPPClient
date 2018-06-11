#pragma once
#ifndef INCLUDED_CLIENT_H
#define INCLUDED_CLIENT_H

#include <curl\curl.h>
#include "rapidjson.h"

class Client
{
   Client()= default;
   ~Client()= default;

   int curlTest();
};

#endif // INCLUDED_CLIENT_H