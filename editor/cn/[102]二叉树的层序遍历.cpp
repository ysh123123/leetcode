//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[9,20],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 1950 👎 0


#include <queue>
#include <vector>
#include <wchar.h>
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.*/
  /*struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };*/
 /**/
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
       std::queue<TreeNode*> tmp;
        if(root !=nullptr) tmp.push(root);//NOTE:要注意为空的情况
        std::vector<int> vec;
        std::vector<std::vector<int>> result;
        while (!tmp.empty())
        {
            auto size = tmp.size();
            vec.clear();
            while (size--)
            {
                auto cur = tmp.front();
                tmp.pop();
                vec.push_back(cur->val);
                if(cur->left!=nullptr) tmp.push(cur->left);
                if(cur->right!=nullptr) tmp.push(cur->right);
            }
            result.push_back(vec);
         }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
