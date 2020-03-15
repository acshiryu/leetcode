//
// Created by hzl on 2020/3/15.
//

#include <include/cplusplus.h>

class Solution
{
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int32_t ans = 0;
    mapped.clear();
    for (size_t i = 0; i < grid.size(); ++i)
    {
      for (size_t j = 0 ; j < grid[i].size(); ++j)
      {
        if (mapped.count({i, j}) || grid[i][j] == 0)
        {
          continue;
        }

        ans = std::max(ans, DFS(i, j, grid));
      }
    }
    return ans;
  }

  int DFS(std::size_t i, size_t j, vector<vector<int>> &grid )
  {
    if (grid[i][j] == 0 || mapped.count({i, j}))
    {
      return 0;
    }

    mapped.emplace(i, j);

    int32_t ans = 1;
    if (i > 0)
    {
      ans += DFS(i-1,j,grid);
    }
    if (j > 0)
    {
      ans += DFS(i,j - 1,grid);
    }
    if (i + 1 < grid.size())
    {
      ans += DFS(i+1,j,grid);
    }
    if (j + 1 < grid[i].size())
    {
      ans += DFS(i,j + 1,grid);
    }
    return ans;
  }

 private:
  std::set<std::pair<int,int>> mapped;
};