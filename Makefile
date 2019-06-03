
CXX = g++ -std=c++11

CXXFLAGS += -Wall -O2

LIB = -lallegro -lallegro_image

INCLUDES = -I "lib/Display" -I "lib/Time" -I "lib/Color" \
	-I "lib/Image" -I "lib/Timer"
	
all: main.cpp
	$(CXX) $? $(INCLUDES) $(LIB) $(CXXFLAGS) -o teste
clean:
	rm -f *.o *~ teste
run:
	make all
	time ./teste
