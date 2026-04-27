// Last updated: 4/27/2026, 3:32:04 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int profit = 0;
5
6        for(int i = 1; i < prices.size(); i++)
7        {
8            if(prices[i] > prices[i-1])
9            {
10                profit += prices[i] - prices[i-1];
11            }
12        }
13
14        return profit;
15    }
16};