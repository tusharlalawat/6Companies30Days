#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> find3Numbers(vector<int> nums, int N) {
        int len = 1;
        vector<int> seq(3, INT_MAX), pos(3, -1), mapping(N, -1);
        seq[0] = nums[0];
        pos[0] = 0;

        for(int i = 1; i < N && len < 3; ++i) {
            int index;

            if(seq[len - 1] < nums[i]) {
                index = len;
                len++;
            }
            else {
                index = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            }

            seq[index] = nums[i];
            pos[index] = i;

            if(index > 0) {
                mapping[i] = pos[index - 1];
            }
        }

        if(len < 3) return vector<int>(0);

        vector<int> result(3, 0);
        int ptr = pos[2];
        for(int i = 0; i < 3; ++i) {
            result[2-i] = nums[ptr];
            ptr = mapping[ptr];
        }

        return result;
    }
};

int main() {
    return 0;
}