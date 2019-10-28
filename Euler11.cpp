#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

int get_largest_product(vector<vector<int> >& g){
	int ret = 0;
	int GRID_SIZE = g.size();

	for(int i = 0; i < GRID_SIZE; i++){
		for(int j = 0 ; j < GRID_SIZE; j++){
			int dleft = 0, down = 0, dright = 0, right = 0;
			//diagonal down left
			if(i + 3 < GRID_SIZE && j - 3 >= 0){
				dleft = g[i][j]*g[i+1][j-1]*g[i+2][j-2]*g[i+3][j-3];
			}
			//straight down
			if(i + 3 < GRID_SIZE){
				down = g[i][j]*g[i+1][j]*g[i+2][j]*g[i+3][j];
			}
			//diagonal down right
			if(i + 3 < GRID_SIZE && j + 3 < GRID_SIZE){
				dright = g[i][j]*g[i+1][j+1]*g[i+2][j+2]*g[i+3][j+3];
			}
			//straight right
			if(j + 3 < GRID_SIZE){
				dright = g[i][j]*g[i][j+1]*g[i][j+2]*g[i][j+3];
			}

			int a = max(dleft, dright);
			int b = max(down, right);
			int c = max(a,b);
			ret = max(ret, c);

		}
	}
	return ret;
}


int main(){
	int GRID_SIZE = 20;
	ifstream f("Euler11.txt");
	vector<vector<int> > grid;
	for(unsigned int i = 0; i < GRID_SIZE; i++){
		vector<int> temp;
		for(unsigned int j = 0; j < GRID_SIZE; j++){
			string num;
			f>>num;
			cout<<num<<endl;
			int n = atoi(num.c_str());
			temp.push_back(n);
		}
		grid.push_back(temp);
	}

	cout<<"Largest product: "<<get_largest_product(grid)<<endl;


}