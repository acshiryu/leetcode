//
// Created by hzl on 2020/9/7.
//

#include <include/cplusplus.h>

class Solution {
  public:
    struct num{
        int val;
        int count;

        bool operator < (const num& t) const{
            return this->count < t.count;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<num> q;

        num last = {nums[0], 1};
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == last.val){
                ++last.count;
            }else{
                q.push(last);
                last.val = nums[i];
                last.count = 1;
            }
        }
        q.push(last);

        vector<int> result;
        while (int(result.size()) < k){
            result.push_back(q.top().val);
            q.pop();
        }
        return result;
    }
};