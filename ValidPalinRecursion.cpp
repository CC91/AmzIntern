class Solution {
public:
    bool isPalindrome(string s) {
        return helper(s, 0, s.size()-1);
    }
    
    bool helper(string s, int start, int end) {
        if (start>end) return true;
        if (!isalnum(s[start])) return helper(s, start+1, end);
        if (!isalnum(s[end])) return helper(s, start, end-1);
        return tolower(s[start])==tolower(s[end]) && helper(s, start+1, end-1);
    }
};