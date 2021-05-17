#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> stringSearch(string big,string small){
    
    vector<int> result;
    int index = big.find(small);
    while(index!=-1){
    	result.push_back(index);
    	index = big.find(small,index+1);
    }
    
    return result;
}

int main(){

	string paragraph = "We are learning about STL strings. STL string class is quite powerful";

	string word = "STL";

	vector<int> result = stringSearch(paragraph,word);
	for(int x:result){
		cout <<x<<",";
	}

	return 0;
}