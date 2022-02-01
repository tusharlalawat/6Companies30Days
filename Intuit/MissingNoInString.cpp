#include<bits/stdc++.h>
using namespace std;

int val(string s, int i, int len){
    if(i+len > s.length()) return -1;

    int n = 0;
    for(int j=0; j<len; j++){
        int temp = s[i+j] - '0';
        if(temp < 0 || temp > 9) return -1;
        n = n*10 + temp;
    }
    return n;
}

int missinNumber(string s){
    for(int len = 1; len <= 6; len++){
        int n = val(s, 0, len);
        if(n == -1) break;

        int missing = -1;
        bool fail = false;

        for(int i=len; i != s.length(); i += 1+log10l(n)){
            if(missing == -1 && val(s, i, 1+log10l(n+2)) == n+2){
                missing = n+1;
                n += 2;
            }
            else if(val(s, i, 1+log10l(n+1)) == n+1) n++;
            else {
                fail = true;
                break;
            }
        }

        if(!fail) return missing;
    }
    return -1;
}

int main() {
    string s;
    cin >>s;

    cout <<"Missing no. is: " <<missinNumber(s) <<endl;
    return 0;
}