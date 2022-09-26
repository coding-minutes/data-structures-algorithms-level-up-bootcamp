#include<bits/stdc++.h>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    vector<string> out;
    for(int i=1; i<=n; i++){
        if(i%15 == 0){
            out.push_back("FizzBuzz");
        }else if(i%3 == 0){
            out.push_back("Fizz");
        }else if(i%5 == 0){
            out.push_back("Buzz");
        }else{
            out.push_back(to_string(i));
        }
    }
    return out;
    
}

int main(){
    vector<string> out = fizzbuzz(20);
    for(int i=0; i<out.size();i++){
        cout<<out[i]<<" ";
    }
    // for(int i:out[0]){
    //     cout<<i<<" ";
    // }
}