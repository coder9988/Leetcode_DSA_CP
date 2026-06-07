// Last updated: 6/7/2026, 10:13:48 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right)
10 *         : val(x), left(left), right(right) {}
11 * };
12 */
13class Solution {
14public:
15    TreeNode* createBinaryTree(vector<vector<int>>& des) {
16        unordered_map<int, TreeNode*> mp;
17        unordered_set<int> children;
18
19        for (auto &d : des) {
20            int p = d[0];
21            int c = d[1];
22            int isLeft = d[2];
23            if (mp.find(p) == mp.end()) {
24                mp[p] = new TreeNode(p);
25            }
26            if (mp.find(c) == mp.end()) {
27                mp[c] = new TreeNode(c);
28            }
29            if (isLeft == 1)
30                mp[p]->left = mp[c];
31            else
32                mp[p]->right = mp[c];
33            children.insert(c);
34        }
35
36        for (auto &it : mp) {
37            if (children.find(it.first) == children.end()) {
38                return it.second;
39            }
40        }
41
42        return nullptr; 
43    }
44};