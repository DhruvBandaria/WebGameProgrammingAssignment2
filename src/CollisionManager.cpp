#include "CollisionManager.h"
#include "Player.h"
#include "Ground.h"


int CollisionManager::squaredDistance(glm::vec2 P1, glm::vec2 P2)
{
	int diffOfXs = P2.x - P1.x;
	int diffOfYs = P2.y - P1.y;
	int result = diffOfXs * diffOfXs + diffOfYs * diffOfYs;

	return result;
}

bool CollisionManager::squaredRadiusCheck(GameObject * object1, GameObject * object2)
{
	glm::vec2 P1 = object1->getPosition();
	glm::vec2 P2 = object2->getPosition();
	int halfHeights = (object1->getHeight() + object2->getHeight()) * 0.5;

	std::cout << "Here11" << std::endl;
	//if (glm::distance(P1, P2) < halfHeights) {

	if (CollisionManager::squaredDistance(P1, P2) < (halfHeights * halfHeights)) {
		if (!object2->getIsColliding()) {
			std::cout << "Here" << std::endl;
			object2->setIsColliding(true);

			switch (object2->getType()) {
			case PLANET:
				//std::cout << "Collision with Island!" << std::endl;
				TheSoundManager::Instance()->playSound("yay", 0);
				break;
			case MINE:
				//std::cout << "Collision with Cloud!" << std::endl;
				TheSoundManager::Instance()->playSound("thunder", 0);
				break;
			default:
				//std::cout << "Collision with unknown type!" << std::endl;
					break;
			}

			return true;
		}
		return false;
	}

	
}

bool CollisionManager::lineLineCheck(glm::vec2 line1Start, glm::vec2 line1End, glm::vec2 line2Start, glm::vec2 line2End)
{
	float x1 = line1Start.x;
	float x2 = line1End.x;
	float x3 = line2Start.x;
	float x4 = line2End.x;
	float y1 = line1Start.y;
	float y2 = line1End.y;
	float y3 = line2Start.y;
	float y4 = line2End.y;

	// calculate the distance to intersection point
	float uA = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));
	float uB = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

	// if uA and uB are between 0-1, lines are colliding
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) 
	{
		return true;
	}
	
	return false;
}
bool CollisionManager::lineRectCheck(Player* player, glm::vec2 line1End, Ground* ground, float recWidth, float recHeight)
{
	float x1 = player->getPosition().x;
	float x2 = line1End.x;
	float y1 = player->getPosition().y;
	float y2 = line1End.y;
	float rx = ground->getPosition().x - ground->getWidth() / 2;
	float ry = ground->getPosition().y;
	float rw = recWidth;
	float rh = recHeight;

	//TODO FIX THIS

	// check if the line has hit any of the rectangle's sides
	// uses the Line/Line function below
	bool left = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx, ry), glm::vec2(rx, ry + rh));
	bool right = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx + rw, ry), glm::vec2(rx + rw, ry + rh));
	bool top = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx, ry), glm::vec2(rx + rw, ry));
	bool bottom = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx, ry + rh), glm::vec2(rx + rw, ry + rh));

	// if ANY of the above are true, the line
	// has hit the rectangle
	if (top) {


		player->stopJump(glm::vec2(player->getPosition().x, ground->getPosition().y - recHeight * 3 / 4));
		player->isGrounded = true;
		ground->playerAtGround = true;
		return true;

	}
	ground->playerAtGround = false;
	return false;
}

bool CollisionManager::lineRectCheck(glm::vec2 line1Start, glm::vec2 line1End, glm::vec2 recStart, float recWidth, float recHeight)
{
	float x1 = line1Start.x;
	float x2 = line1End.x;
	float y1 = line1Start.y;
	float y2 = line1End.y;
	float rx = recStart.x;
	float ry = recStart.y;
	float rw = recWidth;
	float rh = recHeight;

	//TODO FIX THIS

	// check if the line has hit any of the rectangle's sides
	// uses the Line/Line function below
	bool left = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx, ry), glm::vec2(rx, ry + rh));
	bool right = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx + rw, ry), glm::vec2(rx + rw, ry + rh));
	bool top = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx, ry), glm::vec2(rx + rw, ry));
	bool bottom = lineLineCheck(glm::vec2(x1, y1), glm::vec2(x2, y2), glm::vec2(rx, ry + rh), glm::vec2(rx + rw, ry + rh));

	// if ANY of the above are true, the line
	// has hit the rectangle
	if (left || right || top || bottom) {
		return true;
	}

	return false;
}

bool CollisionManager::AABBCheckPlayer(Player* player, GameObject* object2)
{
	// prepare relevant variables
	glm::vec2 P1 = player->getPosition();
	glm::vec2 P2 = object2->getPosition();
	float P1width = player->getWidth();
	float P1height = player->getHeight();
	float P2width = object2->getWidth();
	float P2height = object2->getHeight();

	if (P2.x < P1.x)
	{
		P2.x = P2.x - (P2width / 2);
	}
	else
	{
		P2.x = P2.x + (P2width / 2);
	}


	if (
		P1.x < P2.x + P2width &&
		P1.x + P1width > P2.x&&
		P1.y < P2.y + P2height &&
		P1.y + P1height > P2.y
		)
	{
		if (!object2->getIsColliding()) {

			object2->setIsColliding(true);
			switch (object2->getType())
			{
			case VIRUS:
				TheSoundManager::Instance()->playSound("virusPickUp", 0);
				break;
			}
			return true;
		}
		return false;
	}
	else
	{
		object2->setIsColliding(false);
		return false;
	}

	return false;
}

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}
