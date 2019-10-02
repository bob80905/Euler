#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

unsigned long int next_fib(vector<int>& fiba){
	return fiba[fiba.size()-1] + fiba[fiba.size()-2];
}

int main(){
	vector<int> fibarray;
	fibarray.push_back(0);
	fibarray.push_back(1);

	while(fibarray[fibarray.size()-1] < 4000000){
		fibarray.push_back(next_fib(fibarray));
	}

	unsigned long int sum = 0;
	for(unsigned int i = 0; i < fibarray.size(); i++){
		if(fibarray[i]%2 == 0){
			sum += fibarray[i];
		}
	}
	cout<<"SUM: "<< sum << endl;
}