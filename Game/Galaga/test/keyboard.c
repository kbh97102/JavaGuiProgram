#include "t.h"
#include "keyboard.h"

//1.4142


void init_update() {

}
void update(long delta_time) {
	if (get_keystatus(VK_W)) {
		if (get_keystatus(VK_D)) {
			imageArray[image1]->Xposition += SPEED * Square_Root_2;
			imageArray[image1]->Yposition -= SPEED * Square_Root_2;
		}
		else if (get_keystatus(VK_A)) {
			imageArray[image1]->Xposition -= SPEED * Square_Root_2;
			imageArray[image1]->Yposition -= SPEED * Square_Root_2;
		}
		else {
			imageArray[image1]->Yposition -= SPEED;
		}
	}
	else if (get_keystatus(VK_S)) {
		if (get_keystatus(VK_D)) {
			imageArray[image1]->Xposition += SPEED * Square_Root_2;
			imageArray[image1]->Yposition += SPEED * Square_Root_2;
		}
		else if (get_keystatus(VK_A)) {
			imageArray[image1]->Xposition -= SPEED * Square_Root_2;
			imageArray[image1]->Yposition += SPEED * Square_Root_2;
		}
		else {
			imageArray[image1]->Yposition += SPEED;
		}
	}
	else if (get_keystatus(VK_A)) {
		imageArray[image1]->Xposition -= SPEED;
	}
	else if (get_keystatus(VK_D)) {
		imageArray[image1]->Xposition += SPEED;
	}
	if (get_keystatus(VK_J)) { //발사버튼

	}
	if (get_keystatus(VK_ESCAPE)) { //esc누르면 종료
		isgame_exit = 1;
	}
}
