//给定一个非空二叉树的根节点
// root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10⁻⁵ 以内的答案可以被接受。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[3.00000,14.50000,11.00000]
//解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
//因此返回 [3, 14.5, 11] 。
// 
//
// 示例 2: 
//
// 
//
// 
//输入：root = [3,9,20,15,7]
//输出：[3.00000,14.50000,11.00000]
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 树中节点数量在 [1, 10⁴] 范围内 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 484 👎 0


#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> tmp;
        std::vector<double> vec;
        std::vector<double> result;
        if(root!=nullptr)tmp.push(root);
        auto compute_mean = [&]()
        {
            double mean = 0;
            for(const auto& a:vec)
            {
                mean += a;
            }
            return mean/vec.size();
        };
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
            result.push_back(compute_mean());
        }
        // std::reverse(result.begin(),result.end());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
