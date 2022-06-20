//Que:
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

class Solution {
public:
    void fun(int ind,int n,vector<int> &ds,vector<vector<int>> &ans,vector<int> nums)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        fun(ind+1,n,ds,ans,nums);
        
        ds.pop_back();
        fun(ind+1,n,ds,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        fun(0,n,ds,ans,nums);
        return ans;
    }
};
