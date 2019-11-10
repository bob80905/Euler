#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

vector<int> factors(int n){
	vector<int> ret;
	for(unsigned int i = 1; i < n; i++){
		if(n%i == 0){
			ret.push_back(i);
		}
	}
	return ret;
}

int sum(vector<int> a){
	int ret = 0;
	for(unsigned int i = 0; i < a.size(); i++){
		ret += a[i];
	}
	return ret;
}

int main(){
	int total = 0;
	for(unsigned int i = 1; i < 10000; i++){
		//cout<<i<<endl;
		int b = sum(factors(i));
		if(sum(factors(b)) == i && b != i){
			//cout<<"Adding "<<i<<" will add "<<b<<endl;
			total += i;
		}
	}
	cout<<total<<endl;
}
