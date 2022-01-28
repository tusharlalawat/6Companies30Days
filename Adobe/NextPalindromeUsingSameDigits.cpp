#include<bits/stdc++.h>
using namespace std;

string nextPalin(string s) { 
        //complete the function here
        int n = s.length();
        if(n <= 3) return "-1";

        string first = s.substr(0, n/2);
        if(!next_permutation(first.begin(), first.end())) return "-1";

        string second = first;
        reverse(second.begin(), second.end());
        if(n%2 == 1) first += s[n/2];
        
        return first+second;
    }

int main(){
    string s;
    cin >>s;

    cout <<"Next palindrome is: " <<nextPalin(s) <<endl;
    return 0;
}