
#include "keyboard.h"
#include "render.h"
#include "updater.h"
#include "timer.h"
void main() {
	

	screen_init();
	update_init();
	gameobject_init();
	Renderer_initialize();
	gameplay_init();

	/*for (int i = 0; i < 4; i++) {
		image_pos_chage(i, 150);
	}*/
	
	isgame_exit = 0;  //1이면 종료 0이면 계속
	while (!isgame_exit) {
		long update_time = get_delta_time(LastUpdateTime);

		if (update_time >= 16) { //16 = 1000ms / 60프레임
			set_time_stamp(LastUpdateTime);
			key_pollinput();
			update(update_time);
		}

		long ren_time = get_delta_time(LastRenderTime);

		if (ren_time >= 16) {
			set_time_stamp(LastRenderTime);
			Renderer_Render();
		}
		
	}
	gameobject_destroy();
	screen_destroy();
	
}