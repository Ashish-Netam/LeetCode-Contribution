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
 */class Solution {
public:

    TreeNode* markparents(
        TreeNode* root,
        int target,
        unordered_map<TreeNode*, TreeNode*>& parent
    ) {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* targetNode = nullptr;

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            if (current->val == target) {
                targetNode = current;
            }

            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }

        return targetNode;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* targetNode =
            markparents(root, start, parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {

                TreeNode* current = q.front();
                q.pop();

            
                if (current->left &&
                    !visited[current->left]) {

                    visited[current->left] = true;
                    q.push(current->left);
                    burned = true;
                }

                if (current->right &&
                    !visited[current->right]) {

                    visited[current->right] = true;
                    q.push(current->right);
                    burned = true;
                }

          
                if (parent[current] &&
                    !visited[parent[current]]) {

                    visited[parent[current]] = true;
                    q.push(parent[current]);
                    burned = true;
                }
            }

            if (burned) {
                time++;
            }
        }

        return time;
    }
};