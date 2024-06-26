//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
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
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 2067 👎 0


#include <stack>
#include <vector>
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.*/
  // struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  // };

class Solution {
public:
    void Traversal(TreeNode *node,std::vector<int> &result)
    {
        if(node==nullptr) return;
        Traversal(node->left,result);
        result.emplace_back(node->val);
        Traversal(node->right,result);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        // Traversal(root,result);
        std::stack<TreeNode*> temp;
        auto cur = root;
        while (cur!=nullptr||!temp.empty())
        {
            if(cur!=nullptr)
            {
                temp.push(cur);
                cur = cur->left;
            }else
            {
                cur = temp.top();
                result.push_back(cur->val);
                temp.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
