#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
            string s = "";
            int n = A.length();
            int count[26] = {0};
            for(int i=0; i<n; i++)
            {
                q.push(A[i]);
                count[A[i]-'a']++;
                while(!q.empty())
                {
                    if(count[q.front() - 'a'] > 1)
                        q.pop();
                    else{
                        s.push_back(q.front());
                        break;
                    }
                }
                if(q.empty())
                    s.push_back('#');
            }
            
            return s;
		}

};

int main(){
    string s;
    cin >>s;

    Solution obj;
    cout <<obj.FirstNonRepeating(s) <<endl;
}