#include<bits/stdc++.h>
using namespace std;

int CountWays(string s){
    if(s[0] == '0') return 0;
    // vector<int> dp(s.length()+1, 0);
    // dp[0] = 1;
    // dp[1] = 1;

    int a = 1, b = 1, c;
    for(int i=2; i<=s.length(); i++){
        c = 0;
        int oneDigit = (s[i-1] - '0');
        int twoDigits = (s[i-2] - '0')*10 + oneDigit;

        if(oneDigit >= 1) c += b;
        if(twoDigits >= 10 && twoDigits <= 26) c += a;

        a = b;
        b = c;
    }
    return b;
}

int main(){
    string s;
    cin >>s;

    cout <<CountWays(s) <<endl;
    return 0;
}

/*
Time Complexity:- O(N)
Space Complexity:- O(1)
*/