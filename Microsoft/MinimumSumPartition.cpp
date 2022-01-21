#include<bits/stdc++.h>
using namespace std;

/*
Algorithm:-
This problem is same as "subset sum problem" or "equal sum partition problem".
we have to make a 2d dp array of type boolean, with the dimentions of [n+1][sum+1] where n repesents the no. of items in the array and sum = total sum of the array.
now for every indeces [i][j] we have to check wheather we can find the sum of j till indices (i-1) of the given array.
for every indices we have two options 1.) by excluding the current element and 2.) by including the current element.
here dp[i-1][j] return true if we can find the sum j by excluding the (i-1)th item, and false if we can't.
and (arr[i-1] <= j) is the condition to check wheather we can include the current item into our subset or not.
dp[i-1][j - arr[i-1]] returns true if we can have sum equal to j by including the current item.
*/

int minDifference(vector<int> arr, int n)  { 

	    int sum = 0, ans=INT_MAX;
	    for(int i=0; i<n; i++) sum += arr[i];
	    
	    vector< vector<bool> > dp(n+1, vector<bool> (sum+1, false));
	    for(int i=0; i<=n; i++) dp[i][0] = true;         // Cause we have always find sum = 0 by excluding all the elements
	    for(int i=1; i<=sum; i++) dp[0][i] = false;      // Cause we can't find sum >= 0 by excluding all the elements
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            dp[i][j] = dp[i-1][j];
	            if(arr[i-1] <= j){
	                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
	            }
	        }
	    }
	    
	    for(int i=sum/2; i>=0; i--){
	        if(dp[n][i] == true){
	            ans = sum - 2*i;
	            break;
	        }
	    }
	    
	    return ans;
	} 

int main() {
    int n;
    cin >>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];

    cout <<"Ans is: " <<minDifference(v, n) <<endl;
    return 0;
}