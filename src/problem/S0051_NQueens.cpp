//
// Created by hzl on 2020/9/3.
//
#include <include/cplusplus.h>

class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        init(n);

        ans.clear();
        one.clear();

        solve(0, n);

        return ans;
    }

  private:
    void solve(int k, int n)
    {
        if (k == n)
        {
            ans.push_back(one);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (can(i, n)){
                one.push_back(matrix[i]);
                solve(k + 1, n);
                one.pop_back();
            }
        }
    }

    bool can(int k, int n)
    {
       for (const auto& s : one){
           if (s[k] == 'Q'){
               return false;
           }
       }

       int h = int(one.size());
       for (int i = 1; i < n; ++i){
            if (h - i >= 0 && k - i >= 0){
                if (one[h-i][k-i] == 'Q'){
                    return false;
                }
            }
           if (h - i >= 0 && k + i < n){
               if (one[h-i][k+i] == 'Q'){
                   return false;
               }
           }
       }
       return true;
    }


    void init(int n)
    {
        matrix.clear();
        for (int32_t i = 0 ; i < n ; ++ i){
            string s(n, '.');
            s[i] = 'Q';
            matrix.push_back(s);
        }
    }

  private:
    vector<string> one;
    std::vector<string> matrix;
    vector<vector<string>> ans;
};

int32_t main()
{
    int n;
    Solution solution;
    while (cin >> n){
        solution.solveNQueens(n);
    }
    return 0;
}