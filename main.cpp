#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "class_Player.h"
#include "class_Abstract.h"
#include "class_Enemy.h"
#include "class_Q_Block.h"
#include "class_Coin.h"
#include "class_Flag.h"
//#include "Map.h"


#include <string>
#include <list>
#include <sstream>
#include <algorithm>



float offsetX = 0;
float offsetY = 0;


void _world_generation(std::list<Abstract*> & Dynamic_obj_list, sf::Texture & map_set, sf::Texture & coins_tex);




int main()
{

	sf::RenderWindow window(sf::VideoMode(640, 330), "Super_Mario");
	
	window.setFramerateLimit(60); 
	// limit of frames per sec 


	sf::Texture t;
	t.loadFromFile("mario_sprite_sheet.png");

	sf::Texture map_set;
	map_set.loadFromFile("Mario_tileset.png");
	sf::Sprite map(map_set);

	sf::Texture coins_tex;
	coins_tex.loadFromFile("Coins.png");
	sf::Sprite coins_sprite(coins_tex);

	float currentFrame = 0;

	//------Music-------------------
	
	sf::SoundBuffer jump_buffer;
	jump_buffer.loadFromFile("jump-small.wav");
	sf::Sound jump_sound(jump_buffer);

	sf::SoundBuffer kick_buffer;
	kick_buffer.loadFromFile("kick.wav");
	sf::Sound kick_sound(kick_buffer);

	sf::SoundBuffer coin_buffer;
	coin_buffer.loadFromFile("coin.wav");
	sf::Sound coin_sound(coin_buffer);

	sf::SoundBuffer mario_fall_buffer;
	mario_fall_buffer.loadFromFile("mario_die.wav");
	sf::Sound mario_fall_sound(mario_fall_buffer);

	sf::SoundBuffer stage_clear_buffer;
	stage_clear_buffer.loadFromFile("stage_clear.wav");
	sf::Sound stage_clear_sound(stage_clear_buffer);

	sf::Music music;
	music.openFromFile("Mario_Theme.ogg");
	music.play();
	music.setLoop(true);
	//-------------------------------------


	/////////////////World generation////////////////////

	Player Super_mario(t);
	
	std::list<Abstract*> Dynamic_obj_list;



	_world_generation(Dynamic_obj_list, map_set, coins_tex);  // working only with  /FORCE:MULTIPLE

	sf::Clock clock;
	clock.restart();


	sf::RectangleShape rectangle(sf::Vector2f(16, 16));

	sf::Font font;
	font.loadFromFile("prstart.ttf");
	sf::Text text1("", font, 14);
	sf::Text text2("", font, 14);
	sf::Text text3("", font, 10); //200 on Mario head

	sf::Text coin_text1("", font, 13);
	sf::Text coin_text2("", font, 13);
	
	int text3_tick = 1;
	bool t3_begin = false;// generation of "200"
	
	bool fell_down = false;  
	bool game_over = false;




	
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 700; // speed of game
		
		if (time > 20)
			time = 20;


		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			for (auto it = Dynamic_obj_list.begin(); it != Dynamic_obj_list.end();)
			{
				if ((*it)->alive == false && (*it)->name != "Q_block")
				{
					Abstract * m = *it;

					it = Dynamic_obj_list.erase(it);

					delete m;
					
				}
				else
					++it;
			}
		
		}

		

		/////////////////////Controls//////////////////////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if(!fell_down && !game_over) //Not fell down
			  Super_mario.dx = 0.1;
		
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (!fell_down && !game_over)//Not fell down
			  Super_mario.dx = -0.1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (Super_mario.onGround && !fell_down && !game_over) //can jump only on ground
			{
				Super_mario.dy = -0.3;
				Super_mario.onGround = false; 
				jump_sound.play();
			}
		}


		///////////////////////Update///////////////////////////
		Super_mario.update(time);
		

		for (auto x = Dynamic_obj_list.begin(); x != Dynamic_obj_list.end(); ++x)
			(*x)->update(time);



		///////////////////Interaction_with_obj///////////////////////////////


		for (auto it = Dynamic_obj_list.begin(); it != Dynamic_obj_list.end();++it)
		{
			if (Super_mario.rect.intersects((*it)->rect) && Super_mario.alive)
			{
				if ((*it)->name == "Mushroom")
				{
					if ((*it)->alive)
					{
						if (Super_mario.dy > 0)
						{
							(*it)->dx = 0;
							Super_mario.dy = -0.2;
							(*it)->alive = false;
						
							Super_mario.points+=200;
							
							text3_tick = 1;
							t3_begin = true;

							kick_sound.play();
						}
						else
						{
							Super_mario.sprite.setTextureRect(sf::IntRect(88, 48, 16, 16));
							Super_mario.alive = false;
						}
					}
				}	
				if ((*it)->name == "Q_block")
				{
					if ((*it)->alive == true) 
					{
						if (Super_mario.dy < 0) // push Q block
						{
							(*it)->alive = false;

							// Mario pushed from Q_block
							Super_mario.rect.top = Super_mario.rect.top + 16;
							Super_mario.dy = 0;
							
							
							if (Super_mario.dx > 0)
								Super_mario.rect.left = Super_mario.rect.left - Super_mario.rect.width;
							if (Super_mario.dx < 0)
								Super_mario.rect.left = Super_mario.rect.left + 16;


							(*it)->dy = -0.1;

					
							for (auto p = Dynamic_obj_list.begin(); p != Dynamic_obj_list.end(); ++p)
							{
								if ((*p)->map_pos_x == (*it)->map_pos_x && (*p)->name == "Coin_rot")
								{
									(*p)->dy = -1.0;
									(*p)->alive = false; 
									coin_sound.play();
									
									Super_mario.points += 200;
									++Super_mario.coins;

									text3_tick = 1;
									t3_begin = true;
								}
							}


						}
						else
						{
							Super_mario.onGround = true;
							Super_mario.rect.top = (*it)->rect.top - 16;
				
							Super_mario.dy = 0;
							
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							{
								Super_mario.dx = 0.1;

							}

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
							{
								Super_mario.dx = -0.1;
							}


							currentFrame += 0.005*time;

							if (currentFrame > 3)currentFrame -= 3;

							if (Super_mario.onGround)
							{
								if (Super_mario.dx > 0) 
								{
									Super_mario.sprite.setTextureRect(sf::IntRect(40 * int(currentFrame) + 8, 7, 16, 16));
								}
								if (Super_mario.dx < 0) 
								{
									Super_mario.sprite.setTextureRect(sf::IntRect(102 - 40 * int(currentFrame), 7, -16, 16));
								}
							}
								
											
						}
					}
					else
					{
						
						if (Super_mario.dy < 0)
						{
							
							Super_mario.rect.top = Super_mario.rect.top + 16;
							Super_mario.dy = 0;
							
							if (Super_mario.dx > 0)
								Super_mario.rect.left = Super_mario.rect.left - Super_mario.rect.width;
							if (Super_mario.dx < 0)
								Super_mario.rect.left = Super_mario.rect.left + 16;
							
							
							
							(*it)->dy = -0.1; // box jumps




						}
						else // walking on platform
						{
							Super_mario.onGround = true;
							Super_mario.rect.top = (*it)->rect.top - 16;
						
							Super_mario.dy = 0;
			
							
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							{
								Super_mario.dx = 0.1;

							}

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
							{
								Super_mario.dx = -0.1;
							}
							
							
							currentFrame += 0.005*time;

							if (currentFrame > 3)currentFrame -= 3;

							if (Super_mario.onGround)
							{
								if (Super_mario.dx > 0) 
								{
									Super_mario.sprite.setTextureRect(sf::IntRect(40 * int(currentFrame) + 8, 7, 16, 16));
								}
								if (Super_mario.dx < 0) 
								{
									Super_mario.sprite.setTextureRect(sf::IntRect(102 - 40 * int(currentFrame), 7, -16, 16));
								}
							}
							
							Super_mario.dy = 0;
						}
					}
				}			
			}

		}// 	for (auto it = Dynamic_obj_list.begin(); it != Dynamic_obj_list.end(); ++it)


		for (auto it = Dynamic_obj_list.begin(); it != Dynamic_obj_list.end();)
		{
			
			if (Super_mario.rect.intersects((*it)->rect) && (*it)->name == "Coin_classic" && Super_mario.alive)
			{
				++Super_mario.coins;
				Super_mario.points += 200;

				coin_sound.play();

				Abstract * ptr = *it;

				it = Dynamic_obj_list.erase(it);
				delete ptr;
					
				
			}
			else
				++it;
		
		}

		//Interaction_with_obj___GRAVITY_TEST + Death
		if (Super_mario.rect.top + Super_mario.rect.height >= 20 * 16 || !Super_mario.alive)
		{
			
			music.stop();
			
			if (Super_mario.alive)
			{
				fell_down = true;
				
				mario_fall_sound.play();
				
				Super_mario.sprite.setTextureRect(sf::IntRect(88, 48, 16, 16));

				Super_mario.dy = -0.11;
				Super_mario.alive = false;
	
			}
			else if(!Super_mario.alive && !fell_down) 
			{
				fell_down = true;

				mario_fall_sound.play();

				Super_mario.sprite.setTextureRect(sf::IntRect(88, 48, 16, 16));

				Super_mario.dy = -0.11;

			}


			if (Super_mario.rect.top + Super_mario.rect.height > 21 * 16 && !Super_mario.alive)
				window.close();

		}


		// GAME_OVER_TEST
		if (Super_mario.rect.left + Super_mario.rect.width >= 228 * 16)
		{
			static int game_over_counter = 0;

			if (game_over == false)
			{
				game_over = true;
				
				music.stop();

				Super_mario.sprite.setTextureRect(sf::IntRect(7, 45, 17, 16));
				stage_clear_sound.play();

				auto x = std::find_if(Dynamic_obj_list.begin(), Dynamic_obj_list.end(), [](const Abstract * it)->bool
				{
					return it->name == "Flag";
				});
			
				(*x)->alive = true;
			}
			else if(game_over)
			{
				game_over_counter++;
			}
				

			if (game_over_counter > 500)
				window.close();
		}



		if(Super_mario.rect.left > 320 ) //&& Super_mario.rect.left < 500
		offsetX = Super_mario.rect.left - 320;




		/////////////////MAP//////////////////////////////////////

		window.clear(sf::Color(107, 140, 255)); // blue background
	
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'O')//Cloud
					map.setTextureRect(sf::IntRect(98, 224, 42, 25));
				if (TileMap[i][j] == 'G')//Пол map.setTextureRect(sf::IntRect(208, 59, 42, 40));
					map.setTextureRect(sf::IntRect(96, 112, 16, 16));
				if (TileMap[i][j] == 'T')//Tube
				{	
					if ((i == 16 && j == 27) || i == 16 && j == 38 
					   ||  i == 16 && j == 56|| i == 17 && j == 174 || i == 17 && j == 196)
						map.setTextureRect(sf::IntRect(0, 48, 32, 49));
					else
						continue;
				}
				
				if (TileMap[i][j] == 'K')//Bush
					map.setTextureRect(sf::IntRect(4, 106, 68, 20));
				
				if (TileMap[i][j] == 'B') // Block 
					map.setTextureRect(sf::IntRect(144, 112, 16, 15));
				
				if(TileMap[i][j] == 'Q') // Q_block
					map.setTextureRect(sf::IntRect(112, 112, 15, 15));
				
				if (TileMap[i][j] == 'M')//Big mountain
					map.setTextureRect(sf::IntRect(146, 221, 75, 33));
				
				if (TileMap[i][j] == 'm')// little mountain
					map.setTextureRect(sf::IntRect(0, 140, 47, 20));
				
				if (TileMap[i][j] == 'k')//little bush
					map.setTextureRect(sf::IntRect(50, 58, 41, 20));
						
				if (TileMap[i][j] == 'C')//Castle
					map.setTextureRect(sf::IntRect(95, 6, 107, 105));

				
				

				if (TileMap[i][j] == 'W')
					continue;

				if (TileMap[i][j] == ' ')
					continue;
				
				map.setPosition(j*16 - offsetX, i*16);
				window.draw(map);


			}
		}



		///////////////drowing of dinamic object list////////////
		for (auto x = Dynamic_obj_list.begin(); x != Dynamic_obj_list.end(); ++x)
		{
			if((*x)->name != "Flag" )
				window.draw((*x)->sprite);
			else if ((*x)->name == "Flag" && (*x)->alive == true )
				window.draw((*x)->sprite);
		}
		
		window.draw(Super_mario.sprite);




		//////////////////////Working with text, sometime not stable ////////////////

		std::ostringstream pointsString;
		pointsString << Super_mario.points;
		//pointsString << (Super_mario.rect.left/16); // for texting, drowing coordinates of Mario


		std::stringstream coins;
		coins << Super_mario.coins;

		text1.setString("MARIO");
		text1.setStyle(sf::Text::Bold);

		text2.setString(pointsString.str());
		text3.setString("200");
		
		coin_text1.setString("COINS");
		coin_text2.setString("X " + coins.str());

		text1.setPosition(1 * 16, 0*16);
		text2.setPosition(2 * 16, 1 * 16); // Name and points
		text3.setPosition(Super_mario.rect.left - offsetX, Super_mario.rect.top-2*16);


		coin_text1.setPosition(9 * 16, 0 * 16);
		coin_text2.setPosition(10 * 16, 1 * 16);



		window.draw(text1);
		window.draw(text2);
		window.draw(coin_text1);
		window.draw(coin_text2);

		if (text3_tick < 35 && t3_begin)
		{
			window.draw(text3);
			++text3_tick;
		}



	
		window.display();
	
	} // while (window.isOpen())


	return 0;
}


