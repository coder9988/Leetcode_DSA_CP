// Last updated: 7/2/2026, 10:56:16 PM
1const int N=5000;
2int q[N], front, back;// implement deque
3int maxH[N];
4int d[5]={0, 1, 0, -1, 0};
5class Solution {
6public:
7    static inline int idx(int i, int j, int c){ return i*c+j; }
8    static bool outSide(int i, int j, int r, int c){
9        return i<0||i>=r||j<0||j>=c;
10    }
11    static bool findSafeWalk(vector<vector<int>>& grid, int health) {
12        const int r=grid.size(), c=grid[0].size();
13        memset(maxH, -1, r*c*sizeof(int));
14        front=back=N/2;// reset q
15        q[back++]=0; 
16        maxH[0]=health-grid[0][0];
17        while(front<back){
18            int ij=q[front++];// pop front
19            int curH=maxH[ij];
20            if (ij==r*c-1) return curH>0;
21            auto [i, j]=div(ij, c);
22            for(int a=0; a<4; a++){
23                const int s=i+d[a], t=j+d[a+1];
24                if (outSide(s, t, r, c)) continue;
25                const int st=idx(s,t, c);
26                int H2=curH-grid[s][t];
27                if(H2>maxH[st]){
28                    maxH[st]=H2;
29                    if (grid[s][t]==0) q[--front]=st;
30                    else q[back++]=st;
31                }
32            }
33        }
34        return 0;
35    }
36};