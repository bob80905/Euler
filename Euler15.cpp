#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;



long long int solve(int x, int y, vector<vector<long long int> > & solved){
	if(x == 0 || y == 0){
		return 1;
	}
	//mmm memoization
	if(solved[x][y] != -1){
		return solved[x][y];
	}
	else{
		solved[x][y] = solve(max(x-1, 0), y, solved) + solve(x, max(y-1, 0) ,solved);
	}
	return solved[x][y];
}

int main(){
	int GRID_SIZE = 20;

	vector<long long int> temp (GRID_SIZE+1, -1);
	vector<vector<long long int> > solved;
	for(unsigned int i = 0; i < GRID_SIZE+1; i++){
		solved.push_back(temp);
	}

	long long int result = solve(GRID_SIZE, GRID_SIZE, solved);
	cout<<"Number of paths: "<< result<<endl;
}