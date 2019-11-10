#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>
#include <unordered_set>

using namespace std;

vector<int> factors(int n){
	vector<int> ret;
	for(unsigned int i = 1; i < n/2+1; i++){
		if(n%i == 0){
			ret.push_back(i);
		}
	}
	return ret;
}

bool two_numbers_add_up_to_target(int target, const vector<int>& nums, const vector<bool>& truth){
	int temp = target;
	int i = 0;
	while(nums[i] < target){
    	temp = target - nums[i];
    	if(truth[temp]){
    		return true;
    	}
    	i+=1;
	}
	return false;
}

int sum(vector<int> s){
	int ret = 0;
	for(unsigned int i = 0; i < s.size(); i++){
		ret += s[i];
	}
	return ret;
}

void print1D(vector<int> v){
	for(unsigned int j = 0; j < v.size(); j++){
			if(j != v.size() -1 ){
				cout<<v[j]<<", ";
			}
			else{
				cout<<v[j]<<endl;
			}
		}

}

bool abundant(int i){
	vector<int> f = factors(i);
	int s = sum(f);
	if(s > i){
		return true;
	}
	return false;
}

int main(){

	vector<bool> abundant_truth(28123, false);
	vector<int> abundant_numbers;
	for(unsigned int i = 12; i <= 28123; i++){
		if(abundant(i)){
			abundant_truth[i] = true;
			abundant_numbers.push_back(i);
		}
	}

	cout<<"Done loading "<<abundant_numbers.size()<<" abundant numbers"<<endl;
	int total_sum = 0;

	for(unsigned int i = 0; i <= 28123; i++){
		if(!two_numbers_add_up_to_target(i, abundant_numbers, abundant_truth)){
			total_sum += i;
		}
	}
	cout<<total_sum<<endl;
}