#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
using namespace std;

//how can this be optimized?
int main(){
	int a = 0;
	int b = 0; 
	int c = 0;

	while(1){
		a+=1;
		if(a == 1000){
			a = 0;
			b++;
			if(b == 1000){
				b = 0;
				c++;
			}
		}

		if(a*a + b*b == c*c){
			if(a + b + c == 1000){
				break;
			}
		}
	}
	cout<<"Product of a, b, and c: "<<a*b*c<<endl;
}