#include "TempScene.h"
#include "Game.h"

TempScene::TempScene()
{
	TempScene::start();
}

TempScene::~TempScene()
= default;

void TempScene::draw()
{
	m_pStart->draw();
	m_pInstruction->draw();
	//m_pQuit->draw();
}

void TempScene::update()
{
	m_pStart->setMousePosition(m_mousePosition);
	m_pStart->ButtonClick();

	m_pInstruction->setMousePosition(m_mousePosition);
	m_pInstruction->ButtonClick();
	
	//m_pQuit->setMousePosition(m_mousePosition);
	//m_pQuit->ButtonClick();
}

void TempScene::clean()
{
}

void TempScene::handleEvents()
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
				m_pStart->setMouseButtonClicked(true);
				m_pInstruction->setMouseButtonClicked(true);
				//m_pQuit->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStart->setMouseButtonClicked(false);
				m_pInstruction->setMouseButtonClicked(false);
				//m_pQuit->setMouseButtonClicked(false);
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

void TempScene::start()
{
	m_pStart = new Start();
	m_pInstruction = new Instruction();
	//m_pQuit = new Quit();
	
}
