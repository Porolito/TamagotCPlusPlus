#pragma once
#include <raylib.h>
#include <iostream>

class Tamagot {
public:
	Tamagot(std::string name, const char* imagePath);
	void Draw();
	void UpdateAnyMeter(int meterType, const char& exposant);

private:
	std::string m_name;
	Texture2D m_texture;
	Vector2 m_position{ 275, 275 };
	int m_happinessMeter{ 0 };
	int m_hungrynessMeter{ 0 };
	int m_needsMeter{ 0 };
};