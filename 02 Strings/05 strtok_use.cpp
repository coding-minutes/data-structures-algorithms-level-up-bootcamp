#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int main(){

    char input[1000];
    cin.getline(input,1000);

   //strtok()
     char *token =  strtok(input," ");
     

     while(token!=NULL){
        cout<<token <<endl;
        token = strtok(NULL," ");
     }

    return 0;
}