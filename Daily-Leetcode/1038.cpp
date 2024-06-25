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
    void convertTreeWithoutSum(TreeNode* &root, int &sum){
        if(root == NULL) return;
        convertTreeWithoutSum(root -> right, sum);
        int currNodeVal = root -> val;
        root -> val += sum;
        sum += currNodeVal;
        convertTreeWithoutSum(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        convertTreeWithoutSum(root, sum);
        return root;
    }
};