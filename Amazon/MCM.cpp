#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    void Parenthesis(int i, int j, int n, int* bracket, char& name, string& ans) {
        // If only one matrix left in current segment
        if (i == j) {
            ans.push_back(name++);
            return;
        }
     
        ans += "(";
        Parenthesis(i, *((bracket + i * n) + j), n, bracket, name, ans);
     
        Parenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name, ans);
        ans += ")";
    }
    string matrixChainOrder(int a[], int n){
        // code here
        int m[n][n];
        int bracket[n][n];
    
        for (int i = 1; i < n; i++) m[i][i] = 0;
     
        // L is chain length.
        for (int L = 2; L < n; L++)
        {
            for (int i = 1; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    // q = cost/scalar multiplications
                    int q = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
     
                        // Each entry bracket[i,j]=k shows
                        // where to split the product arr
                        // i,i+1....j for the minimum cost.
                        bracket[i][j] = k;
                    }
                }
            }
        }
        
        string ans = "";
        char name = 'A';
        Parenthesis(1, n - 1, n, (int*)bracket, name, ans);
        return ans;
    }
};

int main() {
    int n;
    cin >>n;

    int v[n];
    for(int i=0; i<n; i++) cin >>v[i];

    Solution obj;
    cout <<obj.matrixChainOrder(v, n) <<endl;
    return 0;
}