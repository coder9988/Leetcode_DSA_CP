// Last updated: 7/22/2026, 10:19:36 PM
1class SegmentTree {
2public:
3    int n;
4    vector<int> arr,seg;
5    SegmentTree(vector<int> &nums) {
6        n=nums.size();
7        arr=nums;
8        seg.assign(4 * max(1,n),0);
9        if(n) build(1,0,n-1);
10    }
11    void build(int node, int l, int r) {
12        if(l==r){
13            seg[node]=arr[l];
14            return;
15        }
16        int mid=(l+r) >> 1;
17        build(node*2,l,mid);
18        build(node*2+1,mid+1,r);
19        seg[node]=max(seg[node*2],seg[node*2+1]);
20    }
21    int internalQuery(int node, int st, int en, int l, int r) {
22        if(l<=st && en<=r) return seg[node];
23        int mid=(st+en) >> 1;
24        int res=0;
25        if(mid>=l) res=max(res,internalQuery(node*2,st,mid,l,r));
26        if(r>mid) res=max(res,internalQuery(node*2+1,mid+1,en,l,r));
27        return res;
28    }
29    int query(int l, int r) {
30        if(l>r || n==0) return 0;
31        return internalQuery(1,0,n-1,l,r);
32    }
33};
34class Solution {
35public:
36    int segsz=0;
37    int lowerBound(vector<int> &v, int x) {
38        int l=0,r=segsz;
39        while(l<r) {
40            int m=(l+r) >> 1;
41            if(v[m]>=x) r=m;
42            else l=m+1;
43        }
44        return l;
45    }
46    int upperBound(vector<int> &v, int x) {
47        int l=0,r=segsz;
48        while(l<r){
49            int m=(l+r) >>1;
50            if(v[m]<=x) l=m+1;
51            else r=m;
52        }
53        return l;
54    }
55    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &q) {
56        int n =s.size();
57        int cnt1=0;
58        for(char c: s)
59            if(c=='1')
60                cnt1++;
61        vector<int> zeroBlocks, zeroLeft, zeroRight;
62        int idx=0;
63        while(idx<n){
64            int r=idx;
65            while(r<n && s[idx]==s[r]) r++;
66            int len=r-idx;
67            if(s[idx]=='0'){
68                zeroBlocks.push_back(len);
69                zeroLeft.push_back(idx);
70                zeroRight.push_back(r-1);
71            }
72
73            idx=r;
74        }
75        int m=zeroBlocks.size();
76        segsz=m;
77
78        vector<int> ans;
79        if(m<=1){
80            for(int i=0;i<q.size();i++)
81                ans.push_back(cnt1);
82            return ans;
83        }
84        vector<int> nums(m-1);
85        for(int i=0;i<m-1;i++)
86            nums[i] = zeroBlocks[i]+zeroBlocks[i+1];
87        SegmentTree st(nums);
88        for(int i=0;i<q.size();i++){
89            int l=q[i][0],r=q[i][1];
90            int lidx=lowerBound(zeroRight,l);
91            int ridx=upperBound(zeroLeft,r)-1;
92            if(lidx>m-1 || ridx<0 || lidx>=ridx){
93                ans.push_back(cnt1);
94                continue;
95            }
96            int leftLen=zeroRight[lidx]-max(zeroLeft[lidx],l)+1;
97            int rightLen=min(r,zeroRight[ridx])-zeroLeft[ridx]+1;
98            if(lidx+1==ridx){
99                ans.push_back(cnt1+leftLen+rightLen);
100                continue;
101            }
102            int leftContri=leftLen+zeroBlocks[lidx+1];
103            int rightContri=rightLen+zeroBlocks[ridx-1];
104            int middleContri=st.query(lidx+1,ridx-2);
105            ans.push_back(cnt1+max(leftContri,max(rightContri, middleContri)));
106        }
107        return ans;
108    }
109};