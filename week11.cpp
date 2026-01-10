

#include <iostream>
#include <unoredered_map>
#include <priority_queue>
#include <stack>
using namespace std;
struct Edge{
  int to, weight;  
};
struct Node{
  int index, distance;
  bool operator<(const Node& other) const{
      return distance > other.distance;
  }
};
vector<int> dijkstra(int start, int V, unoredered_map<int, vector<Edge>>& graph){
    vector<int> distances(V, INT_MAX);
    distances[start]=0;
    priority_queue<Node> nextToProcess;
    nextToProcess.push({start, 0});
    
    while(!nextToProcess.empty()){
        auto current = nextToProcess.top();
        nextToProcess.pop();
        
        if(current.distance > distances[current.index]){
            continue;
        }
        
        for(auto& edge:graph[current.index]){
            if(distances[edge.to] > current.distance + edge.weight){
                distance[edge.to] = current.distance + edge.weight;
                nextToProcess.push({edge.to, current.distance + edge.weight});
            }
        }
        return distances;
    }
}
struct EdgeOne{
    int from, to, weight;
};
vector<int> bellmanFord(int start, int V, vector<Edge>& edges){
   vector<int> distances(V, INT_MAX);
   distances[start] = 0;
   for(int i = 0;i<V - 1;i++){
       for(auto& edge: edges){
           if(distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]){
               distances[edge.to] = distances[edge.from] + edge.weight;
           }
       }
   }
   for(auto& edge:edges){
       if(distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]){
           throw logic_error("Negative cycle");
       }
   }
   return distances;
}
struct Edge{
  int to, weight;  
};

void TopologicalSort(int current, unoredered_map<int, vector<Edge>>& graph, vector<bool>& visited, stack<int>& st){
    visited[current] = true;
    if(graph.find(current) != graph.end()){
        for(auto& el : graph.at(current)){
            if(!visited[el.to]){
                visited[el.to] = true;
                TopologicalSort(el.to, graph, visited, st);
            }
        }
        st.push(current);
    }
}
vector<int> dagShorestPath(int start,int V, unoredered_map<int, vector<Edge>>& graph){
    vector<bool> visited(V, false);
    vector<int> distances(V, INT_MAX);
    distances[start] = 0;
    stack<int> topSort;
    
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            TopologicalSort(i, graph, visited, topSort);
        }
    }
    while(!topSort.empty()){
        auto el = topSort.top();
        topSort.pop();
        
        if(distances[el] != INT_MAX && graph.find(current) != graph.end()){
            for(auto& edge: graph[el]){
                if(distances[el] + edge.weight < distances[edge.to]){
                    distances[edge.to] = distances[el] + edge.weight;
                }
            }
        }
    }
    return distances;
}
int main()
{
    unoredered_map<int, vector<Edge>> mp;
    for(int i = 0;i<10;i++){
        int s,e,w;
        cin>>s>>e>>w;
        mp[s].push_back({e,w});
    }
  

    return 0;
}
zadachi - seminar

1/struct Edge{
  int to, weight;  
};
struct Node{
    int index;
    int distance;  
    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
};
const int INF = 1e9;
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<Edge>> graph;
  for(size_t i = 0; i<edges.size();i++){
    graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
  }
  priority_queue<Node> q;
  q.push({s, 0});
  vector<int> distances(n+1, INF);
  distances[s] = 0;
  while(!q.empty()){
    auto el = q.top();
    q.pop();
    
    if(distances[el.index] < el.distance) continue;
    for(auto e:graph[el.index]){
        int newWay = e.weight + distances[el.index];
        if(newWay < distances[e.to]){
            distances[e.to] = newWay;
            q.push({e.to, newWay});
        }
    }
  }
  vector<int> newDist;
  for(int i = 1;i<n+1;i++){
    if(distances[i] == INF) distances[i] = -1;
    if(distances[i] == 0)continue;
    newDist.push_back(distances[i]);
  }
  return newDist;
}

