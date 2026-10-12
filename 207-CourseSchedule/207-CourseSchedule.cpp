// Last updated: 10/12/2026, 11:02:28 PM
1class Solution {
2private:
3    bool dfs(vector<vector<int>>& dg, int node, vector<bool>& vis,  vector<bool>& currPath ){
4        if(currPath[node]) return true;
5        if(vis[node]) return false;
6
7        vis[node] = true;
8        currPath[node] = true;
9
10        for(int i : dg[node]){
11            if(dfs(dg, i, vis, currPath)){
12                return true;
13            }
14        }
15
16        currPath[node] = false;
17        return false;
18    }
19public:
20    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
21        vector<vector<int>> dg(numCourses);
22        vector<bool> vis(numCourses, false);
23        vector<bool> currPath(numCourses, false);
24
25        for(auto prerequisite : prerequisites){
26           dg[prerequisite[0]].push_back(prerequisite[1]);
27        }
28
29        for(int i =0;i<numCourses;i++){
30            if(!vis[i] && dfs(dg, i, vis, currPath)){
31                return false;
32            }
33        }
34        return true;
35    }
36};