#include "Instruction.h"
#include "Game.h"

Instruction::Instruction()
	:Button(
		"../Assets/textures/Buttons/InstructionButton.png",
		"instructionButton",
		QUIT_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.7f)), m_isClicked(false)
{
	
}

Instruction::~Instruction()
= default;

bool Instruction::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheGame::Instance()->changeSceneState(SceneState::INSTRUCTION_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
