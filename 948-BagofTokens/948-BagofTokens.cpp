// Last updated: 3/18/2026, 12:17:44 AM
1class Solution {
2public:
3    int bagOfTokensScore(vector<int>& tokens, int power) {
4        int i = 0;
5        int j = tokens.size() - 1;
6        sort(begin(tokens),end(tokens));
7        int maxScore = 0;
8        int score = 0;
9        while (i <= j) {
10            if (power >= tokens[i]) {
11                score += 1;
12                power -= tokens[i];
13                i++;
14
15                 maxScore = max(score, maxScore);
16            } else if (score >= 1) {
17                power += tokens[j];
18                score -= 1;
19                j--;
20
21            } else {
22                return maxScore;
23            }
24           
25        }
26        return maxScore;
27    }
28};