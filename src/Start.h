#pragma once
#ifndef __START__
#define __START__

#include "Button.h"

class Start : public Button
{
public:
	Start();
	~Start();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */