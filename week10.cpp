1/int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> mp;
        vector<int> trustedBy(n);
        for(int i = 1;i<=n;i++){
            mp[i] = {};
        }
        for(int i = 0;i<trust.size();i++){
            mp[trust[i][0]].insert(trust[i][1]);
            trustedBy[trust[i][1]-1]++;
        }

        for(auto el:mp){
            if(el.second.empty() && trustedBy[el.first-1] == n-1)
             return el.first;
        }
        return -1;
}

2/ void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur){
        path.push_back(cur);
        if(cur == graph.size() - 1){
            res.push_back(path);
        }
        else for(auto it: graph[cur])
            dfs(graph, res, path, it);
            path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths,path,0);
        return paths;
    }

3/CYCLE IN GRAPH
using namespace std;
bool IsCycle(){
int V, E;
    cin>>V>>E;
    vector<vector<int>> graph(V+1);
    for(int i = 0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(y);
       
}
  
    vector<bool> visited(V+1, false);
    vector<bool> inStack(V+1, false);

    for(int i = 1;i<=V;i++){
        if(visited[i])continue;
        stack<int> st;
        st.push(i);
        while(!st.empty()){
            int el = st.top();
            if(!visited[el]){
             visited[el] = true;
                inStack[el] = true;
            }
            bool allnbr = true;
            for(auto it:graph[el]){
                if(inStack[it]) return true;
               if(!visited[it]) {
                   allnbr = false;
                   st.push(it);
              
                   break;
               }
                
            }
            if(allnbr){
            st.pop();
                inStack[el] = false;
            }
        }
    }
    return false;
}

4/bfs - shortest path
#include <iostream>
#include <queue>
using namespace std;
void bfs(vector<vector<int>>& graph, vector<int>& res){
    queue<int> q;
    int start = 1;
    q.push(start);
     vector<bool> visited(graph.size());
    visited[start] = true;
    res[start] = 0;
    while(!q.empty()){
        int node = q.front();
        visited[node] = true;
        q.pop();
       
        for(auto c: graph[node]){
            if(!visited[c]){
                visited[c] = true;
                q.push(c);
                res[c] = res[node] + 1;
            }
        }
    }
    for(int i =1;i<res.size();i++){
        if(i == start)continue;
        // if(!res[i]) cout<<-1<<' ';
        cout<<res[i]<<' ';
    }
}
int main()
{
    vector<vector<int>> graph = {{}, {2, 3}, {3, 4},{4}, {}};
    vector<int> res(5,-1);
    bfs(graph, res);
    //std::cout<<"Hello World";

    return 0;
}

5/    bool dfs(unordered_map<int, vector<int>>& graph, set<int>& visited, int node, int destination){
            if(node == destination) return true;
            visited.insert(node);
            for(auto it:graph[node]){
                if(visited.find(it) == visited.end()){
                    if(dfs(graph, visited, it, destination)) return true;
                }
            }
            return false;
            
        }
         bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         unordered_map<int, vector<int>> graph;
         for(int i = 0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
         }
         set<int> visited;
        return dfs(graph, visited, source, destination);
    }
6/ int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
          vector<int> connectNodes(edges.size()+2);
         // unoredered_map<int, vector<int>> mp;
          for(int i = 0;i<edges.size();i++){
            connectNodes[edges[i][0]]++;
            connectNodes[edges[i][1]]++;
          }
         for(int i = 0;i<connectNodes.size();i++){
            if(connectNodes[i] == n) return i;
         }
         return -1;
    }

//zadachi ---------------------------------- v izpylnenie
7/struct Comparator{
    bool operator()(const pair<int, int> A, const pair<int, int> B){
        if(A.second != B.second) return A.second > B.second;
        else return A.first > B.first;
    }
};
int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> q;
    int N;
    cin>>N;
    int K;
    cin>>K;
    vector<int> vec;
    map<int, int> mp;
    for(int i = 0;i<N;i++){
     //   cin>>nums[i];
     int x;
     cin>>x;
        mp[x]++;
    }
    
    for(auto el:mp){
        q.push(el);
        if(q.size() >K)q.pop();
    }
    while(!q.empty()){
        vec.push_back(q.top().first);
        q.pop();
    }
    reverse(vec.begin(), vec.end());
    for(size_t i = 0;i<vec.size();i++){
        cout<<vec[i]<<' ';
    }

    return 0;
}
8/IMPORTANT TASK -DVUDELEN GRAPH
bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> colors(graph.size(), -1);
        queue<int> nodes;
        for(int i = 0;i<N;i++){
            if(colors[i] == -1){
           nodes.push(i);
           colors[i] = 0;
           while(!nodes.empty()){
            int el = nodes.front();
            nodes.pop();
            for(auto c : graph[el]){
                if(colors[c] == -1) {colors[c] = 1 - colors[el];nodes.push(c);}
                else if(colors[c] == colors[el]) return false;
            }
           }
            }
        }
        return true;

    }
