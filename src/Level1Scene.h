#pragma once
#ifndef __LEVEL1_SCENE__
#define __LEVEL1_SCENE__

#include "Scene.h"
#include "ship.h"
#include "Ground.h"
#include "Player.h"
#include "Base.h"
#include "Virus.h"
#include "Label.h"
#include "Door.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	bool playerIsGrounded();
private:
	glm::vec2 m_mousePosition;
	const int totalGroundElements = 50;
	std::vector<Ground*> m_pGrounds;
	std::vector<Base*> m_pBase;

	
	float m_FrontStartPoint;
	float m_BackScrollingPoint;
	float m_InitalStartPoint;
	float m_InitialEndPoint;
	
	Player* m_pPlayer;
	Virus* m_pVirus1;
	Virus* m_pVirus2;
	Virus* m_pVirus3;
	Virus* m_pVirus4;
	Virus* m_pVirus5;
	Virus* m_pVirus6;
	Virus* m_pVirus7;
	Virus* m_pVirus8;
	Virus* m_pVirus9;
	Virus* m_pVirus10;

	bool* isCollected;

	int totalCollected;

	Label* m_pScoreLabel;
	bool isDead;

	Door* m_pDoor;
	
};

#endif /* defined (__LEVEL1_SCENE__) */