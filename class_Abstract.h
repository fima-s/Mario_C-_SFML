
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

extern float offsetX;
extern float offsetY;



#ifndef class_ABSTRACT_H_
#define class_ABSTRACT_H_






class Abstract //Abstract base class for dynamic objects
{
public:

	float dx, dy;
	sf::FloatRect rect;
	sf::Sprite sprite;
	float currentFrame;
	bool alive;
	std::string name;

	//Texture param
	int texture_pos_x, texture_pos_y, texture_width, texture_height;
	int count; // animation step 
			   

			   // coordinates of object int game
	int map_pos_x;
	int map_pos_y;


	Abstract(const char* object_name, int pos_x, int pos_y, sf::Texture & t, int t_x, int t_y, int t_width, int t_height, int t_count)
	{
		name = object_name;
		map_pos_x = pos_x;
		map_pos_y = pos_y;

		texture_pos_x = t_x;
		texture_pos_y = t_y;
		texture_width = t_width;
		texture_height = t_height;
		count = t_count;

		sprite.setTexture(t);
		rect = sf::FloatRect(map_pos_x, map_pos_y, t_width, t_height);


		sprite.setTextureRect(sf::IntRect(texture_pos_x, texture_pos_y, texture_width, texture_height));

		currentFrame = 0;
		dx = dy = 0;

	}

	virtual void update(float time) = 0;

	virtual ~Abstract() {}
};






#endif