// There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. 
// HEIGHT[i] is the height of the (i+1)th stair.
// If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
// In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
// Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], 
// the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then 
// a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

#include<bits/stdc++.h>

//Recusive Solution with Memorization :

// int f(int n,vector<int> heights,vector<int> &dp)
// {
//     if(n==0)
//         return 0;
//     if(dp[n]!=-1)    return dp[n];
//     int left=f(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
//     int right=INT_MAX;
//     if(n>1)    right=f(n-2,heights,dp) + abs(heights[n]-heights[n-2]);
//     int ans=min(left,right);
//     return dp[n]=ans;
// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int> dp(n,-1);
    // return f(n-1,heights,dp);
    

    //Tabulation :

    // vector<int> dp(n,-1);
    // dp[0]=0;
    // for(int i=1;i<n;i++)
    // {
    //     if(dp[i]!=-1)    return dp[i];
    //     int left=dp[i-1] + abs(heights[i]-heights[i-1]);
    //     int right=INT_MAX;
    //     if(i>1)    right=dp[i-2] + abs(heights[i]-heights[i-2]);
    //     int ans=min(left,right);
    //     dp[i]=ans;
    // }
    // return dp[n-1];

    //Space Optimization :

    int prev1=0;
    int prev2=0;
    int curr;
    for(int i=1;i<n;i++)
    {
        int left=prev1 + abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)    right=prev2 + abs(heights[i]-heights[i-2]);
        curr=min(left,right);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
