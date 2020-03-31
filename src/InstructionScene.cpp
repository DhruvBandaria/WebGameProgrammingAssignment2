#include "InstructionScene.h"
#include "Game.h"

InstructionScene::InstructionScene()
{
	InstructionScene::start();
}

InstructionScene::~InstructionScene()
= default;

void InstructionScene::draw()
{
	m_pHeading->draw();
	m_pText1->draw();
	m_pText2->draw();
	m_pText3->draw();
	m_pText4->draw();
	m_pText5->draw();
	m_pStartButton->draw();
}

void InstructionScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void InstructionScene::clean()
{
}

void InstructionScene::handleEvents()
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
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
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

void InstructionScene::start()
{
	const SDL_Color black = { 0, 0, 0, 255 };
	m_pHeading = new Label("Instructions", "Consolas", 50, black, glm::vec2(Config::SCREEN_WIDTH * 0.5, 80));
	m_pHeading->setParent(this);
	addChild(m_pHeading);

	std::string text = "Welcome to Corona Run, you are a alien who visited earth to gather sample of corona virus";
	
	m_pText1 = new Label(text, "Consolas", 15, black, glm::vec2(Config::SCREEN_WIDTH * 0.5, 150));
	m_pText1->setParent(this);
	addChild(m_pText1);
	
	m_pText2 = new Label("Controls:", "Consolas", 25, black, glm::vec2(Config::SCREEN_WIDTH * 0.5, 200));
	m_pText2->setParent(this);
	addChild(m_pText2);

	m_pText3 = new Label("W - Jump", "Consolas", 25, black, glm::vec2(Config::SCREEN_WIDTH * 0.5, 250));
	m_pText3->setParent(this);
	addChild(m_pText3);

	m_pText4 = new Label("A - Move Left", "Consolas", 25, black, glm::vec2(Config::SCREEN_WIDTH * 0.5, 300));
	m_pText4->setParent(this);
	addChild(m_pText4);

	m_pText5 = new Label("D - Move Right", "Consolas", 25, black, glm::vec2(Config::SCREEN_WIDTH * 0.5, 350));
	m_pText5->setParent(this);
	addChild(m_pText5);
	
	m_pStartButton = new Start();
	m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, 500));
	addChild(m_pStartButton);
}
