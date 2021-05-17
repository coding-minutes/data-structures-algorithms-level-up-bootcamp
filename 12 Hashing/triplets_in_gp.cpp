#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int count_triplets(vector<int> arr,int r){

    int n = arr.size();
    unordered_map<long,long> right,left;

    //Init the Right Map with freq, Left map = 0
    for(auto x : arr){
        right[x]++;
        left[x] = 0;
    }

    //compute by iterating left to right
    int ans = 0;
    for(int i = 0; i < n; i++){

        right[arr[i]]--;

        if(arr[i]%r==0){
            long b = arr[i];
            long a = arr[i]/r;
            long c = arr[i]*r;

            ans += left[a] * right[c];
        }

        left[arr[i]]++;

    }    
    return ans;

}

int main() {
    
    int n,r;
    cin>>n>>r;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<count_triplets(arr,r);

    return 0;
}
