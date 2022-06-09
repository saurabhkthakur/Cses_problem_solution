#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
 
using namespace std;

int main(){
  int n, budget;
  cin >> n >> budget;
  vector<int> price(n), pages(n);
  for (int&v : price) cin >> v;
  for (int&v : pages) cin >> v;
  vector<vector<int>> dp(n,vector<int>(budget+1,0));
  
  
  for(int j=0;j<budget+1;j++){
      if(j>=price[0]) dp[0][j] = pages[0];
  }
  
  
  for(int i=1;i<n;i++){
      for(int j=0;j<budget+1;j++){
          
          int nottake = dp[i-1][j];
          int take = -1e8;
    
          if(j-price[i]>=0) take = pages[i]+dp[i-1][j-price[i]];
          dp[i][j] = max(take,nottake);
      }
      
  }
  

  cout << dp[n-1][budget];
      
  

 
  
}
 














// // Memoization
 
 

// int mod = 1e9+7;
// int f(int n,int budget,vector<int> &price, vector<int> &pages,vector<vector<int>> &dp){
//     if(n==0){
//         if(budget>=price[0]) return pages[0];
//         else return 0;
        
//     }
    
//     if(dp[n][budget] !=-1) return dp[n][budget];
    
//     int nottake = f(n-1,budget,price,pages,dp);
//     int take = -1e8;
    
//     if(budget-price[n]>0) take = pages[n]+f(n-1,budget-price[n], price,pages,dp);
    
    
//     return dp[n][budget]=max(nottake,take);
// }




// int main(){
//   int n, budget;
//   cin >> n >> budget;
//   vector<int> price(n), pages(n);
//   for (int&v : price) cin >> v;
//   for (int&v : pages) cin >> v;
//   vector<vector<int>> dp(n,vector<int>(budget+1,-1));
  
  

//   cout << f(n-1,budget,price,pages,dp);
      
  

 
  
// }
 