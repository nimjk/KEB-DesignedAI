#include <map>
#include <iostream>
using namespace std;

map<string, int> myMap;
int main(){
    myMap.insert(pair<string,int>("Apple",100));
    myMap.insert(pair<string,int>("Orange",200));
    myMap.insert(pair<string,int>("Banana",300));
    myMap.insert(pair<string,int>("Copper",500));
    myMap.insert(pair<string,int>("TikTok",1000));

    map<string,int>::iterator it;

    for(it = myMap.begin(); it != myMap.end(); it++)
        cout<<"["<<(*it).first <<", "<<it->second<<"]"<<endl;

    for(const auto& i: myMap)
        cout<<"["<<i.first<<", "<<i.second<<"]"<<endl;

}