2/  struct Edge{
        int to, weight;
    };
    struct Node{
        int index, distance;
        bool operator<(const Node& other) const{
            return distance > other.distance;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<Edge>> graph;
        for(int i = 0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<Node> q;
        vector<int> distances(n+1, 1e9);
        distances[k] = 0;
        q.push({k, 0});
        while(!q.empty()){
            auto el = q.top();
            q.pop();
            if(distances[el.index] < el.distance) continue;
            for(auto e:graph[el.index]){
                int newSig = distances[el.index] + e.weight;
                if(newSig < distances[e.to]){
                    distances[e.to] = newSig;
                    q.push({e.to, newSig});
                }
            }
        }
        int maxi = 0;
        for(int i = 1;i<=n;i++){
            maxi = max(maxi, distances[i]);
            if(distances[i] == 1e9) return -1;
        }
       return maxi;
    }

3/using namespace std;

struct Edge{
int to, weight;
};
struct Node{
int index;
int distance;
bool operator<(const Node& other) const{
return distance < other.distance;
}
};
int maxPath(unordered_map<int, vector<Edge>>& graph, int s, int t, int n){
vector<int> dist(n+1, -1e9);
dist[s] = 0;
priority_queue<Node> q;
    q.push({s, 0});
    while(!q.empty()){
        auto el = q.top();
        q.pop();
        if(el.distance < dist[el.index]) continue;
        for(auto e:graph[el.index]){
          int newWay = dist[el.index] + e.weight;
            if(newWay > dist[e.to]){
               dist[e.to] = newWay;
                q.push({e.to, newWay});
            }
        }
    }
    return dist[t] != -1e9 ? dist[t] : -1;
}
int main() {
    unordered_map<int, vector<Edge>> graph;
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    for(int i = 0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y, w});
    }
    
   cout<<maxPath(graph, s, t, n);
    return 0;
}
4/ struct Edge{
        int to;
        double weight;
    };
    struct Node{
      int index;
      double distance;
      bool operator<(const Node& other) const{
        return distance < other.distance;
      }
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<Edge>> graph(n);
        for(int i = 0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<Node> q;
        q.push({start_node, 1});
        vector<double> dist(n, 0);
        dist[start_node] = 1;
        while(!q.empty()){
            auto el = q.top();
            q.pop();

            if(dist[el.index] > el.distance) continue;

            for(auto e:graph[el.index]){
              
               double newProb = dist[el.index] * e.weight;
      
                if(newProb > dist[e.to]){
                    dist[e.to] = newProb;
                    q.push({e.to, newProb});
                }
            }
        }
        return dist[end_node];
    }
5/bool isValid(int x, int y, int n, int m){
        return (x>=0 && x <= n-1 && y >= 0 && y <= m-1);
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        deque<pair<int, int>> q;
        q.push_front({0,0});
        dist[0][0] = 0;
        while(!q.empty()){
            auto el = q.front();
            q.pop_front();
            int x = el.first;
            int y = el.second;
            vector<pair<int, int>> vec = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
            for(int i = 0;i<4;i++){

                int dx = vec[i].first;
                int dy = vec[i].second;

               if(isValid(dx, dy,n, m) && dist[dx][dy] == -1){
                if(grid[dx][dy] == 1){
                    q.push_back({dx, dy});
                    dist[dx][dy] = dist[x][y] + 1;
                }
                else{
                    q.push_front({dx, dy});
                    dist[dx][dy] = dist[x][y];
                }
               }
            }
        }
     
        return dist[n-1][m-1] != -1 ? dist[n-1][m-1] : -1;

    }
6/ bool isValid(int n, int m, int x, int y){
        return (x>=0 && x < n && y >= 0 && y< m);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        deque<pair<int, int>> q;
        q.push_front({0,0});
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        while(!q.empty()){
            auto el = q.front();
            q.pop_front();
            int x = el.first;
            int y = el.second;
            vector<pair<int,int>> vec = {{x, y+1}, {x, y-1}, {x+1, y}, {x-1, y}};
            for(int i = 0;i<4;i++){
                int dx = vec[i].first;
                int dy = vec[i].second;
               if(isValid(n,m,dx,dy)){
                int cost = grid[x][y]-1 == i ? 0 : 1;
                int current = cost + dist[x][y];
                if(current < dist[dx][dy]){
                if(grid[x][y]-1 == i){
                    dist[dx][dy] = current;
                    q.push_front({dx, dy});
                }
                else{
                    dist[dx][dy] = current;
                     q.push_back({dx, dy});
                }
                }
               }
            }
        }
        return dist[n-1][m-1];
    }
7/const int INF = 1e9;
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 && x < n && y>=0 && y < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while(!q.empty()){
            auto el = q.front();
            q.pop();
            int x = el.first;
            int y = el.second;
            vector<pair<int, int>> vec = {{x, y-1}, {x, y+1}, {x-1, y}, {x+1, y}};
            for(int i = 0;i<4;i++){
                int dx = vec[i].first;
                int dy = vec[i].second;
                if(isValid(dx, dy,n,m)){
                    
                    if(dist[dx][dy]>max(dist[x][y], abs(heights[dx][dy] - heights[x][y]))){
                        dist[dx][dy]=max(dist[x][y], abs(heights[dx][dy] - heights[x][y]));
                        q.push({dx, dy});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
8/

//Homework
1/#include <unordered_map>
const int INT_MAX = 1e9;
using namespace std;
struct Edge{
  int to, weight;
};
struct Node{
    int index;
    int time;
    int distance;
    
    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
};
int dijkstraForTime(unordered_map<int, vector<Edge>>& graph,vector<Node>& nodes, int s, int e, int V){
    vector<int> distances(V, INT_MAX);
    priority_queue<Node> next;
    distances[s] = 0;
    next.push({s,nodes[s].time, 0});
    
    while(!next.empty()){
    auto el = next.top();
        next.pop();
        if(el.distance > distances[el.index]){
           continue;
        }
        int wait = 0;
        if( distances[el.index] % el.time == 0)wait = 0;
        else wait = el.time - distances[el.index] % el.time;
        for(auto e:graph[el.index]){
           
            if(distances[el.index] + e.weight + wait < distances[e.to]){
                distances[e.to] = distances[el.index] + e.weight + wait;
                next.push({e.to, nodes[e.to].time, distances[el.index] + e.weight + wait});
            }
        }
    }
    
    
    return distances[e] != INT_MAX ? distances[e] : -1;
}
int main() {
    int V, E,s,e;
    cin>>V>>E>>s>>e;
    unordered_map<int, vector<Edge>> graph;
    vector<Node> nodes;
    for(int i = 0;i<V;i++){
        int t;
        cin>>t;
        nodes.push_back({i, t});
    }
    for(int j = 0;j<E;j++){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        graph[n1].push_back({n2, w});
    }
     cout<<dijkstraForTime(graph,nodes,s,e,V);
    return 0;
}

2/#include <deque>
using namespace std;
bool isValid(int N, int M, int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < M);
}
int countCells(vector<vector<char>>& matrix, int N, int M){
    deque<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(M, -1));
    for(int i = 0;i<N;i++){
        if(matrix[i][0] == '.'){q.push_front({i, 0});dist[i][0] = 0;}
        else{dist[i][0] = 1; q.push_back({i, 0});};
        if(matrix[i][M-1] == '.'){q.push_front({i, M-1});dist[i][M-1] = 0;}
         else{dist[i][M-1] = 1; q.push_back({i, M-1});};
        
    }
    for(int i = 1;i<M-1;i++){
        if(matrix[0][i] == '.'){q.push_front({0, i});dist[0][i] = 0;}
         else{dist[0][i] = 1; q.push_back({0, i});};
        if(matrix[N-1][i] == '.'){q.push_front({N-1, i});dist[N-1][i] = 0;}
         else{dist[N-1][i] = 1; q.push_back({N-1, i});};
    }
    
    while(!q.empty()){
        auto el = q.front();
        q.pop_front();
        
        int x = el.first;
        int y = el.second;
        vector<pair<int, int>> vec = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
        for(int i = 0;i<4;i++){
            int dx = vec[i].first;
            int dy = vec[i].second;
            if(isValid(N,M,dx,dy) && dist[dx][dy] == -1){
                if(matrix[dx][dy] == '.'){
                    dist[dx][dy] = dist[x][y];
                    q.push_front({dx,dy});
                }
                else
                {
                dist[dx][dy] = dist[x][y] + 1;
                q.push_back({dx, dy});
                }
            }
        }
    }
        int maxi = 0;
        for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(matrix[i][j] == '.') maxi = max(maxi, dist[i][j]);
        }
        }
        int count = 0;
        for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(matrix[i][j] == '.' && maxi == dist[i][j])count++;
        }
        }
   
    return count;
}

