// Last updated: 6/14/2026, 12:09:07 AM
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string ans;
5
6        for (string& word : words) {
7            long long sum = 0;
8
9            for (char ch : word) {
10                sum += weights[ch - 'a'];
11            }
12
13            ans.push_back('z' - (sum % 26));
14        }
15
16        return ans;
17    }
18};