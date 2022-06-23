// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves).
// Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
// Can you help Ninja find out the maximum merit points Ninja can earn?
// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
// Your task is to calculate the maximum number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

#include<bits/stdc++.h>
#include<vector>

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4, 0));
    
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));    //Task 3 signifies no task has been performed on the previous day.
    
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last]=0;    //Initialize current task to zero.
            for(int i=0;i<3;i++)
            {
                if(i!=last)   //If any of Task-0,1 or 2 hasn't been performed on the prev day,
                {
                    int point=points[day][i]+dp[day-1][i];    //Perform it and check if it's amounting to max or not.
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    
    return dp[n-1][3];
}
