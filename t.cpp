#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'findHighPoints' function below.
 *
 * The function is expected to return a 2D_BOOLEAN_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY elevations as parameter.
 */

bool isHighPoint(vector<vector<int>>& e, int x, int y){
    cout<<"grid:"<<endl;
    for(unsigned int i = 0; i < e.size(); i++){
        for(unsigned int j = 0; j < e[i].size(); j++){
            cout<<e[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<e.size()<<" "<<e[0].size()<<" "<<x<<" "<<y<<endl;
    if(x == 0){
        if(y == 0){
            if(e[x][y] <= e[x+1][y] || e[x][y] <= e[x+1][y+1] || e[x][y] <= e[x][y+1]){
                return false;
            }
        }
        else if(y == e[x].size()-1){
            if(e[x][y] <= e[x+1][y] || e[x][y] <= e[x+1][y-1] || e[x][y] <= e[x][y-1]){
                return false;
            }
        }
        else{
            if(e[x][y] <= e[x+1][y] || e[x][y] <= e[x+1][y-1] || e[x][y] <= e[x][y-1] ||
            e[x][y] <= e[x+1][y+1] || e[x][y] <= e[x][y+1]){
                return false;
            }
        }
    }
    if(x == e.size()-1){
        if(y == 0){
            if(e[x][y] <= e[x-1][y] || e[x][y] <= e[x-1][y+1] || e[x][y] <= e[x][y+1]){
                return false;
            }
        }
        else if(y == e[x].size()-1){
            if(e[x][y] <= e[x-1][y] || e[x][y] <= e[x-1][y-1] || e[x][y] <= e[x][y-1]){
                return false;
            }
        }
        else{
            if(e[x][y] <= e[x-1][y] || e[x][y] <= e[x-1][y-1] || e[x][y] <= e[x][y-1] ||
            e[x][y] <= e[x-1][y+1] || e[x][y] <= e[x][y+1]){
                return false;
            }
        }
    }
    else{ //x is in the middle somewhere
        int temp = e[x].size();
        if(y == 0){
            if(e[x][y] <= e[x-1][y] || e[x][y] <= e[x-1][y+1] || e[x][y] <= e[x][y+1] ||
            e[x][y] <= e[x+1][y+1] || e[x][y] <= e[x+1][y]){
                return false;
            }
        }
        else if(y == temp-1){
            if(e[x][y] <= e[x-1][y] || e[x][y] <= e[x-1][y-1] || e[x][y] <= e[x][y-1] ||
            e[x][y] <= e[x+1][y-1] || e[x][y] <= e[x+1][y]){
                return false;
            }
        }
        else{ //all 8 directions
            if(e[x][y] <= e[x-1][y] || e[x][y] <= e[x-1][y+1] || e[x][y] <= e[x][y+1] ||
            e[x][y] <= e[x+1][y+1] || e[x][y] <= e[x+1][y] || e[x][y] <= e[x+1][y-1] || e[x][y] <= e[x][y-1] ||
             e[x][y] <= e[x-1][y-1]){
                 return false;
             }
        }
    }
    return true;
}

vector<vector<bool>> findHighPoints(vector<vector<int>> elevations) {
    vector<vector<bool>> ret;
    for(unsigned int i = 0; i < elevations.size(); i++){
        vector<bool> temp(elevations[i].size(), false);
        ret.push_back(temp);
    }
    cout<<elevations.size()<<" "<<elevations[0].size()<<endl;
    for(unsigned int i = 0; i < elevations.size(); i++){
        for(unsigned int j = 0; j<elevations[i].size(); j++){
            if(i == 0){
                if(isHighPoint(elevations,i,j)){
                    ret[i][j] = true;
                }
            }
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string elevations_rows_temp;
    getline(cin, elevations_rows_temp);

    int elevations_rows = stoi(ltrim(rtrim(elevations_rows_temp)));

    string elevations_columns_temp;
    getline(cin, elevations_columns_temp);

    int elevations_columns = stoi(ltrim(rtrim(elevations_columns_temp)));

    vector<vector<int>> elevations(elevations_rows);

    for (int i = 0; i < elevations_rows; i++) {
        elevations[i].resize(elevations_columns);

        string elevations_row_temp_temp;
        getline(cin, elevations_row_temp_temp);

        vector<string> elevations_row_temp = split(rtrim(elevations_row_temp_temp));

        for (int j = 0; j < elevations_columns; j++) {
            int elevations_row_item = stoi(elevations_row_temp[j]);

            elevations[i][j] = elevations_row_item;
        }
    }

    vector<vector<bool>> result = findHighPoints(elevations);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