int main() {
    int N, M;
    cin>>N>>M;
    vector<vector<char>> matrix(N, vector<char>(M));
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
          cin>>matrix[i][j];
        }
    }
    cout<<countCells(matrix, N, M);
    
    return 0;
}


3/
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// #include <queue>

// using namespace std;
// const int INT_MAX = 1e9;
// struct Edge{
//   int to, weight, time;  
// };
// struct Node{
//     int index;
//     int distance;
//     int time;
    
//     bool operator<(const Node& other) const{
//         if(distance != other.distance)
//             return distance > other.distance;
//         else return time > other.time;
//     }
    
// };



// int getThin(unordered_map<int, vector<Edge>>& graph, int V, int K){
//   //  vector<pair<int, int>> distances(V+1, {INT_MAX, 0});
//     vector<vector<int>> distances(V+1, vector<int>(K+1, INT_MAX));
//     distances[1][0] = 0;
//     priority_queue<Node> q;
//     q.push({1, 0, 0});
//     while(!q.empty()){
//         auto el = q.top();
//         q.pop();
        
        
      
//         if(distances[el.index][el.time] < el.distance) continue;
//         for(auto e:graph[el.index]){
//             int newWeight = e.weight + el.distance;
//             int newTime = e.time + el.time;
//             if(newTime <= K && distances[e.to][newTime] > newWeight){
//                 distances[e.to][newTime] = newWeight;
              
