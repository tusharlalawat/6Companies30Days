#include<bits/stdc++.h>
using namespace std;

void clockwise(vector<vector<int>>& v){
    int n = v.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i < j) swap(v[i][j], v[j][i]);
        }
    }

    for(int i=0; i<n; i++) reverse(v[i].begin(), v[i].end());
}

void anti_clockwise(vector<vector<int>>& v){

    int n = v.size();

    for(int i=0; i<n; i++) reverse(v[i].begin(), v[i].end());

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i < j) swap(v[i][j], v[j][i]);
        }
    }
}
int main() {
    int n;
    cin >>n;

    vector< vector<int> > v(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >>v[i][j];
    }

    // anti_clockwise(v);
    // cout <<"Anti clockwise rotation: " <<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout <<v[i][j] <<" ";
    //     cout <<endl;
    // }

    clockwise(v);
    cout <<"Clockwise rotation: " <<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout <<v[i][j] <<" ";
        cout <<endl;
    }

    return 0;
}