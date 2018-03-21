
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"


extern float offsetX;
extern float offsetY;




#ifndef class_PLAYER_H_
#define class_PLAYER_H_


class Player
{
public:

	float dx, dy; // velocity components
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	sf::Sprite jump_sprite;
	float currentFrame;

	int coins;
	int points;

	bool alive;


	Player(sf::Texture & image)
	{
		sprite.setTexture(image);
		sprite.setTextureRect(sf::IntRect(7, 45, 17, 16));


		rect = sf::FloatRect(2 * 16, 7 * 16, 17, 16);

		onGround = true;
		dx = 0.0;
		dy = 0.0;
		currentFrame = 0;

		coins = 0;
		points = 0;

		alive = true;
	}



	void update(float time)
	{
		if (alive)
		{
			rect.left += dx*time;

			CollisionX();


			if (!onGround)
				dy = dy + 0.0005*time; // presence  gravity
									   
			rect.top += dy*time;

			onGround = false;

			CollisionY();

			currentFrame += 0.005*time;

			if (currentFrame > 3)currentFrame -= 3;

			if (onGround)
			{
				if (dx > 0) //right
				{
					sprite.setTextureRect(sf::IntRect(40 * int(currentFrame) + 8, 7, 16, 16));
				}
				if (dx < 0) //left
				{
					sprite.setTextureRect(sf::IntRect(102 - 40 * int(currentFrame), 7, -16, 16));
				}



			}
			else
			{
				if (dy < 0 && dx > 0)
				{
					sprite.setTextureRect(sf::IntRect(126, 6, 20, 17));
				}
				else if (dy < 0 && dx < 0)
				{
					sprite.setTextureRect(sf::IntRect(144, 6, -18, 17));
				}
			}

			sprite.setPosition(rect.left - offsetX, rect.top - offsetY); // position os sprite on map 
																		 


			dx = 0;
		}
		else if (alive == false)
		{
			dx = 0.0;

			onGround = false;

			rect.top += dy*time;

			if (!onGround)
				dy = dy + 0.00008*time; 


		}


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY); 

	}


	void CollisionX()
	{
		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; ++i)
		{
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; ++j)
			{
				if (TileMap[i][j] == 'T' || TileMap[i][j] == 'W' || TileMap[i][j] == 'G' || TileMap[i][j] == 'B' || TileMap[i][j] == 'Q')
				{
					if (dx > 0)
						rect.left = j * 16 - rect.width;
					if (dx < 0)
						rect.left = j * 16 + 16;
				}

			}
		}

	}

	void CollisionY()
	{
		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; ++i)
		{
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; ++j)
			{
				if (TileMap[i][j] == 'T' || TileMap[i][j] == 'W' || TileMap[i][j] == 'G' || TileMap[i][j] == 'B' || TileMap[i][j] == 'Q')
				{
					if (dy > 0) 
					{
						rect.top = i * 16 - rect.height;
						dy = 0;
						onGround = true;
					}
					if (dy < 0)
					{
						rect.top = i * 16 + 16;
						dy = 0;
					}
				}

			}
		}
	}



};






#endif