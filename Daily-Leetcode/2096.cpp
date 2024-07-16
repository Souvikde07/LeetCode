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
    TreeNode* lca(TreeNode* root, int startValue, int destValue) {
        if (!root)
            return NULL;
        if (root->val == startValue || root->val == destValue)
            return root;
        TreeNode* leftV = lca(root->left, startValue, destValue);
        TreeNode* rightV = lca(root->right, startValue, destValue);
        if (leftV && rightV)
            return root;
        return leftV ? leftV : rightV;
    }

    bool getPath(TreeNode* root, int searchValue, string &path) {
        if (!root)
            return false;
        if (root->val == searchValue)
            return true;
        path.push_back('L');
        if (getPath(root->left, searchValue, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if (getPath(root->right, searchValue, path))
            return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lca(root, startValue, destValue);
        string pathToStart = "", pathToDest = "";
        getPath(lcaNode, startValue, pathToStart);
        getPath(lcaNode, destValue, pathToDest);
        for (int i = 0; i < pathToStart.size(); ++i) {
            pathToStart[i] = 'U';
        }
        return pathToStart + pathToDest;
    }
};
