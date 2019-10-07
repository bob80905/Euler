#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

unsigned long int max(unsigned long int x, unsigned long int y){
	if(x > y){
		return x;
	}
	return y;
}

bool is_palindrome(unsigned long int num){
	string n = to_string(num);
	for(unsigned long int i = 0; i < n.size()/2; i++){
		if(n[i] != n[n.size()-1-i]){
			return false;
		}
	}
	return true; 
}

int main(){
	unsigned long int m = 0; 
	for(unsigned int i = 0; i < 1000; i++){
		for(unsigned int j = 0; j < 1000; j++){
			if(is_palindrome(i*j)){
				m = max(m, i*j);
			}
		}
	}
	cout<<"Max palindrome of product of 2 3-digit numbers: "<<m<<endl;
}