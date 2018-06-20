#include "Host.h"

void Host::appendPort()
{
   if (!port)
      return;

   url.append(":").append(std::to_string(port));
}

void Host::appendRoute()
{
   if (!route)
      return;

   if (route[0] != '/')
      url.append("/");
   url.append(route);
}

void Host::appendQuery()
{
   if (queryString) {
      if (url[url.size() - 1] != '/')
         url.append("/");
      url.append(queryString);
   }
}

const char * Host::composeHost()
{
   url= std::string();
   url.append("http://");

   hostAddress= "localhost";
   route= "audaces/idea/api/v1/";
   queryString = "query/?reference=BUTTON&amp;type=raw_material";
   url.append(hostAddress);

   appendPort();
   appendRoute();
   appendQuery();
    
   return url.c_str();
}