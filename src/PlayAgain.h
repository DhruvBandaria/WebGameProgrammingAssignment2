#pragma once
#ifndef __PLAY_AGAIN_BUTTON__
#define __PLAY_AGAIN_BUTTON__

#include "Button.h"

class PlayAgain : public Button
{
public:
	PlayAgain();
	~PlayAgain();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */