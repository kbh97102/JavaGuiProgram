#include "screen.h"


void screen_init(void){
	window = GetConsoleWindow();
	front_dc = GetDC(window); //�����츦 ������
	back_dc = CreateCompatibleDC(front_dc); //front_dc�� �����Ѵ�.
	back_buffer = CreateCompatibleBitmap(front_dc,scr_width,scr_height); // back_dc�� ��ȭ���� �ִ� �Լ�
	MoveWindow(window,0,0,scr_width,scr_height,1);
}
void screen_destroy(void) {
	DeleteObject(back_buffer);
	DeleteDC(back_dc);
	ReleaseDC(window, front_dc);
}




//������۸�. �ϳ��� �޾ƿ� front_Dc �ϳ��� ���� back