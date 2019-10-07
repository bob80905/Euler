#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

unsigned long int getsqofsum(unsigned long int limit){
	unsigned long int sum = (limit * (limit + 1))/2;
	return pow(sum, 2);
}

unsigned long int getsumofsq(unsigned long int limit){
	unsigned long int ret = 0;
	for(unsigned int i = 1; i <= limit; i++){
		ret += pow(i, 2);
	}
	return ret;
}

int main(){
	unsigned long int sqofsum = getsqofsum(100);
	unsigned long int sumofsq = getsumofsq(100);
	cout<<"Difference: "<<sqofsum - sumofsq<<endl;

}