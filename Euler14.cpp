#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

vector<int> c_chain(long int num){
	vector<int> ret;
	while(num != 1){
		if(num%2 == 0){
			ret.push_back(num);
			num/=2;
		}
		else{
			ret.push_back(num);
			num = num*3 + 1;
		}
	}
	return ret;
}

int main(){
	long int m = 0;
	int start = 0;
	for(unsigned int i = 1; i < 1000000; i++){
		vector<int> temp = c_chain(i);
		long int s = temp.size();
		int oldm = m;
		m = max(m, s);
		if(oldm < m){
			start = i;
		}
	}
	cout<<start<<endl;
}