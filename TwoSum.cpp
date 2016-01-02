//1. Two Sum

//sol1: hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            if (m.count(target-nums[i])) {
                vector<int> res = {m[target-nums[i]], i+1};
                return res;
            }
            else m[nums[i]]=i+1;
        }
    }
};

//sol2: find 2 numbers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int a=0, b=tmp.size()-1;
        while (a<b) {
            if (tmp[a]+tmp[b]>target) b--;
            else if(tmp[a]+tmp[b]<target) a++;
            else break;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==tmp[a] ||nums[i]==tmp[b]) res.push_back(i+1);
        }
        if (res[0]>res[1]) swap(res[0], res[1]);
        return res;
    }
};