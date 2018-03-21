
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"

#include "class_Abstract.h"


extern float offsetX;
extern float offsetY;


#ifndef class_ENEMY_H_
#define class_ENEMY_H_



class Enemy :public Abstract
{
public:

	Enemy(const char*  object_name, int pos_x, int pos_y, sf::Texture & t, int t_x, int t_y, int t_width, int t_height, int step) :
		Abstract(object_name, pos_x, pos_y, t, t_x, t_y, t_width, t_height, step)
	{
		alive = true;
		dy = 0;
		dx = 0.05;
	}

	void update(float time) // грибы будут двигаться только по земле 
	{

		rect.left += dx*time;

		CollisionX();


		currentFrame += 0.005*time;



		if (currentFrame > count) // currentFrame > count+1 =)
			currentFrame -= count;

		sprite.setTextureRect(sf::IntRect(19 * int(currentFrame), 0, texture_width, texture_height));





		if (!alive)
			sprite.setTextureRect(sf::IntRect(58, 0, 16, 16));

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY); // выводим спрайт в 															 
																	 // в эту позицию
	}

	void CollisionX()
	{
		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; ++i)
		{
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; ++j)
			{
				if (TileMap[i][j] == 'T' || TileMap[i][j] == 'W' || TileMap[i][j] == 'G' || TileMap[i][j] == 'B' || TileMap[i][j] == 'k')
				{
					if (dx > 0)
					{
						rect.left = j * 16 - rect.width;
						dx = dx*(-1);
					}
					else if (dx < 0)
					{
						rect.left = j * 16 + 16;
						dx = dx*(-1);
					}
				}



			}//for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; ++j)
		}//for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; ++i)

	}

	bool live()
	{
		return alive;
	}

	~Enemy() {}
};





#endif