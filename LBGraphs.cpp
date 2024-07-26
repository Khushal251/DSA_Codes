#include <bits/stdc++.h>
using namespace std;
#define int long long int

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> adj;
    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
        mp[i];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[v].push_back(u);
        mp[u].push_back(v);
    }

    for (auto i : mp)
    {
        vector<int> temp;
        temp.push_back(i.first);

        for (auto j : i.second)
        {
            temp.push_back(j);
        }
        adj.push_back(temp);
    }
    return adj;
}

class graph2
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = {v, weight};
        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }

    // SHORTEST PATH IN DIRECTED ACYCLIC GRAPH
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo)
    {
        vis[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour.first])
            {
                dfs(neighbour.first, vis, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo)
    {
        dist[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
}

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> adjList, vector<int> &ans, unordered_map<int, bool> visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList; // for sorted order change list to set
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, ans, visited, i);
        }
    }
}

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    // hrr connected node ke liye recursive call
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int v, int E, vector<vector<int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[u].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
}

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q; 
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetectionBFS(vector<vector<int>> &edges, int n, int m)
{
    // create adjecency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handel disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans == 1)
                return "YES";
        }
    }
    return "NO";
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if (cycleDetected)
                return true;
        }
        else if (visited[neighbour] && neighbour != parent)
        {
            // cycle present
            return true;
        }
    }
    return false;
}

string cycleDetectionDFS(vector<vector<int>> &edges, int n, int m)
{
    // create adjecency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handel disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if (ans == 1)
                return "YES";
        }
    }
    return "NO";
}

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsvisited, adj);
            if (cycleDetected)
                return true;
        }
        else if (dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // creating adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsvisited, adj);
            if (cycleFound)
                return true;
        }
    }
    return false;
}

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            topoSort(neighbour, visited, s, adj);
    }

    // important
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topological sort util function for al components
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSort(i, visited, s, adj);
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

vector<int> KahnsAlgorithm(vector<vector<int>> &edges, int v, int e) // Topological sort using BFS
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans stroe
        ans.push_back(front);

        // neighbour indegree update
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}

int detectCycleInDirectedGraphUsingToposort(int n, vector<pair<int, int>> &graph)
{
    // Write your code here.

    map<int, set<int>> adj;

    for (int i = 0; i < graph.size(); i++)
    {
        int u = graph[i].first - 1;
        int v = graph[i].second - 1;

        adj[u].insert(v);
    }

    map<int, int> indegree;
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // vector<int>ans;
    int cnt = 0;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        cnt++;

        for (auto neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if (cnt == n)
        return 0;
    else
        return 1;
}

vector<int> shortestPathinUndirectedGraph(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
}

void dfsTopo(int node, map<int, set<pair<int, int>>> &adj, map<int, bool> &visited, stack<int> &s)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour.first])
        {
            dfsTopo(neighbour.first, adj, visited, s);
        }
    }

    s.push(node);
}

void getShortestPath(int src, map<int, set<pair<int, int>>> adj, vector<int> &distance, stack<int> &topoStack)
{
    distance[src] = 0;

    while (!topoStack.empty())
    {
        int frontNode = topoStack.top();
        topoStack.pop();

        if (distance[frontNode] != INT_MAX)
        {
            for (auto neighbour : adj[frontNode])
            {
                if (distance[frontNode] + neighbour.second < distance[neighbour.first])
                {
                    distance[neighbour.first] = distance[frontNode] + neighbour.second;
                }
            }
        }
    }
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    map<int, set<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].insert({v, weight});
        // adj[v].insert({u, weight});
    }

    stack<int> topoStack;
    map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTopo(i, adj, visited, topoStack);
        }
    }

    vector<int> distance;
    for (int i = 0; i < n; i++)
    {
        distance.push_back(INT_MAX);
    }

    getShortestPath(0, adj, distance, topoStack);

    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
            distance[i] = -1;
    }

    return distance;
}

vector<int> Dijkshtra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < vertices; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        // traverse on neighbours
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find({dist[neighbour.first], neighbour.first});
                // if record found,then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record push in set
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
    return dist;
}

vector<pair<pair<int, int>, int>> minimumSpanningTreePrimsAlgorithm(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creating adj list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // lets start the algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        // find min wali node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adjecent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

void dfsBridge(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;
        if (!vis[nbr])
        {
            dfsBridge(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);
            // check edge is bridge
            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfsBridge(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}

void dfsAP(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            dfsAP(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);
            // check AP or not
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = true;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if (parent == -1 && child > -1)
        ap[node] = 1;
}

void artuculationPoint()
{
    int n = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({0, 2});

    // adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfsAP(i, -1, disc, low, vis, adj, ap, timer);
    }

    // print ap;
    cout << "Articulation points are" << endl;

    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void dfsSCC(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfsSCC(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revDfs(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponent(int v, unordered_map<int, bool> &vis, vector<vector<int>> &edges)
{
    // adj
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfsSCC(i, vis, st, adj);
        }
    }

    // create a transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // dfs call suing above ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, LLONG_MAX);
    dist[src] = 0;

    // n-1 times

    for (int i = 1; i <= n; i++)
    {
        // traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != LLONG_MAX && ((dist[u] + wt) < dist[v]))
                dist[v] = dist[u] + wt;
        }
    }

    // check for negative cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != LLONG_MAX && ((dist[u] + wt) < dist[v]))
            flag = 1;
    }

    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}

int32_t main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v, 0);
    }
    g.printAdjList();

    // SHORTEST PATH IN DIRECTED ACYCLIC GRAPH
    graph2 g2;
    g2.addEdge(0, 1, 5);
    g2.addEdge(0, 2, 3);
    g2.addEdge(1, 2, 2);
    g2.addEdge(1, 3, 6);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 4, 4);
    g2.addEdge(2, 5, 2);
    g2.addEdge(3, 4, -1);
    g2.addEdge(4, 5, -2);

    g2.printAdj();

    int x = 6;
    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < x; i++)
    {
        if (!visited[i])
        {
            g2.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(x);
    for (int i = 0; i < x; i++)
    {
        dist[i] = INT_MAX;

        g2.getShortestPath(src, dist, s);

        cout << "answer is: " << endl;

        for (int i = 0; i < dist.size(); i++)
        {
            cout << dist[i] << " ";
        }
        cout << endl;
    }

    return 0;
}