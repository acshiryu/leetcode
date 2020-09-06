//
// Created by hzl on 2020/9/6.
//

#include <include/cplusplus.h>

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;

        using TreeNodeLevel = pair<TreeNode*, int>;
        queue<TreeNodeLevel> q;
        q.emplace(root, 0);
        while (!q.empty()){
            auto [t, l] = q.front();
            q.pop();
            if (t){
                result.resize(l + 1);
                result[l].push_back(t->val);
                q.emplace(t->left, l + 1);
                q.emplace(t->right, l+ 1);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

};