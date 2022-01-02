#include<bits/stdc++.h>
using namespace std;

int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        if(L1[0] > R2[0] || L2[0] > R1[0]) return false; //If any of the two rectangles are on the left side of the other one
        else if(R1[1] > L2[1] || R2[1] > L1[1]) return false; //If any of the two rectangles is above to the other one
        else return true;
    }

int main(){

    int L1[2], R1[2], L2[2], R2[2];
    for(int i=0; i<2; i++) cin >>L1[i];
    for(int i=0; i<2; i++) cin >>R1[i];
    for(int i=0; i<2; i++) cin >>L2[i];
    for(int i=0; i<2; i++) cin >>R2[i];

    cout <<doOverlap(L1, R1, L2, R2) <<endl;
    return 0;
}