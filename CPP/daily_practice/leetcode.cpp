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

https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02

class Solution {
public:

    const int inf = 1e9+7;

    int func(int i, int j, int rem, vector <vector<int>> &arr, vector <vector <vector <int>>> &dp) {
    int n = arr.size();
    int m = arr[0].size();
    if(dp[i][j][rem] != -inf) return dp[i][j][rem];
    if (i == n-1 && j == m-1) {
        if(arr[i][j] >= 0) {
            return arr[i][j];
        }
        else {
            if(rem > 0) {
                return 0;
            }
            else {
                return arr[i][j];
            }
        }
    }
    int ans = INT_MIN;
    if(arr[i][j] < 0) {
        if(rem-1 >=0) {
            if(i+1 < n) ans = max(ans,func(i+1,j,rem-1,arr,dp));
            if(j+1 < m) ans = max(ans,func(i,j+1,rem-1,arr,dp));
        }
        if(i+1 < n) ans = max(ans,arr[i][j]+func(i+1,j,rem,arr,dp));
        if(j+1 < m) ans = max(ans,arr[i][j]+func(i,j+1,rem,arr,dp));
    }
    else {
        if(i+1 < n) ans = max(ans,arr[i][j]+func(i+1,j,rem,arr,dp));
        if(j+1 < m) ans = max(ans,arr[i][j]+func(i,j+1,rem,arr,dp));
    }
    return dp[i][j][rem] = ans;
}
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3,-inf)));
        return func(0,0,2,coins,dp);
    }
};



https://leetcode.com/problems/maximum-walls-destroyed-by-robots/?envType=daily-question&envId=2026-04-03


class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& d, vector<int>& walls) {
        int n = robots.size();

        // Store robots as {position, distance}
        vector<array<int, 2>> x(n);
        for (int i = 0; i < n; i++) {
            x[i] = {robots[i], d[i]};
        }

        // Sort robots and walls to get everything in order
        sort(x.begin(), x.end());
        sort(walls.begin(), walls.end());

        // Dummy robot to avoid boundary checks
        x.push_back({(int)1e9, 0});

        // Function to count walls in range [l, r]
        auto query = [&](int l, int r) -> int {
            if (l > r) return 0;
            auto it1 = upper_bound(walls.begin(), walls.end(), r);
            auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return it1 - it2;
        };

        // dp[i][0] = i-th robot shoots LEFT
        // dp[i][1] = i-th robot shoots RIGHT
        vector<array<int, 2>> dp(n);

        // Base case (i = 0)- shooting left
        dp[0][0] = query(x[0][0] - x[0][1], x[0][0]);

        //shooting right
        if (n > 1) { 
            dp[0][1] = query(
                x[0][0],
                min(x[1][0] - 1, x[0][0] + x[0][1])
            );
        } else {
            dp[0][1] = query(x[0][0], x[0][0] + x[0][1]);
        }

        // DP transitions
        for (int i = 1; i < n; i++) {

            // Case 1: shoot RIGHT
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                       query(
                           x[i][0],
                           min(x[i + 1][0] - 1, x[i][0] + x[i][1])
                       );

            // Case 2: shoot LEFT (no overlap with previous LEFT)
            dp[i][0] = dp[i - 1][0] +
                       query(
                           max(x[i][0] - x[i][1], x[i - 1][0] + 1),
                           x[i][0]
                       );

            // Case 3: shoot LEFT but previous was RIGHT (handle overlap)
            int leftStart = max(x[i][0] - x[i][1], x[i - 1][0] + 1);
            int leftEnd   = x[i][0];

            int overlapStart = leftStart;
            int overlapEnd   = min(x[i - 1][0] + x[i - 1][1], x[i][0] - 1);

            int res = dp[i - 1][1]
                      + query(leftStart, leftEnd)
                      - query(overlapStart, overlapEnd);

            dp[i][0] = max(dp[i][0], res);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};


https://leetcode.com/problems/decode-the-slanted-ciphertext/?envType=daily-question&envId=2026-04-04


class Solution {
public:
    //approach 2
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) return "";
        
        int cols = len / rows;
        string ans = "";
        
        // Each diagonal starts at (0, j) where j is the column index
        for (int j = 0; j < cols; j++) {
            for (int r = 0, c = j; r < rows && c < cols; r++, c++) {
                // Map 2D coordinates (r, c) back to 1D index
                ans.push_back(encodedText[r * cols + c]);
            }
        }
        
        // Remove trailing spaces as per problem constraints
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};

https://leetcode.com/problems/robot-return-to-origin/description/?envType=daily-question&envId=2026-04-05

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char m : moves) {
            if (m == 'R') x++;
            else if (m == 'L') x--;
            else if (m == 'U') y++;
            else if (m == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};


https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (int i=0;i<queries.size();i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            ans ^= nums[i];
        }
        
        return ans;
    }
};

