#pragma once
#ifndef INCLUDED_MESSAGECOMPOSER_H
#define INCLUDED_MESSAGECOMPOSER_H

#include <string>

enum class MessageType { HEADER, BODY };

class MessageComposer
{
   MessageType type;

   const char* key;
   const char* value;

public:
   ~MessageComposer() = default;
   MessageComposer(const char* _key, const char* _value, const MessageType _type) :
      key(_key), value(_value), type(_type) {}

   std::string fomatMessage() {
      std::string msg= key;
      type == MessageType::HEADER ? msg.append(": ") : msg.append("="); msg.append(value).c_str();
      return msg;
   }
};

#endif // !INCLUDED_MESSAGECOMPOSER_H