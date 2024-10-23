#include "Button.h"
#include <iostream>

Button::Button(const char* imagePath, Vector2 imagePosition, float scale)
{
	Image image = LoadImage(imagePath);
	int originalWidth = image.width;
	int originalHeight = image.height;

	int newWidth = static_cast<int>(originalWidth * scale);
	int newHeigth = static_cast<int>(originalHeight * scale);

	ImageResize(&image, newWidth, newHeigth);

	m_texture = LoadTextureFromImage(image);
	UnloadImage(image);
	m_position = imagePosition;
}

void Button::Draw()
{
	DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed)
{
	Rectangle rect = { m_position.x, m_position.y, static_cast<float>(m_texture.width), static_cast<float>(m_texture.height) };

	if (CheckCollisionPointRec(mousePos, rect) && mousePressed) 
	{
		DoAction();
		return true;
	}
	return false;
}

Button::~Button() 
{
	UnloadTexture(m_texture);
}

void StartButton::DoAction()
{
	std::cout << "Start Button pressed" << std::endl;
}

StartButton::StartButton(const char* imagePath, Vector2 imagePosition, float scale) 
	: Button(imagePath, imagePosition, scale) 
{

};
