/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int mod =1e9+7;
int f(int i,int j, vector<string> &arr, vector<vector<int>> &dp){

    
    if(i<0 || j <0) return 0;
    if(i==0 && j==0) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    
    int up=0;
    if(i>0 && arr[i-1][j]!='*')up += f(i-1,j,arr,dp)%mod;
    
    int left=0;
    if(j>0 &&arr[i][j-1]!='*') left += f(i,j-1,arr,dp)%mod;
    
  
    
    return dp[i][j]=(up%mod+left%mod)%mod;

    
    
    
  
    
    
    
}

int main()

{
    int n;
    cin >> n;
    vector<string> arr;
    for(int i=0;i<n;i++){
       string row;
       cin >> row;
       arr.push_back(row);
    }
    
    if(arr[n-1][n-1]=='*') cout << 0;
    else{
    
    vector<vector<int>> dp(n,vector<int>(n,-1));

    
    int ans = f(n-1,n-1,arr,dp);
    
    cout << ans << endl;
    
}
    return 0;
}
