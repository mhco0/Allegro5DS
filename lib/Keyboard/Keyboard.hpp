#include <iostream>
#include <string>
#include <allegro5/allegro.h>


class Keyboard{
private:
	ALLEGRO_KEYBOARD_STATE * __keyst;

public:
	enum Keys : int {
	
	
	};
	
	enum Flags: int {
		Shift = ALLEGRO_KEYMOD_SHIFT,
		Ctrl = ALLEGRO_KEYMOD_CTRL,
		Alt = ALLEGRO_KEYMOD_ALT,
		Lwin = ALLEGRO_KEYMOD_LWIN,
		Rwin = ALLEGRO_KEYMOD_RWIN,
		Menu = ALLEGRO_KEYMOD_MENU,
		Altgr = ALLEGRO_KEYMOD_ALTGR,
		Command = ALLEGRO_KEYMOD_COMMAND,
		Scroll_lock = ALLEGRO_KEYMOD_SCROLLLOCK,
		Num_lock = ALLEGRO_KEYMOD_NUMLOCK,
		Caps_lock = ALLEGRO_KEYMOD_CAPSLOCK,
		Inaltseq = ALLEGRO_KEYMOD_INALTSEQ,
		Accent1 = ALLEGRO_KEYMOD_ACCENT1,
		Accent2 = ALLEGRO_KEYMOD_ACCENT2,
		Accent3 = ALLEGRO_KEYMOD_ACCENT3,
		Accent4 = ALLEGRO_KEYMOD_ACCENT4,
	}



};
