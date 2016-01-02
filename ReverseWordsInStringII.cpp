// 186. Reverse Words in a String II
class Solution {
public: // reverse twice, first whole string, then each word in the reversed string
	void reverseWords(string &s) {
		if (s.empty()) return;
		reverse(s, 0, s.size()-1);
		int left = 0;
		for (int i=0; i<s.size(); i++) {
			if (s[i]==' ') {
				reverse(s, left, i-1);
				left = i+1;
			}
		}
		reverse(s, left, s.size()-1); // reverse the last word
	}

	void reverse(string &s, int l, int r) {
		while (l<=r) {
			char tmp = s[l];
			s[l] = s[r];
			s[r] = tmp;
			l++;
			r--;
		}
	}
}