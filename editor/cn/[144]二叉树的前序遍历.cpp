//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
// 
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 示例 5： 
// 
// 
//输入：root = [1,null,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1245 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.*/
#include <stack>
#include <vector>
  /*struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };*/

class Solution {
public:
    void Traversal(TreeNode* node,std::vector<int> &result)
    {
        if(node==nullptr) return;
        result.emplace_back(node->val);
        Traversal(node->left,result);
        Traversal(node->right,result);
    }
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> temp;
        // Traversal(root,result);
        temp.push(root);
        while(!temp.empty())
        {
            auto cur = temp.top();
            temp.pop();
            if(cur !=nullptr)
            {
                result.push_back(cur->val);
                // temp.pop();
                temp.push(cur->right);
                temp.push(cur->left);
            }
            // else
            // {
            //     // temp.pop();
            //     // continue;
            // }
        }
        return result;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
