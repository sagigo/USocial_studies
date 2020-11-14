#include <iostream>
#include "Message.h"

Message::Message(const std::string text) : _text(text)
{
}

std::string Message::getText() const
{
	return std::string();
}

std::ostream& operator<<(std::ostream& output, const Message& message)
{
	output << message._text;
	return output;
}
