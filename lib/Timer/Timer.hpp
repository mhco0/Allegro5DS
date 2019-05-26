#include<iostream>
#include<allegro5/allegro.h>
#define microsec_to_sec(x) ALLEGRO_USECS_TO_SECS(x)
#define milisec_to_sec(x) ALLEGRO_MSECS_TO_SECS(x)
#define beatsps_to_sec(x) ALLEGRO_BPS_TO_SECS(x)
#define beatspm_to_sec(x) ALLEGRO_BPM_TO_SECS(x)

class Timer{
private:
	ALLEGRO_TIMER * __tim;
public:
	
	Timer(double s, bool check = true){
		if(s < 0.0 && check){
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
	
	bool started(void){
		return al_get_timer_started(__tim);
	}
	
	int64_t count(void){
		return al_get_timer_count(__tim);
	}
	
	void count(int64_t st){
		al_set_timer_count(__tim,st);
	}
	
	void add_count(int64_t st){
		al_add_timer_count(__tim,st);
	}
	
	double timer_speed(void){
		return al_get_timer_speed(__tim);
	}
	
	void timer_speed(double nt){
		al_set_timer_speed(__tim,nt);
	}
};




