// 268. Missing Number

class Solution {
public: // math
    int missingNumber(vector<int>& nums) {
        int sum, n = nums.size();
        sum = (n+1)*n/2;
        for (int i=0; i<n; i++) sum-=nums[i];
        return sum;
    }
};

class Solution {
public: // bit manipulation
    int missingNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int n:nums) a ^= n;
        for (int i=0; i<nums.size()+1; i++) b ^= i;
        return a^b;
    }
};

class Solution {
public: // binary search
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (nums[mid]!=mid) {
                if (mid==0 ||nums[mid-1]==mid-1) return mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        if (i==nums.size()) return nums.size();
    }
};