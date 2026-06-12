# Last updated: 6/13/2026, 1:58:29 AM
1import numpy as np
2import collections
3import sys
4
5class Solution:
6    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
7        n = len(edges) + 1
8        MOD = 10**9 + 7
9        LOG_N = 18 
10
11        # 1. Ultra-fast flat list adjacency structure
12        adj = [[] for _ in range(n + 1)]
13        for u, v in edges:
14            adj[u].append(v); adj[v].append(u)
15
16        up = [[0] * LOG_N for _ in range(n + 2)]
17        depth = [0] * (n + 2)
18
19        # 2. Iterative BFS Queue (Replaces slow recursion)
20        # Element format: (current_node, parent_node, current_depth)
21        queue = collections.deque([(1, 0, 0)])
22        visited = [False] * (n + 1)
23        visited[1] = True
24
25        while queue:
26            node, parent, d = queue.popleft()
27            depth[node] = d
28            up[node][0] = parent
29            
30            for neighbor in adj[node]:
31                if not visited[neighbor]:
32                    visited[neighbor] = True
33                    queue.append((neighbor, node, d + 1))
34
35        # 3. Compute Binary Lifting Matrix 
36        for j in range(1, LOG_N):
37            for i in range(1, n + 1):
38                prev = up[i][j-1]
39                up[i][j] = up[prev][j-1] if prev != 0 else 0
40
41        # =========================================================================
42        # VECTORIZED VECTOR MATRIX PROCESSING
43        # =========================================================================
44        depth_np = np.array(depth, dtype=np.int32)
45        up_np = np.array(up, dtype=np.int32)
46        queries_np = np.array(queries, dtype=np.int32)
47
48        u, v = queries_np[:, 0], queries_np[:, 1]
49        orig_u, orig_v = u.copy(), v.copy()
50
51        # Step A: Leveling
52        swap_mask = depth_np[u] < depth_np[v]
53        u[swap_mask], v[swap_mask] = v[swap_mask], u[swap_mask]
54
55        diff = depth_np[u] - depth_np[v]
56        for j in range(LOG_N):
57            jump_mask = (diff >> j) & 1 == 1
58            u[jump_mask] = up_np[u[jump_mask], j]
59
60        # Step B: Climbing
61        for j in range(LOG_N - 1, -1, -1):
62            jump_mask = (u != v) & (up_np[u, j] != up_np[v, j])
63            u[jump_mask] = up_np[u[jump_mask], j]
64            v[jump_mask] = up_np[v[jump_mask], j]
65
66        lca = u.copy()
67        not_equal_mask = (u != v)
68        lca[not_equal_mask] = up_np[u[not_equal_mask], 0]
69
70        # Step C: Combinatorial Parity math
71        path_lengths = depth_np[orig_u] + depth_np[orig_v] - 2 * depth_np[lca]
72        
73        # Optimized lookup approach: precompute powers array using NumPy vectorization
74        pow2 = np.zeros(n + 2, dtype=np.int64)
75        pow2[0] = 1
76        for i in range(1, n + 2):
77            pow2[i] = (pow2[i-1] * 2) % MOD
78
79        # Direct NumPy index extraction (Avoids slower element-by-element lambda maps)
80        ans = np.where(path_lengths == 0, 0, pow2[(path_lengths - 1).astype(np.int32)])
81
82        return ans.tolist()