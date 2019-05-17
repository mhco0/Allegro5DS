#include<bits/stdc++.h>
#include<Display.hpp>
#include<Time.hpp>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	al_init();
	
	Display disp(480,400,"Perazzo");
	Time t;
	
	disp.show();
	
	t.rest(1.0);
	
	disp.title("novo nome");
	disp.width(600);
	cout << disp.height() << endl;
	disp.show();
	
	t.rest(1.0);
	
	cout << disp.title() << endl;
	cout << t.time() << endl;

	return 0;
}
