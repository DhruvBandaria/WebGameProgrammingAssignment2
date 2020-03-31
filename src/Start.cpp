#include "Start.h"
#include "Game.h"

Start::Start()
	:Button(
		"../Assets/textures/Buttons/StartButton.png",
		"start",
		START, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f)), m_isClicked(false)
{
}

Start::~Start()
{
}

bool Start::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
