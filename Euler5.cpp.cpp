#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

bool checksout(unsigned long int num){
	for(unsigned int i = 1; i < 21; i++){
		if(num%i != 0){
			return false;
		}
	}
	return true;
}

int main(){
	for(unsigned long int i = 20; ; i+=20){ 
	//multiply all the primes together to get a head start
		if(checksout(i)){
			cout<<"Smallest number divis from 1-20: "<<i<<endl;
			return 0;
		}
	}
}