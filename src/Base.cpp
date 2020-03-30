#include "Base.h"
#include "Game.h"

Base::Base()
{
	TheTextureManager::Instance()->load("../Assets/textures/Base.png",
		"base", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("base");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setType(GameObjectType::BASE);
	setIsColliding(false);
}

Base::~Base()
{
}

void Base::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("base", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Base::update()
{
}

void Base::clean()
{
}
