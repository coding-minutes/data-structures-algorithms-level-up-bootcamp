#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
//===============================
//ToDo:  Complete this Function |
//===============================

//helper
void traverseTree(node*root, int d, map<int,vector<int> > &m){
	if(root==NULL){
		return;
	}

	m[d].push_back(root->data);
	traverseTree(root->left, d-1,m);
	traverseTree(root->right,d+1,m);
}

void verticalOrderPrint(node* root){
		
	map<int, vector<int> > m;
	int d = 0;

	traverseTree(root, d, m);

	//Keys are sorted (-2, -1,0,1,2,3.....)
	for(auto p:m){
		int key = p.first;
		vector<int> line = p.second;

		for(auto data : line){
			cout << data <<" ";
		}
		cout <<endl;

	}	
	return;
}

int main(){
	
	node* root = new node(1);
	root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    verticalOrderPrint(root);


	return 0;
}