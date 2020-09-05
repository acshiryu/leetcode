//
// Created by hzl on 2020/9/5.
//

#include <include/cplusplus.h>

class Solution
{

    const std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  public:
    string getPermutation(int n, int k)
    {
        string ans;
        --k;
        std::vector<int> seq(array.begin(), array.begin() + n);
        auto mul = std::accumulate(seq.begin(), seq.end(), 1, [](auto x, auto y) {return x*y;});
        for (int i = 0; i < n; ++i){
            mul /= array[n - i - 1];

            auto a = k / mul;
            ans.append(to_string(seq[a]));
            k %= mul;
            seq.erase(std::find(seq.begin(), seq.end(), seq[a]));

        }
        return ans;


    }
};