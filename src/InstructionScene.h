#pragma once
#ifndef __INSTRUCTION_SCENE__
#define __INSTRUCTION_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Start.h"

class InstructionScene final : public Scene
{
public:
	InstructionScene();
	~InstructionScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	glm::vec2 m_mousePosition;
	Label* m_pHeading;
	Label* m_pText1;
	Label* m_pText2;
	Label* m_pText3;
	Label* m_pText4;
	Label* m_pText5;

	Start* m_pStartButton;
};

#endif /* defined (__END_SCENE__) */#pragma once
