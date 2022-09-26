#include<bits/stdc++.h>
using namespace std;

int mountain(vector<int> arr){
    int n = arr.size();
    int peak = 0;
    for(int i=1;i<=n-2;){
        if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
            int cnt = 1;
            int j=i;
            while(j>=1 and arr[j]>arr[j-1]){
                cnt++;
                j--;
            }
            while(i<=n-2 and arr[i]>arr[i+1]){
                cnt++;
                i++;
            }
            peak = max(peak, cnt);
        }else{
            i++;
        }
    }
    return peak;
}

int main(){
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    int peak = mountain(arr);
    cout<<peak<<endl;

    return 0;
}