9/    bool dfs(vector<vector<int>>& nums, vector<bool>& visited){
      stack<int> st;
      st.push(0);
      int cnt = 0;
      while(!st.empty()){
         int room = st.top();
         st.pop();
         cnt++;
         visited[room] = true;
         for(auto c:nums[room]){
            if(!visited[c]){
                visited[c] = true;
                st.push(c);
            }
         }
      }
      return  cnt == nums.size();
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

          vector<bool> visited(rooms.size());
         return dfs(rooms, visited);

9.1/bool dfs(vector<vector<int>>& rooms,vector<bool>& visited, int node, int cnt){
       if(cnt == rooms.size()) return true;
       visited[node] = true;
       for(auto el: rooms[node]){
        if(!visited[el])
       dfs(rooms, visited, el, cnt+1);
       }

       return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

          vector<bool> visited(rooms.size());
          dfs(rooms, visited, 0, 0);
         for(auto el:visited){
            if(!el) return false;
         }
         return true;

10/ 1/3 working solution
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);

        }
        vector<pair<int, int>> nodes;
        vector<bool> visited(mp.size()+1);
        int level = 0;
        for(auto el:mp){
            queue<int> q;
            if(!visited[el.first]){
                visited[el.first] = true;
                q.push(el.first);
                nodes.push_back({el.first, level});
                while(!q.empty()){

                    auto el = q.front();
                    q.pop();
                    for(auto e:mp[el]){
                        if(!visited[e]){
                            visited[e] = true;
                            q.push(e);
                        }
                    }
                }
            }
            level++;
        }
        sort(nodes.begin(), nodes.end(), [](const pair<int, int>& A, const pair<int, int>& B){
            return A.second<B.second;
        });

        unordered_map<int, pair<int, int>> p;
        for(auto el:nodes){
            p[el.second].first++;
            p[el.second].second+= mp[el.first].size();
        }
        int cnt = 0;
        for(auto el:p){
            int l = el.second.first;
            if(l*(l-1)/2 == el.second.second/2)cnt++;
        }
        return cnt;

    }
10/working solution
int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[i] = {};
        }
        for(int i = 0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);

        }
        //vector<pair<int, int>> nodes;
        vector<bool> visited(n);
        int cnt = 0;
        for(auto el:mp){
            queue<int> q;
            int nodes = 0;
            int ribs = 0;
            if(visited[el.first])continue;
                visited[el.first] = true;
                q.push(el.first);
                while(!q.empty()){
                    auto el = q.front();
                    nodes++;
                    ribs += mp[el].size();
                    q.pop();
                    for(auto e:mp[el]){
                        if(!visited[e]){
                            visited[e] = true;
                            q.push(e);
                            
                        }
                    }
                }
                if(ribs/2 == nodes * (nodes-1)/2)cnt++;
            }
    
        
         return cnt;

11/ vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<prerequisites.size();i++){
         //   mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<int> indg(numCourses, 0);
        for(int i = 0;i<prerequisites.size();i++){
            indg[prerequisites[i][0]]++;
        }
        for(int i = 0;i<numCourses;i++){
            if(indg[i] == 0)q.push(i);

        }
        vector<int> order;
        
        while(!q.empty()){
            auto el = q.front();
            order.push_back(el);
            q.pop();
            for(auto l: mp[el]){
                indg[l]--;
                if(indg[l] == 0)q.push(l);
            }
        }
        if(order.size() != numCourses)return {};
        return order;
    }

12/  int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++)mp[i]={};
        for(int i = 0;i<edges.size();i++){
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int i = -1;
        int cnt = 0;
        for(auto el:mp){
            if(el.second.empty()){cnt++; i = el.first;}
        }
        if(cnt != 1) return -1;
        return i;
    }

