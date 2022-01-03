#include<bits/stdc++.h>
using namespace std;

string printMinNumberForPattern(string s){
        // code here 
        string ans;
        stack<int> st;
        int temp = 1;
        for(auto c : s){
            if(c == 'D') st.push(temp++);
            else {
                st.push(temp++);
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(temp);
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }

int main(){
    string s;
    cin >>s;

    cout <<printMinNumberForPattern(s) <<endl;
    return 0;
}