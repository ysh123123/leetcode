//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: [1,2,3,null,5,null,4]
//输出: [1,3,4]
// 
//
// 示例 2: 
//
// 
//输入: [1,null,3]
//输出: [1,3]
// 
//
// 示例 3: 
//
// 
//输入: []
//输出: []
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,100] 
// 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1060 👎 0


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
    std::vector<int> rightSideView(TreeNode* root) {
      std::queue<TreeNode*> tmp;
        if(root!=nullptr) tmp.push(root);
        std::vector<int> result;
        while(!tmp.empty())
        {
            // FAULT 中将右子节点放入队列中，没有考虑到右节点深度小于左节点时
            // FAULT 要获取左节点的信息，应该是获取每层最右边的数，而不是单纯存放右节点
            // auto cur = tmp.front();
            // tmp.pop();
            // result.push_back(cur->val);
            // if(cur->right!=nullptr) tmp.push(cur->right);
            // else if(cur->left!=nullptr)tmp.push(cur->left);
            int size = tmp.size();
            int most_right = 0;
            while(size--)
            {
                auto cur = tmp.front();
                tmp.pop();
                most_right = cur->val;
                if(cur->left!=nullptr) tmp.push(cur->left);
                if(cur->right!=nullptr) tmp.push(cur->right);
            }
            result.push_back(most_right);
        }
return result;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
