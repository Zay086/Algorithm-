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

bool BiPartileGraph(vector<int> vertecies[], int total_nodes){
    
    vector<int> color(total_nodes, -1);
    queue<int> temp;

    for(int i=0;i<total_nodes;i++){

        if(color[i]==-1){

            temp.push(i);
            color[i]=0;

            while(!temp.empty()){

                int current=temp.front();
                temp.pop();

                for(int j=0;j<vertecies[current].size();j++){

                    int w=vertecies[current][j];
                    if(color[w]==-1){

                        color[w]=1-color[current];
                        temp.push(w);
                    }
                    else if(color[w]==color[current]){
                        return false;
                    }
                }
            }

        }

    }
    return true;

}

int main(){

    int node,edges;
    cin>>node>>edges;

    vector<int> vertecies[node];
    graph(vertecies,node,edges);

    cout<<"Graph representation: "<<endl;
    GraphPrint(vertecies,node);
    cout<<endl;
    
    cout<<"If Bi-Partile Possible: "<<endl;
    if(BiPartileGraph(vertecies, node)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;


}