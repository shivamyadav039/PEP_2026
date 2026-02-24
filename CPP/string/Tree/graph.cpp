#include<iostream>
#include<list>
#include<unordered_map>


using namespace std;

int main(){

    int n ; // number of vertices
    int m ; //number of edges

    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;

    unordered_map<int,list<int>> adjlist;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);///. remove for directed graph
    }
    cout<<"Adjacent list"<<endl;

    for(auto i : adjlist){
        cout<<i.first<<"-> ";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }


}

unordered_map<int,list<pair <int,int>>> ////.  weigted unoreder graph