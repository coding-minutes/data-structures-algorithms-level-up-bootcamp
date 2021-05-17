#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;

//Build a Prefix Tree - Trie
class Node{
public:
	char data;
	unordered_map<char,Node*> children;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}
};

class Trie{
public:
	Node*root;

	Trie(){
		root = new Node('\0');
	}

	void insert(string word){

		Node* temp = root;

		for(char ch : word){

			if(temp->children.count(ch)==0){
				Node *n = new Node(ch);
				temp->children[ch] = n;
			}
			temp = temp->children[ch];
		}

		temp->isTerminal = true;
	}
};

void searchHelper(Trie t, string document, int i, unordered_map<string,bool> &m ){

		Node*temp = t.root;
		for(int j = i; j < document.length();j++){
			char ch = document[j];
			if(temp->children.count(ch)==0){
				return;
			}
			temp = temp->children[ch];
			if(temp->isTerminal){
				//history part 
				string out = document.substr(i,j-i+1);
				m[out] = true;
			}

		}
		return;

}

void documentSearch(string document, vector<string> words){

	//1. Create a trie of words
	Trie t;
	for(string w : words){
		t.insert(w);
	}
	
	//2. Searching (Helper Fn)
	unordered_map<string,bool> m;
	for(int i=0;i<document.length();i++){
		searchHelper(t, document, i, m);
	}

	//3. You can check which words are marked as True inside Hashmap
	for(auto w :words){
		if(m[w]){
			cout<<w <<" : True" <<endl;
		}
		else{
			cout<<w <<" : False "<<endl;
		}
	}

	return;
}


int main(){
	
    string document  ="little cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat", "ttle", "cat","quick","big"};

    documentSearch(document,words);


	return 0;
}

