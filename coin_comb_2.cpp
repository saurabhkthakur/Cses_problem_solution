#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int mod = 1e9+7;
int dp[102][1000007];

int main(){
  int mod = 1e9+7;
  int n, tar;
  cin >> n >> tar;
  vector<int> arr(n);
  for (int&v : arr) cin >> v;


 
 for(int i=0;i<n;i++){
     dp[i][0] = 1;
 }
 
 for(int j=0;j<tar+1;j++) dp[n-1][j] = (j%arr[n-1]==0);
 
 for(int i=n-2;i>=0;i--){
     for(int j=0;j<tar+1;j++){
         int nottake = dp[i+1][j]%mod;
         int take =0;
         if(j-arr[i]>=0) take+=(dp[i][j-arr[i]])%mod;
         dp[i][j] = (take+nottake)%mod;
     }
     
 }
 

    cout << dp[0][tar];

  
}























// int f(int ind,int n,int tar, int *arr,vector<vector<int>> &dp){
//     if(tar == 0) return 1;
//     if(tar < 0 || ind==n) return 0;
    
//     if(dp[ind][tar]!=-1) return dp[ind][tar];
//     int nottake = f(ind+1,n,tar,arr,dp);
    
//     int take=0;
//     if(tar-arr[ind]>=0) take+=f(ind,n,tar-arr[ind],arr,dp);
    
    
    
//     return dp[ind][tar]=take+nottake;
// }



// int main(){
//      int n,tar;
//     cin >> n;
//     cin >> tar;
    
//     int arr[n];
//     for(int i=0;i<n;i++){
//         int a;
//         cin >> a;
//         arr[i]=a;     
//   }
//  vector<vector<int>> dp(n,vector<int>(tar+1,-1));
//   cout << f(0,n,tar,arr,dp);

  
// }