https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-11

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        
        int mini = INT_MAX;
        
        for(auto &it : mp){
            vector<int> &temp = it.second;
            int m = temp.size();
            
            if(m >= 3){
                for(int i = 0; i < m - 2; i++){
                    int a = temp[i];
                    int b = temp[i+1];
                    int c = temp[i+2];
                    
                    int diff = 2 * (c - a);
                    mini = min(mini, diff);
                }
            }
        }
        
        return mini == INT_MAX ? -1 : mini;
    }
};


https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==target){
                res = min(res,abs(i-start));
            }
        }
        return res;
        
    }
};

https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        for (int i = 0; i <= n >> 1; i++)
            if (words[(start + i) % n] == target |
                words[(start - i + n) % n] == target)
                return i;
                
        return -1;
    }
};

https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexMap;

        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }

        vector<int> answer;

        for (int q : queries) {
            vector<int>& indices = indexMap[nums[q]];

            if (indices.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            // Binary search for position of q in the sorted indices list
            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();
            int minDist = INT_MAX;

            // Check neighbor to the right (wrap around if needed)
            int rightIdx = indices[(pos + 1) % indices.size()];
            int d1 = abs(q - rightIdx);
            minDist = min(minDist, min(d1, n - d1));

            // Check neighbor to the left (wrap around if needed)
            int leftIdx = indices[(pos - 1 + indices.size()) % indices.size()];
            int d2 = abs(q - leftIdx);
            minDist = min(minDist, min(d2, n - d2));

            answer.push_back(minDist);
        }

        return answer;
    }
};

https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17


 class Solution {
public:
    int reverse(int val) {
        int newnum = 0;
        while (val != 0) {
            int x = val % 10;
            val /= 10;
            newnum = newnum * 10 + x;
        }
        return newnum;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mindist = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (mp.find(nums[i]) != mp.end()) {
                mindist = min(mindist, i - mp[nums[i]]);
            }
            int rev = reverse(nums[i]);
            mp[rev] = i;
        }
        return mindist == INT_MAX ? -1 : mindist;
    }
};

https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18

class Solution {
public:
    int mirrorDistance(int n) {
        int rev =0;
        int a = n;
        while(n>0){
            int re = n%10;
            rev = rev*10 + re;

            n=n/10;
        }
        return abs(a-rev);
        
    }
};

https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/?envType=daily-question&envId=2026-04-19


class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j - i);
                j++;
            }else{
                i++;
                if(i > j) j = i;
            }
        }

        return ans;
    }
};

https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/?envType=daily-question&envId=2026-04-21

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto& swap : allowedSwaps)
            unite(swap[0], swap[1]);

        // Group source values by their root
        unordered_map<int, unordered_map<int, int>> groupFreq;
        for (int i = 0; i < n; i++)
            groupFreq[find(i)][source[i]]++;

        int hammingDistance = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto& freq = groupFreq[root];
            if (freq.count(target[i]) && freq[target[i]] > 0)
                freq[target[i]]--;
            else
                hammingDistance++;
        }

        return hammingDistance;
    }
};

https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22


class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries[0].size();
        vector<string> ans;
        for(auto &it:queries){
            for(auto &i:dictionary){
                int diff=0;
                for(int idx=0; idx<n; idx++){
                    if(it[idx]!=i[idx]){
                        diff++;
                    }
                    if(diff>2) break;
                }
                if(diff<=2){
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};
https://leetcode.com/problems/furthest-point-from-origin/submissions/1987136244/?envType=daily-question&envId=2026-04-24


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blanks = 0;

        for (char c : moves) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else blanks++;
        }

        return abs(left - right) + blanks;
    }
};
https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/?envType=daily-question&envId=2026-04-25

class Solution {
public:
    typedef long long ll;

