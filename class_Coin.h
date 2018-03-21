

#include "class_Abstract.h"

extern float offsetX;
extern float offsetY;



#ifndef class_COIN_H_
#define class_COIN_H_


class Coin :public Abstract
{
public:

	bool onGround;
	int Ground;

	Coin(const char* object_name, int pos_x, int pos_y, sf::Texture & t, int t_x, int t_y, int t_width, int t_height, int step) :
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
			dy = dy + 0.005*time; //падаем с ускорением на землю
								  // вниз это y > 0
		rect.top += dy*time;

		onGround = false;

		if (rect.top > Ground)
		{
			rect.top = Ground;
			onGround = false;
			dy = 0;
		}

		if (name == "Coin_rot")
		{
			currentFrame += 0.05*time;

			if (currentFrame > count) // currentFrame > count+1 =)
				currentFrame -= count;


			sprite.setTextureRect(sf::IntRect(16 * int(currentFrame) + texture_pos_x, texture_pos_y, texture_width, texture_height));
		}
		else
		{

			currentFrame += 0.005*time;

			if (currentFrame > count) // currentFrame > count+1 =)
				currentFrame -= count;


			sprite.setTextureRect(sf::IntRect(16 * int(currentFrame) + texture_pos_x, texture_pos_y, texture_width, texture_height));


		}




		if (name == "Coin")
			sprite.setPosition(rect.left, rect.top);
		else
			sprite.setPosition(rect.left - offsetX, rect.top - offsetY); 														 																	 // в эту позицию
	}


	~Coin() {};
};



#endif