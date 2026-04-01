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


https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/?envType=daily-question&envId=2026-03-20


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i <= n - k; i++) {
            map<int, int> mp;
            for (int r = i; r < i + k; r++) {
                for (int c = 0; c < k; c++) {
                    mp[grid[r][c]]++;
                }
            }
            for (int c = 0; c <= m - k; c++) {
                if (mp.size() > 1) {
                    int mini = 1e9;
                    auto it = mp.begin();
                    int prev = it->first;
                    for (++it; it != mp.end(); it++) {
                        mini = min(mini, abs(it->first - prev));
                        prev = it->first;
                    }
                    ans[i][c] = mini;
                } else {
                    ans[i][c] = 0;
                }

                if (c < m - k) {
                    for (int r = i; r < i + k; r++) {
                        mp[grid[r][c]]--;
                        if (mp[grid[r][c]] == 0)
                            mp.erase(grid[r][c]);
                        mp[grid[r][c + k]]++;
                    }
                }
            }
        }
        return ans;
    }
};
https://leetcode.com/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21


class Solution {
public:
    static vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int t=x, b=x+k-1; t<b; t++, b--){
            for(int j=y; j<y+k; j++)
                swap(grid[t][j], grid[b][j]);
        }
        return grid;
    }
};


https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/submissions/1955643538/?envType=daily-question&envId=2026-03-22


class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};


https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23

class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<ll>>dp_max(n,vector<ll>(m,0));
        vector<vector<ll>>dp_min(n,vector<ll>(m,0));
        dp_max[0][0]=dp_min[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp_min[i][0]=dp_max[i][0]=dp_max[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            dp_min[0][i]=dp_max[0][i]=dp_max[0][i-1]*grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ll a=dp_min[i-1][j]*grid[i][j];
                ll b=dp_max[i-1][j]*grid[i][j];
                ll c=dp_min[i][j-1]*grid[i][j];
                ll d=dp_max[i][j-1]*grid[i][j];
                dp_min[i][j]=min({a,b,c,d});
                dp_max[i][j]=max({a,b,c,d});
            }
        }
        if(dp_max[n-1][m-1]<0)return -1;
        return dp_max[n-1][m-1]%mod;
    }
};

https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long total = 0;

        // Compute rowSum, colSum, total
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        if (total % 2) return false;

        if (check(rowSum, total)) return true;

        if (check(colSum, total)) return true;

        return false;
    }

    bool check(vector<long long>& arr, long long total) {
        long long left = arr[0];
        long long right = total - left;

        for (int i = 1; i < arr.size(); i++) {
            if (left == right) return true;
            else if(left>right) return false;
            left += arr[i];
            right -= arr[i];
        }
        
        return false;
    }
};

https://leetcode.com/problems/equal-sum-grid-partition-ii/description/?envType=daily-question&envId=2026-03-26


class Solution {
public:
    typedef long long ll;
    bool solve(vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        ll bottomSum=0,topSum=0;
        vector<int>bottomFreq(100001,0),topFreq(100001,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bottomSum+=grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }
        for(int i=0;i<n-1;i++){
           for(int j=0;j<m;j++){
                bottomSum-=grid[i][j];
                bottomFreq[grid[i][j]]--;
                topSum+=grid[i][j];
                topFreq[grid[i][j]]++;
           }
           if(topSum==bottomSum)return true;
           ll diffTop=topSum-bottomSum;
           if(diffTop>0 && diffTop<=100000){
              int h=i+1,w=m;
              if(h>1 && w>1){
                if(topFreq[diffTop])return true;
                }
                else if(h>1 && w==1){
                    if(grid[0][0]==diffTop || grid[i][0]==diffTop)return true;
                }else if(h==1 && w>1){
                    if(grid[0][0]==diffTop || grid[0][w-1]==diffTop)return true;
                }
           }
           ll diffBot=bottomSum-topSum;
           if(diffBot>0 && diffBot<=100000){
            int h=(n-i-1),w=m;
            if(h>1 && w>1){
                if(bottomFreq[diffBot])return true;
            }else if(h>1 && w==1){
                if(grid[i+1][0]==diffBot || grid[n-1][0]==diffBot)return true;
            }else if(h==1 && w>1){
                if(grid[n-1][0]==diffBot || grid[n-1][w-1]==diffBot)return true;
            }
           }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid))return true;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[j][i]=grid[i][j];
            }
        }
        return solve(mat);
    }
};

https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;  //(reduce k<n)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // even row , left rotate
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } else {
                    // odd row , right rotate
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};

https://leetcode.com/problems/find-the-string-with-lcp/description/?envType=daily-question&envId=2026-03-28

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char current = 'a';

        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return word;
    }
};


https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // As the length is 4 we can only swap indexes 0 <-> 2 and 1 <-> 3

        // If char at index 0 doesn't match swap with index 2
        if(s1[0] != s2[0]) swap(s1[0], s1[2]);

        // If char at index 1 doesn't match swap with index 3
        if(s1[1] != s2[1]) swap(s1[1], s1[3]);

        // Check strings are equal or not
        return s1 == s2;
    }
};


https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26, 0), odd(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            if(i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};

https://leetcode.com/problems/lexicographically-smallest-generated-string/description/?envType=daily-question&envId=2026-03-31

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, 'a');
        vector<int> fixed(n + m - 1, 0);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (fixed[j] && s[j] != str2[j - i]) {
                        return "";
                    } else {
                        s[j] = str2[j - i];
                        fixed[j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool flag = false;
                int idx = -1;
                for (int j = i + m - 1; j >= i; j--) {
                    if (str2[j - i] != s[j]) {
                        flag = true;
                    }
                    if (idx == -1 && !fixed[j]) {
                        idx = j;
                    }
                }
                if (flag) {
                    continue;
                } else if (idx != -1) {
                    s[idx] = 'b';
                } else {
                    return "";
                }
            }
        }
        return s;
    }
};

https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2026-04-01



class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n) ;
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st;
        vector<bool> dead(n, false);

        for (int i : order) {
            if (directions[i] == 'R') {
                st.push(i) ;
            } else {
                while (!st.empty() && directions[st.top()] == 'R') {
                    int top = st.top();
                    if (healths[top] > healths[i]) {
                        healths[top]-- ;
                        dead[i] = true;
                        break;
                    } else if (healths[top] < healths[i]) {
                        healths[i]--;
                        dead[top] = true ;
                        st.pop();
                    } else {
                        dead[i] = true;
                        dead[top] = true ;
                        st.pop();
                        break;
                    }
                }
                if (!dead[i]) st.push(i);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (!dead[i]) result.push_back(healths[i]) ;

        return result;
    }
};