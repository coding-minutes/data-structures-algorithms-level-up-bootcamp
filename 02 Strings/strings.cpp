#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){

	//char s[1000] = {'1','a','b','c','\0'};

	string s; //"hello world"; //Dynamic Array

	int n=5;
	vector<string> sarr;
	string temp;

	while(n--){
		getline(cin,temp);
		sarr.push_back(temp);
	}

	for(string x: sarr){
		cout<<x<<","<<endl;
	}

}