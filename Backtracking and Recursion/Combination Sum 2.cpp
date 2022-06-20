// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

class Solution {
public:
    void fun(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> candidates,int target)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        int n=candidates.size();
        for(int i=ind;i<n;i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])     //Check for duplicates : Omit the first element as it should be taken.
                continue;
            if(candidates[i]>target)        //As the array is sorted, there is no point of inserting values greater then current target so break from the loop.
                break;
            ds.push_back(candidates[i]);
            fun(i+1,ds,ans,candidates,target-candidates[i]);    //As each number should be processed only once, move ahead in the array.
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());  //As no duplicates are allowed,we start by sorting the given array.
        fun(0,ds,ans,candidates,target);
        return ans;
    }
};