// //                 distances[e.to].first = distances[el.index].first + e.weight;
// //                 distances[e.to].second = distances[el.index].second + e.time;
//                 q.push({e.to, newWeight, newTime});
//             }
//         }
//     }
//     int ans = INT_MAX;
//     for(int i = 0;i<=K;i++){
//         ans = min(ans, distances[V][i]);
//     }
//     return ans != INT_MAX ? ans : -1;
//     //if(distances[7].first == INT_MAX || distances[7].second > K) return -1;
//     //return -1;
// }
// int main() {
//     int V, E, K;
//     cin>>V>>E>>K;
//     unordered_map<int, vector<Edge>> graph;
//     vector<Node> nodes(V+1);
//     for(int i = 0;i<E;i++){
//        int start, end, kg, time;
//         cin>>start>>end>>kg>>time;
//         graph[start].push_back({end, kg, time});
        
//     }
//     cout<<getThin(graph, V, K);
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int INF= 1e9;
struct Edge{
    int to, weight, time;
};
bool canReach(int maxWeight, int V, int K, unordered_map<int, vector<Edge>>& graph){
    vector<int> dist(V+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[1] = 0;
    q.push({1, 0});
    while(!q.empty()){
        auto el = q.top();
        q.pop();
        int index = el.first;
        int time = el.second;
        if(time > dist[index])continue;
        for(auto e:graph[index]){
            if(e.weight > maxWeight) continue;
            int nt = time + e.time;
            if(nt < dist[e.to]){
                dist[e.to] = nt;
                q.push({e.to, nt});
            }
        }
    }
    return dist[V] <= K;
}

int main() {
    int V, E, K;
    cin>>V>>E>>K;
    int maxW = 0;
    unordered_map<int, vector<Edge>> graph;
  
    for(int i = 0;i<E;i++){
       int start, end, kg, time;
        cin>>start>>end>>kg>>time;
        graph[start].push_back({end, kg, time});
        maxW = max(maxW, kg);
        
    }
    int l = 0;
    int r = maxW;
   int ans = -1;
    while(l <= r){
        int m = l + (r-l)/2;
        if(canReach(m, V, K, graph)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout<< ans <<'\n';
  
 
    return 0;
}

zadacha 
idejna
   struct Edge{
        int to;
        int weight;
       
    };
    struct Node{
        int index;
        int distance;
        int cost;
        bool operator<(const Node& other) const{
     
            return distance > other.distance;
        }
    };
    bool dijkstra(unordered_map<int, vector<Edge>>& graph, int n, int maxTime, vector<int>& passingFees, int cost){
        priority_queue<Node> pq;
        int start = 0;
       
        pq.push({start, 0,passingFees[0]});
        vector<int> mincost(n, 1e9);
        vector<int> dist(n, 1e9);
        dist[start] = 0;
       mincost[start] = passingFees[start];
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
           
            if(curr.index == n-1)return true;
             
            if(curr.cost > cost) continue;
        
            for(auto e:graph[curr.index]){
                int newTime = curr.distance + e.weight;
                int newCost = curr.cost + passingFees[e.to];
                if(newTime<=maxTime && newCost <= cost && mincost[e.to] > newCost){
                
                    mincost[e.to] = newCost;
                    pq.push({e.to,newTime,newCost});
                }
            }
        }
        return false;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
         unordered_map<int,vector<Edge>> mp;
         for(int i= 0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            mp[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            
         }
         int n = passingFees.size();
         int l = 0;

         int r = 0;
         for(int i = 0;i<passingFees.size();i++){
            r += passingFees[i];
         }
         bool flag = false;
         while(l<r){
            int m = l +(r-l)/2;
            if(dijkstra(mp,n,maxTime,passingFees,m)){
                r = m;
                flag = true;
            }
            else l=m+1;
         }
         if(!flag) return -1;
         return l;
               
    }
//zadacha incost we have maxTime limit
  vector<vector<int>> adj[1001];
    int cost[1001], time[1001];

    int dijkstra(int src, int dest, int maxTime){
      for(int i = 1;i<=dest;i++){
        cost[i] = INT_MAX;
        time[i] = INT_MAX;
      }

      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      pq.push({cost[src], time[src], src});

      while(!pq.empty()){
         vector<int> z = pq.top();
         pq.pop();
         int c = z[0];
         int t = z[1];
         int v = z[2];

         for(int i = 0;i < adj[v].size();i++){

            if(t + adj[v][i][1] > maxTime) continue;

            if(cost[adj[v][i][0]] > c + adj[v][i][2]){
                cost[adj[v][i][0]] = c + adj[v][i][2];
                time[adj[v][i][0]] = t + adj[v][i][1];
                pq.push({cost[adj[v][i][0]], time[adj[v][i][0]], adj[v][i][0]});
            }
            else if(time[adj[v][i][0]] > t + adj[v][i][1]){
                time[adj[v][i][0]] = t + adj[v][i][1];
                pq.push({c + adj[v][i][2], time[adj[v][i][0]], adj[v][i][0]});
            }
         }
      }
      return cost[dest];
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int i,x,y,t,e=edges.size(), n=passingFees.size();
    for(i = 0;i<e;i++){
        x = edges[i][0];
        y = edges[i][1];
        t = edges[i][2];

        adj[x].push_back({y,t,passingFees[y]});
        adj[y].push_back({x,t,passingFees[x]});
    }
    cost[0] = passingFees[0];
    time[0] = 0;
    int ans= dijkstra(0,n-1,maxTime);
    if(ans == INT_MAX) return -1;
       return ans;
    }

 5/ struct Edge{
       int to,weight;
    };
    struct Node{
       int index;
       long long time;
       long long ways;
       bool operator<(const Node& other) const{
        return time > other.time;
       }
    };
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<Edge>> graph(n);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});

        }
        int MOD = 1e9 + 7;
        vector<long long> times(n,LLONG_MAX);
        vector<long long> ways(n,0);
        priority_queue<Node> pq;
       
        int start = 0;
        times[start] = 0;
        ways[start] = 1;
        pq.push({start, 0, 1});
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            int idx = el.index;
            long long t = el.time;
            long long w = el.ways;
            
            if(t > times[idx])continue;

            for(auto& e:graph[idx]){
                
                if(times[e.to] > t + e.weight){
                    times[e.to] = t + e.weight;
                    ways[e.to] = ways[idx];
                   // cout<<ways[e.to]<<'\n';
                    pq.push({e.to,times[e.to], ways[e.to]});
                }
                else if(t + e.weight == times[e.to]){
                    ways[e.to] = (ways[e.to] + ways[idx]) % MOD;
                    
                }
               // cout<<times[idx]<<' '<<times[e.to]<<' '<<t<<'\n';
            }
        }
        return ways[n-1];
    }

