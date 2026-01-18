Algoritm Prim
1/struct Edge{
    int from;
    int to;
    int weight;
    
    bool operator<(const Edge& other) const{
        return weight > other.weight;
    }
};
int prims(int n, vector<vector<int>> edges, int start) {
   set<int> visited;
   priority_queue<Edge> pq;
   vector<Edge> finali;
   pq.push({start, start, 0});
  
   size_t n1 = n;
   unordered_map<int,vector<Edge>> mp;
   for(size_t i = 0;i<edges.size();i++){
    mp[edges[i][0]].push_back({edges[i][0], edges[i][1], edges[i][2]});
    mp[edges[i][1]].push_back({edges[i][1], edges[i][0], edges[i][2]});
   }
   while(!pq.empty() && visited.size() < n1){
    auto curr = pq.top();
    pq.pop();
    
    if(visited.count(curr.to)){
        continue;
    }
    visited.insert(curr.to);
    finali.push_back(curr);
    
    for(auto e: mp[curr.to]){
        if(visited.count(e.to)){
            continue;
            
        }
        pq.push(e);
       
    }
    
   }
   
   if(finali.size() < n1-1){
    return -1;
   }
   int total = 0;
   for(size_t i = 0;i<finali.size();i++){
    total += finali[i].weight;
   }
   return total;
}

2/int find(int x, vector<int>& parent){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}
void unite(int a, int b, vector<int>& parent){
    a = find(a, parent);
    b = find(b, parent);
    
    if(a != b) parent[b] = a;
}
struct Edge{
  int from, to, weight;  
    
};
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
vector<Edge> vec;
for(size_t i = 0;i<g_from.size();i++){
    vec.push_back({g_from[i], g_to[i], g_weight[i]});
    
}
sort(vec.begin(), vec.end(), [](const Edge one, const Edge two){
    return one.weight < two.weight;
});
vector<int> parent(g_nodes+1);
for(int i = 1;i<g_nodes+1;i++){
    parent[i] = i;
}
vector<Edge> finali;
for(auto& e : vec){
    if(find(e.from, parent) != find(e.to, parent)){
        finali.push_back(e);
        unite(e.from, e.to, parent);
    }
    if(finali.size() ==(size_t)g_nodes - 1) break;
}
int total = 0;
for(size_t i = 0;i<finali.size();i++){
    total+=finali[i].weight;
}
//cout<<total;
return total;

}
3/struct Edge{
        int from,to,weight;
        bool operator<(const Edge& two) const{
            return weight > two.weight;
        }

    };
    int calcDist(vector<int> one, vector<int> two){
        return abs(one[0] - two[0]) + abs(one[1] - two[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
      vector<Edge> vec;
      unordered_map<int, vector<Edge>> mp;
      for(int i = 0;i<points.size()-1;i++){
        for(int j = i+1;j<points.size();j++){
            int res = calcDist(points[i], points[j]);
        mp[i].push_back({i, j,res});
        mp[j].push_back({j, i,res});
        }
      }
    //   for(auto e:mp){
    //     cout<<e.first<<' '<<e.second[0].weight<<'\n';
    //   }
      priority_queue<Edge> pq;
      int start = 0;
      vector<Edge> finali;
      pq.push({start, start, 0});
      set<int> visited;
      int total = 0;
      while(!pq.empty() && visited.size() < points.size()){
        auto curr = pq.top();
        pq.pop();
        if(visited.count(curr.to)){
            continue;
        }
        visited.insert(curr.to);
        total += curr.weight;
       finali.push_back(curr);
        for(auto e:mp[curr.to]){
           // cout<<e.from<<e.to<<' '<<e.weight<<' ';
            if(visited.count(e.to))continue;
            pq.push(e);
        }
      } 
    return total;
    }
4/#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool dfs(unordered_map<int,vector<int>>& mp, vector<bool> &visited, int curr, int dest){
if(curr == dest) return true;
    visited[curr] = true;
    for(auto& e:mp[curr]){
    if(!visited[e]){
         if(dfs(mp,visited,e,dest)){
             return true;
         }
    }
    }
    return false;
}

int main() {
    int N,M;
    cin>>N>>M;
    unordered_map<int,vector<int>> graph;
    for(int i = 0;i<M;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
    int Q;
    cin>>Q;
    for(int i = 0;i<Q;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z == 1){
            vector<bool> visited(N);
            if(dfs(graph, visited, x,y))cout<<1;
            else cout<<0;
        }
        else if(z == 2){
           graph[x].push_back(y);
           graph[y].push_back(x);
        }
    }
      
    return 0;
}
4.1/faster
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct unionFind{
    vector<int> parent,sizes;
    unionFind(int n){
        parent.resize(n);
        sizes.resize(n, 1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        
        if(sizes[x] < sizes[y]) swap(x, y);
        parent[y] = x;
        if(sizes[x] == sizes[y]) sizes[x]++;
    }
    bool connected(int x,int y){
return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    

    int N,M;
    cin>>N>>M;
    unionFind un(N);
    unordered_map<int,vector<int>> graph;
    for(int i = 0;i<M;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        un.unite(x,y);
        
    }
    int Q;
    cin>>Q;
    for(int i = 0;i<Q;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z == 1){
            x--;y--;
            if(un.connected(x,y)) cout<<1;
            else cout<<0;
        }
        else if(z == 2){
            x--;y--;
           un.unite(x,y);
        }
    }
      
    return 0;
}

//kruskal- hw2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{
    
    int from,to;
    long long effort,profit;
    int index;
};
struct unionFind{
    vector<int> parent, sizes;
    unionFind(int N){
    parent.resize(N+1);
    sizes.resize(N+1,0);
        for(int i=1;i<N+1;i++){
            parent[i] =i;
        }
    }
    
    int find(int x){
        if(parent[x] != x){
           parent[x] = find(parent[x]);}
           return parent[x];
        
    }
    
    bool unite(int a, int b){
     a = find(a);
     b = find(b);
        if(a == b) return false;
        if(sizes[a] < sizes[b]) swap(a,b);
        parent[b] = a;
        if(sizes[a] ==sizes[b])sizes[a]++;
        return true;
    }
    
    
};

int main() {
    int N,M;
    cin>>N>>M;
    vector<Edge> edges(M);
    for(int i = 0;i<M;i++){
        int a,b;
        long long c1,c2;
        cin>>a>>b>>c1>>c2;
        edges[i] = {a,b,c1,c2,i+1};
        
    }
    unionFind un(N);
    vector<int> indxs;
    sort(edges.begin(), edges.end(),[](const Edge& A, const Edge& B){
    if(A.effort != B.effort)
     return A.effort < B.effort;
        else return A.profit > B.profit;
   
    });
    
    int i = 0;
    while(i<M){
        if(indxs.size()==N-1)break;
        if(un.unite(edges[i].from, edges[i].to))indxs.push_back(edges[i].index);
        i++;
}
    for(size_t i =0;i<indxs.size();i++){
    cout<<indxs[i]<<'\n';
    }
    return 0;
}

//count components
 struct unionFind{
    vector<int> parent, sizes;
    unionFind(int n){
    sizes.resize(n,0);
    parent.resize(n);
    for(int i = 0;i<n;i++){
        parent[i] = i;
    }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    int unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(sizes[a]<sizes[b])swap(a,b);
        parent[b]= a;
        if(sizes[a] == sizes[b])sizes[a]++;
        return true;
    }
        
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        int comps = N;
        unionFind un(N);
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(isConnected[i][j] == 1){
                    if(un.unite(i,j)) comps--;
                }
            }
        }
        return comps;
    }

