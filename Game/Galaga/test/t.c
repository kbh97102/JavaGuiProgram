#include "t.h"	


void user_init() {
	user1.user_index_imagearray= 1;
	user1.life = 15;
	user1.user_xpos = scr_width / 2;  //ÃÊ±âxÁÂÇ¥
	user1.user_ypos = 200;	//ÃÊ±â yÁÂÇ¥
}

void enemy_init() {
	int enemy_indexStart = 6;
	int enemy_xposStart = 50;
	int enemy_yposStart = 100;
	for (int i = 0; i < num_enemy; i++) {
		enemy[i].enemy_index_imagearray = enemy_indexStart++;
		enemy[i].life = 5;
		enemy[i].enemy_xpos = enemy_xposStart;
		enemy[i].enemy_ypos = enemy_yposStart;
		enemy_xposStart += 20;
		enemy_yposStart += 30;
	}
}