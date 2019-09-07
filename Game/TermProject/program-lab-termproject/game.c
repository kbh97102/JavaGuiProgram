#include "game.h"


void update_init() {
	srand(time(NULL));
	xoffset = 0;
	yoffset = 0;
	user_bullet_yoffset = -0.5;
	boss_bullet_yoffset = 0.5;
	boss_xoffset = 0.5;
	current_invincTime = 0;
	scr_shape = "□";
}
void object_init() {
	is_running = 1;
	int i;
	for (i = 0; i < Max_bullet; i++) {
		boss_bullet[i].is_exist = FALSE;
		user_bullet[i].is_exist = FALSE;
	}
	item_dmgup.is_exist = FALSE;
	item_dmgup.xpos = 10;
	item_dmgup.ypos = 45;
	user1.life = Init_user_life;
	user1.dmg = Init_user_dmg;
	user1.xpos = 29;
	user1.ypos = 40;
	user1.invinc_time = 0;

	boss1.life = Init_boss_life;
	boss1.dmg = Init_boss_dmg;
	boss1.xpos = 15;
	boss1.ypos = 2;
	boss1.fire_term = 10;
	boss1.current_term = 3;
}
void set_xy() {
	xy_gather[User].minX = user1.xpos-2;
	xy_gather[User].minY = user1.ypos;
	xy_gather[User].maxX = user1.xpos + 2;
	xy_gather[User].maxY = user1.ypos + 2;

	xy_gather[Boss].minX = boss1.xpos;
	xy_gather[Boss].minY = boss1.ypos;
	xy_gather[Boss].maxX = boss1.xpos + 22;
	xy_gather[Boss].maxY = boss1.ypos + 6;

	xy_gather[Item_dmg].minX = item_dmgup.xpos;
	xy_gather[Item_dmg].maxX = item_dmgup.xpos+4;
	xy_gather[Item_dmg].minY = item_dmgup.ypos;
	xy_gather[Item_dmg].maxY = item_dmgup.ypos+3;
	for (int i = 0; i < Max_bullet; i++) {
		if (user_bullet[i].is_exist == TRUE) {
			xy_gather[User_bullet + i].minX = user_bullet[i].bullet_xpos;
			xy_gather[User_bullet + i].minY = user_bullet[i].bullet_ypos - 2;
			xy_gather[User_bullet + i].maxX = user_bullet[i].bullet_xpos + 2;
			xy_gather[User_bullet + i].maxY = user_bullet[i].bullet_ypos - 1;
		}
	}
	for (int i = 0; i < Max_bullet; i++) {
		if (boss_bullet[i].is_exist == TRUE) {
			xy_gather[Boss_bullet + i].minX = boss_bullet[i].bullet_xpos;
			xy_gather[Boss_bullet + i].minY = boss_bullet[i].bullet_ypos;
			xy_gather[Boss_bullet + i].maxX = boss_bullet[i].bullet_xpos + 2;
			xy_gather[Boss_bullet + i].maxY = boss_bullet[i].bullet_ypos - 1;
		}
	}
}
void moving() {
	int i;
	if (get_keystat(w)) {
		yoffset = -User_Speed+0.3;
	}
	if (get_keystat(s)) {
		yoffset = User_Speed - 0.3;
	}
	if (get_keystat(a)) {
		xoffset = -User_Speed;
	}
	if (get_keystat(d)) {
		xoffset = User_Speed;
	}
	if (xoffset != 0 && yoffset != 0) {
		xoffset /= Sqrt2;
		yoffset /= Sqrt2;
	}
	user1.xpos += xoffset;
	user1.ypos += yoffset;
	if (get_keystat(j) == press) {
		for (i = 0; i < Max_bullet &&user_bullet[i].is_exist == TRUE; i++) { ; }
		if (i != Max_bullet) {
			user_bullet[i].bullet_xpos = user1.xpos;
			user_bullet[i].bullet_ypos = user1.ypos;
			user_bullet[i].is_exist = TRUE;
		}
	}

	//화면밖으로 안가게 제어
	if (xy_gather[User].minX + xoffset <= Scr_x1 + 2) {
		user1.xpos -= xoffset;
	}
	if (xy_gather[User].maxX + xoffset >= Scr_width - 2) {
		user1.xpos -= xoffset;
	}
	if (xy_gather[User].minY + yoffset <= Scr_y1 + 1) {
		user1.ypos -= yoffset;
	}
	if (xy_gather[User].maxY + yoffset >= Scr_height - 1) {
		user1.ypos -= yoffset;
	}
	
	//노래관련
	if (GetAsyncKeyState(VK_P)& 0x0001) {
		play_backgrondMusic();
	}
	if (GetAsyncKeyState(VK_O) & 0x0001){
		pause_backgrondMusic();
	}
}
void item_colide() {
	if (is_colide(User, Item_dmg)) {
		user1.dmg += 5;
		erase_dmgup();
		item_dmgup.is_exist = FALSE;
	}
}
void user_bullet_colide() {
	int i;
	for(i=0;i<Max_bullet;i++){
		if (user_bullet[i].is_exist == TRUE) {
			erase_user_bullet(i);
			if (is_colide(User_bullet+i, Boss)) {
				boss1.life -= user1.dmg;
				user_bullet[i].is_exist = FALSE;
				erase_user_bullet(i);
			}
			else if (user_bullet[i].bullet_ypos +user_bullet_yoffset <= Scr_y1 +1) {
				user_bullet[i].is_exist = FALSE;
				erase_user_bullet(i);
			}
			else {
				user_bullet[i].bullet_ypos += user_bullet_yoffset;
				draw_user_bullet(i);
			}
		}
	}
}
void boss_bullet_colide() {
	int i;
	for (i = 0; i < Max_bullet; i++) {
	
		if (boss_bullet[i].is_exist == FALSE && boss1.current_term <=0) {
			boss_bullet[i].bullet_xpos = boss1.xpos + 10;
			boss_bullet[i].bullet_ypos = boss1.ypos + 7;
			gotoxy(boss_bullet[i].bullet_xpos, boss_bullet[i].bullet_ypos);
			printf("▽");
			boss_bullet[i].is_exist = TRUE;
			boss1.current_term += boss1.fire_term;
		}
		if (boss_bullet[i].is_exist == TRUE) {
			erase_boss_bullet(i);
			if (is_colide(Boss_bullet+i, User) && user1.invinc_time > 0) {
				boss_bullet[i].is_exist = FALSE;
				erase_boss_bullet(i);
			}
			if (is_colide(Item_dmg, Boss_bullet + i)) {
				erase_dmgup();
				item_dmgup.is_exist = FALSE;
			}
			else if(is_colide(Boss_bullet+i, User) && user1.invinc_time == 0) {
				current_invincTime = clock();
				boss_bullet[i].is_exist = FALSE;
				erase_boss_bullet(i);
				user1.invinc_time = 100;
				user1.life -= boss1.dmg;
			}
			else if (boss_bullet[i].bullet_ypos + boss_bullet_yoffset == Scr_height - 1) {
				boss_bullet[i].is_exist = FALSE;
				erase_boss_bullet(i);
			}
			else {
				erase_boss_bullet(i);
				boss_bullet[i].bullet_ypos += boss_bullet_yoffset;
				draw_boss_bullet(i);
			}
		}
	}
}
void erase_boss_bullet(int index) {
	gotoxy(boss_bullet[index].bullet_xpos, boss_bullet[index].bullet_ypos);
	printf("  ");
}
void draw_boss_bullet(int index) {
	erase_boss_bullet(index);
	textcolor(MAGENTA2, BLACK);
	gotoxy(boss_bullet[index].bullet_xpos, boss_bullet[index].bullet_ypos);
	printf("★");
	textcolor(WHITE, BLACK);
}
void erase_user_bullet(int index) {
	gotoxy(user_bullet[index].bullet_xpos, user_bullet[index].bullet_ypos);
	printf("  ");
	gotoxy(user_bullet[index].bullet_xpos, user_bullet[index].bullet_ypos + 1);
	printf("  ");
}
void draw_user_bullet(int index) {
	erase_user_bullet(index);
	gotoxy(user_bullet[index].bullet_xpos, user_bullet[index].bullet_ypos);
	printf("▲");
	gotoxy(user_bullet[index].bullet_xpos, user_bullet[index].bullet_ypos + 1);
	printf("○");
}

