#include<bits/stdc++.h>
using namespace std;

string encode(string s)
{     
  //Your code here 
    string ans = "";
    int n = s.length();
    int temp = 0;
    char c = s[0];
    for(int i=0; i<n; i++){
        if(s[i] != c){
            ans += (c + to_string(temp));
            c = s[i];
            temp = 0;
        }
        temp++;
    }
    ans += (c + to_string(temp));
    return ans;
}

int main(){
    string s;
    cin >>s;

    s = encode(s);
    cout <<s <<endl;
    return 0;
}
