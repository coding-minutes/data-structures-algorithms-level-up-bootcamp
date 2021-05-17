#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


int countSubsets(vector<int> arr,int n,int i,int X){

	//base case
	if(i==n){
		if(X==0){
			return 1;
		}
		return 0;
	}

	//recusive case 
	int inc  = countSubsets(arr,n,i+1,X - arr[i]);
	int exc = countSubsets(arr,n,i+1,X);
	return inc + exc;
}

int main(){
	vector<int> arr{1,2,3,4,5};
	int X = 10;

	cout << countSubsets(arr,arr.size(),0,X)<<endl;

	return 0;

}