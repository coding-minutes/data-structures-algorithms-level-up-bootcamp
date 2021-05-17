#include<iostream>
using namespace std;


class node{
public:
	node *left; //0
	node *right; // 1
};

class trie{
	node*root;

public:
	trie(){
		root = new node();
	}

	void insert(int n){
		//bits of that number in the trie
		node* temp = root;
		for(int i=31;i>=0;i--){
			int bit = (n>>i)&1;
			if(bit==0){
				if(temp->left==NULL){
					temp->left = new node();
				}
				//go to that node
				temp = temp->left;
			}
			else{
				if(temp->right==NULL){
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
		//Insertion is Done
	}

	int max_xor_helper(int value){

		int current_ans = 0;
		node* temp = root;

		for(int j=31;j>=0;j--){
			int bit =(value>>j)&1;

			if(bit==0){
				//find the opp value
				if(temp->right!=NULL){
					temp = temp->right;
					current_ans += (1<<j);
				}
				else{
					temp = temp->left;
				}
			}
			else{
				//look for a zero 
				if(temp->left!=NULL){
					temp = temp->left;
					current_ans += (1<<j);
				}
				else{
					temp = temp->right;
				}
			}

		}
		return current_ans;

	}
	int max_xor(int *input,int n){

		int max_xor = 0;
		for(int i=0;i<n;i++){
			int value = input[i];
			insert(value);
			int current_xor = max_xor_helper(value);
			max_xor = max(max_xor,current_xor);
		}

		return max_xor;
	}

};


int main(){

	int input[] = {3,10,5,25,9,2};
	int n = sizeof(input)/sizeof(int);
	trie t;
	cout<< t.max_xor(input,n)<<endl;




	return 0;

};