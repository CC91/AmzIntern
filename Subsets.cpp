// 78. Subsets 

//sol1: add subset to each possibility 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            int n = res.size();
            for (int j=0; j<n; j++) {
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

//sol2: bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<pow(2, len); i++) {
            res.push_back(num2set(nums, i));
        }
        return res;
    }
    
    vector<int> num2set(vector<int>& nums, int n) {
        vector<int> r;
        int i=0;
        while (n) {
            if (n&1) r.push_back(nums[i]);
            n>>=1;
            i++;
        }
        return r;
    }
};