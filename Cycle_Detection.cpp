#include<bits/stdc++.h>
using namespace std;

void graph(vector<int> vertecies[],int node, int edges){

    for(int i=0;i<edges;i++){

        int nodeA,nodeB;
        cin>>nodeA>>nodeB;

        vertecies[nodeA].push_back(nodeB);
        vertecies[nodeB].push_back(nodeA);
    }
}

void GraphPrint(vector<int> vertecies[],int node){

    for(int i=0;i<node;i++){

        cout<<i<<"->";
        for(int j=0;j<vertecies[i].size();j++){

            cout<<vertecies[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool CycleDetection(vector<int> vertecies[], int total_nodes){
    
    vector<bool>visited(total_nodes, false);
   
    for(int i=0;i<total_nodes;i++){

        if(!visited[i]){

            queue<pair<int,int>> temp;
            temp.push({i,-1});
            visited[i]=true;

            while(!temp.empty()){

                pair<int ,int> current=temp.front();
                temp.pop();

                for(int j=0;j<vertecies[current.first].size();j++){

                    int neighbours=vertecies[current.first][j];

                    if(visited[neighbours] && neighbours!=current.second){
                        return true;
                    }
                    else if(!visited[neighbours]){
                        temp.push({neighbours, current.first});
                        visited[neighbours]=true;
                    
                    }
                }
            }
        }
    }

    return false;

}

int main(){

    int node,edges;
    cin>>node>>edges;

    vector<int> vertecies[node];
    graph(vertecies,node,edges);

    cout<<"Graph representation: "<<endl;
    GraphPrint(vertecies,node);
    cout<<endl;
    
    cout<<"If Cycle Present: "<<endl;
    if(CycleDetection(vertecies, node)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;

}
