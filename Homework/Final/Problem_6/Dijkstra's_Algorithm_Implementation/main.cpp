/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Dec. 8, 2022, 2:40 PM
 * Purpose: Problem 6 Part 1 - Dijkstra's Algorithm.
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
#include <algorithm> //Reverse().
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.
const int INF=1e9+7; //To represent infinity for our program.

//Function Prototypes:
//Adds an edge between 2 vertices w/in an adjacency list.
void addEdge(vector<vector<pair<int,int>>> &,int,int,int);
//Performs Dijkstra's algorithm to find the shortest path from a 
//starting vertex to an ending vertex. (Uses an adjacency list.)
//The shortest path is returned from the function.
vector<int> dijkstra(vector<vector<pair<int,int>>>,int,int);
//Displays a path (Our shortest path returned from Dijkstra's algorithm.
void showPath(vector<int>,int,int);

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //The number of vertices we have.
    const int V=7;
    
    //Our starting and ending vertices.
    int start, end;
    
    //Our adjacency list. (Sized w/ how many vertices we have.)
    vector<vector<pair<int,int>>> adj(V);
    
    //Building our adjacency list by adding edges.
    addEdge(adj,0,1,2703); //An edge from SFO to BOS w/ a weight of 2703.
    addEdge(adj,0,2,1847); //An edge from SFO to ORD w/ a weight of 1847.
    addEdge(adj,2,1,868);  //An edge from ORD to BOS w/ a weight of 868.
    addEdge(adj,2,3,743);  //An edge from ORD to JFK w/ a weight of 743.
    addEdge(adj,3,1,189);  //An edge from JFK to BOS w/ a weight of 189.
    addEdge(adj,0,4,1465); //An edge from SFO to DFW w/ a weight of 1465.
    addEdge(adj,4,2,803);  //An edge from DFW to ORD w/ a weight of 803.
    addEdge(adj,4,5,1124); //An edge from DFW to MIA w/ a weight of 1124.
    addEdge(adj,5,3,1093); //An edge from MIA to JFK w/ a weight of 1093.
    addEdge(adj,5,1,1257); //An edge from MIA to BOS w/ a weight of 1257.
    addEdge(adj,0,6,338);  //An edge from SFO to LAX w/ a weight of 338.
    addEdge(adj,6,4,1234); //An edge from LAX to DFW w/ a weight of 1234.
    addEdge(adj,6,5,2341); //An edge from LAX to MIA w/ a weight of 2341.
    
    //Performing Dijkstra's algorithm to find the shortest 
    //path from ORD (Vertex 2) to LAX (Vertex 6).
    start=2, end=6;
    //The algorithm returns the shortest path.
    vector<int> path1=dijkstra(adj,start,end);
    //Outputting the path.
    showPath(path1,start,end);
    
    //Performing Dijkstra's algorithm to find the shortest 
    //path from JFK (Vertex 3) to SFO (Vertex 0).
    start=3, end=0;
    //The algorithm returns the shortest path.
    vector<int> path2=dijkstra(adj,start,end);
    //Outputting the path.
    showPath(path2,start,end);
    
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
//To perform Dijkstra's algorithm given an adjacency list.
vector<int> dijkstra(vector<vector<pair<int,int>>> adj,int start,int end){
    //To hold which vertices we've permanently labeled.
    vector<bool> labeled(adj.size(),0);
    //To hold our distances (Initialized to infinity).
    vector<int> dist(adj.size(),INF);
    //Giving the starting node a permanent label.
    dist[start]=0;    //Setting its distance to 0.
    labeled[start]=1; //Setting its label to true.
    //Looping until the ending vertex has a permanent label.
    int curr=start;   //To hold the current node.
    while(!labeled[end]){
        //cout<<"current node = "<<curr<<endl;
        //We go to the adjacent vertices of the current node...
        for(pair<int,int> p:adj[curr]){
            int v=p.first;  //The adjacent vertex.
            int w=p.second; //The weight along the edge.
            //cout<<"adjacent node = "<<v<<endl;
            //Storing the sum. We only update our sum for the adjacent
            //vertex if the new sum is smaller. Also, the node can't
            //already be labeled. 
            if(!labeled[v]&&dist[curr]+w<dist[v])
                dist[v]=dist[curr]+w;
        }
        //Choosing the vertex with the shortest distance.
        int minVal=INF, indx=0;
        for(int i=0;i<adj.size();i++){
            //We need to choose a vertex that hasn't been labeled...
            if(!labeled[i]&&dist[i]<minVal) 
                minVal=dist[i],indx=i;
        }
        //Giving the vertex a permanent label.
        labeled[indx]=1;
        //Repeating the process above with the vertex we chose.
        curr=indx;
    }
    //Backtracking and finding our path.
    vector<int> path;
    //We start at the end and keep looping until we hit the start.
    curr=end;
    while(curr!=start){
        path.push_back(curr);
        //We check all adjacent vertices of the current vertex...
        for(pair<int,int> p:adj[curr]){
            //The adjacent vertex.
            int v=p.first;
            //The weight along the edge.
            int w=p.second;
            //If the difference in distances matches the weight,
            //we know the vertex belongs in our shortest path.
            if(dist[curr]-dist[v]==w) curr=v;
        }
    }
    //Pushing on the starting node.
    path.push_back(start);
    //Writing the route forwards.
    reverse(path.begin(),path.end());
    //Returning our shortest path.
    return path;
}
//To display our shortest path.
void showPath(vector<int> path,int start,int end){
    //Outputting the path.
    cout<<"Shortest Path from Vertex "<<start<<" to Vertex "<<end<<":\n";
    for(int v:path){
        cout<<v;
        if(v!=end) cout<<" -> ";
    }
    cout<<endl;
}