//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[15,7],[9,20],[3]]
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
// Related Topics 树 广度优先搜索 二叉树 👍 792 👎 0


#include <algorithm>
#include <queue>
#include <vector>
#include <wchar.h>
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
       std::queue<TreeNode*> tmp;
        std::vector<int> vec;
        std::vector<std::vector<int>> result;
        if(root!=nullptr)tmp.push(root);
        while (!tmp.empty())
        {
            int size = tmp.size();
            vec.clear();
            while (size--)
            {
                auto cur = tmp.front();
                tmp.pop();
                vec.push_back(cur->val);
                if(cur->left!=nullptr) tmp.push(cur->left);
                if(cur->right!=nullptr)tmp.push(cur->right);
            }
            result.push_back(vec);
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
