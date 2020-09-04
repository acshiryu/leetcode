//
// Created by hzl on 2020/9/4.
//
#include <include/cplusplus.h>

class Solution
{
 public:
  vector<string> binaryTreePaths(TreeNode *root)
  {


    if (root == nullptr) {
      return {};
    }

    path.clear();
    paths.clear();

    path.append(to_string(root->val));
    next(root);

    return paths;
  }

  void next(TreeNode *root)
  {
    if (root->left == nullptr && root->right == nullptr){
      paths.push_back(path);
      return;
    }

    if (root->left)
    {
      auto size = path.size();
      path.append("->").append(to_string(root->left->val));
      next(root->left);
      path.erase(size, std::string::npos);
    }


    if (root->right)
    {
      auto size = path.size();
      path.append("->").append(to_string(root->right->val));
      next(root->right);
      path.erase(size, std::string::npos);
    }
  }

 private:
  string path;
  vector<string> paths;
};
