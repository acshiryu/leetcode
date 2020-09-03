//
// Created by hzl on 2020/2/16.
//

#include <include/cplusplus.h>

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> index;
    for (size_t i = 0 ; i < nums.size(); ++i)
    {
      auto x = target - nums[i];
      if (index.count(x) > 0)
        return {index[x], int(i)};
      index[nums[i]] = int(i) ;
    }
    return {0, 0};
  }
};

int32_t main()
{
  return 0;
}