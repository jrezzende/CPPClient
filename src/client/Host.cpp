#include "Host.h"
#include <sstream>

void Host::appendPort()
{
   if (!port)
      return;

   url_.append(":").append(std::to_string(port));
}

void Host::appendRoute()
{
   if (!route)
      return;

   if (route[0] != '/')
      url_.append("/");
   url_.append(route);
}

void Host::appendQuery()
{
   if (queryString) {
      if (url_[url_.size() - 1] != '/')
         url_.append("/");
      url_.append(queryString);
   }
}

const char* Host::compose()
{
   url_ = std::string();
   url_.append("http://");
   hostAddress= "localhost";

   url_.append(hostAddress);
   appendPort();
   appendRoute();
   appendQuery();
    
   return url_.c_str();
}