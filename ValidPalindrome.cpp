// 125. Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start = 0, end = s.size()-1;
        while (start<end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};