    bool Check(vector<ll>& res, int side, int k, int dist){
        int n = res.size();
        ll peri = 1ll*side*4;

        for(int i = 0; i < n; i++){
            ll curr = res[i];
            int count = 1;
            int lastIdx = i;

            while(count < k){
                // greedy find
                auto it = lower_bound(res.begin(), res.end(), curr + dist); // find next point with value >= curr+dist
                if(it == res.end()) break;

                lastIdx = it-res.begin();  // keeping track of last index i am at
                curr = *it; // value of currDistance
                count++; // number of nodes
            }

            if(count == k && peri - (res[lastIdx] - res[i]) >= dist){ // second condition is the wrap around, because we take first 4 points but didn't consider distance between last point and first point.. since it's a square so a wrap around will be there
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> res;

        // conversion to 1D .. basic intuition -> Aggressive cows in a circular graph
        for(auto &p : points){
            int x = p[0];
            int y = p[1];

            if(x == 0){
                res.push_back(y);
            } else if(y == side){
                res.push_back((ll)side + x);
            } else if(x == side){
                res.push_back((ll)3*side-y);
            } else {
                res.push_back((ll)4*side - x);
            }
        }
        sort(res.begin(), res.end());

        ll left = 1;
        ll right = (1ll*4*side);

        ll ans = 0;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(Check(res, side, k, mid)){
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return ans;
    }
};


https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/1990400187/?envType=daily-question&envId=2026-04-28


class Solution {
public:
    static int minOperations(vector<vector<int>>& grid, int x) {
        const int m = grid.size(), n = grid[0].size(), N = m * n;
        int freq[10001] = {0}, xMin = INT_MAX, xMax = 0;

        int r = grid[0][0] % x;
        for (const auto& row : grid) {
            for (int num : row) {
                auto [q, rr] = div(num, x);
                if (rr != r)
                    return -1; // If not consistent, return -1
                freq[q]++;  
                xMax=max(xMax, q);
                xMin=min(xMin, q);
            }
        }
        int op=0;
        for (int l=xMin, r=xMax; l<r; ) {
            while(l<r && freq[l]==0) l++;
            while(l<r && freq[r]==0) r--;
            op+=r-l;
            if (--freq[l]==0) l++;
            if (--freq[r]==0) r--;
        }
        return op;
    }
};

https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-05-01


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        auto F = [&](vector<int>& arr) {
            long f = 0;
            for (int i = 0; i < arr.size(); i++) {
                f += i * arr[i];
            }
            return f;
        };

        int n = nums.size();
        long total = 0;

        for (int x : nums) total += x;

        vector<long> dp;
        dp.push_back(F(nums));

        for (int i = 1; i < n; i++) {
            long curr = dp[i - 1] + total - (long)n * nums[n - i];
            dp.push_back(curr);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
https://leetcode.com/problems/jump-game-ix/submissions/1997435865/?envType=daily-question&envId=2026-05-07

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            res.push_back(max(res.back(), nums[i]));
        }

        int min_idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (res[i] > nums[min_idx]) {
                res[i] = res[min_idx];
            }
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
        }
        return res;
    }
};


https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/?envType=daily-question&envId=2026-05-08


class Solution {
public:
    
    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) factors.push_back(x);

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            for (int f : factors) {
                mp[f].push_back(i);
            }
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int idx = q.front();
                q.pop();

                if (idx == n - 1) return steps;

                // left
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // right
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                // teleport
                if (isPrime(nums[idx])) {

                    int p = nums[idx];

                    for (int nextIdx : mp[p]) {

                        if (!vis[nextIdx]) {
                            vis[nextIdx] = 1;
                            q.push(nextIdx);
                        }
                    }

                    mp[p].clear();
                }
            }

            steps++;
        }

        return -1;
    }
};


https://leetcode.com/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09



class Solution {
public:
    void rotateArray(vector<int>& arr,int k){
        int n = arr.size();
        k = k%n;

        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.end());
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int K) {
        int n = grid.size();
        int m = grid[0].size();

        for(int k=0;k<min(n/2,m/2);k++){
            int row_st = k;
            int row_end = n-k-1;
            int col_st = k;
            int col_end = m-k-1;
            vector<int> helper;
            //left to right
            for(int j=col_st;j<=col_end;j++){
                helper.push_back(grid[row_st][j]); 
            }

            //top to bottom
            for(int i=row_st+1;i<=row_end;i++){
                helper.push_back(grid[i][col_end]);
            }

            //right to left
            for(int j=col_end-1;j>=col_st;j--){
                helper.push_back(grid[row_end][j]);
            }

            //bottom to top
            for(int i=row_end-1;i>=row_st+1;i--){
                helper.push_back(grid[i][col_st]);
            }

            rotateArray(helper,K);

            int ind = 0;

            //left to right
            for(int j=col_st;j<=col_end;j++){
                grid[row_st][j] = helper[ind++]; 
            }

            //top to bottom
            for(int i=row_st+1;i<=row_end;i++){
                grid[i][col_end] = helper[ind++];
            }

            //right to left
            for(int j=col_end-1;j>=col_st;j--){
                grid[row_end][j] = helper[ind++];
            }

            //bottom to top
            for(int i=row_end-1;i>=row_st+1;i--){
                grid[i][col_st] = helper[ind++];
            }
        }
        

        return grid;
    }
};

https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int val = nums[i];
            while (val > 0) {
                ans.push_back(val % 10);
                val /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
