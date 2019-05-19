#include <iostream>
#include <string>
#include <utility>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Image{
private:
	ALLEGRO_BITMAP * __img;
	enum class Flags : int {
		Memory = ALLEGRO_MEMORY_BITMAP,
		Video = ALLEGRO_VIDEO_BITMAP,
		Convert = ALLEGRO_CONVERT_BITMAP,
		Force = ALLEGRO_FORCE_LOCKING,
		No_texture = ALLEGRO_NO_PRESERVE_TEXTURE,
		Alpha = ALLEGRO_ALPHA_TEST,
		Min_linear = ALLEGRO_MIN_LINEAR,
		Mag_linear = ALLEGRO_MAG_LINEAR,
		Mipmap = ALLEGRO_MIPMAP
	};
public:
	Image(int w,int h){
		__img = al_create_bitmap(w,h);
		if(__img == nullptr)
			std::cerr << "error to create image" << std::endl;
	}

	Image(const Image& c){
		this->__img = al_clone_bitmap(c.__img);
	}
	
	~Image(void){
		al_destroy_bitmap(__img);
	}
	
	Image& operator=(const Image& c){
		this->__img = al_clone_bitmap(c.__img);
		return *this;
	}
};
