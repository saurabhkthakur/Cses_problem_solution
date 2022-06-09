#include <iostream>
#include<vector>
#include<set>
#include <bits/stdc++.h>
#include <map>

using namespace std;

vector <int> removeduplicate(vector<int> input){

    set <int> s;
    vector<int> result;

    for(int i=0; i<input.size();i++){
        if(s.find(input[i]) == s.end()){

        
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }

    return result;

}

char nonrepeat(string str){

    map<char,int> frequency;
    for( int i=0; i<str.length();i++){
        char currentchar = str[i];
        frequency[currentchar]++;
    }

    for(int i=0; i<str.length(); i++){
        if ( frequency[str[i]] ==1){
            return str[i];

        }
    }

    return str[0];
}


int main(){

    vector <int> s = {2,3,43,34,34,34,5,5};

    vector <int> out = removeduplicate(s);
    

    for (int i = 0; i < out.size(); i++)
        cout << out[i] << " ";


    return 0;
}