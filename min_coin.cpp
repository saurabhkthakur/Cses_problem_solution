#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[102][1000007]  = {0};
int f(int n,int tar,int *arr,vector<vector<int>> &dp){
    if(n == 0){
        if(tar % arr[n]==0) return tar/arr[n];
        else return 0;
    }
    if(dp[n][tar]!=-1) return dp[n][tar];
    
    int nottake = 0+f(n-1,tar,arr,dp);
    int take = 1e8;
    if(tar>= arr[n]) take = 1+f(n,tar-arr[n],arr,dp);

    return dp[n][tar]=min(take,nottake);
   
}

int main()
{   

  int n,tar;
  cin >> n;
  cin >> tar;
    
  int arr[n];
  for(int i=0;i<n;i++){
      int a;
      cin >> a;
      arr[i]=a;
   
      
  }
  for(int j=0;j<tar+1; j++){
      if(j%arr[0] ==0) dp[0][j] = j/arr[0];
      else dp[0][j] = 1e8;
  }
  
  
  for(int i=1;i<n;i++){
      for(int j=0;j<tar+1;j++){
            
    
        int nottake = dp[i-1][j];
        int take = 1e8;
        if(j>= arr[i]) take = 1+dp[i][j-arr[i]];
        dp[i][j] = min(take,nottake);
          
        }
     }
     

  if(dp[n-1][tar]==1e8) cout << -1;
  else cout << dp[n-1][tar];




}































// #include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int f(int n,int tar,int *arr,vector<vector<int>> &dp){
//     if(n == 0){
//         if(tar % arr[0]==0) return tar/arr[0];
//         else return 1e8;
//     }
//     if(dp[n][tar]!=-1) return dp[n][tar];
    
//     int nottake = 0+f(n-1,tar,arr,dp);
//     int take = 1e8;
//     if(tar>= arr[n]) take = 1+f(n,tar-arr[n],arr,dp);

//     return dp[n][tar]=min(take,nottake);
   
// }

// int main()
// {   

//   int n,tar;
//   int a;
//   cin >> n;
//   cin >> tar;
    
//   int arr[n];
//   for(int i=0;i<n;i++){
      
//       cin >> a;
//       arr[i]=a;
  
      
//   }
//   vector<vector<int>> dp(n,vector<int>(tar+1,-1));


//   int ans = f(n-1,tar,arr,dp);
//   if(ans == 1e8) cout << -1;
//   else cout << ans;
// }
