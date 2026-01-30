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