/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */class Codec {
public:


    void serializeHelper(TreeNode* root, string& ans) {

        if (root == NULL) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        serializeHelper(root->left, ans);
        serializeHelper(root->right, ans);
    }

    string serialize(TreeNode* root) {

        string ans;

        serializeHelper(root, ans);

        return ans;
    }


  
    TreeNode* deserializeHelper(stringstream& ss) {

        string value;

        getline(ss, value, ',');

        if (value == "N") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return deserializeHelper(ss);
    }
};