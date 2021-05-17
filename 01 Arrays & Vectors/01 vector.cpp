#include<iostream>
#include<vector>
using namespace std;

int main(){
	//Demo Vector
	//vector<int> arr =  //{1,2,10,12,15};

	//Fill Constructor
	vector<int> arr(10,7);

	//Fill Constructor
	vector<int> visited(100,0);

	//Pop_back
	arr.pop_back();
	// Push_Back O(1)
	arr.push_back(16);

	//Print all the elements
	for(int x : arr){
		cout << x <<",";
	}

	/*for(int i=0;i< arr.size(); i++){
		cout << arr[i] <<endl;
	}*/

	return 0;
}