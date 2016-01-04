// Longest Common Substring

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int maxL = 0;
        int aL = A.size(), bL = B.size();
        for (int i=0; i<aL; i++) {
            for (int j=0; j<bL; j++) {
                int len = 0;
                while (i+len<aL && j+len<bL && A[i+len]==B[j+len]) len++;
                maxL = max(maxL, len);
            }
        }
        return maxL;
    }
};
