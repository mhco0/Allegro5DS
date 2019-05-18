#include<iostream>
#include<string>
#include<utility>
#include<allegro5/allegro.h>

class Display{
private:
	ALLEGRO_DISPLAY * __disp;
	std::string __title,__cliptxt;
	int __height,__width,__x,__y;
	int __maxw,__maxh,__minw,__minh;
	bool __constraint_mode;
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
	}

	~Display(){
		al_destroy_display(__disp);
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
	
	void clipboard(std::string s){
		__cliptxt = s;
		if(!al_set_clipboard_text(__disp,__cliptxt.c_str()))
			std::cerr << "error on setting clipboard text" << std::endl;
	}
	
};

