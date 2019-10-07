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


	for(unsigned long int i = 4; i < pow(num, .5); i++ ){
		if(num%i == 0){
			return false;
		}
	}
	return true;
}

vector<int> factor(unsigned long int num){
	vector<int> ret;
	for(unsigned long int i = 1 ; i < pow(num, .5); i++){
		if(num%i == 0){
			if(isprime(i)){
				ret.push_back(i);
			}
		}
	}
	return ret;
}

int main(){
	unsigned long int to_factor = 600851475143;
	vector<int> factors = factor(to_factor);
	cout<<"largest factor: "<<factors[factors.size()-1];
}