#pragma once
#ifndef __WIN_SCENE__
#define __WIN_SCENE__

#include "Scene.h"
#include "Label.h"
#include "PlayAgain.h"

class WinScene final : public Scene
{
public:
	WinScene();
	~WinScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	glm::vec2 m_mousePosition;
	Label* m_label;

	PlayAgain* m_pPlayAgain;
};

#endif /* defined (__END_SCENE__) */