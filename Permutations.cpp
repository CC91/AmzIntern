// 46. Permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        res.push_back(vector<int> (1, nums[0]));
        for (int i=1; i<nums.size(); i++) {
            int n = res.size();
            for (int j=0; j<n; j++) {
                for (int k=0; k<res[j].size(); k++) {
                    vector<int> tmp = res[j];
                    tmp.insert(tmp.begin()+k, nums[i]);
                    res.push_back(tmp);
                }
                res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};


class Solution {
public: // backtracking
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perm(nums, 0, nums.size()-1, res);
        return res;
    }
    
    void perm(vector<int>& nums, int start, int end, vector<vector<int>> &res) {
        if (start==end) res.push_back(nums);
        for (int i=start; i<=end; i++) {
            int tmp = nums[start];
            nums[start] = nums[i];
            nums[i] = tmp;
            perm(nums, start+1, end, res); // backtracking
            tmp = nums[start];
            nums[start] = nums[i];
            nums[i] = tmp;
        }
    }
};