BOOL is_colide(int index1, int index2) {
	BOOL colideX = xy_gather[index1].maxX >= xy_gather[index2].minX  && xy_gather[index2].maxX >= xy_gather[index1].minX;
	BOOL colideY = xy_gather[index1].maxY >= xy_gather[index2].minY && xy_gather[index2].maxY >= xy_gather[index1].minY;
	return colideX && colideY;
}
void erase_user() {
	gotoxy(user1.xpos - xoffset, user1.ypos - yoffset); printf(" ");
	gotoxy((user1.xpos - xoffset) - 2, user1.ypos - yoffset + 1); printf("      ");
	gotoxy((user1.xpos - xoffset) - 2, user1.ypos - yoffset + 2); printf("      ");
}
void draw_user() {
	erase_user();
	gotoxy(user1.xpos, user1.ypos); printf("△");
	gotoxy(user1.xpos - 2.0, user1.ypos + 1.0); printf("△■△");
	gotoxy(user1.xpos - 2.0, user1.ypos + 2.0); printf("▼  ▼");
}
void erase_boss() {
	gotoxy(boss1.xpos, boss1.ypos);   printf("                      ");
	gotoxy(boss1.xpos, boss1.ypos+1); printf("                      ");
	gotoxy(boss1.xpos, boss1.ypos+2); printf("                      ");
	gotoxy(boss1.xpos, boss1.ypos+3); printf("                      ");
	gotoxy(boss1.xpos, boss1.ypos+4); printf("                      ");
	gotoxy(boss1.xpos, boss1.ypos+5); printf("                      ");
	gotoxy(boss1.xpos, boss1.ypos+6); printf("                      ");
}
void draw_boss() {
	erase_boss();
	move_pattern_boss();
	textcolor(RED1, BLACK);
	gotoxy(boss1.xpos, boss1.ypos);   printf("■■■■■■■■■■■");
	gotoxy(boss1.xpos, boss1.ypos+1); printf("■■■■■■■■■■■");
	gotoxy(boss1.xpos, boss1.ypos+2); printf("       ■■■■       ");
	gotoxy(boss1.xpos, boss1.ypos+3); printf("       ■■■■       ");
	gotoxy(boss1.xpos, boss1.ypos+4); printf("   ■■■■■■■■   ");
	gotoxy(boss1.xpos, boss1.ypos+5); printf("   ■■■■■■■■   ");
	gotoxy(boss1.xpos, boss1.ypos+6); printf("         ■■         ");
	textcolor(WHITE, BLACK);
}

