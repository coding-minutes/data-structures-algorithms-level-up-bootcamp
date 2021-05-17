#include <iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define M 3 
#define N 4 


class Node{
public:
	char s;
	unordered_map<char,Node*> children;
	string word;
	bool isTerminal;

	Node(char s){
		this->s = s;
		isTerminal = false;
		word = "";
	}
};

class Trie{
public:
	Node*root;

	Trie(){
		root = new Node('\0');
	}

	void addWord(string word){

		Node * temp = root;
		for(auto ch : word){
			if(temp->children.count(ch)==0){
				temp->children[ch] = new Node(ch);
			}
			temp = temp->children[ch];
		}
		//last node
		temp->isTerminal = true;
		temp->word = word;
	}
};


//main algorithm (8-way dfs + trie guided search)

void dfs(char board[M][N],Node *node,int i,int j,bool visited[][N], unordered_set<string> &output){

	//base case
	char ch = board[i][j];
	if(node->children.count(ch)==0){
		return;
	}

	//otherwise trie contains this node
	visited[i][j] = true;
	node = node->children[ch];


	// if it is a terminal node in the trie 
	if(node->isTerminal){
		output.insert(node->word);
	}

	//explore the neigbours 
    int dx[] = {0, 1 , 1 ,1, 0, -1, -1,-1};
	int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};

	for(int k=0;k<8;k++){

		int ni = i + dx[k];
		int nj = j + dy[k];

		//if it is in bounds and is not visited
		if(ni>=0 and nj>=0 and ni < M and nj < N and !visited[ni][nj]){
			dfs(board,node,ni,nj,visited,output);
		}
	}
	//last step (backtracking)
	visited[i][j] = false;
	return;
}


int main() {
    

    
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO","TUNES","CAT"};
    
    char board[M][N] = { { 'S', 'E', 'R' ,'T'}, 
                          { 'U', 'N', 'K' ,'S'},
                          { 'T', 'C', 'A' ,'T'} };

     //1. Trie

      Trie t;
      for(auto w : words){
      	t.addWord(w);
      }

      //2. Take a container to store words that are found in dfs search
      unordered_set<string> output;


      //3. Step (8-DFS Search from every cell)
      bool visited[M][N] =  {0};


      for(int i=0; i<M;i++){
      	for(int j=0;j<N;j++){
      		dfs(board,t.root,i,j,visited,output);
      		//reset the visited array after every call (while backtracking)
      	}
      }

      //4. Print the Output

      for(auto word: output){
      	cout<< word <<endl;
      }


    return 0;
}
