#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        
        bool difSign = (dividend > 0ll) ^ (divisor > 0ll);

        dividend = labs(dividend);
        divisor = labs(divisor);

        long long quotient = 0;

        while(dividend > 0ll) {
            int count = 0;

            while((dividend - (divisor << (count + 1))) >= 0) count++;

            dividend -= divisor << count;

            if(dividend >= 0ll) {
                quotient += (1ll << count);
            }
        }

        return min((difSign ? -quotient : quotient), (long long) 2147483647);
    }
};

int main() {
    return 0;
}