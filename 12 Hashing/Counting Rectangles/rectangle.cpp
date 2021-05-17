#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Point Class
class Point {
public:
	int x;
	int y;

	Point() {

	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

};

//Comparator Class
class Compare{

public:
	bool operator()(const Point p1,const Point p2){
		if(p1.x==p2.x){
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};


//Count Rectangles Function
int count_rectangles(vector<Point> points) {

	//1. Insert all Points in the set
	set<Point,Compare> s;

	for(Point p:points){
		s.insert(p);
	}

	int ans = 0;
	//2. Logic Brute Force Two Points + LookUp for other Two
	for(auto it = s.begin();it!= prev(s.end());it++){
		for(auto jt= next(it); jt!=s.end();jt++){

			Point p1 = *it;
			Point p2 = *jt;

			//small check that we want to make
			if(p2.x==p1.x or p2.y==p1.y){
				continue;
			}


			//P3, P4
			Point p3(p1.x,p2.y);
			Point p4(p2.x,p1.y);

			//Lookup
			if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
			{
				ans += 1;
			}

		}

	}

	return ans/2;

}



int main() {

	int N;
	cin >> N;

	int x, y;

	vector<Point> points;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		Point p(x, y);
		points.push_back(p);
	}

	cout << count_rectangles(points) << endl;

	return 0;
}


