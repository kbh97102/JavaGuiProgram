#include "updater.h"

void update_init() {
	current_scene = Ingame;
	yoffset = 0;
	xoffset = 0;
	delta = 1;
	load_soundFile();
	sound_play(1);
}
void gameplay_init() {
	ingame_timer_init();
}
void update(long delta_time) {
	switch (current_scene) {
	case Title:
		update_title();
		break;
	case Ingame:
		ingame_timer += delta_time;
		update_ingame();
		break;
	}
}
void update_title() {

}
int is_collide(int image_index1, int image_index2) {
	if (xy_collection[image_index1].minX + xoffset <= xy_collection[image_index2].maxX  &&
		xy_collection[image_index1].maxX + xoffset >= xy_collection[image_index2].minX) {
		if (xy_collection[image_index1].minY + yoffset <= xy_collection[image_index2].maxY  &&
			xy_collection[image_index1].maxY + yoffset >= xy_collection[image_index2].minY) {
			return 1;
		}
		else return 0;
	}
	else return 0;
}
void ingame_timer_init() {
	ingame_timer = get_current_time();
}
void set_xy_collection() {
	//최대 최소 이미지 좌표 설정
	xy_collection[User].minX = imageArray[User]->Xposition;
	xy_collection[User].minY = imageArray[User]->Yposition;
	xy_collection[User].maxX = imageArray[User]->Xposition + (double)imageArray[User]->width;
	xy_collection[User].maxY = imageArray[User]->Yposition + (double)imageArray[User]->height;

	xy_collection[Boss].minX = imageArray[Boss]->Xposition;
	xy_collection[Boss].minY = imageArray[Boss]->Yposition;
	xy_collection[Boss].maxX = imageArray[Boss]->Xposition + (double)imageArray[Boss]->width;
	xy_collection[Boss].maxY = imageArray[Boss]->Yposition + (double)imageArray[Boss]->height;
}
void update_ingame() {
	set_xy_collection();
	if (get_keystatus(VK_W)) {
		yoffset = -SPEED * delta;
	}
	if (get_keystatus(VK_S)) {
		yoffset = SPEED * delta;
	}
	if (get_keystatus(VK_A)) {
		xoffset = -SPEED * delta;
	}
	if (get_keystatus(VK_D)) {
		xoffset = SPEED * delta;
	}
	if (xoffset != 0 && yoffset != 0) {
		xoffset /= SQRT2;
		yoffset /= SQRT2;
	}
	imageArray[User]->Xposition += xoffset;
	imageArray[User]->Yposition += yoffset;

	if (get_keystatus(VK_Z)) { // Z누르면 정지
		sound1_stat = mciSendCommand(sound1_id, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	}
	if (get_keystatus(VK_X)) { // X누르면 재생
		sound1_stat = mciSendCommand(sound1_id, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Sound_Play);
	}
	//화면밖으로 못나가게
	//미리 보는것 지금 장소+속도 가 화면밖을 넘어가면 지금장소로 찍게끔
	if (xy_collection[User].minY +yoffset < 0) {  //위쪽 충돌
		imageArray[User]->Yposition -= yoffset;
	}
	if (xy_collection[User].maxY + yoffset > scr_height) { //아래쪽 충돌
		imageArray[User]->Yposition -= yoffset;
	}
	if (xy_collection[User].minX +xoffset < 0) {
		imageArray[User]->Xposition -= xoffset;
	}
	if (xy_collection[User].maxX + xoffset > scr_width) {
		imageArray[User]->Xposition  -= xoffset;
	}
	if (is_collide(User, Boss)) {
		imageArray[User]->Xposition -= xoffset;
		imageArray[User]->Yposition -= yoffset;
	}
	//패턴짜기 기초
	if (ingame_timer % 5000 <= 20) {
		destroy_enemy = 0;
		draw_boss = 1;
	}
	if (ingame_timer % 10000 <= 20) {
		sound_pause(1);
		sound_play(2);
	}
	if (ingame_timer <= 5000) {
		
	}
}





