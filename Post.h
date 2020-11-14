#pragma once

#include <string>
#include <memory>
#include "Media.h"

class Post
{
public:
	explicit Post(const std::string);
	Post(const std::string,  Media*);
	void display();
	virtual ~Post();

	std::string getText() const;
	Media* getMedia() const;

private:
	std::string _text;
	Media* _media;
};
