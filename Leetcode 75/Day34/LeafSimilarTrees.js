var leafSimilar = function(root1, root2) {
    const collectLeafValues = (root, leafValues) => {
        if (!root) {
            return;
        }
        if (!root.left && !root.right) {
            leafValues.push(root.val);
        }
        collectLeafValues(root.left, leafValues);
        collectLeafValues(root.right, leafValues);
    };

    const leafValues1 = [];
    const leafValues2 = [];
    collectLeafValues(root1, leafValues1);
    collectLeafValues(root2, leafValues2);

    return JSON.stringify(leafValues1) === JSON.stringify(leafValues2);
};
/*C++
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
 /*
class Solution {
    public:
        void inOrder(TreeNode* root, string& s){
            if (root==NULL) return;
            //leaf node
            if(root->left == NULL && root->right == NULL){
                s += to_string(root-> val)+"_";
                return; 
            }
            inOrder(root->left, s);
            inOrder(root->right,s);
        }    
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            string s1 = "";
            string s2 = "";

            inOrder(root1, s1);
            inOrder(root2, s2);

            return s1==s2;
        }
};
*/