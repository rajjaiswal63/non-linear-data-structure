// same tree 

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
    bool isSame(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true;  // base cases
        if(p!=NULL and q==NULL) return false;
        if(p==NULL and q!=NULL) return false;

        if(p->val != q->val) return false;   // checking root

        bool left = isSame(p->left,q->left); // checking leftsubtree
        if(left==false) return false;

        bool right=isSame(p->right,q->right);  // checking rightsubtree
        if(right==false) return false;

        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};