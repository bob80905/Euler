#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

//return number of characters, (one ... nine)
int ones(int n){
	if(n == 3 || n == 7 || n == 8){
		return 5;
	}
	else if(n == 1 || n == 2 || n == 6){
		return 3;
	}
	else if(n == 4 || n == 9 || n == 5){
		return 4;
	}
	else if (n == 0){
		return 0;
	}
}

//return number of characters, (twenty ... ninety)
int tens(int n){

	if(n == 4 || n == 5 || n == 6){
		return 5;
	}

	else if(n == 2 || n == 3){
		return 6;
	}

	else if(n == 8 || n == 9){
		return 6;
	}

	else if(n == 7){
		return 7;
	}
}

//return number of characters (ten ... nineteen)
int teens(int n){
	if(n == 11 || n == 12){
		return 6;
	}
	else if(n == 13 || n == 14 || n == 18 || n == 19){
		return 8;
	}
	else if(n == 15 || n == 16){
		return 7;
	}
	else if(n == 17){
		return 9;
	}
	else if(n == 10){
		return 3;
	}

}

int main(){
	int sum = 0;
	for(unsigned int i = 1; i <= 1000; i++){
		if(i < 20){
			if(i < 10){
				sum += ones(i);
			}
			if(i >= 10 && i <= 19){
				sum += teens(i);
			}
		}
		if(i >= 20 && i <= 99){
			sum += tens(i/10);
			sum += ones(i%10);
		}
		if(i >= 100 && i <= 999){
			sum += 7; //account for the "hundred"
			if(i % 100 != 0){
				sum += 3; //account for the "and"
			}
			
			int h = i/100;
			int t = (i % 100)/10;
			int o = i % 10;

			sum += ones(h);

			if(t == 0){
				sum += ones(o);
			}
			if(t == 1){
				sum += teens(t*10 + o);
			}
			if(t >= 2){
				sum += tens(t);
				sum += ones(o);
			}
		}
		if(i == 1000){
			sum += 3;
			sum += 8;
		}
	}
	cout<<"Sum: "<<sum<<endl;
}