#include<bits/stdc++.h>
using namespace std;

int disconnected=0;

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
    //vector<bool>parents(total_nodes, false);
    bool cycle=false;
    

    for(int i=0;i<total_nodes;i++){

        if(!visited[i]){

            disconnected++;

            queue<pair<int,int>> temp;
            temp.push({i,-1});
            visited[i]=true;
            //parents[i]=true;

            while(!temp.empty()){

                pair<int ,int> current=temp.front();
                temp.pop();

                for(int j=0;j<vertecies[current.first].size();j++){

                    int neighbours=vertecies[current.first][j];

                    if(visited[neighbours] && neighbours!=current.second){
                        cycle=true;

                    }
                    else if(!visited[neighbours]){
                        temp.push({neighbours, current.first});
                        visited[neighbours]=true;
                        //parents[neighbours]=true;
                    
                    }
                }
            }
        }
    }

    return cycle;

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

    cout<<"Is Disconnected: "<<endl;
    if(disconnected>1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;

}
/*
5 4
0 1
0 2
1 2
3 4
*/