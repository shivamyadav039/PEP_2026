https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1 ; 
        int mask = (1 << (32 - __builtin_clz(n))) - 1; 
        return n ^ mask ;
    }
};


https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/description/?envType=daily-question&envId=2026-03-12


class DSU {
public:
    vector<int> p, r;
    DSU(int n) {
        p.resize(n);
        r.assign(n, 0);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(r[a] < r[b]) swap(a, b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& e, int k) {
        sort(e.begin(), e.end(), [](auto &a, auto &b){
            return a[3] == b[3] ? a[2] > b[2] : a[3] > b[3];
        });

        DSU d(n);
        vector<int> extra;
        int used = 0, ans = INT_MAX;

        for(auto &x : e) {
            int u = x[0], v = x[1], w = x[2], req = x[3];

            if(req) {
                if(!d.unite(u, v)) return -1;
                ans = w;
                used++;
            } 
            else if(d.unite(u, v)) {
                extra.push_back(w);
                used++;
            }

            if(used == n - 1) break;
        }

        if(used != n - 1) return -1;
        if(extra.empty()) return ans;

        int m = extra.size();
        if(m > k) return min({extra[m - k - 1], 2 * extra.back(), ans});
        return min(2 * extra.back(), ans);
    }
};
https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13

class Solution {
public:
    inline static long long f(long long t, vector<int>& workerTimes){
        long long x=0;
        for(int w: workerTimes)
            x+=(long long)((sqrt(1+8.0*t/w)-1)/2);
        return x;
    }
    static long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int wz=workerTimes.size();
        if (wz==1)
            return (long long)workerTimes[0]*mountainHeight*(mountainHeight+1)/2;
        long long l=1, r=1e12*(long long)mountainHeight/wz;
        while(l<r){
            long long m=l+(r-l)/2;
            long long x=f(m, workerTimes);
            if(x>=mountainHeight) r=m;
            else l=m+1;
        }
        return l;
    }
};


https://leetcode.com/problems/fancy-sequence/description/?envType=daily-question&envId=2026-03-15


class Fancy {
public:
    const long MOD = 1e9+7;
    vector<long> raw;
    long mult=1, add=0;

    long modinv(long x){
        long res=1,p=MOD-2;
        while(p){
            if(p&1) res=res*x%MOD;
            x=x*x%MOD;
            p>>=1;
        }
        return res;
    }

    void append(int val){
        long base=(val-add)%MOD;
        base=base*modinv(mult)%MOD;
        raw.push_back((base+MOD)%MOD);
    }

    void addAll(int inc){
        add=(add+inc)%MOD;
    }

    void multAll(int m){
        mult=mult*m%MOD;
        add=add*m%MOD;
    }

    int getIndex(int idx){
        if(idx>=raw.size()) return -1;
        return (raw[idx]*mult+add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */




 https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/?envType=daily-question&envId=2026-03-16



 class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // size 0 rhombus
                st.insert(grid[i][j]);

                for(int k = 1; ; k++) {

                    int r = i + 2*k;
                    int left = j - k;
                    int right = j + k;

                    if(r >= m || left < 0 || right >= n) break;

                    int sum = 0;

                    int x = i, y = j;

                    // top -> right
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + t][y + t];
                    }

                    // right -> bottom
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k + t][y + k - t];
                    }

                    // bottom -> left
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + 2*k - t][y - t];
                    }

                    // left -> top
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k - t][y - k + t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) {
            ans.push_back(*it);
        }

        return ans;
    }
};


https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2026-03-17

class Solution {
public:  
    static int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m=matrix.size(), n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        if (m==1) return area;
        if (n==1){
            for(int i=1; i<m; i++){
                matrix[i][0]+=matrix[i][0]*matrix[i-1][0];
                area=max(area, matrix[i][0]);
            }
            return area;
        }
        
        for(int i=1; i<m; i++){
            for(int j=0;  j<n; j++){
                matrix[i][j]+=matrix[i][j]*matrix[i-1][j];
            }
            const auto& row=matrix[i];
            int minH=i+1, maxH=0;
            for(int x: row){
                minH=min(minH, x);
                maxH=max(maxH, x);
            }
            vector<int> freq(maxH-minH+1, 0);
            for(int x: row){
                freq[x-minH]++;
            }
            int acc=0;
            for(int x=maxH-minH; acc<n; x--){
                if (freq[x]>0){
                    acc+=freq[x];
                    area=max(area, acc*(x+minH));
                }
            }  
        }
        return area;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();