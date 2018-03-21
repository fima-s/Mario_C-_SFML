#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



#include "class_Abstract.h"
#include "class_Coin.h"
#include "class_Enemy.h"
#include "class_Q_Block.h"
#include "class_Flag.h"

#include <list>





void _world_generation(std::list<Abstract*> & Dynamic_obj_list, sf::Texture & map_set, sf::Texture & coins_tex)
{

	//////////////////////////////// Enemies //////////////////////////////////////////////////
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 10 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 15 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 22 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 30 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 50 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 56 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 75 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 78 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 96 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 115 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 128 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 135 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 168 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 180 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));
	Dynamic_obj_list.push_back(new Enemy("Mushroom", 190 * 16, 18 * 16, map_set, 17, 0, 18, 16, 2));


	//////////////////////////////// Coins //////////////////////////////////////////////////
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 13 * 16, 13 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 14 * 16, 13 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 15 * 16, 13 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 41 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 42 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 43 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 50 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 51 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 52 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 53 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 52 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 53 * 16, 10 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 84 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 85 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 86 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 95 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 96 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 137 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 139 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 148 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 149 * 16, 11 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 184 * 16, 14 * 16, coins_tex, 147, 98, 9, 15, 4));
	Dynamic_obj_list.push_back(new Coin("Coin_classic", 186 * 16, 14 * 16, coins_tex, 147, 98, 9, 15, 4));


	for (int i = 0; i < 7; ++i)
	{
		Dynamic_obj_list.push_back(new Coin("Coin_classic", (30 + i) * 16, 13 * 16, coins_tex, 147, 98, 9, 15, 4));
	}




	// Jumping coins
	Dynamic_obj_list.push_back(new Coin("Coin_rot", 12 * 16, 14 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 12 * 16, 14 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 14 * 16, 10 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 14 * 16, 10 * 16, map_set, 128, 112, 16, 15, 0));


	Dynamic_obj_list.push_back(new Coin("Coin_rot", 5 * 16, 14 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 5 * 16, 14 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 76 * 16, 14 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 76 * 16, 14 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 84 * 16, 8 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 84 * 16, 8 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 86 * 16, 8 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 86 * 16, 8 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 110 * 16, 15 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 110 * 16, 15 * 16, map_set, 128, 112, 16, 15, 0));


	Dynamic_obj_list.push_back(new Coin("Coin_rot", 125 * 16, 15 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 125 * 16, 15 * 16, map_set, 128, 112, 16, 15, 0));


	Dynamic_obj_list.push_back(new Coin("Coin_rot", 132 * 16, 14 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 132 * 16, 14 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 138 * 16, 8 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 138 * 16, 8 * 16, map_set, 128, 112, 16, 15, 0));

	Dynamic_obj_list.push_back(new Coin("Coin_rot", 185 * 16, 11 * 16, coins_tex, 4, 113, 15, 15, 2));
	Dynamic_obj_list.push_back(new Q_Block("Q_block", 185 * 16, 11 * 16, map_set, 128, 112, 16, 15, 0));


	Dynamic_obj_list.push_back(new Coin("Coin", 9 * 16, 1 * 16, coins_tex, 147, 98, 9, 15, 4));


	Dynamic_obj_list.push_back(new Flag("Flag", 228.5 * 16, 12.2 * 16, coins_tex, 128, 1, 16, 15, 0));
}






