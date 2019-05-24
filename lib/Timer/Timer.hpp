#include<iostream>
#include<allegro5/allegro.h>
#define microsec_to_sec(x) ALLEGRO_USECS_TO_SECS(x)
#define milisec_to_sec(x) ALLEGRO_MSECS_TO_SECS(x)
#define beats_to_sec(x) ALLEGRO_BPS_TO_SECS(x)

class Timer{
private:
	ALLEGRO_TIMER * __tim;
public:
	
	Timer(double s){
		if(s < 0.0){
			s = -s;
			std::cerr << "The timer seconds must be positives" << std::endl;
		}
		
		__tim = al_create_timer(s);
		if(!__tim) std::cerr << "Error in create timer" << std::endl;
	}
	
	~Timer(){
		al_destroy_timer(__tim);
	}
	
	void start(void){
		al_start_timer(__tim);
	}
	
	void resume(void){
		al_resume_timer(__tim);
	}

	void stop(void){
		al_stop_timer(__tim);
	}
	
	bool is_started(void){
		return al_get_timer_started(__tim);
	}
	
	int64_t count(void){
		return al_get_timer_count(__tim);
	}
};




