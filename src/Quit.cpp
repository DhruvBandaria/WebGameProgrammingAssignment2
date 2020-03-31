#include "Quit.h"
#include "Game.h"

Quit::Quit()
	:Button(
		"../Assets/textures/Buttons/QuitButton.png",
		"quit",
		GameObjectType::QUIT, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f)), m_isClicked(false)
{
}

Quit::~Quit()
{
}

bool Quit::ButtonClick()
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