13/  int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<size;i++){
            for(int j = 0;j<size;j++){
                if(isConnected[i][j]) {
                mp[i].push_back(j);
                mp[j].push_back(i);}
            }

        }
        vector<int> visited(size);
        int cnt = 0;
        for(int i = 0;i<size;i++){
            if(visited[i])continue;
            queue<int> q;
            q.push(i);
            cnt++;
            while(!q.empty()){
                int el = q.front();
                q.pop();
                for(auto e:mp[el]){
                    if(!visited[e]){
                        visited[e] = true;
                        q.push(e);
                    }
                }

            }

        }
        return cnt;
    }
//path exist - bfs
 bool bfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int node, int des){
           if(node == des) return true;
           queue<int> q;
           q.push(node);
           while(!q.empty()){
            int el = q.front();
            q.pop();
            visited[el] = true;
            for(auto e:graph[el]){
                if(!visited[e]){
                if(e == des) return true;
                visited[e] = true;
                q.push(e);}
            }
           }
           return false;

        }

8/all stars
void printStarCenters(vector<vector<int>>& pairs, ){
    vector<int> nbs(2*pairs.size(), 0);
    for(int i = 0;i<pairs.size();i++){
        nbs[pairs[i][0]]++;
        nbs[pairs[i][1]]++;
    }
    vector<int> stars;
    for(int i = 0;i<2*n;i++){
        if(nbs[i] > 1) stars.push_back(i);
    }
    for(int i = 0;i<stars.size();i++){
        cout<<stars[i]<<' ';
    }
}


//HOMEWORK
1/#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool isValid(int N, int x, int y){
return (x < N && x >= 0 && y>= 0 && y< N);
}
vector<pair<int, int>> nbs(int x, int y){
vector<pair<int, int>> vec = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    return vec;
}
void printRegions(vector<vector<int>>& matrix, int N){
    vector<int> res;
    vector<vector<bool>> visited(N, vector<bool>(N));
    for(int i = 0;i<N;i++){
       for(int j = 0;j<N;j++){
           queue<pair<int, int>> q;
           if(!visited[i][j] && matrix[i][j] == 1){
                q.push({i, j});
            //   cout<<i<<' '<<j;
               visited[i][j] = true;
               int minidxI = i;
               int maxidxI = i;
               int minidxJ = j;
               int maxidxJ = j;
                while(!q.empty()){
               vector<pair<int, int>> help = nbs(q.front().first, q.front().second);
                    q.pop();
                    for(int i = 0;i<4;i++){
                        int h1 = help[i].first;
                        int h2 = help[i].second;
                        if(isValid(N, h1, h2) && !visited[h1][h2] && matrix[h1][h2] == 1){
                           visited[h1][h2] = true;
                            
                             minidxI = min(minidxI, h1);
                             maxidxI = max(maxidxI, h1);
                             minidxJ = min(minidxJ, h2);
                             maxidxJ = max(maxidxJ, h2);
                            
                            q.push({h1, h2});
                        }
                    }
                   // cout<<maxidxI<<' '<<minidxI<<' ';
                }
               int s = (maxidxI - minidxI)*(maxidxJ - minidxJ);
               res.push_back(s);
           }
       }
    }
    sort(res.begin(), res.end(),[](const int a, const int b){
        return a > b;
    });
    for(size_t i = 0;i<res.size();i++){
    cout<<res[i]<<' ';
    }
    
}
int main() {
    int N;
    cin>>N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for(int i = 0;i<N;i++){
    for(int j= 0;j<N;j++){
        cin>>matrix[i][j];
    }
    }
    printRegions(matrix, N);
   }

