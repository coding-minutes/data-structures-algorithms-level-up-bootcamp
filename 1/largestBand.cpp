#include<bits/stdc++.h>
using namespace std;

int largestBand(vector<int> v){
    unordered_set<int> s;
    for(auto i:v){
        s.insert(i);
    }
    int longest = 1;
    for(auto ele:s){
        int parent = ele-1;
        if(s.find(parent) == s.end()){
            int next = ele+1;
            int cnt = 1;
            while(s.find(next) != s.end()){
                cnt++;
                next++;
            }
            if(cnt>longest){
                longest = cnt;
            }
        }
    }
    return longest;
}

int main(){
    vector<int> v{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<largestBand(v);

    return 0;
}