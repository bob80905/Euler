#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

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
	int index = 0;
	int result = 2;
	for(unsigned int i = 2; index < 10001; i++){
		if(isprime(i)){
			index++;
			result = i;
			//at this point in the first iteration index = 1 (for 1st) and result = 2.
			//2 is the 1st prime
		}
	}
	cout<<"The 10001st prime is: "<< result << endl;

}