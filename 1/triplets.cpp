#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int targetSum){
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    int n = arr.size(); 
    for(int i=0; i<n-2;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];
            if(currentSum == targetSum){
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }else if(currentSum>targetSum){
                k--;
            }else{
                j++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int sum = 18;
    auto result = triplets(arr, sum);
    for(auto n:result){
        for(auto no:n){
            cout<<no<<" ";
        }
        cout<<endl;
    }
    return 0;
}
