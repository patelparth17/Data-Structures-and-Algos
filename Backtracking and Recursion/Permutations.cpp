// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

class Solution {
public:
    void fun(int ind,vector<vector<int>> &ans,vector<int> nums)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);    //return the permutation when index becomes equal to n
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);    //Swap nums[i] with nums[ind] as for i=0, all permutations starting with 1,2 and 3 will be obtained in the beginning and then the function will move to next index.
            fun(ind+1,ans,nums);
            swap(nums[i],nums[ind]);    //Once the function returns from it's execution, swap to get back the original array.
        }
              
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(0,ans,nums);
        return ans;
    }
};
