#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void swap(char &a, char &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    string findMaximumNum(string &str, int k, int index = 0)
    {
       int length = str.length();

       if(k == 0 || index >= length) {
           return str;
       }

       int max_index = index;
       vector<int> max_indices;

        for(int i = index + 1; i < length; ++i) {
            if(str[max_index] <= str[i]) {
                if(str[max_index] < str[i]) {
                    max_indices.clear();
                }
                max_index = i;
                max_indices.push_back(i);
            }
        }

        if(str[max_index] == str[index]) {
            return findMaximumNum(str, k, index + 1);
        }

        string ans = str;

        for(int max_index: max_indices) {
            swap(str[max_index], str[index]);
            ans = max(ans, findMaximumNum(str, k - 1, index + 1));
            swap(str[max_index], str[index]);
        }

        return ans;
    }
};

int main() {
    return 0;
}