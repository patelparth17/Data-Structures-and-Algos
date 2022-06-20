class Solution {
public:
    void fun(int ind,int n,vector<int> &ds,vector<vector<int>> &ans,vector<int> candidates,int target)
    {
        if(ind==n)
        {
            if(target==0)
            {
                ans.push_back(ds);  //print the data structure as it contains all the elements of the target.
            }
            return;
        }
        
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);      //This can be a potential member as it's value is less than target, push it into a data structure.
            fun(ind,n,ds,ans,candidates,target-candidates[ind]);    //Repetition : As repetition is allowed, call for the same index again.
            ds.pop_back();                      //As this value is processes alongwith it's children, pop it from the data structure.
        }

        
        fun(ind+1,n,ds,ans,candidates,target);      //No repettition : Now look for those indices which do not contain the index element 
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=candidates.size();
        fun(0,n,ds,ans,candidates,target);
        return ans;
    }
};