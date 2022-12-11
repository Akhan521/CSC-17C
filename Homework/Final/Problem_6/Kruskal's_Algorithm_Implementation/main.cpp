/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Dec. 8, 2022, 3:40 PM
 * Purpose: Problem 6 Part 2 - Kruskal's Algorithm.
 *      
 *      We'll be using the edge-vertex structure
 *          below to perform our analysis.    
 * 
 *    Vertex Edge Vertex         Numbering of Vertices:
 *    SFO    2703    BOS             Vertex 0 - SFO
 *    SFO    1847    ORD             Vertex 1 - BOS
 *    ORD    868     BOS             Vertex 2 - ORD
 *    ORD    743     JFK             Vertex 3 - JFK
 *    JFK    189     BOS             Vertex 4 - DFW
 *    SFO    1465    DFW             Vertex 5 - MIA
 *    DFW    803     ORD             Vertex 6 - LAX
 *    DFW    1124    MIA
 *    MIA    1093    JFK
 *    MIA    1257    BOS
 *    SFO    338     LAX
 *    LAX    1234    DFW
 *    LAX    2341    MIA
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <vector>    //Vectors.
#include <utility>   //Pairs.
#include <array>     //Array class.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
//Adds an edge between 2 vertices w/in an adjacency list.
void addEdge(vector<vector<pair<int,int>>> &,int,int,int);
//To pop an edge off of our adjacency list given 2 vertices.
void popEdge(vector<vector<pair<int,int>>> &,int,int);
//Sorts our edges based on their weights.
void sortEdges(vector<array<int,3>> &);
//Determines if a cycle exists in a subgraph reachable from a specified vertex.
bool isCyclic(vector<vector<pair<int,int>>>,int,vector<bool> &,int);
//Determines if any cycles exist in our entire graph.
bool isCyclic(vector<vector<pair<int,int>>>);
//To perform Kruskal's algorithm given an adjacency list.
int kruskal(vector<vector<pair<int,int>>> &,vector<array<int,3>>);

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //The number of vertices.
    const int V=7;
    
    //Our edge vector. (Will be sorted for Kruskal's algorithm.)
    //We store the 1st vertex of the edge, the 2nd vertex, and
    //the weight along the edge.
    vector<array<int,3>> edges;
    
    //Our adjacency list. (Will be used to build our MST.)
    vector<vector<pair<int,int>>> adj(V);
    
    //Adding our edges into our edge vector that will be sorted:
    //An edge from SFO to BOS w/ a weight of 2703.
    edges.push_back(array<int,3>{0,1,2703});
    //An edge from SFO to ORD w/ a weight of 1847.
    edges.push_back(array<int,3>{0,2,1847});
    //An edge from ORD to BOS w/ a weight of 868.
    edges.push_back(array<int,3>{2,1,868}); 
    //An edge from ORD to JFK w/ a weight of 743.
    edges.push_back(array<int,3>{2,3,743});
    //An edge from JFK to BOS w/ a weight of 189.
    edges.push_back(array<int,3>{3,1,189});  
    //An edge from SFO to DFW w/ a weight of 1465.
    edges.push_back(array<int,3>{0,4,1465}); 
    //An edge from DFW to ORD w/ a weight of 803.
    edges.push_back(array<int,3>{4,2,803});  
    //An edge from DFW to MIA w/ a weight of 1124.
    edges.push_back(array<int,3>{4,5,1124}); 
    //An edge from MIA to JFK w/ a weight of 1093.
    edges.push_back(array<int,3>{5,3,1093}); 
    //An edge from MIA to BOS w/ a weight of 1257.
    edges.push_back(array<int,3>{5,1,1257}); 
    //An edge from SFO to LAX w/ a weight of 338.
    edges.push_back(array<int,3>{0,6,338}); 
    //An edge from LAX to DFW w/ a weight of 1234.
    edges.push_back(array<int,3>{6,4,1234});
    //An edge from LAX to MIA w/ a weight of 2341.
    edges.push_back(array<int,3>{6,5,2341}); 
    
    //Sorting our edge vector.
    sortEdges(edges);
    
    //Performing Kruskal's algorithm given our adj. list and edge vector.
    //The total cost of our MST is returned by the algorithm.
    int cost=kruskal(adj,edges);
    
    //Outputting the total cost.
    cout<<"\nTotal Cost of our MST = "<<cost<<endl;
    
    //Exit the Program - Cleanup.
    return 0;
}
//To add an edge between 2 vertices in our adjacency list.
//We input our adjacency list, our first vertex, our 2nd vertex, and
//the weight along the edge.
void addEdge(vector<vector<pair<int,int>>> &adj,int u,int v,int w){
    //Storing the adjacent vertex in our adjacency list.
    //The weight is also stored along with the vertex.
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
//To pop an edge off of our adjacency list given 2 vertices.
//We input our adj. list and the 2 vertices that form the edge.
void popEdge(vector<vector<pair<int,int>>> &adj,int u,int v){
    //Popping the edges off...
    adj[u].pop_back();
    adj[v].pop_back();
}
//To sort our edges based on their weights for Kruskal's algorithm.
void sortEdges(vector<array<int,3>> &edges){
    for(int i=0;i<edges.size()-1;i++){
        for(int j=i+1;j<edges.size();j++){
            //Comparing the weights of both edges.
            int wght1=edges[i][2]; //The weight of the ith edge.
            int wght2=edges[j][2]; //The weight of the jth edge.
            //If the edges need to be swapped...
            if(wght1>wght2){
                //We swap the edges.
                edges[i].swap(edges[j]);
            }
        }
    }
}
//To determine if a cycle exists in a subgraph reachable from a specified vertex.
//We input our adj. list, the current vertex, a visited array, and the parent vertex.
bool isCyclic(vector<vector<pair<int,int>>> adj,int v,vector<bool> &vis,int par){
    //We mark the current vertex as visited.
    vis[v]=1;
    //We check the adjacent nodes...
    for(pair<int,int> p:adj[v]){
        int adjVert=p.first;
        //If the adjacent node hasn't been visited...
        if(!vis[adjVert]){
            //We recursively check if a cycle exists starting from that vertex.
            //If a cycle exists starting from the adjacent node, we return true.
            if(isCyclic(adj,adjVert,vis,v)) return true;
        }
        //If the adjacent node has been visited, we need to make sure that the
        //visited node is the parent of the current vertex. If it isn't, that
        //would tell us that we have a cycle because the parent of the current
        //vertex would not match with the adjacent vertex.
        else if(adjVert!=par) return true;
    }
    //If we have no cycles...
    return false;
}
//To determine if any cycles exist in our entire graph.
bool isCyclic(vector<vector<pair<int,int>>> adj){
    //To hold which nodes we've visited.
    vector<bool> vis(adj.size(),0);
    //We check if any cycles exist from all of our vertices:
    for(int u=0;u<adj.size();u++){
        //If the vertex hasn't been visited...
        if(!vis[u]){
            //We check to see if there is a cycle. If a cycle exists in a 
            //subgraph reachable from the current vertex, we return true.
            if(isCyclic(adj,u,vis,-1)) return true;
        }
    }
    //If we have no cycles in our entire graph...
    return false;
}
//To perform Kruskal's algorithm given an adjacency list and an edge vector.
int kruskal(vector<vector<pair<int,int>>> &adj,vector<array<int,3>> edges){
    cout<<"The edges in our MST are:\n";
    //To hold the cost of our MST.
    int cost=0;
    //To hold how many edges we've included in our tree.
    //Our MST will have V-1 edges by the end.
    int numEdges=0;
    //Step 1: Selecting the shortest edge in a network.
    //We add the shortest edge to our adjacency list.
    addEdge(adj,edges[0][0],edges[0][1],edges[0][2]);
    //We increment the number of included edges.
    numEdges++;
    //We add the edge's weight to our total cost.
    cost+=edges[0][2];
    //We also output our edge.
    cout<<"("<<edges[0][0]<<", "<<edges[0][1]<<") Weight = "<<edges[0][2]<<endl;
    //We continue looping until we have V-1 edges in our tree.
    int i=1; //To keep track of the next edge we're adding.
    while(numEdges!=adj.size()-1){
        //We add the next shortest edge to our adj. list.
        addEdge(adj,edges[i][0],edges[i][1],edges[i][2]);
        //If the edge we've added doesn't form a cycle, we can continue.
        if(!isCyclic(adj)){
            //We increment the number of included edges.
            numEdges++;
            //We add the edge's weight to our total cost.
            cost+=edges[i][2];
            //We also output our edge.
            cout<<"("<<edges[i][0]<<", "<<edges[i][1]<<") Weight = "
                     <<edges[i][2]<<endl;
        }
        //If we have a cycle...
        else{
            //We remove the edge from our list.
            popEdge(adj,edges[i][0],edges[i][1]);
        }
        //We move on to the next shortest edge.
        i++; 
    }
    //Returning the cost of the MST.
    return cost;
}