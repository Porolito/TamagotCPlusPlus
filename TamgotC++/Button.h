#pragma once
#include <raylib.h>
#include "Tamagot.h"

class Button
{
public:
	Button(const char* imagePath, Vector2 imagePosition, float scale);
	~Button();
	void Draw();
	virtual bool isPressed(Vector2 mousePos, bool mousePressed);
	virtual void DoAction() = 0;
	virtual void DoAction(Tamagot) = 0;
protected:
	Texture2D m_texture;
	Vector2 m_position;
};

class StartButton : public Button 
{
public:
	StartButton(const char* imagePath, Vector2 imagePosition, float scale);
	~StartButton() = default;
	void DoAction() override;
	void DoAction(Tamagot currentTamagot) override {};
}; 

class FeedButton : public Button 
{
public:
	FeedButton(const char* imagePath, Vector2 imagePosition, float scale);
	~FeedButton() = default;
	virtual bool isPressed(Vector2 mousePos, bool mousePressed, Tamagot currentTamagot);
	void DoAction() override {};
	void DoAction(Tamagot currentTamagot) override;
private:
	int m_meterContext{ 2 };
};
