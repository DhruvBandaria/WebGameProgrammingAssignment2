#include "Virus.h"
#include "Game.h"

Virus::Virus()
{
	TheTextureManager::Instance()->load("../Assets/textures/Virus.png", "virus", 
					TheGame::Instance()->getRenderer());
	setPosition(glm::vec2(200, 200));

	std::cout << "Player on scene!" << std::endl;

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("virus");
	setWidth(size.x);
	setHeight(size.y);
	setIsColliding(false);
	setType(GameObjectType::VIRUS);
}

Virus::~Virus()
{
}

void Virus::draw()
{
	TheTextureManager::Instance()->draw("virus", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(), true);
}

void Virus::update()
{
}

void Virus::clean()
{
}
