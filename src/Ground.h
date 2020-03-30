#pragma once
#ifndef __GROUND__

#define __GROUND__

#include "DisplayObject.h"

class Ground : public DisplayObject
{
public:

	Ground();
	~Ground();

	void draw() override;
	void update() override;
	void clean() override;

	bool playerAtGround;

};

#endif
