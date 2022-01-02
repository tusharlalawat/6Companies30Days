#include<bits/stdc++.h>
using namespace std;

string gcdOfStrings(string s1, string s2) {

    if(s1 == s2) return s2;
    if(s1 < s2) swap(s1, s2);

    int n = s1.length(), m = s2.length();
    int i=1, len = 0;
    string temp = "";

    while(i <= n && i <= m && s1[i-1] == s2[i-1]){
        temp += s1[i-1];
        bool matches = true;
        
        if(n%i == 0 && m%i == 0){    // becuase, substring length i must be the common divisor of lengthes of s1 and s2.
            for(int j=2*i; matches && j <= n; j += i){     //For checking that the the string is repeated itself or not in s1
                matches = (temp == s1.substr(j-i, i));
            }

            for(int j=2*i; matches && j <= m; j += i){    //For checking that the the string is repeated itself or not in s2
                matches = (temp == s2.substr(j-i, i));
            }

            if(matches == true) len = i;                 // Updating maximum length for the substring
        }
        i++;
    }

    return s1.substr(0, len);
}

int main(){
    string s1, s2;
    cin >>s1 >>s2;

    cout <<gcdOfStrings(s1, s2) <<endl;
    return 0;
}