2/
pair<char, char> lin(string& word1, string& word2){
int i = 0;
    int len = min(word1.size(), word2.size());
while(i<len && word1[i] == word2[i]){
i++;
}
    if(i == len) return {'0', '0'};
    return {word1[i], word2[i]};
}
int main() {
    int N;
    cin>>N;
    vector<string> words;
    for(int i = 0;i<N;i++){
        string word;
        cin>>word;
        words.push_back(word);
    }
    vector<pair<char, char>> vec;
    map<char, vector<char>> mp;
    set<char> st;
    for(int i = 1;i<N;i++){
        string word1 = words[i-1];
        string word2 = words[i];
        auto help = lin(word1, word2);
        if(help.first=='0')continue;
        vec.push_back(help);
        
        char el1 = help.first;
        char el2 = help.second;
        st.insert(el1);
        st.insert(el2);
        mp[el1].push_back(el2);
        
    }
    map<char, int> indg;
      for(auto el:st)indg[el]=0;
    for(size_t i = 0;i<vec.size();i++){
        indg[vec[i].second]++;
    }
    vector<char> res;
    queue<char> q;
  
    for(auto el:indg){
if(el.second == 0)q.push(el.first);
    }
    while(!q.empty()){
auto el = q.front();
        res.push_back(el);
        q.pop();
        for(auto l:mp[el]){
            indg[l]--;
            if(indg[l] == 0)q.push(l);
        }
    }
    for(char c:res){
        cout<<c<<' ';
    }
    
    
3/
int bfs(vector<pair<int, vector<int>>>& graph, int N, int Mine){
    vector<int> friends;
    for(int i = 1;i<=N;i++){
        
        if(graph[i].first == Mine){
            friends.push_back(i);
        }
    }
    int minDist = 1e9;

    for(int start: friends){
        queue<int> q;
        vector<int> dist(N+1, -1);
        q.push(start);
        dist[start] = 0;
        while(!q.empty()){
         int u = q.front();
            q.pop();
            for(int c:graph[u].second){
                if(dist[c] == -1){
                    dist[c] = dist[u] + 1;
                    q.push(c);
                }
                    if(graph[c].first == Mine && c != start){
                        minDist = min(minDist, dist[c]);
                    }
                }
            }
        }
    
    return minDist == 1e9 ? -1 : minDist;
}

int main() {
    int N, M;
    cin>>N>>M;
    vector<pair<int, vector<int>>> g(N+1);
    for(int i = 0;i<M;i++){

    int x, y;
    cin>>x>>y;
        g[x].second.push_back(y);
        g[y].second.push_back(x);
    }
    for(int i = 1;i<=N;i++){
    cin>>g[i].first;
    }
    int Mine;
    cin>>Mine;
    cout<<bfs(g, N, Mine);
  
    return 0;
}

//zadachi - pregovor

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
void bfs(vector<vector<int>>& g){
    int start = 0;
    queue<int> q;
    vector<bool> visited(g.size());
   
    q.push(start);
    while(!q.empty()){
        int el = q.front();
        q.pop();
        cout<<el<<'\n';
        visited[el] = true;
        for(auto e: g[el]){
            if(!visited[e]){
                q.push(e);
                visited[e] = true;
            }
        }
    }
}
void dfs(vector<vector<int>>& g){
    stack<int> st;
    st.push(0);
    vector<bool> visited(g.size());
    while(!st.empty()){
        int el = st.top();
        st.pop();
        if(!visited[el]){
        cout<<el<<'\n';
        visited[el] = true;
        for(auto e: g[el]){
            if(!visited[e]){
                st.push(e);
                visited[e] = true;
            }
        }
        }
    }
}
bool existPath(vector<vector<int>>& graph,vector<bool> visited, int node,int des){
    if(node == des) return true;
    visited[node] = true;
    for(auto el:graph[node]){
        if(!visited[el]){
            if(existPath(graph, visited, el, des)) return true;
        }
    }
    return false;
}
// void minDist(vector<pair<int, vector<int>>>& graph, int fr){
//      vector<bool> visited(graph.size());
//     vector<int> dist(graph.size(), -1);
//     queue<int> q;
//     vector<int> friends;
//     for(int i=0;i<graph.size();i++){
//         if(graph[i].first == fr) friends.push_back(i);
//     }
//     int minDist = 1e9;
//     for(auto start: friends){
//     vector<int> dist(graph.size());
//     queue<int> q;
//     q.push(i);
//     dist[start] = 0;
//     while(!q.empty()){
//         int el= q.top();
//         q.pop();
//         for(auto e:el){
//             if(dist[e] == -1){
//                 dist[e] = dist[el] + 1;
//                 q.push(e);
       
//                 if(graph[e].first == fr){
//                 minDist = min(minDist, dist[e]);
                    
//                 }
//             }
//         }
//     }
    
//     }
//     return minDist = minDist==1e9 ? -1 : minDist;
    
    
// }
bool CycleInGraph(vector<vector<int>>& graph){
    vector<bool> visited(graph.size());
    for(int i = 0;i<graph.size();i++){
        if(visited[i]) continue;
        stack<int> q;
        q.push(i);
        vector<int> instack(graph.size());
        instack[i] = true;
        while(!q.empty()){
            int el = q.top();
            visited[el] = true;
            bool all = true;
            for(auto c:graph[el]){
                if(q.find(c) != q.end()) return true;
                if(!visited[c]){
                    all = false;
                    q.push(c);
                    visited[c] = true;
                }
            }
            if(all){
                instack[c] = false;
                st.pop();
            }
        }
        
    }
    return false;
}
//topological sort
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<numCourses;i++){
            mp[i] = {};
        }
        for(int i = 0;i<prerequisites.size();i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ind(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            ind[prerequisites[i][0]]++;
        }
       // int cnt = 0;
        queue<int> q;
        vector<int> order;
        for(int i = 0;i<ind.size();i++){
            if(ind[i] == 0) {
                q.push(i);
             //  cnt++;
            }
        }
      //  if(cnt != 1) return order;
         while(!q.empty()){
            int el = q.front();
            q.pop();
            order.push_back(el);
            for(auto e:mp[el]){
                ind[e]--;
                if(ind[e] == 0)q.push(e);
            }
         }
        if(order.size() != numCourses) return {};
         return order;
    }
