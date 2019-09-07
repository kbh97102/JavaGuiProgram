#include "render.h"



void Renderer_initialize() {
	current_scene = Ingame;
	imageArray[User]->Yposition = 800;
	imageArray[User]->Xposition = scr_width /2;
	imageArray[Enemy2]->Yposition = 100;
	imageArray[Enemy2]->Xposition = scr_width/2;
	imageArray[Boss]->Xposition = scr_width / 2 - (imageArray[Boss]->width)/2;
	imageArray[Boss]->Yposition = 100;
	destroy_enemy = 1;
	draw_boss = 0;
}


void Renderer_Render() {
	
	BitBlt(back_dc, 0, 0, scr_width, scr_height, back_dc, 0, 0, BLACKNESS);
	SelectObject(back_dc, back_buffer);
	switch (current_scene) {
	case Title:
		render_title();
		break;
	case Ingame:
		render_ingame();
		break;
	}
	BitBlt(front_dc, 0, 0, scr_width, scr_height, back_dc, 0, 0, SRCCOPY); // backdc에서 frontdc로 그림을 가져오는 작업(마지막 작업)

}


void Renderer_destroy() {

}

void draw_image(int image_handle) {
	BitBlt(back_dc, imageArray[image_handle]->Xposition, imageArray[image_handle]->Yposition, imageArray[image_handle]->width,
		imageArray[image_handle]->height,
		imageArray[image_handle]->img,
		0, 0, SRCCOPY);
}

void render_title() {
	draw_image(1);
	draw_image(0);
}
void render_ingame() {
	draw_image(Background);
	draw_image(User);
	if (destroy_enemy) {
		draw_image(Enemy2);
	}
	if (draw_boss) {
		draw_image(Boss);
	}
}
