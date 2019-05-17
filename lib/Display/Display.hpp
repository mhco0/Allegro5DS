#include<iostream>
#include<string>
#include<allegro5/allegro.h>

class Display{
private:
	ALLEGRO_DISPLAY * __disp;
	std::string __title;
	int __height,__width;
public:
	Display(int w,int h){
		__disp = al_create_display(w,h);
		if(__disp == nullptr) std::cerr << "error in create display" << std::endl;
		
		al_set_window_title(__disp,"AllegroDS");
		
		__title = "AllegroDS";
		__width = w;
		__height = h;
	}
	
	Display(int w,int h,const std::string name){
		__disp = al_create_display(w,h);
		if(__disp == nullptr) std::cerr << "error in create display" << std::endl;
		
		al_set_window_title(__disp,name.c_str());
		
		__title = name;
		__width = w;
		__height = h;
	}

	~Display(){
		al_destroy_display(__disp);
	}	

	void show(){
		al_flip_display();
	}
	
	void title(const std::string name){
		al_set_window_title(__disp,name.c_str());
		__title = name;
	}

	std::string title(void){
		return __title;
	}
	
	void height(int h){
		__height = h;
		if(!al_resize_display(__disp,__width,__height))
			std::cerr << "error in resize height" << std::endl;
	}
	
	int height(){
		return __height;
	}
	
	void width(int w){
		__width = w;
		if(!al_resize_display(__disp,__width,__height))
			std::cerr << "error in resize width" << std::endl;
	}
	
	int width(){
		return __width;
	}
	
	void update_region(int x,int y,int w,int h){
		al_update_display_region(x,y,w,h);
	}
};