//biparity graph
 bool isBipartite(vector<vector<int>>& graph) {
     int N = graph.size();
     vector<int> colors(N, -1);
     queue<int> q;
     for(int i = 0;i<N;i++){
        if(colors[i] == -1)q.push(i);
         colors[i] = 0;
         while(!q.empty()){
            int el = q.front();
            q.pop();
            for(auto e:graph[el]){
                if(colors[e] == -1){
                colors[e] = 1 - colors[el];
                q.push(e);
                }
                else if(colors[e] == colors[el]) return false;
            }
         }
        

     }
     return true;
 }
 //zad
 int countCompleteComponents(int n, vector<vector<int>>& edges) {
 unordered_map<int, vector<int>> mp;
 for(int i = 0;i<n;i++){
    mp[i] = {};
 }
 for(int i = 0;i<edges.size();i++){
    mp[edges[i][0]].push_back(edges[i][1]);
    mp[edges[i][1]].push_back(edges[i][0]);
 }

 vector<bool> visited(n);
 int ans = 0;
for(auto el: mp){
    queue<int> q;
   q.push(el.first);
   int edges = 0;
   int nodes = 0;
    if(visited[el.first]) continue;
    visited[el.first] = true;
   while(!q.empty()){
    int el = q.front();
    q.pop();
    nodes++;
    edges += mp[el].size();
    for(auto e:mp[el]){
        if(!visited[e]){
            visited[e] = true;
            q.push(e);
        }
    }
    }
     if(nodes*(nodes-1) == edges)ans++;
 }
 return ans;
}
//all paths 
void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, int node, vector<int>& path){
        path.push_back(node);
        if(node == graph.size()-1) paths.push_back(path);
        
        for(auto e:graph[node]){
            dfs(graph, paths, e, path);
        }
        path.pop_back();
    }
     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, 0, path);
        return paths;
    }
    
/
int main()
{
    vector<vector<int>> g = {{1, 2}, {3}, {4}, {}, {}};
    //dfs(g);
    vector<vector<int>> g1 = {{1}, {2}, {0}};    
    cout<<CycleInGraph(g1);
    vector<pair<int, vector<int>> g1 = {{1, {1, 2}}, {1, {3}}, {{2, {}}}}
    vector<bool> visited(g.size());
    cout<<existPath(g, visited, 0, 2);

    return 0;
}

