// Last updated: 6/30/2026, 2:19:56 AM
1class Solution {
2public:
3    void dfs(vector<bool> &visited,vector<vector<int>>& isConnected,int city)
4    {
5        visited[city] = true;
6        for(int i = 0;i<isConnected.size();i++)
7        {
8            if(isConnected[city][i] == 1 && !visited[i])
9            {
10                visited[city] = true;
11                dfs(visited,isConnected,i);
12            }
13        }
14    }
15    int findCircleNum(vector<vector<int>>& isConnected) {
16        int province = 0;
17        int n = isConnected.size();
18        vector<bool> visited(n,false);
19        for(int i = 0;i<n;i++)
20        {
21            if(!visited[i])
22            {
23                dfs(visited,isConnected,i);
24                province++;
25            }
26        }
27        return province;
28    }
29};