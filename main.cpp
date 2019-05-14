#include<bits/stdc++.h>
#include<allegro5/allegro.h>
using namespace std;

class Display{
private:
	ALLEGRO_DISPLAY * __disp;
	string __title;
	int __height,__width;
public:
	Display(int w,int h){
		__disp = al_create_display(w,h);
		if(__disp == nullptr) cerr << "error in create display" << endl;
		
		al_set_window_title(__disp,"AllegroDS");
		
		__title = "AllegroDS";
		__width = w;
		__height = h;
	}
	
	Display(int w,int h,const string name){
		__disp = al_create_display(w,h);
		if(__disp == nullptr) cerr << "error in create display" << endl;
		
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
	
	void title(const string name){
		al_set_window_title(__disp,name.c_str());
		__title = name;
	}

	string title(void){
		return __title;
	}
	
	void height(int h){
		__height = h;
		if(!al_resize_display(__disp,__width,__height))
			cerr << "error in resize height" << endl;
	}
	
	int height(){
		return __height;
	}
	
	void width(int w){
		__width = w;
		if(!al_resize_display(__disp,__width,__height))
			cerr << "error in resize width" << endl;
	}
	
	int width(){
		return __width;
	}
};


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	al_init();
	Display disp(480,400,"meu teste");
	
	disp.show();
	
	al_rest(1.0);
	
	disp.title("novo nome");
	disp.width(600);
	disp.show();
	
	al_rest(1.0);
	
	cout << disp.title() << endl;

	return 0;
}
