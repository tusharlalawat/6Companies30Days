#include<bits/stdc++.h>
using namespace std;

// Basicall we need to sort both the character arrays according to given string.
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    string s = "!#$%&*@^~";    // Given
	    int v[n];
	    for(int i=0; i<n; i++){
	        if(nuts[i] == '!') v[i] = 0;
	        else if(nuts[i] == '#') v[i] = 1;
	        else if(nuts[i] == '$') v[i] = 2;
	        else if(nuts[i] == '%') v[i] = 3;
	        else if(nuts[i] == '&') v[i] = 4;
	        else if(nuts[i] == '*') v[i] = 5;
	        else if(nuts[i] == '@') v[i] = 6;
	        else if(nuts[i] == '^') v[i] = 7;
	        else if(nuts[i] == '~') v[i] = 8;
	    }
	    sort(v, v+n);
	    for(int i=0; i<n; i++){
	        nuts[i] = s[v[i]];
	        bolts[i] = s[v[i]];
	    }
	}

};

int main(){
    int n;
    cin >>n;

    char Nuts[n], Bolts[n];
    for(int i=0; i<n; i++) cin >>Nuts[i];
    for(int i=0; i<n; i++) cin >>Bolts[i];

    Solution obj;
    cout <<obj.matchPairs(Nuts, Bolts, n) <<endl; 
    return 0;
}