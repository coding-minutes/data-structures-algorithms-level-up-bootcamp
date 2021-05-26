#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    //Using Kadane’s algorithm 
    int local_max=0,global_max=0;
    for(auto &i:arr)
    {
        local_max = max(0,local_max+i);
        global_max = max(global_max,local_max);
    }
    return global_max;
}