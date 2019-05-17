#include<iostream>
#include<allegro5/allegro.h>

class Time{
private:
	ALLEGRO_TIMEOUT __timer;	
public:
	Time(void){}
	
	double time(void){
		return al_get_time();
	}
	
	void rest(double s){
		al_rest(s);
	}
	
	void timeout(double s){
		al_init_timeout(&__timer,s);
	}
};
