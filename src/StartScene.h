#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Instruction.h"
#include "Start.h"
#include "Quit.h"

class StartScene final : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	glm::vec2 getMousePosition();
private:
	glm::vec2 m_mousePosition;
	
	Label* m_pStartLabel;
	Label* m_pGuide;

	Start* m_pStartButton;
	Instruction* m_pInstruction;
	Quit* m_pQuitButton;
	
};

#endif /* defined (__START_SCENE__) */