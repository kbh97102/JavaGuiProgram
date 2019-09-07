#include "title.h"

void testInt(int test) {
	char testQuote[30] = { 0 };
	sprintf(&testQuote, "title TestValue : %d", test);
	system(testQuote);
}

void title() {
	system("mode con:cols=63 lines=55");	//system("color 0");
	removeCursor();
	cls(BLACK, WHITE);
	system("cls");
	update_init();
	load_soundfile();
	is_title_run = TRUE;
	int is_draw_title = 0;
	play_titleSound();
	while (is_title_run){
		if (is_draw_title == 0) {
			draw_box(0, 0, Scr_width, Scr_height, scr_shape);
			gotoxy(22, 10); printf("〓〓〓〓〓〓〓〓〓");
			gotoxy(22, 11); printf("     1.Start	  ");
			gotoxy(22, 12); printf("     2.Exit	      ");
			gotoxy(22, 13); printf("〓〓〓〓〓〓〓〓〓");
			gotoxy(15, 15); printf("Start : Press V  End : Press C");
			gotoxy(10, 35); printf("W : 위 S : 아래 A : 왼쪽 D : 오른쪽 J : 발사");
			is_draw_title = 1;
		}
		if (GetAsyncKeyState(VK_V) & 0x8000) {
			stop_titleSound();
			Ingame();
			system("cls");
			is_draw_title = 0;
			stop_effect_gameOver();
			stop_effect_gameWin();
			cls(BLACK, WHITE);
			play_titleSound();

		}
		if (GetAsyncKeyState(VK_C) & 0x8000) {
			is_title_run = FALSE;
		}
	}

}