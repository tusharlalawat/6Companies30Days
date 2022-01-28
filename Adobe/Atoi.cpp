#include<bits/stdc++.h>
using namespace std;

int atoi(string s) {
        //Your code here
        int n = s.length();
        int ans = 0;
        bool neg = false;
        
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        
        if(s[i] == '-') {
            neg = true;
            i++;
        }
        
        for(i; i<n; i++){
            if(s[i] < '0' || s[i] > '9') return -1;
            else ans = ans*10 + (s[i] - '0');
        }
        
        if(neg) ans *= -1;
        return ans;
    }

int main(){
    string s;
    cin >>s;

    cout <<"Number is: " <<atoi(s) <<endl;
    return 0;
}