// 5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        string res = s.substr(0, 1);
        for (int i=0; i<n; i++) {
            string s1 = expand(s, i, i);
            if (s1.size()>res.size()) res = s1;
            string s2 = expand(s, i, i+1);
            if (s2.size()>res.size()) res = s2;
        }
        return res;
    }
    
    string expand(string s, int i, int j) {
        while (i>=0 && j<s.size() && s[i]==s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
};