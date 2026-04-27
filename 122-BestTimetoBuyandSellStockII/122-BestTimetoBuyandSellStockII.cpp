// Last updated: 4/27/2026, 2:16:52 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int maxprofit = 0;
5        int buy = 0;
6        int sell = 1;
7        if(prices.size()==1)
8        {
9            return 0;
10        }
11        while(sell<prices.size())
12        {
13            int profit = prices[sell]-prices[buy];
14            if(profit<0)
15            {
16                buy = sell;
17                sell+=1;
18            }
19            else
20            {
21                maxprofit += profit;
22                buy += 1;
23                sell += 1;
24            }
25        }
26        return maxprofit;
27    }
28};