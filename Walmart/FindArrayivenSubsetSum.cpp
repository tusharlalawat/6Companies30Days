#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print(vector<int> &v) {
        for(auto &e: v) {
            cout << e << " ";
        }
        cout << endl;
    }
    vector<int> array(int n, vector<int>& sums) {
        if(n == 1) {
            vector<int> result;
            if(sums[0] == 0) {
                result.push_back(sums[1]);
            }
            else if(sums[1] == 0) {
                result.push_back(sums[0]);
            }
            return result;
        }

        int num = sums[(1 << n) - 1] - sums[(1 << n) - 2];

        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        for(int sum: sums) {
            ++freq1[sum];
            ++freq2[sum];
        }

        // cosider num = |largest negative num|
        vector<int> neg;
        bool valid_neg = false;
        for(auto sum: sums) {
            if(freq1.count(sum) && freq1.count(sum + num)) {
                if(freq1[sum] > 0) {
                    neg.push_back(sum + num);
                    if(sum + num == 0) valid_neg = true;
                    --freq1[sum];
                    --freq1[sum + num];
                }
            }
            else {
                if(freq1[sum] > 0)
                    break;
            }
        }

        if(valid_neg && neg.size() == (1 << (n - 1))) {
            vector<int> result = array(n - 1, neg);
            result.push_back(-num);
            if(result.size() == n) 
                return result;
        }
        
        // cosider num = |smallest positive num|
        vector<int> pos;
        bool valid_pos = false;
        int limit = (1 << n);
        for(int i = 0; i < limit; ++i) {
            int sum = sums[limit - 1 - i];
            if(freq2.count(sum) && freq2.count(sum - num)) {
                if(freq2[sum] > 0) {
                    pos.push_back(sum - num);
                    if(sum - num == 0) valid_pos = true;
                    --freq2[sum];
                    --freq2[sum - num];
                }
            }
            else {
                if(freq2[sum] > 0)
                    break;
            }
        }

        if(valid_pos && pos.size() == (1 << (n - 1))) {
            reverse(pos.begin(), pos.end());
            vector<int> result = array(n - 1, pos);
            result.push_back(num);
            if(result.size() == n) 
                return result;
        }

        return vector<int>(0);
    }

    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        return array(n, sums);
    }
};

int main() {
    return 0;
}