#include<bits/stdc++.h>
using namespace std;

string amendSentence (string s)
    {
        // your code here
        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z')  {
                if(i != 0) ans += " ";
                ans += tolower(s[i]);
            }
            else ans += s[i];
        }
        return ans;
    }

int main() {
    return 0;
}