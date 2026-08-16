// Last updated: 8/16/2026, 2:24:24 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* invertTree(TreeNode* root) {
15        if(root == nullptr)
16        {
17            return root;
18        }
19        TreeNode* temp = root;
20        root->left = invertTree(root->left);
21        root->right = invertTree(root->right);
22        swap(temp->left,temp->right);
23        return temp;
24    }
25};