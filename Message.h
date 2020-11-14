#pragma once
#include <string>

class Message
{
	friend std::ostream& operator<<(std::ostream&, const Message&);
public:
	explicit Message(const std::string);
	~Message() {};

	std::string getText() const;

private:
	std::string _text;
};

