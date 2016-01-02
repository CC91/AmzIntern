// 48. Rotate Image

class Solution {
public:
    // transpose the matrix first then reverse each row
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};