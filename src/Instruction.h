#pragma once
#ifndef __INSTRUCTION_BUTTON__
#define __INSTRUCTION_BUTTON__

#include "Button.h"

class Instruction : public Button
{
public:
	Instruction();
	~Instruction();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */