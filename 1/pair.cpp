#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> searchPair(vector<int> arr, int sum){
    unordered_set<int> s;
    vector<int> result;
    for(int i=0; i<arr.size(); i++){
        int x = sum - arr[i];
        if(s.find(x) != s.end()){
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
}

int main(){
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    auto p = searchPair(arr, 4);
    if(p.size()==0){
        cout<<"No such element...";
    }else{
        cout<<p[0]<<" "<<p[1];
    }

    return 0;
}
