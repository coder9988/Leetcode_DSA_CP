// Last updated: 8/14/2026, 7:54:26 PM
1class Solution {
2public:
3void dfs(vector<vector<int>>& isConnected, int start, vector<int>& visited)
4{
5    visited[start] = 1;
6
7    for(int j = 0; j < isConnected.size(); j++)
8    {
9        if(isConnected[start][j] == 1 && !visited[j])
10        {
11            dfs(isConnected, j, visited);
12        }
13    }
14}
15    int findCircleNum(vector<vector<int>>& isConnected) {
16        vector<int> visited(isConnected.size(),0);
17        int province = 0;
18        for(int i= 0;i<isConnected.size();i++)
19        {
20            if(visited[i] == 0 )
21            {
22                    province+=1;
23                    dfs(isConnected,i,visited);
24            }
25        }
26        return province;
27    }
28};