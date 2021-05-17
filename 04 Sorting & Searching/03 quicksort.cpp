#include<iostream>
#include <vector>
using namespace std;


int partition(vector<int> &a,int s,int e){

	int pivot = a[e];
	int i = s - 1;

	for(int j=s;j<e;j++){
		if(a[j] < pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	
	swap(a[i+1],a[e]);
	return i + 1;
	
}

void quicksort(vector<int> &a, int s,int e){
	//Base Case
	if(s>=e){
		return;
	}
	//Rec Case
	int p = partition(a,s,e);
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);
}


int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    cout<< arr.size() <<endl;
    int n = arr.size();

    quicksort(arr,0,n-1);

    for(int x :arr){
    	cout << x << " ";
    }

    return 0;
}