//find if path exist
struct unionFind{
    vector<int> parent, sizes;
    unionFind(int N){
        parent.resize(N);
        sizes.resize(N, 0);
        for(int i = 0;i<N;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
            
        }
        return parent[x];
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(sizes[a] < sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b]) sizes[a]++;
        return true;
    }
    bool inOneComponent(int a, int b){
        return find(a) == find(b);
    }

    };
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unionFind un(n);
        for(int i = 0;i<edges.size();i++){
            un.unite(edges[i][0], edges[i][1]);
        }
        return un.inOneComponent(source, destination);
    }

//finding minimal forest of K components
struct unionFind{
        vector<int> parent, sizes;
        unionFind(int n){
            parent.resize(n);
            for(int i = 0;i<n;i++){
                parent[i] = i;
            }
            sizes.resize(n,0);
        }
        int find(int x){
            if(x != parent[x]){
                parent[x] = find(parent[x]);

            }
            return parent[x];
        }
        bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a ==  b) return false;
        if(sizes[a] < sizes[b]) swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b]) sizes[a]++;
        return true;
        }
    }
    int minEdgesMakeKGora(int K,int N, vector<vector<int>>& edges){
        sort(edges.begin(), edges.end(), [](const vector<int>& A, const vector<int>& B){
            return A[2] < B[2];
        });
        vector<int> indxs;
        int components = N;
        int minSum = 0;
        unionFind un(N);
        for(int i = 0;i<edges.size();i++){
            if(components == K) break;
            if(un.unite(edges[i][0], edges[i][1]))
            {components--;minSum += edges[i][2];}
        }
        return minSum;
    }


//zad Find Path Using Dijkstra - shortest path

#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Edge{
  int to;
  int weight;
    
};

struct Node{
    int index;
    int distance;
    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
};

void dijkstra(unordered_map<int, vector<Edge>>& graph, int N, int s, int e){
    priority_queue<Node> pq;
    pq.push({s, 0});
    vector<int> dist(N+1, 1e9);
    vector<int> parent(N+1, -1);
    dist[s] = 0;
    
    while(!pq.empty()){
        
        auto el = pq.top();
        pq.pop();
        if(el.distance > dist[el.index])continue;
        
        for(auto ed:graph[el.index]){
            if(dist[ed.to] > el.distance + ed.weight){
                dist[ed.to] = el.distance + ed.weight;
                parent[ed.to] = el.index;
                pq.push({ed.to, dist[ed.to]});
            }
        }
    }
    if(dist[e] == 1e9){
        cout<<-1;
        return;
    }
    vector<int> stops;
    int curr = e;
    
    while(curr != -1){
        stops.push_back(curr);
        if(curr == s)break;
        curr = parent[curr];
    }
    
    reverse(stops.begin(), stops.end());
    for(size_t i = 0; i< stops.size();i++){
        cout<<stops[i]<<' ';
    }
    
}
int main()
{
    int N, M;
    cin>>N>>M;
    int S, X;
    cin>>S>>X;
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0;i<M;i++){
        int x, y, t;
        cin>>x>>y>>t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }
    dijkstra(graph, N, S, X);
    return 0;
}
