#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
	list<int> *l;
	int V;

public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
	}

	bool dfs(int node,vector<bool> &visited, vector<bool> &stack){
		//arrive at node
		visited[node] = true;
		stack[node] = true;

		//do some work at node,return true if backedge is found here itself
		for(int nbr : l[node]){

			if(stack[nbr]==true){
				return true;
			}
			else if(visited[nbr]==false){
				bool nbrFoundACycle = dfs(nbr,visited,stack);
				if(nbrFoundACycle){
					return true;
				}
			}
		}

		//going back
		stack[node] = false;
		return false;
	}

	bool contains_cycle(){
		vector<bool> visited(V,false);
		vector<bool> stack(V,false);

		for(int i=0;i<V;i++){
			if(!visited[i]){
				if(dfs(i,visited,stack)){
					return true;
				}
			}

		}
		return false;
	}

};

//Udemy Code Judge - Stub
bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method

	Graph g(V);
	for(auto edge : edges){
		g.addEdge(edge.first,edge.second);
	}
	return g.contains_cycle();
    
}

int main(){

	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);

	cout << g.contains_cycle() <<endl;

	return 0;
}