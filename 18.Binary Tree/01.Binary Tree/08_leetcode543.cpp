// 453-Diameter of BT
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
class Solution {
public:
    int level(TreeNode* root){  // finding levels
        if(root==NULL) return 0;
        return 1+ max(level(root->left),level(root->right));
    }
    int helper(TreeNode* root, int &maxdia){      //
        if(root==NULL) return 0;
        int diameter=level(root->left)+level(root->right);  // make diameter
        maxdia=max(diameter,maxdia);  // which is greater
        helper(root->left,maxdia);   // recursive call
        helper(root->right,maxdia);
        return maxdia;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=0;
        return helper(root,maxdia);
    }
};
 