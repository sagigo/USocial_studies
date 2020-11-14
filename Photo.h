#pragma once

#include "Media.h"

class Photo : public Media
{
public:
	Photo() {}
	virtual ~Photo() {}
	virtual void display() const override;

};
