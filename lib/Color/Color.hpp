#include<iostream>
#include<allegro5/allegro.h>

class Color{
private:
	ALLEGRO_COLOR __color;
	unsigned char __r,__g,__b,__a;
	
	ALLEGRO_COLOR get_color(void){
		return __color;
	}
public:
	Color(){
		__color = al_map_rgb(0,0,0);
		__r = 0;
		__g = 0;
		__b = 0;
		__a = 255;
	}
	
	Color(int r,int g,int b, int a = 255){
		__r = static_cast<unsigned char>(r);
		__g = static_cast<unsigned char>(g);
		__b = static_cast<unsigned char>(b);
		__a = static_cast<unsigned char>(a);
		
		__color = al_map_rgba(__r,__g,__b,__a);
	}
	
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255){
		__r = r;
		__g = g;
		__b = b;
		__a = a;
		
		__color = al_map_rgba(__r,__g,__b,__a);
	}
	
	Color(float r,float g,float b,float a = 1.0){
		__color = al_map_rgba_f(r,g,b,a);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b);
		__a = static_cast<unsigned char>(255*a);	 
	}
	
	Color(double r,double g,double b,double a = 1.0){
		__color = al_map_rgba_f((float)r,(float)g,(float)b,(float)a);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b);
		__a = static_cast<unsigned char>(255*a);	 
	}
	
	void rgb(int r,int g,int b){
		__r = static_cast<unsigned char>(r);
		__g = static_cast<unsigned char>(g);
		__b = static_cast<unsigned char>(b);
		
		__color = al_map_rgb(__r,__g,__b);
	}

	void rgb(unsigned char r,unsigned char g,unsigned char b){
		__color = al_map_rgb(r,g,b);
		
		__r = r;
		__g = g;
		__b = b;		
	}
	
	void rgb(float r,float g,float b){
		__color = al_map_rgb_f(r,g,b);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b); 
	}
	
	void rgb(double r,double g,double b){
		__color = al_map_rgb_f((float)r,(float)g,(float)b);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b); 
	}
	
	void rgba(int r,int g,int b, int a){
		__r = static_cast<unsigned char>(r);
		__g = static_cast<unsigned char>(g);
		__b = static_cast<unsigned char>(b);
		__a = static_cast<unsigned char>(a);
		
	
		__color = al_map_rgba(__r,__g,__b,__a);
	}
	
	void rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
		__r = r;
		__g = g;
		__b = b;
		__a = a;
	
		__color = al_map_rgba(__r,__g,__b,__a);
	}
	
	void rgba(float r, float g, float b, float a){
		__color = al_map_rgba(r,g,b,a);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b);
		__a = static_cast<unsigned char>(255*a);
	}
	
	void rgba(double r, double g, double b, double a){
		__color = al_map_rgba((float)r,(float)g,(float)b,(float)a);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b);
		__a = static_cast<unsigned char>(255*a);
	}
	
	void premul_rbga(int r,int g,int b, int a){
		__r = static_cast<unsigned char>(r);
		__g = static_cast<unsigned char>(g);
		__b = static_cast<unsigned char>(b);
		__a = static_cast<unsigned char>(a);
	
		__color = al_premul_rgba(__r,__g,__b,__a);
	}
	
	void premul_rbga(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
		__r = r;
		__g = g;
		__b = b;
		__a = a;
	
		__color = al_premul_rgba(__r,__g,__b,__a);
	}
	
	void premul_rgba(float r, float g, float b, float a){
		__color = al_premul_rgba_f(r,g,b,a);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b);
		__a = static_cast<unsigned char>(255*a);
	}
	
	void premul_rgba(double r, double g, double b, double a){
		__color = al_premul_rgba_f((float)r,(float)g,(float)b,(float)a);
		
		__r = static_cast<unsigned char>(255*r);
		__g = static_cast<unsigned char>(255*g);
		__b = static_cast<unsigned char>(255*b);
		__a = static_cast<unsigned char>(255*a);
	}
	
	unsigned char r(void){
		return __r;
	}
	
	unsigned char g(void){
		return __g;
	}
	
	unsigned char b(void){
		return __b;
	}

	unsigned char a(void){
		return __a;
	}
};
