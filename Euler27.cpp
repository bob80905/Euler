#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

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


        for(unsigned long int i = 5; i <= pow(num, .5); i+=2 ){
            if(num%i == 0){
                return false;
            }
        }
        return true;
}

int f(int a, int b ){
	vector<int> ret;
	for(int i = 0;;i++){
		int sol = i*i + a*i + b;
		if(sol < 2 || !isprime(sol)){ //dont use isprime for negative integers.
			return ret.size();
		}
		ret.push_back(sol);
	}
	return ret.size();
}

int main(){
	int m = 0;
	int besta = 0;
	int bestb = 0;
	for(int a = -999; a < 1000; a++){
		for(int b = -1000; b <= 1000; b++){
			int s = f(a,b);
			if (s > m){
				m = s;
				besta = a;
				bestb = b;
			}
		}
	}
	cout<<"best product: "<<besta*bestb<<" with a size of: "<<m<<endl;
	cout<<besta<<' '<<bestb<<endl;
}