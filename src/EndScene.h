#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "PlayAgain.h"

class EndScene final : public Scene
{
public:
	EndScene();
	~EndScene();

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