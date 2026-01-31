   bool validPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;

        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return checkpalindrome(s, lo + 1, hi) || checkpalindrome(s, lo, hi - 1);
            }
            lo++;
            hi--;
        }
        return true;
    }
};

find first repchar

string firstRepChar(string s) {
    unordered_set<char> seen;
    for (char c : s) {
        if (seen.count(c)) {
            return string(1, c);
        }
        seen.insert(c);
    }
    return "";
}
