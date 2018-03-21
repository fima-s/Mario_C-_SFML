
#ifndef MAP_H_
#define MAP_H_



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


const int H = 22;

const int W = 256;


sf::String TileMap[H] = {

	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	"W                                                                                                                                                                                                                                                            WW",//1
	"W                                                                                                                                                                                                                                                            WW",//2
	"W                                                                                                                                                                                                                                                            WW",//3
	"W                                                                                                                                                                                                                                                            WW",//4
	"W                                                                                                                                                                                                                                                            Ww",//5
	"W        O                   O               O                      O O               O O            O O                                                                                                                                                     WW",//6
	"W                                                                                                                                                                                                                                                            WW",//7
	"W                                                                                                                                                                                                                                                            WW",//8
	"W                    O               O                O  O               O                  O   O          O O O                                                                                                                                             WW",//9
	"W                                                                                                                                                                                                                                                            WW",//10
	"W                                                                                                                                                                                                                   QQ                                       WW",//11
	"W                                                                                  BBBBB      BBBB                                       BBB       BBBB                                                            QQQ                                       WW",//12
	"W                                                                                                                                                                                                                 QQQQ            C                          WW",//13
	"W            BBB                                                                                                                                                                                                 QQQQQ                                       WW",//14
	"W                                                                                                                                                                                       BBB                     QQQQQQ                                       WW",//15
	"W                          TT         TT                TT                                                                                                                                                     QQQQQQQ                                       WW",//16
	"WM                         WW         WW            M   WW                                               M                                                                    TT              M     TT        QQQQQQQQ  M                                    WW",//17
	"W                  K       WW         WW    k           WW  K    m      k  m         k        k                     k     K   m             K             k        k   m      WW     k              WW       QQQQQQQQQ        K       K                      WW",//18
	"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG   GGGGGGGGGGGGGGGGGGGGGGGGG  GGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
	"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG   GGGGGGGGGGGGGGGGGGGGGGGGG  GGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
	"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG   GGGGGGGGGGGGGGGGGGGGGGGGG  GGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
	//0         |10       |20       |30       |40       |50       |60       |70       |801       |90       |100      |110      |120      |130      |140      |150      |160      |170      |180      |190      |200      |210      |220 ..Эта шкала смещена, потому что я еблан
};




#endif