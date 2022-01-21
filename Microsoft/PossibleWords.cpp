#include<bits/stdc++.h>
using namespace std;

string fun(int n){
switch(n){
        case 2:
            return "abc";
            ;
        case 3:
            return "def";
           
        case 4:
            return "ghi";
            
        case 5:
            return "jkl";
            
        case 6:
            return "mno";
            
        case 7:
            return "pqrs";
            
        case 8:
            return "tuv";
            
        case 9:
            return "wxyz";
            
    }
}

void solve(int ind, int n, int a[], string s, vector<string> &v){
    if(ind == n){
        v.push_back(s);
        return;
    }
    
    string temp = fun(a[ind]);
    for(int i=0; i<temp.size(); i++){
        solve(ind+1, n, a, s+temp[i], v);
    }
}

vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string> v;
        
        solve(0, n, a, "", v);
        return v;
    }

int main() {
    return 0;
}