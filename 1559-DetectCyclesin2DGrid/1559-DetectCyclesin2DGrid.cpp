// Last updated: 4/26/2026, 5:12:39 PM
1class Solution {
2public:
3    bool bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
4        int n = grid.size();
5        int m = grid[0].size();
6
7        queue<pair<pair<int,int>, pair<int,int>>> q;
8        q.push({{i,j}, {-1,-1}});
9        visited[i][j] = true;
10
11        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
12
13        while(!q.empty()) {
14            auto curr = q.front(); q.pop();
15
16            int x = curr.first.first;
17            int y = curr.first.second;
18            int px = curr.second.first;
19            int py = curr.second.second;
20
21            for(auto &d : dirs) {
22                int nx = x + d[0];
23                int ny = y + d[1];
24
25                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
26
27                if(grid[nx][ny] != grid[x][y]) continue;
28
29                if(nx == px && ny == py) continue;
30
31                if(visited[nx][ny]) return true;
32
33                visited[nx][ny] = true;
34                q.push({{nx, ny}, {x, y}});
35            }
36        }
37        return false;
38    }
39
40    bool containsCycle(vector<vector<char>>& grid) {
41        int n = grid.size();
42        int m = grid[0].size();
43
44        vector<vector<bool>> visited(n, vector<bool>(m, false));
45
46        for(int i = 0; i < n; i++) {
47            for(int j = 0; j < m; j++) {
48                if(!visited[i][j]) {
49                    if(bfs(i, j, grid, visited)) {
50                        return true;
51                    }
52                }
53            }
54        }
55        return false;
56    }
57};