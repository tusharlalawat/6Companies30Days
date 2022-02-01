#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStone(vector<int>&A,int n, int start, int end, vector<vector<int>>& cache) {
        
        if(end < start) {
            return 0;
        }
        if(end == start) {
            return A[end];
        }
        if(cache[start][end] != -1) return cache[start][end];
        
        return cache[start][end] = max({
            A[start] + min(maxStone(A, n, start + 2, end, cache), maxStone(A, n, start + 1, end - 1, cache)),
            A[end]   + min(maxStone(A, n, start, end - 2, cache), maxStone(A, n, start + 1, end - 1, cache))
        });
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> cache(n, vector<int>(n, -1));
	    int alice = maxStone(piles, n, 0, n-1, cache);
        int bob = accumulate(piles.begin(), piles.end(), 0) - alice;

        return alice > bob;
    }
};

int main() {
    return 0;
}