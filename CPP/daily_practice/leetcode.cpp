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