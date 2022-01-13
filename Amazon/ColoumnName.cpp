#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        char c;
        while(n){
            // n-1 is used to make string 0 indexed.
            c = (n-1)%26 + 'A';
            ans = c + ans;
            n = (n-1)/26;
        }
        return ans;
    }
};

int main(){
    long long n;
    cin >>n;

    Solution obj;
    cout <<obj.colName(n) <<endl;
    return 0;
}