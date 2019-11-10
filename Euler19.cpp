#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include <fstream>

using namespace std;

class Date{
public:

	Date(){
		year = 1900;
		month = 0;
		day_num = 1;
		total_day_count = 1;
		day_names = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		days_per_month = {31,28,31,30,31,30,31,31,30,31,30,31};

	}

	string get_day_name() const{
		return day_names[total_day_count%7];
	}

	void increment_day(){
		day_num++;
		total_day_count++;
		if(day_num > days_per_month[month]){
			month += 1;
			day_num = 1;
			if(month >= 12){
				month = 0;
				year += 1;
				if(year%4 == 0){
					if(year%100 == 0 && year%400 != 0){
						days_per_month[1]=28;
						return;
					}
					days_per_month[1]=29;
				}
				else{
					days_per_month[1]=28;
				}
			}

		}
	}

	int get_year() const{
		return year;
	}
	int get_month() const {
		return month;
	}
	string get_month_name() const{
		vector<string> month_names = {"January", "February", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December"};
		return month_names[month];
	}
	int get_day_num() const{
		return day_num;
	}

private:
	int year;
	int month;
	int day_num;
	vector<int> days_per_month;
	vector<string> day_names;
	int total_day_count;
};

ostream& operator<<(ostream& os, const Date& d){
    os << d.get_day_name() << " " << d.get_day_num() << ", " << d.get_month_name() << " " << d.get_year()<<endl;
    return os;
}

int main(){
	Date d;
	int count = 0;
	while(d.get_year() != 2000 || d.get_month() != 11 || d.get_day_num() != 31){
		if(d.get_day_name() == "Sunday" && d.get_day_num() == 1 && d.get_year() >= 1901){
			count ++;
		}
		cout<<d;
		d.increment_day();
	}
	cout<<count<<endl;
}