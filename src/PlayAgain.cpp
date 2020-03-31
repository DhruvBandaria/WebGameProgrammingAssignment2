#include "PlayAgain.h"
#include "Game.h"

PlayAgain::PlayAgain()
	:Button(
		"../Assets/textures/Buttons/PlayAgain.png",
		"playAgain",
		PLAY_AGAIN, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.7f)), m_isClicked(false)
{
}

PlayAgain::~PlayAgain()
{
}

bool PlayAgain::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
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
