// Last updated: 6/25/2026, 2:11:34 AM
1constexpr int mod = 1e9 + 7;
2// using 1D vector to denote the compressed form: a[i*m+j]=m[i][j]
3using matrix=vector<int>;
4static int m;
5static inline matrix operator*(const matrix& A, const matrix& B) {
6    // all matrix size m*m
7    matrix C(m*m, 0);
8    for (int i = 0; i < m; i++) {
9        for (int k = 0; k < m; k++) {
10            if (A[i*m+k] == 0) continue;
11            for (int j = 0; j < m; j++) {
12                C[i*m+j] = (C[i*m+j] + 1LL * A[i*m+k] * B[k*m+j]) % mod;
13            }
14        }
15    }
16    return C;
17}
18static matrix I(){
19    matrix ans(m*m, 0);
20    for(int i=0; i<m; i++)
21        ans[i*m+i]=1;
22    return ans;
23}
24// MSBF modular Matrix Exponentiation
25static matrix pow(const matrix& M, unsigned m) {
26    if (m == 0)
27        return I();
28    int bMax = 31 - __builtin_clz(m);
29    matrix ans = M;
30    for (int i = bMax - 1; i >= 0; i--) {
31        ans = ans * ans;
32        if ((m>>i)&1)
33            ans = ans * M;
34    }
35    return ans;
36}
37
38class Solution {
39public:
40    static int zigZagArrays(int n, int l, int r) {
41        m=r-l+1;
42        matrix U(m*m, 0), L(m*m, 0);
43        for(int i=0; i<m; i++){
44            for(int j=i+1; j<m; j++) U[i*m+j]=1;
45        }
46        for(int i=0; i<m; i++){
47            for(int j=0; j<i; j++) L[i*m+j]=1;
48        }
49        n--;
50        const int n0=n>>1;
51        const matrix UL=U*L;
52        matrix P=pow(UL, n0);
53        if (n&1) P=L*P;
54        return 2LL*reduce(P.begin(), P.end(), 0LL)%mod;
55    }
56};
57auto init = []() {
58    ios::sync_with_stdio(false);
59    cin.tie(nullptr);
60    cout.tie(nullptr);
61    return 'c';
62}();