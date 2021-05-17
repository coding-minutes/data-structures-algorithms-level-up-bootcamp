//BST to Linked List
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



void printInOrder(Node *root){
	if(root==NULL){
		return;
	}
	//left, root, right
	printInOrder(root->left);
	cout << root-> key <<" ,";
	printInOrder(root->right);
}


//---------BST to Sorted Linked List
class LinkedList{
public:
	Node * head;
	Node * tail;
};

LinkedList tree2LL(Node * root){

	LinkedList l;
	//base case
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}

	//4 cases
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
	}
	else if(root->left!=NULL and root->right==NULL){
		LinkedList leftLL = tree2LL(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
	}
	else if(root->left==NULL and root->right!=NULL){
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;

	}
	else{
		LinkedList leftLL = tree2LL(root->left);
		LinkedList rightLL = tree2LL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}

	return l;
}



int main(){

	Node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x : arr){
		root = insert(root,x);
	}
	//printInOrder(root);
	LinkedList l = tree2LL(root);

	Node * temp = l.head;
	while(temp!=NULL){
		cout << temp->key <<"--> ";
		temp = temp->right;
	}
	

	return 0;
}