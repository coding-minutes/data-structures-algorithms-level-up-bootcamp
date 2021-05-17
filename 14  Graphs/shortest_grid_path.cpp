#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Node{
public:
	int x;
	int y;
	int dist;

	Node(int x,int y,int dist){
		this-> x = x;
		this->y = y;
		this->dist = dist;
	}
};

//comparator should return boolean value, 
// indicating whether the element passed as 
// first argument is considered to go before the second in the specific strict weak ordering
class Compare{
public:
	bool operator()(const Node &a,const Node &b){
		return a.dist <= b.dist;
	}
};


int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    
    int m = grid.size();
    int n = grid[0].size();

    int i = 0;
    int j = 0;

    //2D vector to denote of each cell
    vector<vector<int> > dist(m+1, vector<int>(n+1,INT_MAX));

    dist[i][j] = grid[0][0];
    set<Node,Compare> s;

    s.insert(Node(0,0,dist[0][0]));

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};


    while(!s.empty()){

    	auto it = s.begin();
    	int cx = it->x;
    	int cy = it->y;
    	int cd = it->dist;
    	s.erase(it);

    	//update nbrs
    	for(int k=0;k<4;k++){
    		int nx = cx + dx[k];
    		int ny = cy + dy[k];

    		if(nx>=0 and nx<m and ny>=0 and ny<n and cd + grid[nx][ny] < dist[nx][ny]){
    			//remove the old node if it exist
    			Node temp(nx,ny,dist[nx][ny]);
    			if(s.find(temp)!=s.end()){
    				s.erase(s.find(temp));
    			}

    			//insert the new node in the set
    			int nd = grid[nx][ny] + cd;
    			dist[nx][ny] = nd;
    			s.insert(Node(nx,ny,nd));
    		}

    	}

    }
    return dist[m-1][n-1];
    
}

int main(){

	return 0;
}