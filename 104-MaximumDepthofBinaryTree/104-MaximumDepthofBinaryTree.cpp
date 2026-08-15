// Last updated: 8/15/2026, 6:23:09 PM
1
2class Solution {
3public:
4    int solve(TreeNode*& root) {
5        int ans = 0;
6        queue<TreeNode*> q;
7        q.push(root);
8
9        while (!q.empty()) {
10            int levelSize = q.size();
11            ans += 1;
12            for (int i = 0; i < levelSize; i++) {
13                TreeNode* node = q.front();
14                q.pop();
15
16                cout << node->val << " ";
17
18                if (node->left)
19                    q.push(node->left);
20
21                if (node->right)
22                    q.push(node->right);
23            }
24        }
25        return ans;
26    }
27    int maxDepth(TreeNode* root) {
28        // int ans = 0;
29        if(root==nullptr)
30        {
31            return 0;
32        }
33        int ans = solve(root);
34        return ans;
35    }
36};