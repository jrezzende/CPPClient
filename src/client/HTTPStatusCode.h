#pragma once
#ifndef INCLUDED_HTTPSTATUSCODE_H
#define INCLUDED_HTTPSTATUSCODE_H

#include <stdexcept>

class HTTPStatusCode : public std::exception { virtual const char* what() const = 0; };

class HTTPStatusCode1XX : public HTTPStatusCode 
{
   virtual const char* what() const { return "Request received. Continuing proccess."; }
};

class HTTPStatusCode2XX : public HTTPStatusCode
{
   virtual const char* what() const { return "Request has been successfully accepted."; }
};

class HTTPStatusCode3XX : public HTTPStatusCode
{
   virtual const char* what() const { return "Client must take additional actions to complete the request."; }
};

class HTTPStatusCode4XX : public HTTPStatusCode
{
   virtual const char* what() const { return "Client request misguided."; }
};

class HTTPStatusCode5XX : public HTTPStatusCode
{
   virtual const char* what() const { return "Server couldn't resolve request."; }
};

#endif // INCLUDED_HTTPSTATUSCODE_H