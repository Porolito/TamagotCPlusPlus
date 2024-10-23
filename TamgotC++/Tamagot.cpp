#include "Tamagot.h"

Tamagot::Tamagot(std::string name, const char* imagePath)
{
	m_name = name;
	m_texture = LoadTexture(imagePath);
}

void Tamagot::Draw()
{
	DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
}

/// <summary>
/// 1 = Happiness
/// 2 = Hungryness
/// 3 = Needs
/// </summary>
/// <param name="meterType"></param>
/// <param name="exposant"></param>
void Tamagot::UpdateAnyMeter(int meterType, const char& exposant)
{
	const char plus = '+';
	const char moins = '-';
	switch (meterType) 
	{
	case 1:
		if (exposant == plus) {
			m_happinessMeter += 10;
		}
		else if (exposant == moins) {
			m_happinessMeter -= 10;
		}
		std::cout << "Happiness meter : " << m_happinessMeter << std::endl;
		break;

	case 2:
		if (exposant == plus) {
			m_hungrynessMeter += 10;
		}
		else if (exposant == moins) {
			m_hungrynessMeter -= 10;
		}
		std::cout << "Hungryness meter : " << m_hungrynessMeter << std::endl;
		break;
		
	case 3:
		if (exposant == plus) {
			m_needsMeter += 10;
		}
		else if (exposant == moins) {
			m_needsMeter -= 10;
		}
		std::cout << "Needs meter : " << m_needsMeter << std::endl;
		break;

	default:
		std::cout << "Wrong type was typed" << std::endl;
	}
	
	
	

}
