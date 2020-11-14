#pragma once
#include "Media.h"

class Video : public Media
{
public:
	Video() {}
	~Video() {}
	virtual void display() const override;

};