zad HARD grid time
 bool isValid(int x, int y, int n, int m){
        return (x >= 0 && x<n && y>=0 && y < m);
    }
    struct Edge{
        pair<int, int> to;
        int time;
    };
    struct Node{
        pair<int, int> index;
        int time;
        bool operator<(const Node& other) const{
            return time > other.time;
        }
    };  
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<Node> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        pq.push({{0,0}, 0});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            int x = el.index.first;
            int y = el.index.second;
            if(el.time > dist[x][y])continue;
            vector<pair<int, int>> vec = {{x, y-1}, {x, y + 1}, {x-1, y}, {x+1, y}};
            for(int i = 0;i<4;i++){
                int dx = vec[i].first;
                int dy = vec[i].second;
                //&& el.time + 1 >= grid[dx][dy] && dist[dx][dy] > el.time + 1
                if(isValid(dx,dy,n,m)){
                    int wait = (grid[dx][dy] - el.time) % 2 == 0;
                    int arrive = max(el.time + 1, grid[dx][dy] + wait);
                    if(dist[dx][dy] > arrive){
                    dist[dx][dy] = arrive;
                    pq.push({{dx, dy}, arrive});}
                    
                }
            }
        }
      return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1] ;
    }

8/   bool isValid(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    struct Node{
        pair<int, int> index;
        int time;
        bool operator<(const Node& other) const{
            return time > other.time;
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        pair<int, int> start = {0, 0};
        priority_queue<Node> pq;
        int n = grid.size();
        int m = grid[0].size();
        pq.push({start, 0});
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];
       
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            int x = el.index.first;
            int y = el.index.second;

            if(el.time > dist[x][y]) continue;
            vector<pair<int,int>> vec = {{x-1, y}, {x+1, y}, {x,y-1}, {x, y+1}};
            for(int i = 0;i<4;i++){
                int dx = vec[i].first;
                int dy = vec[i].second;
                 if(!isValid(dx,dy,n,m)) continue;
             
                // int newTime = max(dist[x][y], grid[dx][dy]);
                // if(dist[dx][dy] > newTime){
                //     dist[dx][dy] = newTime;
                //     pq.push({{dx,dy}, newTime});
                // }
                if(dist[x][y] > grid[dx][dy]){
                    if(dist[dx][dy] > dist[x][y]){
                     dist[dx][dy] = dist[x][y];
                     pq.push({{dx, dy}, dist[dx][dy]});}
                }
                else{
                    int wait = grid[dx][dy];
                    if(dist[dx][dy] > wait){
                        dist[dx][dy] = wait;
                        pq.push({{dx, dy}, wait});
                    }
                }
            }
        }
           return dist[n-1][m-1];
        } 

//BellmanFord Algorithm
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> distances(n, INT_MAX);
    distances[src] = 0;
    for(int i = 0;i<=k;i++){
       vector<int> nextRow(distances);
       for(auto edge:flights){
        if(distances[edge[0]] != INT_MAX){
            nextRow[edge[1]] = min(nextRow[edge[1]], distances[edge[0]] + edge[2]);
        }
       }
       distances = std::move(nextRow);
    }
    if(distances[dst] == INT_MAX) return -1;
    return distances[dst];

}

//Kontrolno 6
lesna zadachaa 2 :(
{
    int N;
    cin>>N;
    queue<int> q;
    unordered_map<int, int> mp;
    for(int i = 0;i<N;i++){
        int x;
        cin>>x;
        mp[x]++;
        q.push(x);
        while(!q.empty() && mp[q.front()] > 1) {
            q.pop();
            
        }
        if(q.empty()) cout<<-1;
        else cout<<q.front();
        cout<<' ';
    }
    return 0;
}
