#include<bits/stdc++.h>
using namespace std;

void hash(){
    //declaration
    unordered_map<string, int> menu;
    //if we use map then the operation will take O(log n) time instead of O(1)

    //initialization
    menu["samosa"] = 10;
    menu["chai"] = 8;
    menu["dosa"] = 50;
    menu["pizza"] = 499;

    //updation
    menu["pizza"] = 1.1*menu["pizza"];

    //deletion
    menu.erase("dosa");
    string item;
    cin>>item;

    //searching , it takes O(1) avg time complexity
    if(menu.count(item) == 0){
        cout<<item<<" doesn't exist."<<endl;
    }else{
        cout<<item<<" price is "<<menu[item]<<endl;
    }

    //iteration
    for(pair<string, int> item: menu){
        cout<<item.first<<"-"<<item.second<<endl;
    }
}

void phonebook(){
    map<string, vector<string>> phonebook;
    phonebook["Ajay"].push_back("987665");
    phonebook["Ajay"].push_back("23487665");
    phonebook["Ajay"].push_back("+923665");

    for(auto i=phonebook["Ajay"].begin();i != phonebook["Ajay"].end();i++){
        cout<<*i<<" ";
    }

}

int main(){
    phonebook();

    return 0;
}