// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution {
public:
    void fun(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> nums)
    {
        int n=nums.size();
        ans.push_back(ds);      //Insert the subset formed at the starting first.
        if(ind==n)      //Base condition for return.
            return;
        
        for(int i=ind;i<n;i++)      //Whenever we check for duplicacy, we use a for loop to make sure duplicates aren't processed.
        {
            if(i!=ind && nums[i]==nums[i-1])    //Check for duplicates : if they exist, continue.
                continue;
            ds.push_back(nums[i]);
            fun(i+1,ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());  //As duplicates are to be ignored,sort the array first.
        fun(0,ds,ans,nums);
        return ans;
    }
};
