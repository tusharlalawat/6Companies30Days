#include<bits/stdc++.h>
using namespace std;

/*
If target = 3, then k = 2, delta = 0 and the answer is k = 2.
If target = 4, then k = 3, delta = 2, delta is even and the answer is k = 3.
If target = 7, then k = 4, delta = 3, delta is odd and adding k+1 makes delta even. The answer is k+1 = 5.
If target = 5, then k = 3, delta = 1, delta is odd and adding k+1 keeps delta odd. The answer is k+2 = 5.
*/

class Solution {
public:
    int reachNumber(int target) {
        
        target = abs(target);
        int k = 0;
        while(target > 0) target -= ++k;
    
        return (target%2 == 0 ? k : k+1+k%2);
    }
};

int main() {
    int n;
    cin >>n;

    Solution obj;
    cout <<obj.reachNumber(n) <<endl;
    return 0;
}