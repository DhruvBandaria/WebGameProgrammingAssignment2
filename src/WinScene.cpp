#include "WinScene.h";
#include "Game.h"

WinScene::WinScene()
{
	WinScene::start();
}

WinScene::~WinScene()
= default;

void WinScene::draw()
{
	m_label->draw();
	m_pPlayAgain->draw();
}

void WinScene::update()
{
	m_pPlayAgain->setMousePosition(m_mousePosition);
	m_pPlayAgain->ButtonClick();
}

void WinScene::clean()
{
	delete m_label;
	removeAllChildren();
}

void WinScene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pPlayAgain->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pPlayAgain->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;


				/************************************************************************/
			case SDLK_w:
				break;
			case SDLK_s:

				break;
			case SDLK_a:
				break;
			case SDLK_d:

				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				//m_pPlayer->jumping = false;

				break;

			case SDLK_s:

				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		default:
			break;
		}
	}
}

void WinScene::start()
{
	TheSoundManager::Instance()->stopMusic();
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_label = new Label("You Won", "Consolas", 80, blue, glm::vec2(400.0f, 200.0f));
	m_label->setParent(this);
	addChild(m_label);

	m_pPlayAgain = new PlayAgain();
	m_pPlayAgain->setParent(this);
	addChild(m_pPlayAgain);
}
