#include <knightos/display.h>
#include <knightos/system.h>
#include <knightos/keys.h>
#include <corelib.h>

SCREEN *screen; //declare this at the top of the function because C89

void main_menu() {
	while(1) {
		unsigned char _;

		unsigned char key;
		unsigned char message;
		flush_keys();
		screen_clear(screen);
		draw_string(screen, 0, 0, "Hello! This is a demo \nshowing how to use the \ncorelib library in C.");
		draw_string(screen, 0, 21, "		1: showPrompt");
		draw_string(screen, 0, 27, "		2: drawWindow");
		draw_string(screen, 0, 33, "		3: showMessage");
		draw_string(screen, 0, 39, "		4: drawScrollbar");
		draw_string(screen, 0, 45, "		5: drawTabs");
		draw_string(screen, 0, 51, "		6: showMenu");
		draw_string(screen, 0, 57, "		7: showError");

		screen_draw(screen);
		key = app_get_key(&_);
		switch(key) {
			case KEY_ENTER:
				main_menu();
			case KEY_MODE:
				break;
			case KEY_1:
				message = prompt_string(screen, "Message", 7, "Enter string");
				message = 0;
				break;
			case KEY_2:
				screen_clear(screen);
				draw_window(screen, "title", 0);
				screen_draw(screen);
				break;
			case KEY_3:
				screen_clear(screen);
				show_message(screen, "Some options below", "\x02Option 1\x00Option 2\x00", 0);
				screen_draw(screen);
				break;
			case KEY_4:
				screen_clear(screen);
				draw_window(screen, "title", 0);
				draw_string(screen, 38, 40, "Look there -->");
				draw_scrollbar(screen, 30, 15);
				screen_draw(screen);
				break;
			case KEY_5:
				screen_clear(screen);
				draw_window(screen, "title", 0);
				draw_tabs(screen, "\x04Info\x00 Tasks\x00 RAM\x00 Flash\x00", 0);
				screen_draw(screen);
				break;
			case KEY_6:
				screen_clear(screen);
				draw_window(screen, "title", 0x02);
				show_menu(screen, "\x03Info\x00Tasks\x00RAM\x00", 40);
				screen_draw(screen);
				break;
			case KEY_7:
				screen_clear(screen);
				show_error(screen, ERR_TOO_MANY_THREADS);
				screen_draw(screen);
				break;
			}

		ksleep(5);
	}
}

void main() {
	load_library("/lib/core");
	get_lcd_lock();
	get_keypad_lock();
	screen = screen_allocate();
	flush_keys();
	main_menu();
}

