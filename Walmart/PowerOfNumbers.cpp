#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    long long MOD = 1e9+7;
    long long power(long long N, long long R)
    {
        N %= MOD;
        long long ans = 1;
        while (R > 0) {
            if (R & 1) {
                ans = (ans * N) % MOD;
            }
            N = (N * N) % MOD;
            R >>= 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}