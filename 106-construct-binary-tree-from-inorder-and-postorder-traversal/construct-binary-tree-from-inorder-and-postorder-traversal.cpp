/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.size() != postorder.size()) {
            return NULL;
        }

        map<int, int> hm;

        for (int i = 0; i < postorder.size(); i++) {
            hm[inorder[i]] = i;
        }
        return BuildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, hm);
    }

    TreeNode* BuildTreePostIn(vector<int>& inorder, int is, int ie,
                              vector<int>& postorder, int ps, int pe,
                              map<int, int>& hm) {

        if (ps > pe || is > ie) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);

        int InRoot = hm[postorder[pe]];
        int numsLeft = InRoot - is;

        root->left = BuildTreePostIn(inorder, is, InRoot - 1, postorder, ps,
                                     ps + numsLeft - 1, hm);

        root->right = BuildTreePostIn(inorder, InRoot + 1, ie, postorder,
                                      ps + numsLeft, pe - 1, hm);

        return root;
    }
};