//cycle - important task
bool hasCycle(vector<vector<int>>& graph, set<int>& visited, int node){
    if(visited.count(node)) return true
    visited.insert(node);
    for(auto el:graph[node]){
        if(hasCycle(graph, visited, el)) return true;
    }
    visited.erase(node);
    return false;
}
int main()
{
    
    vector<vector<int>> graph = {{1, 2}, {3}, {4}, {}, {}};
    
    for(int i =0;i<graph.size();i++){
        set<int> visited;
        if(!hasCycle(graph,visited, i))return true;
    }
//remove ribs
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int numRemovedRibs(unordered_map<int, vector<int>>& mp, vector<bool>& visited, int node, int& res){
    if(mp[node].size() == 0) return 1;
    visited[node] = true;
    size_t children = 1;
    for(auto e:mp[node]){
        if(!visited[e]){
        children += numRemovedRibs(mp, visited, e, res);
        }
    }
    if(children % 2 == 0) 
    {res++;
     return 0;
    }
    
    return children;
}

int main() {
    int V, E;
    cin>>V>>E;
    unordered_map<int, vector<int>> mp;
    for(int i = 0;i<V;i++){mp[i] = {};};
    for(int i = 0;i<E;i++){
    int x, y;
    cin>>x>>y;
    mp[x].push_back(y);
    mp[y].push_back(x);
    }
    vector<bool> visited(V+1);
    int res = 0;
    numRemovedRibs(mp, visited, 1, res);
    cout<<res-1; 
    return 0;
}

//clone graph
unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
    if(!node) return nullptr;    
    
    if(mp.find(node) == mp.end()){
        mp[node] = new Node(node->val, {});
        for(auto el:node->neighbors){
            mp[node]->neighbors.push_back(cloneGraph(el));
        }
    }
    return mp[node];
    }
};

bool hasCycle(vector<vector<int>>& graph, set<int>& visited,int node){
    if(visited.find(node) != visited.end()) return true;
    visited.insert(node);
    for(auto el:graph[node]){
      if(hasCycle(graph, visited, el)) return true;
    }
    visited.erase(node);
    return false;
}

int main() {
    int K;
    cin>>K;
    while(K--){
   int V, E;
    cin>>V>>E;
    vector<vector<int>> graph(V+1);
    for(int i = 0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(y);
       
}bool flag= true;
    for(int i = 0;i<graph.size();i++){
        set<int> visited;
       if(hasCycle(graph, visited, i)){ cout<<"true ";flag = false;break;}
    }
    if(flag)cout<<"false ";
    }
}

bool hasCycle(vector<vector<int>>& graph, set<int>& visited,int node){
    if(visited.find(node) != visited.end()) return true;
    visited.insert(node);
    for(auto el:graph[node]){
        if(visited.find(el) != visited.end()) return true;
      if(hasCycle(graph, visited, el)) return true;
    }
    visited.erase(node);
    return false;
}

int main() {
    int K;
    cin>>K;
    while(K--){
   int V, E;
    cin>>V>>E;
    vector<vector<int>> graph(V+1);
    for(int i = 0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(y);
       
}bool flag= true;
    for(int i = 0;i<graph.size();i++){
        set<int> visited;
       if(hasCycle(graph, visited, i)){ cout<<"true ";flag = false;break;}
    }
    if(flag)cout<<"false ";
    }
}

bool hasCycleUndirectedGraph(vector<vector<int>>& g, vector<bool>& visited, int node, int parent){
visited[node] = true;
    for(auto el: graph[node]){
        if(!visited[el]){
    if(hasCycleUndirectedGraph(g, visited, el, node))return true;
            }
        else if(parent != node) return true;
    }
    return false;
}



//K5 SDA
//zad 1 SDA graph edges
{
    int V, E;
    cin>>V>>E;
    vector<bool> visited(V);
    vector<vector<int>> g(V);
    vector<int> edges;
    for(int i = 0;i<E;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            int edg = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                auto el = q.front();
                q.pop();
                edg += g[el].size();
                visited[el] = true;
                for(auto e:g[el]){
                    if(!visited[e]){
                        visited[e] = true;
                        q.push(e);
                    }
                }
                }
                 edges.push_back(edg/2);
        }
       
    }
    sort(edges.begin(), edges.end());
    for(auto e:edges) cout<<e<<' ';
    return 0;
}

//zad 2 - K least element in a stream
 priority_queue<int, vector<int>, less<int>> q;
     int K;
     cin>>K;
     while(true){
         int x;
         cin>>x;
         if(x == -1) break;
         if(x == 0){
             if(q.size() < K) cout<<-1<<'\n';
             else cout<<q.top()<<'\n';
             continue;
         }
         q.push(x);
         if(q.size() > K) q.pop();
     }
