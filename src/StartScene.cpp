#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	m_pStartLabel->draw();
	m_pGuide->draw();
	m_pStartButton->draw();
	m_pInstruction->draw();
	m_pQuitButton->draw();
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();

	m_pInstruction->setMousePosition(m_mousePosition);
	m_pInstruction->ButtonClick();

	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();

}

void StartScene::clean()
{
	std::cout << "Clean called on StartScene" << std::endl;
	
	delete m_pStartLabel;
	m_pStartLabel = nullptr;
	//removeAllChildren();
}

void StartScene::handleEvents()
{
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
			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				m_pInstruction->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pInstruction->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::INSTRUCTION_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

void StartScene::start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pStartLabel = new Label("Corona Run", "Consolas", 80, blue, glm::vec2(400.0f, 140.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	const SDL_Color red = { 255, 0, 0, 255 };
	m_pGuide = new Label("Shortcuts: 1 for start 2 for instruction and Esc for Quit", "Consolas", 10, red, glm::vec2(200.0f, 20.0f));
	m_pGuide->setParent(this);
	addChild(m_pGuide);

	m_pStartButton = new Start();
	m_pInstruction = new Instruction();
	m_pQuitButton = new Quit();

	TheSoundManager::Instance()->load("../Assets/audio/MenuSound.mp3", "menuSound", SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("menuSound", 0);
	
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}