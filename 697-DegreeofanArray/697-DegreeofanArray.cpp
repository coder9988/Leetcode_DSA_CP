// Last updated: 3/24/2026, 12:31:27 AM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int buy = prices[0];
5        int price = 0;
6        for(int i = 0;i<prices.size();i++)
7        {
8            if(prices[i]<buy)
9            {
10                buy = prices[i];
11            }
12            price = max(prices[i]-buy,price);
13        }
14        return price;
15    }
16};