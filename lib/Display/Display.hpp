#include <iostream>
#include <string>
#include <utility>
#include <allegro5/allegro.h>

class Display{
private:
	ALLEGRO_DISPLAY * __disp;
	std::string __title,__cliptxt;
	int __height,__width,__x,__y;
	int __maxw,__maxh,__minw,__minh;
	bool __constraint_mode;
	enum class Flags : int {
		Windowed = ALLEGRO_WINDOWED,
		Fullscreen_window = ALLEGRO_FULLSCREEN_WINDOW,
		Fullscreen = ALLEGRO_FULLSCREEN,
		Resizable = ALLEGRO_RESIZABLE,
		Maximized = ALLEGRO_MAXIMIZED,
		Opengl = ALLEGRO_OPENGL,
		Opengl_3_0 = ALLEGRO_OPENGL_3_0,
		Opengl_forward_compatible = ALLEGRO_OPENGL_FORWARD_COMPATIBLE,
		#ifdef _WIN64
		Direct3d = ALLEGRO_DIRECT3D,
		Gtk_toplevel = ALLEGRO_GTK_TOPLEVEL,
		#endif
		Pipeline = ALLEGRO_PROGRAMMABLE_PIPELINE,
		Frameless = ALLEGRO_FRAMELESS,
		Noframe = ALLEGRO_NOFRAME,
		Generate_expose_events = ALLEGRO_GENERATE_EXPOSE_EVENTS
	};
	
	static Display::Flags __fl;
public:
	Display(int w,int h){
		__disp = al_create_display(w,h);
		if(__disp == nullptr) std::cerr << "error in create display" << std::endl;
		
		al_set_window_title(__disp,"AllegroDS");
		al_get_window_position(__disp,&__x,&__y);
		
		__title = "AllegroDS";
		__width = w;
		__height = h;
		__maxw = INT_MAX;
		__maxh = INT_MAX;
		__minw = 0;
		__minh = 0;
		__constraint_mode = false;
		__cliptxt = "";
		__fl = static_cast<Display::Flags>(al_get_new_display_flags()); 
	}
	
	Display(int w,int h, Display::Flags f){
		al_set_new_display_flags(static_cast<int>(f));
		
		__disp = al_create_display(w,h);
		if(__disp == nullptr) std::cerr << "error in create display" << std::endl;
		
		al_set_window_title(__disp,"AllegroDS");
		al_get_window_position(__disp,&__x,&__y);
		
		__title = "AllegroDS";
		__width = w;
		__height = h;
		__maxw = INT_MAX;
		__maxh = INT_MAX;
		__minw = 0;
		__minh = 0;
		__constraint_mode = false;
		__cliptxt = "";
		__fl = static_cast<Display::Flags>(al_get_new_display_flags());
	}
	
	Display(int w,int h,const std::string name){
		__disp = al_create_display(w,h);
		if(__disp == nullptr) std::cerr << "error in create display" << std::endl;
		
		al_set_window_title(__disp,name.c_str());
		al_get_window_position(__disp,&__x,&__y);
		
		__title = name;
		__width = w;
		__height = h;
		__maxw = INT_MAX;
		__maxh = INT_MAX;
		__minw = 0;
		__minh = 0;
		__constraint_mode = false;
		__cliptxt = "";
		__fl = static_cast<Display::Flags>(al_get_new_display_flags());
	}
	
	Display(int w,int h,const std::string name,Display::Flags f){
		al_set_new_display_flags(static_cast<int>(f));
	
		__disp = al_create_display(w,h);
		if(__disp == nullptr) std::cerr << "error in create display" << std::endl;
		
		al_set_window_title(__disp,name.c_str());
		al_get_window_position(__disp,&__x,&__y);
		
		__title = name;
		__width = w;
		__height = h;
		__maxw = INT_MAX;
		__maxh = INT_MAX;
		__minw = 0;
		__minh = 0;
		__constraint_mode = false;
		__cliptxt = "";
		__fl = static_cast<Display::Flags>(al_get_new_display_flags());
	}

	~Display(){
		al_destroy_display(__disp);
		
		if(has_text()) al_free(al_get_clipboard_text(__disp));
	}	

	void show(){
		al_flip_display();
	}
	
	std::string title(void){
		return __title;
	}
	
	void title(const std::string name){
		al_set_window_title(__disp,name.c_str());
		__title = name;
	}
	
	int width(){
		return __width;
	}
	
	int height(){
		return __height;
	}
	
	void width(int w){
		__width = w;
		if(!al_resize_display(__disp,__width,__height))
			std::cerr << "error in resize width" << std::endl;
	}
	
	void height(int h){
		__height = h;
		if(!al_resize_display(__disp,__width,__height))
			std::cerr << "error in resize height" << std::endl;
	}
	
	bool resize(int w,int h){
		__width = w;
		__height = h;
		if(al_resize_display(__disp,__width,__height)){
			return true;
		}else{
			std::cerr << "error in resize display" << std::endl;
			return false;
		}
	}
	
	void update_region(int x,int y,int w,int h){
		al_update_display_region(x,y,w,h);
	}
	
	bool sync(void){
		return al_wait_for_vsync();
	}
	
	int x(void){
		return __x;
	}
	
	int y(void){
		return __y;
	}
	
	void x(int dx){
		__x = dx;
		al_set_window_position(__disp,__x,__y);
	}
	
	void y(int dy){
		__y = dy;
		al_set_window_position(__disp,__x,__y);
	}
	
	std::pair<int,int> position(void){
		return std::make_pair(__x,__y);
	}
	
	void position(int dx,int dy){
		__x = dx;
		__y = dy;
		
		al_set_window_position(__disp,__x,__y);
	}
	
	std::pair<std::pair<int,int>,std::pair<int,int>> constrains(void){
		return std::make_pair(std::make_pair(__minw,__maxw),std::make_pair(__minh,__maxh));
	}
	
	void constraints(int minw,int minh,int maxw,int maxh){
		__maxw = maxw;
		__maxh = maxh;
		__minw = minw;
		__minh = minh;
		__constraint_mode = true;
		
		if(!al_set_window_constraints(__disp,__minw,__minh,__maxw,__maxh))
			std::cerr << "error in define the display constrain" << std::endl;
			
		al_apply_window_constraints(__disp,__constraint_mode);
	}
	
	void disable_constraints(void){
		__constraint_mode = false;
		al_apply_window_constraints(__disp,__constraint_mode);
	}
	
	std::string clipboard(void){
		return __cliptxt;
	}
	
	void clipboard(std::string s){
		__cliptxt = s;
		if(!al_set_clipboard_text(__disp,__cliptxt.c_str()))
			std::cerr << "error on setting clipboard text" << std::endl;
	}
	
	bool has_text(void){
		return al_clipboard_has_text(__disp);
	}
};

