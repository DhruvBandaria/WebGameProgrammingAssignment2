#include "StartButton.h"
#include "Game.h"


StartButton::StartButton()
	:Button(
		"../Assets/textures/Buttons/QuitButton.png",
		"startButton1",
		START_BUTTON1, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.7f)), m_isClicked(false)
{
}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheGame::Instance()->quit();
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
