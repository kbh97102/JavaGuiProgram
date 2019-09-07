#include "screen.h"


void screen_init(void){
	window = GetConsoleWindow();
	front_dc = GetDC(window); //윈도우를 빌려옴
	back_dc = CreateCompatibleDC(front_dc); //front_dc를 복사한다.
	back_buffer = CreateCompatibleBitmap(front_dc,scr_width,scr_height); // back_dc에 도화지를 넣는 함수
	MoveWindow(window,0,0,scr_width,scr_height,1);
}
void screen_destroy(void) {
	DeleteObject(back_buffer);
	DeleteDC(back_dc);
	ReleaseDC(window, front_dc);
}




//더블버퍼링. 하나는 받아옴 front_Dc 하나는 만듬 back