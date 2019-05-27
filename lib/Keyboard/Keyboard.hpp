#include <iostream>
#include <string>
#include <allegro5/allegro.h>


class Keyboard{
private:
	ALLEGRO_KEYBOARD_STATE * __keyst;

public:
	enum class Keys : int {
		A = ALLEGRO_KEY_A,
		B = ALLEGRO_KEY_B,
		C = ALLEGRO_KEY_C,
		D = ALLEGRO_KEY_D,
		E = ALLEGRO_KEY_E,
		F = ALLEGRO_KEY_F,
		G = ALLEGRO_KEY_G,
		H = ALLEGRO_KEY_H,
		I = ALLEGRO_KEY_I,
		J = ALLEGRO_KEY_J,
		K = ALLEGRO_KEY_K,
		L = ALLEGRO_KEY_L,
		M = ALLEGRO_KEY_M,
		N = ALLEGRO_KEY_N,
		O = ALLEGRO_KEY_O,
		P = ALLEGRO_KEY_P,
		Q = ALLEGRO_KEY_Q,
		R = ALLEGRO_KEY_R,
		S = ALLEGRO_KEY_S,
		T = ALLEGRO_KEY_T,
		U = ALLEGRO_KEY_U,
		V = ALLEGRO_KEY_V,
		W = ALLEGRO_KEY_W,
		X = ALLEGRO_KEY_X,
		Y = ALLEGRO_KEY_Y,
		Z = ALLEGRO_KEY_Z,
		N0 = ALLEGRO_KEY_0,
		N1 = ALLEGRO_KEY_1,
		N2 = ALLEGRO_KEY_2,
		N3 = ALLEGRO_KEY_3,
		N4 = ALLEGRO_KEY_4,
		N5 = ALLEGRO_KEY_5,
		N6 = ALLEGRO_KEY_6,
		N7 = ALLEGRO_KEY_7,
		N8 = ALLEGRO_KEY_8,
		N9 = ALLEGRO_KEY_9,
		F1 = ALLEGRO_KEY_F1,
		F2 = ALLEGRO_KEY_F2,
		F3 = ALLEGRO_KEY_F3,
		F4 = ALLEGRO_KEY_F4,
		F5 = ALLEGRO_KEY_F5,
		F6 = ALLEGRO_KEY_F6,
		F7 = ALLEGRO_KEY_F7,
		F8 = ALLEGRO_KEY_F8,
		F9 = ALLEGRO_KEY_F9,
		F10 = ALLEGRO_KEY_F10,
		F11 = ALLEGRO_KEY_F11,
		Pad_0 = ALLEGRO_KEY_PAD_0,
		Pad_1 = ALLEGRO_KEY_PAD_1,
		Pad_2 = ALLEGRO_KEY_PAD_2,
		Pad_3 = ALLEGRO_KEY_PAD_3,
		Pad_4 = ALLEGRO_KEY_PAD_4,
		Pad_5 = ALLEGRO_KEY_PAD_5,
		Pad_6 = ALLEGRO_KEY_PAD_6,
		Pad_7 = ALLEGRO_KEY_PAD_7,
		Pad_8 = ALLEGRO_KEY_PAD_8,
		Pad_9 = ALLEGRO_KEY_PAD_9,
		Escape = ALLEGRO_KEY_ESCAPE,
		Tilde = ALLEGRO_KEY_TILDE,
		Minus = ALLEGRO_KEY_MINUS,
		Equals = ALLEGRO_KEY_EQUALS,
		Backspace = ALLEGRO_KEY_BACKSPACE,
		Tab = ALLEGRO_KEY_TAB,
		Openbrace = ALLEGRO_KEY_OPENBRACE,
		Closebrace = ALLEGRO_KEY_CLOSEBRACE,
		Enter = ALLEGRO_KEY_ENTER,
		Semicolon = ALLEGRO_KEY_SEMICOLON,
		Quote = ALLEGRO_KEY_QUOTE,
		Backslash = ALLEGRO_KEY_BACKSLASH,
		Backslash2 = ALLEGRO_KEY_BACKSLASH2,
		Comma = ALLEGRO_KEY_COMMA,
		Fullstop = ALLEGRO_KEY_FULLSTOP,
		Slash = ALLEGRO_KEY_SLASH,
		Space = ALLEGRO_KEY_SPACE,
		Insert = ALLEGRO_KEY_INSERT,
		Delete = ALLEGRO_KEY_DELETE,
		
	
	};
	
	enum class Flags: int {
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

	Keyboard(void){
		if(!this->installed()){
			if(!al_install_keyboard()) std::cerr << "Error on installing the keyboard" << std::endl;
		}
	}
	
	~Keyboard(void){
		al_uninstall_keyboard();
	}
	
	bool installed(void){
		return al_is_keyboard_installed();
	}

};

