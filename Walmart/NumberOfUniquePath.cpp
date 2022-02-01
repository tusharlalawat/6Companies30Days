#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> M(a, vector<int>(b, 1));
        
        for(int r = 1; r < a; ++r) {
            for(int c = 1; c < b; ++c) {
                M[r][c] = M[r-1][c] + M[r][c-1];
            }
        }

        return M.back().back();
    }
};

int main() {
    return 0;
}