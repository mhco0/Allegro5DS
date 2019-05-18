#include<bits/stdc++.h>
#include<Display.hpp>
#include<Time.hpp>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	al_init();
	
	Display disp(480,400,"Testes");
	disp.clipboard("memes");
	Time t;
	
	disp.x(0);
	disp.y(800);
	
	disp.show();
	
	t.rest(1.0);
	
	disp.title("novo nome");
	disp.width(600);
	cout << disp.height() << endl;
	disp.position(0,0);
	disp.resize(500,500);
	disp.constraints(20,20,100,100);
	disp.show();
	
	cout << disp.x() << ' ' << disp.y() << endl;
	
	t.rest(1.0);
	
	cout << disp.title() << endl;
	cout << t.time() << endl;

	return 0;
}
