#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Using Deque
    // Time Complexity:- O(N)
    // Space Complexity:- O(K)

    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        deque<int> dq;  // Used to store indexes of the elements
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();   // removing all the elements which are smaller than curr element as thy are useless.
            dq.push_back(i);                                                // Inserting current element's index.
        }
        
        for(int i=k; i<n; i++){
            ans.push_back(arr[dq.front()]);                                // the element at front will be the maximum element of the subarray
            
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();  // removing all the elements which are smaller than curr element as thy are useless.
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();        // removing all the elements which are out of the curr window.
            
            dq.push_back(i);                                                // Inserting current element's index.
        }
        ans.push_back(arr[dq.front()]);                                    // Adding the last remaining element to aur answer list.
        return ans;
    }

    // Using Multiset
    // Time Complexity:- O(NlogN) => log n for inserting and removing elements from multiset
    // Space Complexity:- O(K)
    void UsingMultiset(vector<int>& v, int n, int k){
        multiset<int> mp;
        for(int i=0; i<k; i++) mp.insert(v[i]);

        cout <<"Ans: " <<*mp.rbegin() <<" ";
        for(int i=k; i<n; i++){
            mp.erase(v[i-k]);
            mp.insert(v[i]);
            cout <<*mp.rbegin() <<" ";
        }
        cout <<endl;
    }
};

int main(){
    int n, k;
    cin >>n >>k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];
    
    Solution obj;
    vector<int> ans = obj.max_of_subarrays(v, n, k);
    for(int i=0; i<ans.size(); i++) cout <<ans[i] <<" ";
    cout <<endl;
    // obj.UsingMultiset(v, n, k);
    return 0;
}