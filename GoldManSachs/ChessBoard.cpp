#include<bits/stdc++.h>
using namespace std;

long long squaresInChessBoard(long long N) {
        // code here
        return N*(N+1)*(2*N+1)/6;
    }

int main(){
    int n;
    cin >>n;

    cout <<squaresInChessBoard(n) <<endl;
    return 0;
}