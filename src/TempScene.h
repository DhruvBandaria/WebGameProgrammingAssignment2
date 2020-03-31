#pragma once
#ifndef __TEMP_SCENE__
#define __TEMP_SCENE__

#include "Scene.h"
#include "Label.h"
#include "PlayAgain.h"
#include "Start.h"
#include "Instruction.h"
#include "Quit.h"

class TempScene final : public Scene
{
public:
	TempScene();
	~TempScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	Start* m_pStart;
	Instruction* m_pInstruction;
	Quit* m_pQuit;

	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */