#pragma once

#include "Media.h"

class Audio : public Media
{
public:
	Audio() {}
	virtual ~Audio() {}
	virtual void display() const override;

};
