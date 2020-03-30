#pragma once
#ifndef __VIRUS__
#define __VIRUS__

#include "DisplayObject.h"

class Virus : public DisplayObject
{
public:
	Virus();
	~Virus();
	void draw() override;
	void update() override;
	void clean() override;
};

#endif
