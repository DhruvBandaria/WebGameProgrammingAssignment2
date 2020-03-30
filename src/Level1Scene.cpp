#include "Level1Scene.h"
#include "Game.h"

Level1Scene::Level1Scene()
{
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
= default;

void Level1Scene::draw()
{
	int tempCount=0;
	for (Ground* ground : m_pGrounds) {
		if(tempCount>10 && tempCount< 17)
		{
			
		}
		else if(tempCount> 22 && tempCount< 26)
		{
			
		}
		else if (tempCount > 31 && tempCount < 34)
		{

		}
		else if(tempCount > 40 && tempCount < 44)
		{
			
		}
		else {
			ground->draw();
		}
		tempCount++;
	}
	tempCount = 0;
	for (Base* base : m_pBase)
	{
		if (tempCount > 10 && tempCount < 17)
		{

		}
		else if (tempCount > 22 && tempCount < 26)
		{

		}
		else if (tempCount > 31 && tempCount < 34)
		{

		}
		else if (tempCount > 40 && tempCount < 44)
		{

		}
		else {
			base->draw();
		}
		tempCount++;
	}
	if(!isCollected[0])
		m_pVirus1->draw();
	if (!isCollected[1])
		m_pVirus2->draw();
	if (!isCollected[2])
		m_pVirus3->draw();
	if (!isCollected[3])
		m_pVirus4->draw();
	if (!isCollected[4])
		m_pVirus5->draw();
	if (!isCollected[5])
		m_pVirus6->draw();
	if (!isCollected[6])
		m_pVirus7->draw();
	if (!isCollected[7])
		m_pVirus8->draw();
	if (!isCollected[8])
		m_pVirus9->draw();
	if (!isCollected[9])
		m_pVirus10->draw();

	m_pDoor->draw();
	
	m_pPlayer->draw();

	m_pScoreLabel->draw();
	//drawDisplayList();
}

void Level1Scene::update()
{
	if (!isDead) {
		int tempCount = 0;
		for (Ground* ground : m_pGrounds) {
			if (tempCount > 10 && tempCount < 17)
			{

			}
			else if (tempCount > 22 && tempCount < 26)
			{

			}
			else if (tempCount > 31 && tempCount < 34)
			{

			}
			else if (tempCount > 40 && tempCount < 44)
			{

			}
			else {
				auto bottomLine = glm::vec2(m_pPlayer->getPosition().x, m_pPlayer->getPosition().y + m_pPlayer->getHeight() / 2 + 22);
				Collision::lineRectCheck(m_pPlayer, bottomLine, ground, ground->getWidth(), ground->getHeight() + 30);
			}
			tempCount++;
		}
		m_pPlayer->update();
		m_pPlayer->isGrounded = playerIsGrounded();
		bool isStartPointReached = false;
		if (m_pPlayer->getPosition().x > m_FrontStartPoint)
		{
			int i = 5;
			int count = 0;
			bool isEndPointReached = false;
			for (Ground* ground : m_pGrounds) {
				if (count == totalGroundElements - 1)
				{
					if (ground->getPosition().x <= m_InitialEndPoint)
					{
						float* tempXvalues = new float[totalGroundElements];
						float temp = 784;
						for (int i = totalGroundElements - 1; i >= 0; i--)
						{
							tempXvalues[i] = temp;
							temp -= 32;
						}
						count = 0;
						for (Ground* ground : m_pGrounds)
						{
							ground->setPosition(glm::vec2(tempXvalues[count], 330));
							count++;
						}
						isEndPointReached = true;
						break;
					}
				}
				ground->setPosition(glm::vec2(ground->getPosition().x - i, 330));
				count++;
			}
			i = 5;
			count = 0;
			isEndPointReached = false;
			for (Base* ground : m_pBase) {
				if (count == totalGroundElements - 1)
				{
					if (ground->getPosition().x <= m_InitialEndPoint)
					{
						float* tempXvalues = new float[totalGroundElements];
						float temp = 784;
						for (int i = totalGroundElements - 1; i >= 0; i--)
						{
							tempXvalues[i] = temp;
							temp -= 32;
						}
						count = 0;
						for (Base* ground : m_pBase)
						{
							ground->setPosition(glm::vec2(tempXvalues[count], 480));
							count++;
						}
						isEndPointReached = true;
						break;
					}
				}
				ground->setPosition(glm::vec2(ground->getPosition().x - i, 480));
				count++;
			}

			if (!isEndPointReached) {
				m_pPlayer->setPosition(glm::vec2(m_pPlayer->getPosition().x - i, m_pPlayer->getPosition().y));
				m_pVirus1->setPosition(glm::vec2(m_pVirus1->getPosition().x - i, m_pVirus1->getPosition().y));
				m_pVirus2->setPosition(glm::vec2(m_pVirus2->getPosition().x - i, m_pVirus2->getPosition().y));
				m_pVirus3->setPosition(glm::vec2(m_pVirus3->getPosition().x - i, m_pVirus3->getPosition().y));
				m_pVirus4->setPosition(glm::vec2(m_pVirus4->getPosition().x - i, m_pVirus4->getPosition().y));
				m_pVirus5->setPosition(glm::vec2(m_pVirus5->getPosition().x - i, m_pVirus5->getPosition().y));
				m_pVirus6->setPosition(glm::vec2(m_pVirus6->getPosition().x - i, m_pVirus6->getPosition().y));
				m_pVirus7->setPosition(glm::vec2(m_pVirus7->getPosition().x - i, m_pVirus7->getPosition().y));
				m_pVirus8->setPosition(glm::vec2(m_pVirus8->getPosition().x - i, m_pVirus8->getPosition().y));
				m_pVirus9->setPosition(glm::vec2(m_pVirus9->getPosition().x - i, m_pVirus9->getPosition().y));
				m_pVirus10->setPosition(glm::vec2(m_pVirus10->getPosition().x - i, m_pVirus10->getPosition().y));
				m_pDoor->setPosition(glm::vec2(m_pDoor->getPosition().x - i, m_pDoor->getPosition().y));
			}
		}
		if (m_pPlayer->getPosition().y > 450)
		{
			isDead = true;
		}
		if (m_pPlayer->getPosition().x < m_BackScrollingPoint)
		{
			int i = 5;
			int count = 0;

			for (Ground* ground : m_pGrounds) {
				if (count == 0)
				{
					if (ground->getPosition().x >= m_InitalStartPoint)
					{
						float temp = 16;

						for (Ground* ground : m_pGrounds)
						{
							ground->setPosition(glm::vec2(temp, 330));
							temp += 32;
						}
						isStartPointReached = true;
						break;
					}
				}
				ground->setPosition(glm::vec2(ground->getPosition().x + i, 330));
				count++;
			}
			i = 5;
			count = 0;

			for (Base* ground : m_pBase) {
				if (count == 0)
				{
					if (ground->getPosition().x >= m_InitalStartPoint)
					{
						float temp = 16;

						for (Base* ground : m_pBase)
						{
							ground->setPosition(glm::vec2(temp, 480));
							temp += 32;
						}
						isStartPointReached = true;
						break;
					}
				}
				ground->setPosition(glm::vec2(ground->getPosition().x + i, 480));
				count++;
			}

			if (!isStartPointReached) {
				m_pPlayer->setPosition(glm::vec2(m_pPlayer->getPosition().x + i, m_pPlayer->getPosition().y));
				m_pVirus1->setPosition(glm::vec2(m_pVirus1->getPosition().x + i, m_pVirus1->getPosition().y));
				m_pVirus2->setPosition(glm::vec2(m_pVirus2->getPosition().x + i, m_pVirus2->getPosition().y));
				m_pVirus3->setPosition(glm::vec2(m_pVirus3->getPosition().x + i, m_pVirus3->getPosition().y));
				m_pVirus4->setPosition(glm::vec2(m_pVirus4->getPosition().x + i, m_pVirus4->getPosition().y));
				m_pVirus5->setPosition(glm::vec2(m_pVirus5->getPosition().x + i, m_pVirus5->getPosition().y));
				m_pVirus6->setPosition(glm::vec2(m_pVirus6->getPosition().x + i, m_pVirus6->getPosition().y));
				m_pVirus7->setPosition(glm::vec2(m_pVirus7->getPosition().x + i, m_pVirus7->getPosition().y));
				m_pVirus8->setPosition(glm::vec2(m_pVirus8->getPosition().x + i, m_pVirus8->getPosition().y));
				m_pVirus9->setPosition(glm::vec2(m_pVirus9->getPosition().x + i, m_pVirus9->getPosition().y));
				m_pVirus10->setPosition(glm::vec2(m_pVirus10->getPosition().x + i, m_pVirus10->getPosition().y));
				m_pDoor->setPosition(glm::vec2(m_pDoor->getPosition().x + i, m_pDoor->getPosition().y));
			}
		}
		if (!isCollected[0]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus1))
			{
				isCollected[0] = true;
				totalCollected++;
			}
		}
		if (!isCollected[1]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus2))
			{
				isCollected[1] = true;
				totalCollected++;
			}
		}
		if (!isCollected[2]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus3))
			{
				isCollected[2] = true;
				totalCollected++;
			}
		}
		if (!isCollected[3]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus4))
			{
				isCollected[3] = true;
				totalCollected++;
			}
		}
		if (!isCollected[4]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus5))
			{
				isCollected[4] = true;
				totalCollected++;
			}
		}
		if (!isCollected[5]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus6))
			{
				isCollected[5] = true;
				totalCollected++;
			}
		}
		if (!isCollected[6]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus7))
			{
				isCollected[6] = true;
				totalCollected++;
			}
		}
		if (!isCollected[7]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus8))
			{
				isCollected[7] = true;
				totalCollected++;
			}
		}
		if (!isCollected[8]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus9))
			{
				isCollected[8] = true;
				totalCollected++;
			}
		}
		if (!isCollected[9]) {
			if (Collision::AABBCheckPlayer(m_pPlayer, m_pVirus10))
			{
				isCollected[9] = true;
				totalCollected++;
			}
		}

		m_pScoreLabel->setText("Score:" + std::to_string(totalCollected) + "/10");
	}
	else
	{
		TheGame::Instance()->changeSceneState(END_SCENE);
	}
}

