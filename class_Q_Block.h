

#include "class_Abstract.h"

extern float offsetX;
extern float offsetY;


#ifndef class_Q_BLOCK
#define class_Q_BLOCK


class Q_Block :public Abstract
{
public:

	bool onGround;
	int Ground;

	Q_Block(const char* object_name, int pos_x, int pos_y, sf::Texture & t, int t_x, int t_y, int t_width, int t_height, int step) :
		Abstract(object_name, pos_x, pos_y, t, t_x, t_y, t_width, t_height, step)
	{
		alive = true;
		dy = 0.0;
		dx = 0.0;

		Ground = pos_y;
		onGround = true;
	}

	void update(float time)
	{

		if (!onGround)
			dy = dy + 0.001*time; //падаем с ускорением на землю
								  // вниз это y > 0
		rect.top += dy*time;

		onGround = false;

		if (rect.top > Ground)
		{
			rect.top = Ground;
			onGround = false;
			dy = 0;
		}


		sprite.setTextureRect(sf::IntRect(texture_pos_x, texture_pos_y, texture_width, texture_height));

		if (!alive)
			sprite.setTextureRect(sf::IntRect(sf::IntRect(144, 112, 16, 15)));
		//sprite.setTextureRect(sf::IntRect(112, 112, 16, 16));








		sprite.setPosition(rect.left - offsetX, rect.top - offsetY); // выводим спрайт в 															 
																	 // в эту позицию
	}

	~Q_Block() {};
};




#endif
