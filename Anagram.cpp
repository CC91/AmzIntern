// 6: Anagram

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
    	vector<string> res;
    	unordered_map<string, int> m;
    	if (strs.empty()) return res;
    	for (int i=0; i<strs.size(); i++) {
        	string t = strs[i];
        	sort(t.begin(), t.end());
        	if (m.count(t)) {
            	res.push_back(strs[i]);
            	if (m[t]!=-1) {
                	res.push_back(strs[m[t]]);
                	m[t] = -1;
            	}
        	}
        	else m[t] = i;
    	}
    	return res;
	}
};