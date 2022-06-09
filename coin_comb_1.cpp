#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
 


 
int main(){
    int mod = 1e9+7;
  int n, tar;
  cin >> n >> tar;
  vector<int> arr(n);
  for (int&v : arr) cin >> v;
  vector<int>dp(tar+1,0);
  
  dp[0]=1;
  
  for(int i=1;i<tar+1;i++){
    for(int k= 0;k<n;k++){
        if(i-arr[k]>=0) dp[i] =(dp[i]+ dp[i-arr[k]])%mod;
    }
  }  
  cout << dp[tar];
 
  
}





























// Memoization



// int mod = 1e9+7;
// int f(int ind,int n,int tar, vector<int> &arr,vector<vector<int>>&dp){
//     if(tar == 0) return 1;
//     if(tar < 0 || ind==n) return 0;
//     if(dp[ind][tar]!=-1) return dp[ind][tar];
//     int out =0;
//     for(int i= 0;i<n;i++){
//         out =out%mod+ f(i,n,tar-arr[i],arr,dp)%mod;
//     }
    
    
    
//     return dp[ind][tar]=out%mod;
// }



// int main(){
//    int n, tar;
//   cin >> n >> tar;
//   vector<int> arr(n);
//   for (int&v : arr) cin >> v;
//   vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    
//   cout << f(0,n,tar,arr,dp);

  
// }


