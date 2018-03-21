

#include "class_Abstract.h"

extern float offsetX;
extern float offsetY;


#ifndef class_FLAG_H_
#define class_FLAG_H_


class Flag :public Abstract
{
public:

	bool alive;

	Flag(const char* object_name, int pos_x, int pos_y, sf::Texture & t, int t_x, int t_y, int t_width, int t_height, int step) :
		Abstract(object_name, pos_x, pos_y, t, t_x, t_y, t_width, t_height, step)
	{

		alive = false;
		dy = 0.0;
		dx = 0.0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	}

	~Flag() {};
};




#endif
