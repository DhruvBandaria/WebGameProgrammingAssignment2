#pragma once
#ifndef __BUTTON__
#define __BUTTON__

#include "DisplayObject.h"
#include <SDL_hints.h>

class Button : public DisplayObject
{
public:
	Button(std::string imagePath = "../Assets/textures/StartButton.png",
		std::string buttonName = "start",
		GameObjectType type = START,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);

	virtual ~Button();

	void draw() override;
	void update() override;
	void clean() override;

	// setters
	void setMousePosition(glm::vec2 mousePosition);
	void setMouseButtonClicked(bool clicked);

	virtual bool ButtonClick() = 0;

private:
	Uint8 m_alpha;
	std::string m_name;
	bool m_isCentered;
	


protected:
	// getters
	bool m_mouseButtonClicked;
	bool m_mouseOver();
	glm::vec2 m_mousePosition;
};

#endif /* defined (__BUTTON__) */