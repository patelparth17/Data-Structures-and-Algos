// // You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

class Solution {
public:
    int fun(vector<int> nums)
    {
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            int notpick=prev1;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)    temp1.push_back(nums[i]);     //First look for maximum money without the first house i.e. 1 to n-1.
            if(i!=n-1)  temp2.push_back(nums[i]);     //Then look for maximum money without the last house i.e. 0 to n-2.
        }
        return max(fun(temp1),fun(temp2));      //Take maximum of the money found by first ignoring the first house and then ignoring the second.
    }
};
