// 242. Valid Anagram

//sol1: hashmap
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        int m[26] = {0};
        for (int i=0; i<s.size(); i++) m[s[i]-'a']++;
        for (int i=0; i<t.size(); i++) {
            if (--m[t[i]-'a']<0) return false;
        }
        return true;
    }
};

//sol2: naive method
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};