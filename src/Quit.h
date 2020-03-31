#pragma once
#ifndef __QUIT__
#define __QUIT__

#include "Button.h"

class Quit : public Button
{
public:
	Quit();
	~Quit();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */