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
		draw_string(screen, 0, 0, "Hello! This is a demo \nshowing how to use the \ncorelib library in C. \n Commands: \n");
		draw_string(screen, 0, 25, "		1: showPrompt");
		draw_string(screen, 0, 31, "		2: drawWindow");
		draw_string(screen, 0, 37, "		3: showMessage");
		draw_string(screen, 0, 43, "		4: drawScrollbar");

		screen_draw(screen);
		key = app_get_key(&_);
		switch(key) {
			case KEY_ENTER:
				main_menu();
			case KEY_MODE:
				break;
			case KEY_1:
				message = prompt_string(screen, "Preset msg", 12, "enter string");
			case KEY_2:
				screen_clear(screen);
				draw_window(screen, "title", 0);
				screen_draw(screen);
				break;
			case KEY_3:
				show_message(screen, "message", "   list", 0);
				break;
			case KEY_4:
				screen_clear(screen);
				draw_window(screen, "title", 0);
				draw_string(screen, 38, 40, "Look there -->");
				draw_scrollbar(screen, 30, 15);
				screen_draw(screen);
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
