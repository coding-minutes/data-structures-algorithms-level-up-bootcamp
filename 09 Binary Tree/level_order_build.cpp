#include<iostream>
#include<queue>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}
/*Level Order Traversal
Expected Output

1
2 3
4 5 6
7
*/

void levelOrderPrint(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			//insert a new null for the next level
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}

	}
	return;
}

/* Implement Level Order Build
for the tree
*/

node* levelOrderBuild(){

	int d;
	cin>>d;

	node* root = new node(d);

	queue<node*> q;
	q.push(root);


	while(!q.empty()){
		node* current = q.front();
		q.pop();

		int c1, c2;
		cin>> c1 >> c2;

		if(c1!=-1){
			current->left = new node(c1);
			q.push(current->left);
		}
		if(c2!=-1){
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	return root;
}

//Todo: Replace with Descendant Sum leaving leaf nodes intact
int replaceWithSum(node *root){
	//base case
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	//recursive case
	int LS = replaceWithSum(root->left);
	int RS = replaceWithSum(root->right);

	int temp = root->data;
	root->data = LS + RS;
	return root->data + temp;
}

int main(){
	
	//node* root = buildTree();
	node* root = levelOrderBuild();
	levelOrderPrint(root);
	cout<<endl;
	replaceWithSum(root);
	levelOrderPrint(root);


	return 0;
}