void move_pattern_boss() {
	boss1.xpos += boss_xoffset;
	if (xy_gather[Boss].minX + boss_xoffset <= Scr_x1 + 4) {
		boss_xoffset *= -1;
	}
	if (xy_gather[Boss].maxX + boss_xoffset >= Scr_width - 2) {
		boss_xoffset *= -1;
	}
}
void erase_dmgup() {
	gotoxy(item_dmgup.xpos, item_dmgup.ypos); printf("    ");
	gotoxy(item_dmgup.xpos, item_dmgup.ypos + 1); printf("    ");
	gotoxy(item_dmgup.xpos, item_dmgup.ypos + 2); printf("    ");
}
void draw_dmgup() {
	if (item_dmgup.is_exist == FALSE) {
		erase_dmgup();
		item_dmgup.xpos = (rand() % (Scr_width - 10)) + 4;
		item_dmgup.ypos = (rand() % 30) + 10;
		gotoxy(item_dmgup.xpos, item_dmgup.ypos); printf("●");
		gotoxy(item_dmgup.xpos, item_dmgup.ypos + 1); printf("●●");
		gotoxy(item_dmgup.xpos, item_dmgup.ypos + 2); printf("●●");
		item_dmgup.is_exist = TRUE;
	}
}
void check_game() {
	now = clock();
	change_color = clock();
	gotoxy(1, 51); printf("Boss HP : %d", boss1.life); gotoxy(18, 51); printf("User HP : %d", user1.life);
	if (boss1.current_term > 0) {
		--boss1.current_term;
	}
	if (now - current_invincTime >= 1) {
		if (user1.invinc_time > 0) {
			--user1.invinc_time;
		}
	}
	if (user1.life <= 0) {
		system("cls");
		is_running = 0;
		start_deltaTime = clock() - startTime;
		stop_backgrondMusic();
		play_effect_gameOver();
		cls(BLACK, RED1);
		gotoxy(18, 20); printf(" ■    ■  ■■■   ■  ■");
		gotoxy(18, 21); printf("  ■  ■   ■  ■   ■  ■");
		gotoxy(18, 22); printf("    ■     ■  ■   ■  ■");
		gotoxy(18, 23); printf("    ■     ■■■   ■■■");
		gotoxy(18, 24);	printf("                         ");
		gotoxy(18, 25);	printf(" ■■■    ■  ■■■  ■■■");
		gotoxy(18, 26);	printf(" ■    ■  ■  ■      ■    ■");
		gotoxy(18, 27);	printf(" ■    ■  ■  ■■■  ■    ■");
		gotoxy(18, 28);	printf(" ■    ■  ■  ■      ■    ■");
		gotoxy(18, 29);	printf(" ■■■    ■  ■■■  ■■■  ");
		textcolor(RED1, BLACK);
		gotoxy(20, 45);
		printf("Press X to Start");
	
		while (!(GetAsyncKeyState(VK_X) & 0x8000));
	}
	if (boss1.life <= 0) {
		system("cls");
		is_running = 0;
		start_deltaTime = clock() - startTime;

		stop_backgrondMusic();
		play_effect_gameWin();
		
		cls(CYAN1, WHITE);
		gotoxy(18, 10); printf(" ■    ■  ■■■   ■  ■");
		gotoxy(18, 11); printf("  ■  ■   ■  ■   ■  ■");
		gotoxy(18, 12); printf("    ■     ■  ■   ■  ■");
		gotoxy(18, 13); printf("    ■     ■■■   ■■■");
		gotoxy(18, 14);	printf("                         ");
		gotoxy(18, 15);	printf(" ■     ■     ■  ■  ■■■");
		gotoxy(18, 16);	printf("  ■    ■    ■   ■  ■  ■");
		gotoxy(18, 17);	printf("   ■  ■■  ■    ■  ■  ■");
		gotoxy(18, 18);	printf("     ■    ■      ■  ■  ■");
	
		
		if (start_deltaTime >= 60000) {
			gotoxy(17, 22); printf(" ■■■     ■    ■■■  ■  ■");
			gotoxy(17, 23); printf(" ■  ■   ■  ■  ■  ■  ■■  ");
			gotoxy(17, 24); printf(" ■■     ■■■  ■  ■  ■  ■");
			gotoxy(17, 25); printf(" ■  ■   ■  ■  ■  ■  ■  ■");
			gotoxy(17, 26);	printf("");
			gotoxy(17, 27);	printf("             ■■■   ");
			gotoxy(17, 28);	printf("             ■    ■ ");
			gotoxy(17, 29);	printf("             ■    ■ ");
			gotoxy(17, 30);	printf("             ■■■   ");
		}
		if (start_deltaTime >= 50000 && start_deltaTime < 60000) {
			gotoxy(17, 22); printf(" ■■■     ■    ■■■  ■  ■");
			gotoxy(17, 23); printf(" ■  ■   ■  ■  ■  ■  ■■  ");
			gotoxy(17, 24); printf(" ■■     ■■■  ■  ■  ■  ■");
			gotoxy(17, 25); printf(" ■  ■   ■  ■  ■  ■  ■  ■");
			gotoxy(17, 26);	printf("");
			gotoxy(17, 27);	printf("             ■■■■   ");
			gotoxy(17, 28);	printf("             ■     ");
			gotoxy(17, 29);	printf("             ■     ");
			gotoxy(17, 30);	printf("             ■■■■   ");
		}
		if (start_deltaTime >= 40000 && start_deltaTime < 50000) {
			gotoxy(17, 22); printf(" ■■■     ■    ■■■  ■  ■");
			gotoxy(17, 23); printf(" ■  ■   ■  ■  ■  ■  ■■  ");
			gotoxy(17, 24); printf(" ■■     ■■■  ■  ■  ■  ■");
			gotoxy(17, 25); printf(" ■  ■   ■  ■  ■  ■  ■  ■");
			gotoxy(17, 26);	printf("");
			gotoxy(17, 27);	printf("             ■■■   ");
			gotoxy(17, 28);	printf("             ■    ■ ");
			gotoxy(17, 29);	printf("             ■■■ ");
			gotoxy(17, 30);	printf("             ■    ■ ");
			gotoxy(17, 31);	printf("             ■■■   ");
		}
		if (start_deltaTime >= 30000 && start_deltaTime < 40000) {
			gotoxy(17, 22); printf(" ■■■     ■    ■■■  ■  ■");
			gotoxy(17, 23); printf(" ■  ■   ■  ■  ■  ■  ■■  ");
			gotoxy(17, 24); printf(" ■■     ■■■  ■  ■  ■  ■");
			gotoxy(17, 25); printf(" ■  ■   ■  ■  ■  ■  ■  ■");
			gotoxy(17, 26);	printf("");
			gotoxy(17, 27);	printf("               ■   ");
			gotoxy(17, 28);	printf("             ■  ■ ");
			gotoxy(17, 29);	printf("             ■■■ ");
			gotoxy(17, 30);	printf("             ■  ■   ");
		}
		if (start_deltaTime < 30000) {
			gotoxy(17, 22); printf(" ■■■    ■    ■■■  ■  ■");
			gotoxy(17, 23); printf(" ■  ■  ■  ■  ■  ■  ■■  ");
			gotoxy(17, 24); printf(" ■■    ■■■  ■  ■  ■  ■");
			gotoxy(17, 25); printf(" ■  ■  ■  ■  ■  ■  ■  ■");
			gotoxy(17, 26);	printf("");
			gotoxy(17, 27);	printf("               ■■■   ");
			gotoxy(17, 28);	printf("             ■   ");
			gotoxy(17, 29);	printf("             ■■■■ ");
			gotoxy(17, 30);	printf("                   ■   ");
			gotoxy(17, 31);	printf("             ■■■  ");

		}
		gotoxy(18, 40);
		textcolor(WHITE, GREEN1);
		printf("Press X to Move Title");
		while (!(GetAsyncKeyState(VK_X) & 0x8000));
	}
}
void Ingame() {
	object_init();
	play_backgrondMusic();
	system("cls");
	draw_box(0, 0, Scr_width, Scr_height, scr_shape);
	removeCursor();
	startTime = clock();
	while (is_running) {
		uptime = clock() - now;
	
		if (uptime >= 16) {
			now = clock();
			get_keyinput();
			//move_bullet();
			moving();
			set_xy();

			draw_dmgup();

			draw_boss();
			draw_user();

			
			user_bullet_colide();
			boss_bullet_colide();
			item_colide();
			check_game();
		}

	}
}