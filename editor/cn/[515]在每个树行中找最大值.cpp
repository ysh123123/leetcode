//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。 
//
// 
//
// 示例1： 
//
// 
//
// 
//输入: root = [1,3,2,5,3,null,9]
//输出: [1,3,9]
// 
//
// 示例2： 
//
// 
//输入: root = [1,2,3]
//输出: [1,3]
// 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点个数的范围是 [0,10⁴] 
// 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 363 👎 0


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
    std::vector<int> largestValues(TreeNode* root) {
       std::queue<TreeNode*> tmp;
        if(root!=nullptr) tmp.push(root);
        std::vector<int> result,vec;
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
                if(cur->right!=nullptr) tmp.push(cur->right);
            }
            result.push_back(std::move(*std::max_element(vec.begin(),vec.end())));
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
