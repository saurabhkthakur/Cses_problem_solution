#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int mod = 1e9+7;
int f(int n,vector<int>&dp){
    if(n == 0) return 1;
    
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int out =0;
    for(int i= 1;i<=6;i++){
        out =out%mod+ f(n-i,dp)%mod;
    }
    
    
    
    return dp[n]=out%mod;
}

int main()
{   
//   int n;
//   cin >> n;
//   vector<int> dp(n+1,-1);
// //   vector<vector<int>> dp(7,vector<int>(n+1,-1));
   
//   cout << f(n,dp);
  int n,tar;
  cin >> n;
  vector<int> dp(n+1,0);
  dp[0]=1;
  for(int i=1;i<n+1;i++){
      for(int j=1;j<=6;j++){
          
         if(i-j>=0) dp[i] = (dp[i]+dp[i-j])%mod;
      }
      
  }

   
  cout << dp[n];
}