void Level1Scene::clean()
{

	removeAllChildren();
}

void Level1Scene::handleEvents()
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
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
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
				if (m_pPlayer->isGrounded)
				{
					m_pPlayer->jump();

				}
				break;
			case SDLK_s:

				break;
			case SDLK_a:
				m_pPlayer->move(LEFT);
				break;
			case SDLK_d:
				m_pPlayer->move(RIGHT);

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
				m_pPlayer->setVelocity(glm::vec2(0, m_pPlayer->getVelocity().y));

				break;
			case SDLK_d:
				m_pPlayer->setVelocity(glm::vec2(0, m_pPlayer->getVelocity().y));

				break;
			}

			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	TheSoundManager::Instance()->stopMusic();
	for (size_t i = 0; i < totalGroundElements; i++)
	{
		m_pGrounds.push_back(new Ground());
		m_pBase.push_back(new Base());
	}
	int i = 16;

	for (Ground* ground : m_pGrounds) {
		ground->setPosition(glm::vec2(i, 330));
		addChild(ground);

		i += 32;
	}
	i = 16;
	for(Base* base : m_pBase)
	{
		base->setPosition(glm::vec2(i, 480));
		addChild(base);
		i += 32;
	}

	m_pPlayer = new Player();
	m_pPlayer->setPosition(glm::vec2(100, 100));
	addChild(m_pPlayer);

	m_pVirus1 = new Virus();
	m_pVirus1->setPosition(glm::vec2(345, 300));
	addChild(m_pVirus1);

	m_pVirus2 = new Virus();
	m_pVirus2->setPosition(glm::vec2(390, 250));
	addChild(m_pVirus2);

	m_pVirus3 = new Virus();
	m_pVirus3->setPosition(glm::vec2(440, 205));
	addChild(m_pVirus3);

	m_pVirus4 = new Virus();
	m_pVirus4->setPosition(glm::vec2(500, 250));
	addChild(m_pVirus4);
	
	m_pVirus5 = new Virus();
	m_pVirus5->setPosition(glm::vec2(540, 300));
	addChild(m_pVirus5);

	m_pVirus6 = new Virus();
	m_pVirus6->setPosition(glm::vec2(710, 300));
	addChild(m_pVirus6);
	
	m_pVirus7 = new Virus();
	m_pVirus7->setPosition(glm::vec2(780, 230));
	addChild(m_pVirus7);

	m_pVirus8 = new Virus();
	m_pVirus8->setPosition(glm::vec2(860, 300));
	addChild(m_pVirus8);

	m_pVirus9 = new Virus();
	m_pVirus9->setPosition(glm::vec2(1060, 230));
	addChild(m_pVirus9);

	m_pVirus10 = new Virus();
	m_pVirus10->setPosition(glm::vec2(1360, 205));
	addChild(m_pVirus9);

	isCollected = new bool[10];
	totalCollected = 0;
	for(int i = 0; i < 10; i++)
	{
		isCollected[i] = false;
	}
	const SDL_Color blue = { 255, 0, 0, 255 };
	m_pScoreLabel = new Label("Score:"+std::to_string(totalCollected)+"/10", "Consolas", 25, blue, glm::vec2(700.0f, 50.0f));
	m_pScoreLabel->setParent(this);
	addChild(m_pScoreLabel);
	
	m_FrontStartPoint = 650.0f;
	m_BackScrollingPoint = 150.0f;
	m_InitalStartPoint = 0;
	m_InitialEndPoint = Config::SCREEN_WIDTH;

	isDead = false;

	m_pDoor = new Door();
	m_pDoor->setPosition(glm::vec2(1500, 300));

	TheSoundManager::Instance()->load("../Assets/audio/VirusPickUp.wav", "virusPickUp", SOUND_SFX);
	TheSoundManager::Instance()->load("../Assets/audio/GameMusic.mp3", "gameSound", SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("gameSound", 1);
}

bool Level1Scene::playerIsGrounded()
{
	for (Ground* ground : m_pGrounds) {

		if (ground->playerAtGround == true)
		{
			return true;
		}
	}
	return false;
}
