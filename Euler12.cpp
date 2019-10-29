#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

void print(vector<int> v){
	for(unsigned int i = 0; i < v.size(); i++){
		cout<<v[i]<<endl;
	}
}

vector<int> get_divisors(int n){
	vector<int> ret;
	int lim = pow(n, .5);
	int i = 2;

	ret.push_back(1);
	ret.push_back(n);

	while(i < lim){
		if(n%i == 0){
			ret.push_back(i);
			ret.push_back(n/i);
		}
		i+=1;
	}
	return ret;
}



int main(){
	int num = 0;
	int add = 0;
	while(true){
		num += add+1;
		vector<int> factors = get_divisors(num);
		//cout<<num<<": ";
		//print(factors);
		if(factors.size() > 500){
			cout<<"Triangle number: "<<num<<endl;
			return 0;
		}
		add += 1;
		
	}
	return 1;
}