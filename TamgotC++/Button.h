#pragma once
#include <raylib.h>

class Button
{
public:
	Button(const char* imagePath, Vector2 imagePosition, float scale);
	~Button();
	void Draw();
	bool isPressed(Vector2 mousePos, bool mousePressed);
	virtual void DoAction() = 0;
protected:
	Texture2D m_texture;
	Vector2 m_position;
};

class StartButton : public Button 
{
public:
	StartButton(const char* imagePath, Vector2 imagePosition, float scale);
	~StartButton() = default;
	virtual void DoAction();
};
