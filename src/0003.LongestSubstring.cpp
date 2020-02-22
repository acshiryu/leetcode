//
// Created by hzl on 2020/2/22.
//

#include <include/cplusplus.h>

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    std::map<char, int32_t>count;
    std::vector<int32_t> length;
    for (size_t i = 0 ; i < s.length(); ++i)
    {
      if (count.find(s[i]) == count.end())
      {
        count[s[i]] = static_cast<int>(i);
        length.push_back(-1);
      }
      else
      {
        length.push_back(count[s[i]]);
        count[s[i]] = static_cast<int>(i);
      }
    }


    int32_t ans = 0;
    int32_t dp = 0;

    for (int j = 0; j < static_cast<int>(length.size()); ++j) {
      dp = min(dp + 1, j - length[j]);
      ans = max(ans, dp);
    }
    return ans;
  }
};

int32_t main()
{
  return 0;
}