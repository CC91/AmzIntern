// 151. Reverse Words in a String

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int j = s.size();
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i]==' ') j=i;
            else if (i==0 || s[i-1]==' ') {
                if (!res.empty()) res += ' ';
                res += s.substr(i, j-i);
            }
        }
        s=res;
    }
};