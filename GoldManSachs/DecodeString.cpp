#include<bits/stdc++.h>
using namespace std;

string solve(string &s, int &ind) {
    int n = 0;
    string word = "";
    
    while(ind < s.length()) {

        // If the character is a number
        if(s[ind] >= '0' && s[ind] <= '9')
            n = n*10 + (s[ind] - '0');
        else if(s[ind] == '[') {
            ind++;
            string temp = solve(s, ind);
            while(n--) word += temp;
            n = 0;
        }
        else if(s[ind] == ']')
            return word;
        else                             // If the character is an english alphabet
            word += s[ind];
        ind++;
    }
    return word;
}

string decodedString(string s){
    int ind = 0;
    return solve(s, ind);
}

int main(){
    string s;
    cin >>s;
    
    cout <<decodedString(s) <<endl;
    return 0;
}