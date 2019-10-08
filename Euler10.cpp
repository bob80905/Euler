#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
using namespace std;

//How can we further optimize this?
bool isprime(unsigned long int num){
        if(num == 2 || num == 3){
                return true;
        }

        if(num < 2){
                return false;
        }

        if(num%2 == 0 || num%3 == 0){
        	return false;
        }

        for(unsigned long int i = 4; i <= pow(num, .5); i++ ){
            if(num%i == 0){
                return false;
            }
        }
        return true;
}

int main(){
	unsigned long int sum = 2;
	for(unsigned int i = 3; i < 2000000; i+=2){
		if(isprime(i)){
			sum += i;
		}
	}
	cout<<"Sum of all primes < 2M: "<<sum<<endl;
}