#pragma once
#ifndef __BASE__

#define __BASE__

#include "DisplayObject.h"

class Base : public DisplayObject
{
public:

	Base();
	~Base();

	void draw() override;
	void update() override;
	void clean() override;

	bool playerAtGround;

};

#endif
