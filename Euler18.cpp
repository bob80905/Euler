#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

void print2D(vector<vector<int> > v){
	for(unsigned int i = 0; i < v.size(); i++){
		for(unsigned int j = 0; j < v[i].size(); j++){
			if(j != v[i].size() -1 ){
				cout<<v[i][j]<<", ";
			}
			else{
				cout<<v[i][j]<<endl;
			}
		}
	}
}

int solve(vector<vector<int> > t, int i, int j){
	if(i == t.size()-1){
		return t[i][j];
	}
	return t[i][j] + max(solve(t, i+1, j), solve(t, i+1, j+1));
}

int main(){
	vector<vector<int> > triangle;
	ifstream in_str("Euler18.txt");

	string tri;
	int len = 1;
	vector<int> temp;
	while(in_str>>tri){
		int num = atoi(tri.c_str());

		if(temp.size() < len){
			temp.push_back(num);
		}
		else{
			triangle.push_back(temp);
			temp.clear();
			temp.push_back(num);
			len += 1;
		}
	}
	triangle.push_back(temp);

	cout<<solve(triangle, 0, 0)<<endl;

}