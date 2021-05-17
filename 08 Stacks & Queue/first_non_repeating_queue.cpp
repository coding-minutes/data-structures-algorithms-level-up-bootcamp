#include<iostream>
#include<queue>
using namespace std;

#include<iostream>
using namespace std;


void play_song(int song_id){
	
	if(song_id==0){
		return;
	}


}	


int main() {

	//First Non-Repeating character in the running stream
	queue<char> q;
	int freq[27] = {0}; //a-z

	char ch;
	cin >> ch;

	while(ch!='.'){

		//letter 
		q.push(ch);
		freq[ch - 'a']++;

		//query -> remove all chars from front of queue till you get a char with freq 1
		while(!q.empty()){
			int idx = q.front() - 'a';
			if(freq[idx]>1){
				q.pop();
			}
			else{
				cout<< q.front() <<endl;
				break;
			}
		}

		if(q.empty()){
			cout<<"-1" <<endl;
		}
		cin>>ch;
	}

	return 0;
}