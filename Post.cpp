#include "Post.h"
#include <memory>
#include <iostream>

Post::Post(const std::string text) :_text(text), _media(nullptr)
{
}

Post::Post(const std::string text, Media* media) : _text(text), _media(media)
{
}

void Post::display()
{
	std::cout << "[" << _text << "]: ";
	if (_media)
	{
		_media->display();
	}
	else
	{
		std::cout << std::endl;
	}
}


Post::~Post()
{
	delete _media;
}

std::string Post::getText() const
{
	return _text;
}

Media* Post::getMedia() const
{
	return _media;
}

