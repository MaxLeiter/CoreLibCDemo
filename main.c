#include <knightos/display.h>
#include <knightos/system.h>
#include <knightos/keys.h>
#include <knightos/filesystem.h>
#include <corelib.h>
#include <stdbool.h>
#include <errno.h>

SCREEN *screen;
void filesystem_status();
/** Filesystem things**/
bool error_one;
bool error_two;
bool error_three;

void main_menu() {
	while(1) {
		unsigned char _;
		unsigned char key;
		unsigned char message;

		flush_keys();
		screen_clear(screen);
		draw_string(screen, 0, 0, "		1: showPrompt");
		draw_string(screen, 0, 6, "		2: drawWindow");
		draw_string(screen, 0, 12, "		3: showMessage");
		draw_string(screen, 0, 18, "		4: drawScrollbar");
		draw_string(screen, 0, 24, "		5: drawTabs");
		draw_string(screen, 0, 30, "		6: showMenu");
		draw_string(screen, 0, 36, "		7: showError");
		draw_string(screen, 0, 42, "		8: filesystem status");

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
				launch_castle();
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
			case KEY_8:
				screen_clear(screen);
				filesystem_status();
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

void filesystem_status() {
	draw_string(screen, 0, 0, "Test dir exist: ");
	draw_string(screen, 0, 12, "Create test dir: ");
	draw_string(screen, 0, 24, "Test dir exist: ");
	draw_string(screen, 0, 36, "Create dir errno: ");

	error_one = directory_exists("/asde");
	error_two = create_directory("/asde");
	error_three = directory_exists("/asde");

	draw_byte(screen, 10, 5, error_one);
	draw_byte(screen, 10, 17, error_two);
	draw_byte(screen, 10, 29, error_three);

	draw_byte(screen, 10, 41, errno);

}