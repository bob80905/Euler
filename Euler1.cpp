#include <iostream>
#include <stdlib.h>
using namespace std;



int main(){
	int sum = 0;
	for(unsigned int i = 0; i < 1000; i++){
		if(i%3 == 0 || i % 5 == 0){
			sum += i;
		}
	}
	cout<<"Sum of all numbers divisible by 3 or 5 less than 1000 is "<<sum<<endl;
	
}