#include <iostream>

#include "App.h"
#include "rapidjson\document.h"
#include "rapidjson\pointer.h"
#include "rapidjson\prettywriter.h"
#include "rapidjson\stringbuffer.h"

#include "curl\curl.h"
#include "HTTPClient.h"

void App::performTest()
{
   try {
      Response& resp= HTTPClient(
      "localhost")
      .port(5000)
      .route("audaces/idea/api/v1/")
      .headerParams("Authorization", "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWV9.E7anaGokIC_y1qEp1XibXjvDNRADhE_pB8WnudVKptw")
      .get("query/?reference=BUTTON&type=raw_material"
      );

      rapidjson::Document document;
      document.Parse(resp.body().c_str());

      rapidjson::StringBuffer buffer;
      rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

      document.Accept(writer);

      std::cout << buffer.GetString() << std::endl;

   } catch (CURLcode errorCode) {
      std::string codeStr= curl_easy_strerror(errorCode);
      std::cout << codeStr << std::endl;
   }
}
