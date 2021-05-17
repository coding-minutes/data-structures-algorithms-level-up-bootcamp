#include <iostream>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

Node* insert(Node * root, int key){
	if(root==NULL){
		return new Node(key);
	}

	//rec case 
	if(key < root->key){
		root->left = insert(root->left,key);
	}
	else{
		root->right = insert(root->right,key);
	}
	return root;

}

int findClosestInBST(Node * root, int target){
	//todo 

	int closest;
	int diff = INT_MAX;

	Node *temp = root;

	while(temp!=NULL){

		int current_diff = abs(temp->key - target);

		if(current_diff==0){
			return temp->key;
		}

		
		if(current_diff < diff){
			diff = current_diff;
			closest = temp->key;
		}


		//right or left
		if(temp-> key < target){
			temp = temp -> right;
		}
		else{
			temp = temp->left;
		}
	}
	return closest;

}

void printInOrder(Node *root){
	if(root==NULL){
		return;
	}
	//left, root, right
	printInOrder(root->left);
	cout << root-> key <<" ,";
	printInOrder(root->right);
}


int main(){

	Node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x : arr){
		root = insert(root,x);
	}
	//printInOrder(root);

	cout << findClosestInBST(root,12) <<endl;

	return 0;
}