#include <bits/stdc++.h>
using namespace std;
#define int long long int

class graph
{
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
            adj[v].push_back(u);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

void doBFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto nbr : adj[front])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
    // return ans;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < vertex; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void doDFS(int node, unordered_map<int, vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    ans.push_back(node);

    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            doDFS(nbr, adj, ans, visited);
        }
    }
}

vector<int> depthFirstSearch(int v, int E, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            doDFS(i, adj, ans, visited);
        }
    }
}


void floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited=image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int startcolor=image[sr][sc];
        
        

        visited[sr][sc]=color;
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            pair<int,int> front=q.front();
            int r=front.first;
            int c=front.second;
            q.pop();
      
            
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && visited[nrow][ncol]==startcolor)
                {
                    visited[nrow][ncol]=color;
                    q.push({nrow,ncol});
                    // cout<<"Yes"<<endl;
                    
                }

            }
        }
                
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
        // return visited;
        
    }

int32_t main()
{
    // graph g;

    // int n, m;
    // cout << "Enter number of nodes" << endl;
    // cin >> n;
    // cout << "Enter number of edges" << endl;
    // cin >> m;

    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v, 0);
    // }
    // g.printAdj();

        vector<vector<int>> test={{1,1,1},{1,1,0},{1,0,1}};
    
    floodFill(test,1,1,2);

    return 0;
}

// /*
// 	Time complexity: O(n + m).
// 	Space complexity: O(n).

// 	Where 'n' is the number of vertices in the input graph and
//    'm' is the number of edges in the input graph.
// */

// vector<int> bfsTraversal(int n, vector<vector<int>>& adj) {
//     vector<int> res;
//     queue<int> q;

//     // Start BFS from vertex 0
//     q.push(0);

//     // Initialize the visited array with all zeros
//     vector<int> vis(n, 0);

//     // Mark vertex 0 as visited (1 indicates visited, 0 indicates not visited)
//     vis[0] = 1;

//     while (!q.empty()) {
//         // Get the front vertex from the queue
//         int topVertex = q.front();
//         q.pop();

//         // Add the current vertex to the result vector
//         res.push_back(topVertex);

//         // Traverse all neighbors of the current vertex
//         for (auto neighbor : adj[topVertex]) {
//             // If the neighbor is not visited, mark it as visited and enqueue it
//             if (!vis[neighbor]) {
//                 vis[neighbor] = 1;
//                 q.push(neighbor);
//             }
//         }
//     }

//     return res;
// }

// class Graph {
// private:

//     // Function to check for a cycle starting from a given node.
//     bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited) {

//         // Store parent nodes to identify back edges.
//         vector<int> parent(V, -1);=
//         // Queue to perform BFS traversal.
//         queue<pair<int, int>> q;

//         // Mark the current node as visited.
//         visited[s] = true;

//         // Push the current node into the queue with no parent.
//         q.push({s, -1});

//         while (!q.empty()) {

//             // Get the current node.
//             int node = q.front().first;

//             // Get its parent.
//             int par = q.front().second;
//             q.pop();

//             // Traverse through the adjacent nodes of the current node.
//             for (auto it : adj[node]) {
//                 if (!visited[it]) {

//                     // Mark the adjacent node as visited.
//                     visited[it] = true;

//                     // Push it into the queue with the current node as parent.
//                     q.push({it, node});
//                 } else if (par != it) {

//                     // If the adjacent node is visited and not the parent, cycle is detected.
//                     return true;
//                 }
//             }
//         }

//         // If no cycle is detected.
//         return false;
//     }

// public:

//     // Function to detect a cycle in the graph.
//     bool detectCycle(int V, vector<int> adj[]) {

//         // Create a vector to track visited nodes.
//         vector<int> vis(V, 0);
//         for (int i = 0; i < V; i++) {

//             // If the current node is not visited.
//             if (!vis[i]) {

//                 // Check for cycle starting from this node.
//                 if (checkForCycle(i, V, adj, vis)) return true;
//             }
//         }

//         // If no cycle is found in the entire graph.
//         return false;
//     }
// };

//     Time Complexity - O(E * log(V))
//     Space Complexity - O(E + V)

//     where V is the number of nodes in the graph.
//     and E is the number of edges in the graph.
// */

// #include <vector>
// #include <algorithm>
// using namespace std;

// // Comparator for sorting edges in increasing order of their weights
// bool sortByWeight(const vector<int>& edge1, const vector<int>& edge2)
// {
//     return edge1[2] < edge2[2];
// }

// // Finding the set of a node
// // (Uses path compression technique)
// int findSet(vector<int>& parent, int node)
// {
//     if (node == parent[node])
//         return node;
//     return parent[node] = findSet(parent, parent[node]);
// }

// // Function to initialize a set
// void makeSet(vector<int>& parent, vector<int>& rank, int node)
// {
//     parent[node] = node;
//     rank[node] = 0;
// }

// // Function that does the union of two sets
// void unionSet(vector<int>& parent,vector<int>& rank, int set1, int set2)
// {
//     set1 = findSet(parent, set1);
//     set2 = findSet(parent, set2);

//     if (set1 != set2)
//     {
//         if (rank[set1] < rank[set2])
//         {
//             swap(set1, set2);
//         }

//         parent[set2] = set1;

//         if (rank[set1] == rank[set2])
//         {
//             rank[set1]++;
//         }
//     }
// }

// // Function which returns weight of the MST of a graph
// int minimumSpanningTree(vector<vector<int>>& edges, int n)
// {
//     // Sort edges by increasing order of their weight
//     sort(edges.begin(), edges.end(), sortByWeight);

//     // Variable to store weight of MST
//     int finalWeight = 0;

//     vector<int> parent(n);
//     vector<int> rank(n);

//     // Initializing all sets
//     for (int i = 0; i < n; i++)
//     {
//         makeSet(parent, rank, i);
//     }

//     // Traverse through edges in increasing order of their weights
//     for (int i = 0; i < edges.size(); i++)
//     {
//         // Find the set for each node in the edge
//         int set1 = findSet(parent, edges[i][0]);
//         int set2 = findSet(parent, edges[i][1]);

//         // If both sets are different, perform union
//         // And add this edge to our final MST, hence add its weight to final weight

//         // Avoiding cycle
//         if(set1 != set2)
//         {
//             finalWeight += edges[i][2];

//             // Perform union
//             unionSet(parent,rank, set1, set2);
//         }
//     }

//     // Return weight of MST
//     return finalWeight;
// }
