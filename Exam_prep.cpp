//zad 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
//&
void dfs(int node, unordered_map<int, vector<int>>& graph, set<int>& visited){
    for(auto v:graph[node]){
    if(!visited.count(v)){
    visited.insert(v);
        dfs(v, graph, visited);
    }
    }
}
bool isConnected(int V, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& mp){
    int start = -1;
    for(auto i: mp){
        if(i.second > 0){
            start = i.first;
            break;
            }
    }
    if(start == -1) return true;
    set<int> visited;
    visited.insert(start);
    dfs(start,graph, visited);

    for(auto i:mp){
    if(i.second > 0 && !visited.count(i.first)){
        return false;
    }
}
return true;
 
}

int main() {
    int q;
    cin>>q;
    while(q--){
    int N, M;
        cin>>N>>M;
        unordered_map<int, int> mp;
        unordered_map<int, vector<int>> graph;
        for(int i = 0;i<M;i++){
            int a, b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
 
            mp[a]++;
            mp[b]++;
        }
 
        if(!isConnected(N, graph, mp)){
            cout<<"none"<<'\n';
            continue;
        }
        int odd = 0;
        for(auto i:mp){
 
            if(i.second % 2 == 1) odd++;
        }
 
        if(odd == 2)cout<<"epath";
        else if(odd == 0)cout<<"ecycle";
        else cout<<"none";
        cout<<'\n';
    }
 
    return 0;
}

//2

        path.push_back(node);
        if(node == trg) result.push_back(path);
        for(auto v:graph[node]){
            allpaths(v, trg, graph, path, result);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        allpaths(0, graph.size()-1, graph, path, result);
        return result;
    }

3// void _permute(int start, vector<int>& nums, vector<vector<int>>& results){
       if(start == nums.size()){
        results.push_back(nums);
        return;
       }
       for(int i=start;i<nums.size();i++){
        swap(nums[start], nums[i]);
        _permute(start+1, nums, results);
        swap(nums[start], nums[i]);
       }

    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> result;
       _permute(0, nums, result);
       return result;
    }

4// vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    for(auto ticket:tickets){
        mp[ticket[0]].push(ticket[1]);
    }
    vector<string> result;
    stack<string> st;
    st.push("JFK");
    while(!st.empty()){
    string current = st.top();
        if(!mp[current].empty()){
            st.push(mp[current].top());
            mp[current].pop();
          //  mp[current].erase(mp[current.top()]);
        }
        else{
            result.push_back(current);
            st.pop();
        }
    }
    reverse(result.begin(), result.end());
    return result;
    }
5// vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_map<int, queue<int>> mp;
    unordered_map<int, int> in;
    unordered_map<int, int> out;

    for(auto pair:pairs){
        mp[pair[0]].push(pair[1]);
        in[pair[1]]++;
        out[pair[0]]++;
    }
    stack<int> st;
    vector<int> result;
    for(auto e:out){
        if(e.second - in[e.first] == 1){
          st.push(e.first);
          break;
        }
    }
    if(st.empty()){
      for(auto e:out){
        if(e.second>0){
          st.push(e.first);
          break;
        }
    }
    }
    while(!st.empty()){
        int current = st.top();
        if(!mp[current].empty()){
            st.push(mp[current].front());
            mp[current].pop();
        }
        else{
            result.push_back(current);
            st.pop();
        }
    }
    reverse(result.begin(),result.end());
    vector<vector<int>> finalResults;
    for(int i = 0;i<result.size()-1;i++){
        finalResults.push_back({result[i], result[i+1]});
    }
    return finalResults;
    }

EXAM 1
6//struct unionFind{
 vector<int> parent;
 vector<int> sizes;
 vector<int> maxWeight;
 
    unionFind(int N){
    parent.resize(N);
 
    for(int i = 0;i<N;i++){
        parent[i] = i;
 
    }
    sizes.resize(N, 0);
    maxWeight.resize(N, 0);
    }
 
    int find(int a){
        if(parent[a] != a){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
 
    bool unite(int a, int b, int w){
        a = find(a);
        b = find(b);
        if(a == b)return false;
        else if(sizes[a]<sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b])sizes[a]++;
        maxWeight[a] = max(max(maxWeight[a],maxWeight[b]), w);
        return true;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<vector<int>> edges;
    int V,E,K;
    cin>>V>>E>>K;
    unionFind un(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(), edges.end(), [](const vector<int>& A, const vector<int>& B){
       return A[2] < B[2];
    });
    int components = V;
    for(auto edge:edges){
    if(components == K)break;
    if(un.unite(edge[0], edge[1], edge[2]))components--;
    }
 
    vector<int> result;
    for(int i = 0;i<V;i++){
        if(un.find(i) == i)result.push_back(un.maxWeight[i]);
    }
 
    // set<int> big;
    // for(auto e: un.maxWeight){
    //     big.insert(e);
    // }
    sort(result.begin(), result.end());
    for(auto e:result){
        cout<<e<<' ';
    }

    return 0;
}

7//
#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 0.000000000000001;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<pair<int, pair<int, double>>> vec;
    int N;
    cin>>N;
    for(int i = 0;i<N;i++){
    double d, p;
    cin>>d>>p;
    double cena = 4*p/(d*d);
    vec.push_back({i+1, {d, cena}});
    }
    sort(vec.begin(), vec.end(),[](const pair<int, pair<int, double>> A, const pair<int, pair<int, double>> B){
 
       if(A.second.second != B.second.second)
           return A.second.second + EPSILON < B.second.second;
        else return A.second.first > B.second.first;
    });
    for(auto e:vec){
        cout<<e.first<<' ';
    }
    return 0;
}

8//struct unionFind{
    vector<int> sizes;
    vector<int> parent;
    unionFind(int N){
        sizes.resize(N,0);
        parent.resize(N);
        for(int i = 0;i<N;i++){
            parent[i] = i;
        }
    }
    int find(int a){
        if(parent[a] != a){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)return false;
        if(sizes[a] < sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b])sizes[a]++;
        return true;
}
    bool connected(int a, int b){
        return find(a) == find(b);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Q;
    cin>>Q;
    while(Q--){
        int V, E;
        cin>>V>>E;
        unionFind un(V);
        bool flagi = false;
        for(int i = 0;i<E;i++){
            int a, b;
            cin>>a>>b;
            if(!un.unite(a, b))flagi = true;
        }
        if(flagi){
        cout<<0<<'\n';
            continue;
        }
         if(E + 1 != V){
            cout<<0;
             continue;
        }
        bool flag = false;
        int root = un.find(0);
        for(int i = 1;i<V;i++){
            if(un.find(i) != root){
                cout<<0;
                flag = true;
                break;
            }
        }
        if(flag == false)cout<<1;
        cout<<'\n';
}
 
 
}

bool hasCycle(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited){
    visited[node] = true;
    for(auto e:graph[node]){
        if(!visited[e]){
            if(hasCycle(e, node, graph, visited))return true;
        }
        else if(e != parent)return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Q;
    cin>>Q;
    while(Q--){
        int V, E;
        cin>>V>>E;
        vector<vector<int>> graph(V);
 
        for(int i = 0;i<E;i++){
            int a, b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(V);
         if(E + 1 == V && !hasCycle(0,-1, graph, visited))cout<<1;
        else cout<<0;
        cout<<'\n';
 
 
}
9//{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string one, two;
    cin>>one>>two;
    vector<int> One(26);
    vector<int> Two(26);
    for(size_t i = 0;i<one.size();i++){
        One[one[i]-'a']++;
}
      for(size_t i = 0;i<two.size();i++){
        Two[two[i]-'a']++;
}
    int cnt = 0;
    for(int i = 0;i<26;i++){
        cnt += min(One[i], Two[i]);
}
 
    cout<< cnt;

int LCS(int i, int j, string s, string w, vector<vector<int>>& dp){
    if(i < 0 || j < 0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(s[i] == w[j]) return dp[i][j] = 1 + LCS(i-1, j-1, s,w,dp);
    return dp[i][j] = max(LCS(i, j-1, s,w,dp), LCS(i-1, j, s,w,dp));
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string s,w;
    cin>>s>>w;
    vector<vector<int>> dp(s.size(), vector<int>(w.size(), -1));
    LCS(s.size()-1, w.size() - 1, s,w,dp);
    cout<< dp[s.size()-1][w.size() - 1];

//10
 int N,K;
    cin>>N>>K;
    vector<int> zones(N);
    for(int i = 0;i<N;i++){
        cin>>zones[i];
    }
    unordered_map<int, int> idx;
    vector<int> sums(N);
    sums[0] = zones[0];
    idx[zones[0]] = 0;
    int suma = 0;
    for(int i = 0;i<N;i++){
        suma += zones[i];
        idx[suma] = i;;
       // cout<<idx[suma]<<' '<<suma<<' ';
    }
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sumi=0;
    int maxi = 0;
    int count = 0;
    for(int i = 0;i<N;i++){
        sumi+=zones[i];
        if(mp.find(sumi-K) != mp.end()){
            maxi = max(maxi, i-idx[sumi-K]);
           // cout<<idx[sumi-K]<<' '<<sumi<<'\n';
            count += mp[sumi-K];
        }
        mp[sumi]++;
    }
 
    if(count == 0)cout<<-1;
    else cout<<maxi<<' '<<count;

EXAM 2
1// int N;
    cin>>N;
    unordered_map<int, int> st;
    vector<int> g(N);
    vector<int> ivan(N);
    for(int i = 0;i<N;i++){
        cin>>g[i];
    }
    for(int i = 0;i<N;i++){
        cin>>ivan[i];
    }
    int cnt = 0;
    for(int i = 0;i<N;i++){
        st[g[i]]++;
        if(st.find(ivan[i]) == st.end() || st[ivan[i]]==0){
            cnt++;
        }
        else st[ivan[i]]--;
        //cout<<cnt<<'\n';
    }
    cout<<cnt;

2// int N, E, K;
    cin>>N>>E>>K;
    vector<bool> visited(N);
    vector<vector<int>> graph(N);
    for(int i = 0;i<E;i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;

    int cnt = 0;
    for(int i = 0;i<N;i++){
        if(visited[i])continue;
        q.push(i);
        visited[i] = true;
        int c = 1;
        while(!q.empty()){
        auto el = q.front();
            q.pop();
        for(auto e:graph[el]){
            if(visited[e])continue;
            visited[e] = true;
            q.push(e);
            c++;
        }
    }
        if(c % K == 0)cnt++;
    }
    cout<<cnt<<'\n';

3// int N, M;
    cin>>N>>M;
    vector<vector<int>> vec(N, vector<int>(M, 0));
    for(int i = 0;i<N;i++){
    for(int j = 0;j<M;j++){
        cin>>vec[i][j];
    }
    }
    unordered_map<long long, int> mp;
    int cnt = 0;
    for(int i = 0;i<N;i++){
        long long suma = 0;
        for(int j = 0;j<M;j++){
           suma = 10*suma + vec[i][j];
        }
        mp[suma]++;
    }
    for(auto e:mp){
        if(e.second == 1)cnt++;
    }
    cout<<cnt;
4//struct Edge{
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
void dijkstra(int N, int idx, vector<vector<Edge>>& graph){
    vector<int> dist(N+1, 1e9);
    dist[idx] = 0;
    priority_queue<Node> pq;
    pq.push({idx, 0});
    while(!pq.empty()){
        auto el = pq.top();
        pq.pop();
        if(el.distance > dist[el.index])continue;
 
        for(auto e:graph[el.index]){
            if(dist[e.to] > el.distance + e.weight){
            dist[e.to] = el.distance + e.weight;
                pq.push({e.to, dist[e.to]});
            }
        }
    }
    for(int i = 1;i<=N;i++){
if(i == idx)continue;
        if(dist[i] == 1e9)cout<<-1;
        else cout<<dist[i];
        cout<<' ';
    }
 
 
 
}
using namespace std;
int main() {
    int Q;
    cin>>Q;
 
    vector<int> sizes(Q);
    for(int id = 0;id<Q;id++){
        int N, E;
        cin>>N>>E;
 
        vector<vector<Edge>> graph(N+1);
        for(int i = 0;i<E;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back({y, 6});
            graph[y].push_back({x, 6});
        }
        int idx;
        cin>>idx;
         dijkstra(N, idx, graph);
        cout<<'\n';
 
    }
 

EXAM 3
1//   int N, M;
    cin>>N>>M;
    vector<int> one(N);
    vector<int> two(M);
    for(int i = 0;i<N;i++){
        cin>>one[i];
    }
 
    for(int i = 0;i<M;i++){
    cin>>two[i];
    }
    vector<int> counts(*max_element(one.begin(), one.end()) + 1);
    for(int i = 0;i<N;i++){
        counts[one[i]]++;
    }
    for(size_t i = 0;i<counts.size()-1;i++){
        counts[i+1] += counts[i];
    }
 
    for(int i = 0;i<M;i++){
        if(two[i]>counts.size()-1)cout<<N;
        else cout<<counts[two[i]];
        cout<<' ';
    }
//negative numbers
int binarySearch(int l, int r, vector<int>& vec, int num){
    while(l<r){
int m = l + (r-l)/2;
    if(num > vec[m]){
       l = m+1;
    }
        else r = m;
    }
    return l;
}
int main() {
    int N, M;
    cin>>N>>M;
    vector<int> one(N);
    vector<int> two(M);
    for(int i = 0;i<N;i++){
        cin>>one[i];
    }
    sort(one.begin(), one.end());
    for(int i = 0;i<M;i++){
    cin>>two[i];
    }
 
    for(int i = 0;i<M;i++){
        cout<<binarySearch(0, N, one, two[i])<<' ';
    }

    return 0;

2//  for(int i = 0;i<N;i++){
    int a;
    cin>>a;
    q.push(a);
    if(i+1 % T == 0){
       for(int j = 0;j<K;j++){
           int el = q.top();
           cout<<el<<'\n';
           result.push_back(el);
           q.pop();
       }
    }
 

3// int N;
    cin>>N;
    vector<int> ar(N);
    for(int i = 0;i<N;i++){
    cin>>ar[i];
    }
    unordered_map<int, int> mp;
    unordered_map<int, int> idx;
    int longest = 0;
    int windowIdx = 0;
    for(int i = 0;i<N;i++){
 
    if(idx.find(ar[i]) != idx.end()){
 
 
        windowIdx=max(windowIdx, idx[ar[i]]+1);
 
 
       }
             longest = max(longest, i - windowIdx+1);
            idx[ar[i]] = i;
 
    }
    cout<<longest;

4//struct unionFind{
    vector<int> parent;
    vector<int> sizes;
 
    unionFind(int n){
    parent.resize(n);
    for(int i = 0;i<n;i++){
    parent[i] = i;
    }
    sizes.resize(n, 0);
    }
 
    int find(int a){
     if(a != parent[a]){
      parent[a] = find(parent[a]);
 
     }
        return parent[a];
    }
 
    bool unite(int a, int b){
     a = find(a);
    b = find(b);
        if(a == b)return false;
 
        if(sizes[a]< sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b])sizes[a]++;
        return true;
 
    }
    bool areConnected(int a, int b){
return find(a) == find(b);
    }
 
};
int main() {
    int N,M;
    cin>>N>>M;
    unionFind un(N);
    while(M--){
        int u, v;
        cin>>u>>v;
        un.unite(u, v);
    }
    int K;
    cin>>K;
 
    while(K--){
    int x,y;
        cin>>x>>y;
        if(un.areConnected(x, y))cout<<1;
        else cout<<0;
        cout<<' ';
    }

5//struct unionFind{
    vector<int> parent;
    vector<int> sizes;
 
    unionFind(int n){
    parent.resize(n);
    for(int i = 0;i<n;i++){
    parent[i] = i;
    }
    sizes.resize(n, 0);
    }
 
    int find(int a){
     if(a != parent[a]){
      parent[a] = find(parent[a]);
 
     }
        return parent[a];
    }
 
    bool unite(int a, int b){
     a = find(a);
    b = find(b);
        if(a == b)return false;
 
        if(sizes[a]< sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b])sizes[a]++;
        return true;
 
    }
    bool areConnected(int a, int b){
return find(a) == find(b);
    }
 
};
int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<int>> edges;
    unionFind un(N);
    while(M--){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(), edges.end(), [](const vector<int>& A, const vector<int>& B){
    return A[2] > B[2];
    });
    int suma = 0;
     for(size_t i = 0;i<edges.size();i++){
 
         if(!un.unite(edges[i][0], edges[i][1])) suma += edges[i][2];
     }
        cout<<suma;

6//int size(Node* head, Node* tail){
    if(!head)return 0;
    Node* curr = head;
    int cnt = 1;
    while(curr != tail){
    curr = curr->next;
    cnt++;
    }
    return cnt;
}
void reverse(int n, int m){
    if(!head) return;
    int s = size(head, tail);
    if(n > s) return;
    if(m > s) m = s;
 
    Node* curr = head;
    Node* prev = nullptr;
 
    for(int i = 1;i<n;i++){
        prev = curr;
        curr = curr->next;
    }
    Node* l = prev;
    Node* start = curr;
    Node* next = nullptr;
 
    for(int i = 0;i< m-n + 1;i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    if(l != nullptr)l->next = prev;
    else head = prev;
 
    start->next = curr;
 
    if(curr == nullptr) tail = start;
 
}

EXAM 4
1//
struct Edge{
int  to, weight;
};
int bfs(int src, int trg, vector<vector<Edge>>& graph){
    queue<int> q;
    q.push(src);
    vector<int> dist(graph.size(), -1);
    dist[src] = 0;
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        for(auto e: graph[el]){
            if(dist[e.to] != -1)continue;
            dist[e.to] = dist[el] + e.weight;
            q.push(e.to);
        }
    }
    return dist[trg];
}
int main() {
    int N, M;
    cin>>N>>M;
    vector<vector<Edge>> graph(N);
    for(int i = 0;i<M;i++){
        int x, y, w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
 
    }
    int K;
    cin>>K;
    vector<int> nodes(K);
    for(int i = 0;i<K;i++){
        cin>>nodes[i];
    }
    int path = 0;
    bool flag = false;
    for(int i = 1;i<K;i++){
        int suma = 0;
 
         suma = bfs(nodes[i-1], nodes[i], graph);
        if(suma == -1) {flag = true;break;}
        else path += suma;
    }
    if(flag)cout<<-1;
    else cout<<path;

//vtori nachin
struct Edge{
int  to, weight;
};

int main() {
    int N, M;
    cin>>N>>M;
    vector<vector<Edge>> graph(N);
    for(int i = 0;i<M;i++){
        int x, y, w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
 
    }
    int K;
    cin>>K;
    vector<int> nodes(K);
    for(int i = 0;i<K;i++){
        cin>>nodes[i];
    }
    int path = 0;
    bool found = false;
    for(int i = 1;i<K;i++){
        int suma = 0;
        int u = nodes[i-1];
        int v = nodes[i];
 
        for(auto e:graph[u]){
            if(e.to == v){suma += e.weight;found=true;}
        }
        if(found) path += suma;
        else{cout<<-1;return 0;}
    }
           cout<<path;
    return 0;

2// void printLeftProfile() {
      queue<Node*> q;
        vector<int> profile;
        q.push(root);
        while(!q.empty()){
 
            int size = q.size();
            vector<int> current;
            for(int i = 0;i<size;i++){
 
                auto el = q.front();
                 current.push_back(el->value);
                q.pop();
                if(el->left){
                    q.push(el->left);
                }
                if(el->right){
                    q.push(el->right);
                }
            }
            profile.push_back(current[0]);
        }
 
        for(size_t i = 0;i<profile.size();i++){
        cout<<profile[i]<<' ';
        }
 
    }

3//struct unionFind{
vector<int> parent;
    vector<int> sizes;
 
    unionFind(int n){
        parent.resize(n);
        for(int i = 0;i<n;i++){
          parent[i] = i;
        }
        sizes.resize(n, 0);
    }
    int find(int a){
    if(a != parent[a]){
        parent[a] = find(parent[a]);
    }
        return parent[a];
    }
 
    bool unite(int a, int b){
    a = find(a);
    b = find(b);
        if(a == b) return false;
        if(sizes[a]<sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b]) sizes[a]++;
        return true;
    }
};

int main() {
    int T;
    cin>>T;
    vector<int> ob;
    while(T--){
    int N, M;
    cin>>N>>M;
        int o = N;
        unionFind un(N);
        for(int i = 0;i<M;i++){
        int x, y;
 
            cin>>x>>y;
            if(un.unite(x, y))o--;
        }
        ob.push_back(o);
 
    }
    for(size_t j = 0;j<ob.size();j++){
        cout<<ob[j]<<' ';
    }

4//int lowerBound(int l, int r, int num, vector<int>& ar){
while(l<r){
    int m = l + (r-l)/2;
    if(ar[m] < num){
        l = m + 1;
    }
    else{
        r=m;
    }
}
    return l;
}
int upperBound(int l, int r, int num, vector<int>& ar){
while(l<r){
    int m = l + (r-l)/2;
    if(ar[m] <= num){
        l = m + 1;
    }
    else{
        r=m;
    }
}
    return l;
}
int main() {
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i = 0;i<n;i++){
        cin>>ar[i];
    }
    int Q;
    cin>>Q;
    vector<int> numbers(Q);
    for(int i = 0;i<Q;i++){
        cin>>numbers[i];
    }
    for(int i = 0;i<Q;i++){
    int l = lowerBound(0, n, numbers[i], ar);
        int r = upperBound(0, n, numbers[i], ar);
        if(l == r) cout<<l;
        else cout<<l<<' '<<r-1;
        cout<<'\n';
    }

EXAM 5
1//
bool hasCycle(int node, unordered_map<int,vector<int>>& graph, set<int>& visited){
    if(visited.count(node))return true;
    visited.insert(node);
    for(auto e:graph[node]){
 
        if(hasCycle(e,graph, visited))return true;
    }
    visited.erase(node);
    return false;
}
int main() {
    int Q;
    cin>>Q;
    while(Q--){
    int N, M;
        cin>>N>>M;
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<M;i++){
          int x,y,w;
            cin>>x>>y>>w;
            mp[x].push_back(y);
 
         }
 
        bool flag = false;
        for(int i = 1;i<=N;i++){
            set<int> visited;
            if(hasCycle(i, mp, visited))
        {flag = true;break;}
        }
        if(flag)cout<<"true";
        else cout<<"false";
        cout<<' ';
    }
2//int main() {
    string line;
    getline(cin, line);

    stringstream ss1(line);
    unordered_map<string, int> word1;
     string w1;
    while(ss1>>w1){
 
        word1[w1]++;
    }
    string lin;
    getline(cin, lin);
 
    stringstream ss2(lin);
    unordered_map<string, int> word2;
    string w;
    while(ss2>>w){
 
        word2[w]++;
    }
    vector<string> result;
    for(auto e: word1){
        if(e.second>1)continue;
       else if(word2.find(e.first) != word2.end())continue;
        else result.push_back(e.first);
 
    }
      for(auto e: word2){
        if(e.second>1)continue;
       else if(word1.find(e.first) != word1.end())continue;
        else result.push_back(e.first);
 
    }
    sort(result.begin(), result.end());
    for(size_t i = 0;i<result.size();i++){
        cout<<result[i]<<'\n';
    }

3, 4//struct Node{
    Node* right;
    Node* left;
    int val;
 
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};
struct BST{
Node* root;
BST(){
root = nullptr;}
Node* insertNode(Node* root, int val){
    if(!root) return root = new Node(val);
    if(root->val < val){
      root->right = insertNode(root->right, val);
    }
    else if(root->val == val)return root;
    else {
     root->left = insertNode(root->left, val);
    }
    return root;
}
    void print(Node* node){
 
        if(!node)return;
 
        cout<<node->val<<' ';
        print(node->left);
        print(node->right);
}
Node* getSuccessor(Node* curr){
    curr = curr->right;
    while(curr != nullptr && curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
 
}
Node* delNode(Node* root, int x){
    if(!root) return root;
    if(root->val > x){
        root->left = delNode(root->left, x);
    }
    else if(root->val < x){
        root->right = delNode(root->right, x);
    }
    else{
       if(root->left == nullptr){
        Node* temp = root->right;
           delete root;
           return temp;
       }
        if(root->right == nullptr){
        Node* temp = root->left;
           delete root;
           return temp;
       }
        Node* newi = getSuccessor(root);
        root->val = newi->val;
        root->right = delNode(root->right, newi->val);
 
    }
    return root;
}
void print_odd_layers(){
    if(!root)return;
  queue<Node*> q;
    q.push(root);
    int cnt = 0;
    vector<int> result;
    while(!q.empty()){
        cnt++;
        int size = q.size();
        for(int i = 0;i<size;i++){
            auto el = q.front();
            q.pop();
            if(cnt % 2 == 1){
                result.push_back(el->val);
            }
            if(el->left){
                q.push(el->left);
            }
            if(el->right){
                q.push(el->right);
            }
        }
    }
    for(size_t i = 0;i<result.size();i++){
        cout<<result[i]<<' ';
    }
}
};

int main() {
    int N;
    cin>>N;
    BST tree;
    while(N--){
        string command;
        cin>>command;
        if(command == "add"){
         int value;
            cin>>value;
            tree.root = tree.insertNode(tree.root,value);
        }
        else if(command == "print"){
 
tree.print(tree.root);
        }
        else if(command == "print_odd_layers"){
 tree.print_odd_layers();
        }
        else if(command == "remove"){
            int y;
            cin>>y;
            tree.root = tree.delNode(tree.root, y);
        }
    }

return 0;
}

5//void printCities(int N, unordered_map<int, vector<int>>& mp, int K){
    vector<int> dist(N+1, -1);
    dist[N] = 0;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        for(auto e:mp[el]){
            if(dist[e] == -1){
                dist[e] = dist[el] + 1;
                q.push(e);
            }
        }
    }
    bool flag = false;
    for(int i = 1;i<N;i++){
      if(dist[i] == K){cout<<i<<' ';flag = true;}
    }
    if(!flag)cout<<-1;
 
}
int main() {
    int N, M, K;
    cin>>N>>M>>K;
    unordered_map<int, vector<int>> mp;
    for(int i = 0;i<M;i++){
    int x, y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    printCities(N, mp, K);
}

//zadacha - critical, pseudocritical edges
 struct unionFind{
    vector<int> parent;
    vector<int> sizes;
    unionFind(int n){
        parent.resize(n);
        sizes.resize(n, 0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int a){
        if(parent[a] != a){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(sizes[a] < sizes[b])swap(a, b);
        parent[b] = a;
        if(sizes[a] == sizes[b])sizes[a]++;
        return true;
    }

    };
    int Kruskal(vector<vector<int>> edges, int n){
        sort(edges.begin(), edges.end(), [](const vector<int>& A, const vector<int>& B){
            return A[2] < B[2];
        });
 
        unionFind un(n);
        int size = 0;
        int suma= 0;
        bool flag = false;
        for(int i = 0;i<edges.size();i++){
            if(size == n-1){flag = true;break;};
            if(un.unite(edges[i][0], edges[i][1])){
                size++;
                suma += edges[i][2];
            }
        }
        if(!flag)return -1;
        return suma;
    }

     int KruskalPseudo(vector<vector<int>> edges, int n, vector<int> edge){
        sort(edges.begin(), edges.end(), [](const vector<int>& A, const vector<int>& B){
            return A[2] < B[2];
        });
 
        unionFind un(n);
        int suma= 0;
        int size = 0;
        if(un.unite(edge[0], edge[1])){size++;suma+=edge[2];}
 
        bool flag = false;
        for(int i = 0;i<edges.size();i++){
            if(size == n-1){flag = true;break;};
            if(un.unite(edges[i][0], edges[i][1])){
                size++;
                suma += edges[i][2];
            }
        }
        if(!flag)return -1;
        return suma;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int suma = Kruskal(edges, n);
        vector<vector<int>> finali(2);
 
        for(int i = 0;i<edges.size();i++){
            vector<vector<int>> newEdges = edges;
            newEdges.erase(newEdges.begin() + i);
            int result = Kruskal(newEdges, n);
            if(result == -1 || result > suma)finali[0].push_back(i);
            else if(KruskalPseudo(newEdges, n, edges[i]) == suma) finali[1].push_back(i);
        }
        return finali;

    }

zad 1/int singleNumber(vector<int>& nums) {
        int num = nums[0];
        for(int i = 1;i<nums.size();i++){
           num = num ^ nums[i];
        }
        return num;
    }

zad 2/ int firstMissingPositive(vector<int>& nums) {
        long long maxi = *max_element(nums.begin(), nums.end());
        if(maxi <= 0) return 1;
        vector<bool> numsi(maxi+1);
       for(int i = 0;i<nums.size();i++){
          if(nums[i] > 0)numsi[nums[i]] = true;
       }

       for(int i = 1;i<=maxi;i++){
        if(!numsi[i])return i;
       }
       return maxi+1;
    }
zad counting sort with objects
struct Student{
    int id;
    int grade;
};
int main()
{
    int N = 5;
    vector<Student> ar = {{1,2}, {2,3}, {1,22}, {4, 5}, {4, 66}};
    vector<int> ids = {1,2,1,4,4};
    vector<int> counts(*max_element(ids.begin(), ids.end()) + 1);
    for(int i = 0;i<ids.size();i++){
        counts[ids[i]]++;
    }
    for(int i = 1;i<counts.size();i++){
        counts[i] += counts[i-1];
    }
    vector<Student> output(N);
    for(int i = N-1;i>=0;i--){
        output[counts[ar[i].id]-1] = ar[i];
        counts[ar[i].id]--;
    }
     for(int i = N-1;i>=0;i--){
        cout<<output[i].id<<' '<<output[i].grade<<'\n';
    }

//Radix sort
int len(int num){
    int cnt = 0;
    while(num){
        num/= 10;
        cnt++;
    }
    return cnt;
}
int power(int base, int stepen){
    int c = 1;
    for(int i = 0;i<stepen;i++){
        c*=base;
    }
    return c;
}
int main()
{
    int N = 5;
    vector<int> numbers = {123, 2334, 5, 666,5561};
    int l = len(*max_element(numbers.begin(), numbers.end()));
    vector<int> output;
    int expo = 1;
    for(int i = 0;i<l;i++){
 
        vector<int> digits(N);
        for(int i = 0;i<N;i++){
            digits[i] = numbers[i] / expo % 10;
        }
        vector<int> counts(*max_element(digits.begin(), digits.end()) + 1);
        for(int i = 0;i<digits.size();i++){
        counts[digits[i]]++;
    }
    for(int i = 1;i<counts.size();i++){
        counts[i] += counts[i-1];
    }
        vector<int> output(N);
        for(int i = N-1;i>=0;i--){
        output[counts[digits[i]]-1] = numbers[i];
        counts[digits[i]]--;
    }
    numbers = output;
    expo *=10;
    }
 
    for(int i = 0;i<N;i++){
        cout<<numbers[i]<<' ';
    }

//Binary search
int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] < target){
                l = m + 1;
            }
            else{
                r = m;
            }
        }
        return l;
    }
upperBound
1//bool canMake(vector<int>& times, long long time, long long N){
    long long count = 0;
    for(size_t i = 0;i<times.size();i++){
        if(times[i] == 0)continue;
        count += time/ times[i];
    }
    return (count >= N);
}
int main() {
    long long N;
    int K;
    cin>>N>>K;
    vector<int> times(K);
    for(int i = 0;i<K;i++){
        cin>>times[i];
    }
    long long l = 1;
    long long r = *max_element(times.begin(), times.end()) * N;
    while(l < r){
        long long m = l + (r - l)/2;
        if(!canMake(times, m, N)){
            l = m+1;
        }
        else r = m;
    }
    cout<<l;

2//sum of descendants
int bfs(int src, unordered_map<int, vector<int>>& mp){
    queue<int> q;
    q.push(src);
    int suma = 0;
    set<int> visited;
    visited.insert(src);
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        suma += el;
        for(auto e:mp[el]){
            if(visited.count(e))continue;
            visited.insert(e);
        q.push(e);
        }
    }
 
    return suma-src;
}
int main() {
    int M, T;
    cin>>M>>T;
    unordered_map<int, vector<int>> mp;
    for(int i = 0;i<M;i++){
    int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
 
    }
    while(T--){
        int n;
        cin>>n;
        cout<<bfs(n, mp)<<'\n';
 
   }

3.1// bool hash(int start, int k,vector<int>& nums,int& sum){
        unordered_map<int, int> mp;
        for(int i = start;i<start+k;i++){
        sum += nums[i];
        mp[nums[i]]++;
        if(mp[nums[i]] > 1)return false;
        }
        return true;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int sum = 0;
       int maxSum = 0;
       unordered_map<int, vector<int>> mp;
       for(int i = 0;i<=nums.size()-k;i++){
        int sum = 0;
          if(hash(i, k, nums, sum)){
            maxSum = max(maxSum, sum);
          }
       }
       return maxSum;
    }
3.2/ long long hash(int start, int k,vector<int>& nums,unordered_map<int, int>& mp){
        long long sum = 0;
        for(int i = start;i<start+k;i++){
        sum += nums[i];
        mp[nums[i]]++;
        }
        return sum;
 
    }
    bool validMap(unordered_map<int, int>& mp){
        for(auto e:mp){
            if(e.second > 1)return false;
        }
        return true;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
 
       long long maxSum = 0;
       unordered_map<int, int> mp;
       long long sum = hash(0,k,nums, mp);
       if(validMap(mp)){
        maxSum = max(maxSum, sum);
       }
       for(int i = 0;i<nums.size()-k;i++){
           mp[nums[i]]--;
           mp[nums[i+k]]++;
           sum -= nums[i];
           sum += nums[i+k];
           if(validMap(mp)){
            maxSum = max(maxSum, sum);
           }
          }
 
       return maxSum;
    }
//rabotesht nachin
long long hash(int start, int k,vector<int>& nums,unordered_map<int, int>& mp){
        long long sum = 0;
        for(int i = start;i<start+k;i++){
        sum += nums[i];
        mp[nums[i]]++;
        }
        return sum;
 
    }
      int countDuplicates(unordered_map<int, int>& mp){
      int dup = 0;
      for(auto e:mp){
        if(e.second > 1)dup++;
       }
       return dup;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
       if(k == 1) return *max_element(nums.begin(), nums.end());
       long long maxSum = 0;
 
       unordered_map<int, int> mp;
       long long sum = hash(0,k,nums, mp);
       int dup = countDuplicates(mp);
 
       if(dup == 0)maxSum = max(maxSum, sum);
       for(int i = 0;i<nums.size()-k;i++){
            cout<<dup<<'\n';
            if(nums[i] == nums[i+k])continue;
           mp[nums[i]]--;
           mp[nums[i+k]]++;
           if(mp[nums[i]] == 1)dup--;
           if(mp[nums[i+k]] == 2)dup++;
 
           sum -= nums[i];
           sum += nums[i+k];
 
           if(dup == 0){
            maxSum = max(maxSum, sum);
           }
          }
 
       return maxSum;
    }

4/int peakIndexInMountainArray(vector<int>& arr) {
       int l = 1;
       int r = arr.size() - 1;

       while(l <= r){
        int mid = l + (r - l)/2;

        if(arr[mid] < arr[mid+1]){
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
       }
       return l;
    }
5/ int N;
    cin>>N;
    vector<int> ar(N);
    unordered_map<int, int> freq;
    for(int i = 0;i<N;i++){
        freq[ar[i]]++;
        cin>>ar[i];
    }
    unordered_map<int, int> idx;
    sort(ar.begin(), ar.end());
    for(int i = 0;i<ar.size();i++){
        idx[ar[i]] = i;
    }
 
    for(int i = 0;i<ar.size();i++){
        cout<<ar.size() - 1-idx[ar[i]]<<' ';
        idx[ar[i]]++;
    }

6/bool canEatAll(vector<int>& apps, int H, int X){
    int hours = 0;
    for(int i = 0;i<apps.size();i++){
        hours += apps[i] / X + (apps[i] % X != 0);
    }
    return hours > H;
}
int main()
{
    int N,H;
    cin>>N>>H;
    vector<int> apps(N);
    for(int i = 0;i<N;i++){
        cin>>apps[i];
    }
    int low = 1;
    int high = *max_element(apps.begin(), apps.end());
 
    while(low < high){
 
        int m = low + (high - low) / 2;
        if(canEatAll(apps,H, m)){
            low = m+1;
        }
        else{
            high = m;
        }
    }
    cout<<low;
 

7/#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canSeparate(vector<int>& skills, int T, long long sum){
    int cnt = 1;
    long long suma = 0;
    for(size_t i = 0;i<skills.size();i++){
    if(suma + skills[i] > sum){
        suma = skills[i];
        cnt++;
        if(cnt > T)return false;
 
    }
    else suma += skills[i];
    }
    return true;
}
int main() {
    int N, T;
    cin>>N>>T;
    vector<int> skills(N);
    for(int i = 0;i<N;i++){
    cin>>skills[i];
    }
    long long low = *max_element(skills.begin(), skills.end());
    long long high = 0;
    for(int i = 0;i<N;i++){
        high += skills[i];
    }
 
    while(low < high){
        long long m = low + (high-low)/2;
        if(canSeparate(skills, T, m)){
            high = m;
 
        }
        else low = m + 1;
    }
    cout<<low;
 }

8/bool canPut(vector<int>& position, int m, int dist){
        int cnt = 1;
        int last = position[0];

        for(int i = 1;i < position.size(); i++){
            if(position[i] - last >= dist){
                cnt++;
                last = position[i];
 
            }
            if(cnt >= m)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = (position[position.size()-1] - position[0]);
        while(low <= high){
            int mid = low + (high - low)/ 2;
            if(canPut(position, m,mid)){
                low = mid + 1;
            }
            else high = mid-1;
        }
        return high;
    }
9/bool canNotPlace(vector<int>& ar, int m, int k, int n, int day){
    int groups = 0;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        bool flag = false;
        while(i < n && ar[i] <= day){
 
            cnt++;
            if(cnt == k){
                groups++;
                flag = true;
               break;
            }
            i++;
 
        }
 
 
    }

 
    return groups < m;
}
int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> traffic(n);
    for(int i = 0;i<n;i++){
       cin>>traffic[i];
    }
    if(m*k > n){cout<<-1;return 0;}
    int low = 1;
    int high = *max_element(traffic.begin(), traffic.end());
    canNotPlace(traffic, m,k,n,12);
    bool flag = false;
    while(low < high){
     int mid = low + (high - low)/2;
        if(canNotPlace(traffic, m,k,n, mid)){
         low = mid + 1;
           // cout<<'l';
        }
        else{
            high = mid;
            flag = true;
        }
    }
 
    cout<<low;

//IMPORTANT ZADACHA - FINDING THE PATH PASSING EXACT LOCATIONS
Using set to keep the locations we musn't visit Di+1, Di+2.... before the Di destination
int path(int start, int end, set<int>& toVisit, vector<int>& at, unordered_map<int, vector<int>>& mp, int N){
    queue<int> q;
    q.push(start);
    vector<int> dist(N, -1);
    dist[start] = 0;
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        for(auto e: mp[el]){
           if(dist[e] != -1)continue;
            if(toVisit.count(e))continue;
            dist[e] = dist[el] + 1;
            q.push(e);
        }
    }
    return dist[end];
}
int main() {
   int N, M;
    cin>>N>>M;
    unordered_map<int, vector<int>> graph;
    while(M--){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    }
    int K;
    cin>>K;
    vector<int> at(K);
    set<int> toVisit;
    for(int i = 0;i<K;i++){
     cin>>at[i];
        toVisit.insert(at[i]);
    }
    int patho = 0;
 
    toVisit.erase(at[0]);
    for(int i = 0;i<K-1;i++){
        toVisit.erase(at[i+1]);
        int p = path(at[i], at[i+1], toVisit, at, graph, N);
        if(p == -1){
            cout<<-1;
            return 0;
        }
        patho += p;
    }
    cout<<patho;
    return 0;
}

Linked List
1/int size(ListNode* head){
        int cnt=0;
        ListNode* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        if(!head->next)return head;
        int s = size(head);
        cout<<s;
        int k = s/2;
        while(k--){
            head = head->next;
        }
        return head;
2/ ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
 
        }
        return prev;
    }

3/bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }
        return false;
    }
Even and odd lists
4/ ListNode* oddEvenList(ListNode* head) {
        if(!head)  return nullptr;
        ListNode* dummyOdd = new ListNode(0);
        ListNode* dummyEven = new ListNode(0);

        ListNode* odd = dummyOdd;
        ListNode* even = dummyEven;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        int pos = 1;

        while(curr){
 
            if(pos % 2 == 1){
                odd->next = curr;
                prev = curr;
                odd = odd->next;
            }
            else{
                 even->next = curr;
                even = even->next;
            }
            pos++;
            curr = curr->next;
 
        }
       even->next = nullptr;
       odd->next = dummyEven->next;
       return dummyOdd->next;
    }
5/ ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while(true){
            bool flag1 = false;
            bool flag2 = false;
            if(!curr1){curr1 = headB;flag1 = true;}
            if(!curr2){curr2 = headA;flag2 = true;}
            if(!flag1)curr1 = curr1->next;
            if(!flag2)curr2 = curr2->next;
 
            if(curr1 ==  curr2)return curr1;
        }
        return nullptr;
    }
6/Reverse DLL
struct Node{
  Node* prev;
  Node* next;
  int data;
  Node(int newData) : data(newData){
      prev = next = nullptr;
  }
 
};
struct DLL{
    Node* tail;
    Node* head;
 
    DLL(){
        head = tail = nullptr;
    }
    void addNode(int data){
        if(!head &&!tail){
            head = tail = new Node(data);
            return;
        }
        Node* temp = new Node(data);
        head->prev = temp;
        temp->prev = nullptr;
        temp->next = head;
        head = temp;
    }
    void print(){
        while(head){
            cout<<head->data<<' ';
            head = head->next;
        }
    }
    void reverse(){
        Node* curr = head;
        Node* prev = nullptr;
        while(curr){
            Node* next = curr->next;
            prev = curr->prev;
            curr->next = prev;
            curr->prev = next;
            curr = next;
        }
        swap(head, tail);
 
    }
    void deleteNodeFirst(){
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    void deleteAtPos(int pos){
        if(pos == 0){
            deleteNodeFirst();
            return;
        }
 
        Node* prev = nullptr;
        Node* curr = head;
        for(int i = 0;i<pos;i++){
            prev = curr;
            curr = curr->next;
        }
        Node* temp = curr;
        prev->next = curr->next;
        curr->next->prev = prev;
        delete curr;
    }
 
 
};
int main(){
    DLL d;
    d.addNode(1);
    d.addNode(2);
    d.addNode(3);
    //d.deleteNodeFirst();
   // d.deleteAtPos(1);
   // d.print();
    d.reverse();
    d.print();
//Stack, Queue...
int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result = 0;
                if(tokens[i] == "+"){
                    result = a + b;
                }
                else if(tokens[i] == "-"){
                    result = a - b;
                }
                else if(tokens[i] == "*"){
                    result = a * b;
                }
                else if(tokens[i] == "/"){
                    cout<<a<<' '<<b<<'\n';
                    result = a / b;
 
                }
                st.push(result);
 
            }
            else {
                st.push(stoi(tokens[i]));
            }

        }
        return st.top();
    }
//Asteroids collision
1/half-working
  vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                int prev = 0;
                while(!st.empty() && asteroids[i] < 0 && abs(asteroids[i])>=st.top()){
                    prev = st.top();
                    st.pop();
                }
                if(st.empty() && prev != abs(asteroids[i]) || (!st.empty() && st.top() < 0)) st.push(asteroids[i]);
            }

        }
        vector<int> ast;
        while(!st.empty()){
            ast.push_back(st.top());
            st.pop();
        }
        reverse(ast.begin(), ast.end());
        return ast;
    }
1.1.1/ vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(auto a:asteroids){
            bool destroyed = false;
            while(st.size()>0 && a < 0 && st.back() > 0){
                if(abs(a) > st.back()){
                    st.pop_back();
                    continue;
                }
                else if(abs(a) == st.back()){
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }

            }
            if(!destroyed){
                st.push_back(a);
            }
        }
        return st;
    }

1.1/Terziev way
vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int i = 0;i<asteroids.size();i++){
            if(result.size() > 0 && result.back() < 0 || asteroids[i] > 0){
                result.push_back(asteroids[i]);
                continue;
            }
            while(result.size() > 0 && result.back() > 0 && result.back() < abs(asteroids[i])){
                result.pop_back();
            }
            if(result.size() > 0 && result.back() == abs(asteroids[i])){
                result.pop_back();
            }
            else if(result.size() == 0 || result.back() < 0){
                result.push_back(asteroids[i]);
            }
        }
        return result;
    }

2/Greater temperatures
vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        for(int i = 0;i<temperatures.size();i++){
         while(!st.empty() && temperatures[i] > temperatures[st.top()]){
            ans[st.top()] = i - st.top();
            st.pop();
         }
 
 
         st.push(i);
        }
        return ans;
    }

3/best view
    int n;
    cin>>n;
    vector<int> trees(n);
    for(int i = 0;i<n;i++){
        cin>>trees[i];
    }
    int maxIdx = 0;
    int maxDist = 0;
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && trees[i] >= trees[st.top()]){
                     st.pop();
        }
        if(maxDist <= st.size()){
        maxDist = st.size();
            maxIdx = i;
        }
        st.push(i);
}
    cout<<maxIdx;

4/int n;
    cin>>n;
    vector<int> prices(n);
    for(int i = 0;i<n;i++){
        cin>>prices[i];
    }
    vector<int> ans(n, 0);
    stack<int> st;
    for(int i= 0;i<n;i++){
        while(!st.empty() && prices[i] > prices[st.top()]){
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0;i<n;i++){
    cout<<ans[i]<<' ';
    }

5/vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for(int i = 0;i<nums.size();i++){
            while(!dq.empty() && nums[i]  >= nums[dq.back()]){
            dq.pop_back();
            }
            dq.push_back(i);
 
            if(dq.front() <= i-k) dq.pop_front();

            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
 
        }
        return result;
    }
 6/ vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>  nge(n, -1);
        stack<int> st;
        for(int i = 2*n-1;i>=0;i--){
            int curr = nums[i % n];
            while(!st.empty() && st.top() <= curr){
                st.pop();
            }
            if(i < n){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(curr);
        }
        return nge;
    }
7/ bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ind(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0;i<ind.size();i++){
            if(ind[i] == 0) q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            auto el = q.front();
            result.push_back(el);
            q.pop();
            for(auto e: graph[el]){
                ind[e]--;
                if(ind[e] == 0){
                    q.push(e);
                }
            }
        }
        return result.size() == numCourses;
    }
 if(result.size() < numCourses)return {};
        return result;

8/bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
 
 
        for(int i = 0;i<graph.size();i++){
            if(color[i] != -1)continue;
            queue<int> q;
            q.push(i);
            color[i] = 0;
        while(!q.empty()){
            auto el = q.front();
            q.pop();
            for(auto e:graph[el]){
                if(color[e] != -1){
                    if(color[e] == color[el])return false;
                    continue;
                }
                color[e] = 1 - color[el];
                q.push(e);

            }
        }
        }
        return true;
    }

TREES
9/int n;cin>>n;
    vector<int> tree(n);
    vector<int> parent = {0,-1,1,3};
    int root = -1;
    for(int i = 0;i<parent.size();i++){
        if(parent[i] == -1){
            root = i;
            continue;
        }
        tree[parent[i]].push_back(i);
    }

10/bool contains(Node* current, int key){
    if(!current)return false;
    if(key == current->val) return true;
    return contains(current->left, key) || contains(current->right, key);
}

12/Node* insert(Node* current, int val){
    if(!current){
        return new Node(val);
    }
    if(current->right < val){
        current->right = insert(current->right, val);
    }
    else if(current->val == val) return current;
    else current->left = insert(current->left, val);
 
    return current;
}
13/Node* remove(Node* current, int val){
    if(!current) return nullptr;
    if(val < current->val){
        current->left = remove(current->left, val);
    }
    else if(current->val < val){
        current->right = remove(current->right, val);
    }
    else{
        if(!current->right && !current->left){
            return nullptr;
        }
        if(!current->right){
            return current->left;
        }
        if(!current->left){
            return current->right;
        }
        Node* temp = current->right;
        while(temp->left){
            temp = temp->left;
        }
        current->val = temp->val;
        current->right = remove(current->right, current->val);
    }
    return current;
}
root = remove(root, val);

14/ void printInorder(TreeNode* root, vector<int>& result){
        if(!root)return;
        printInorder(root->left, result);
        result.push_back(root->val);
        printInorder(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        printInorder(root, result);
        return result;
    }
15/void sumNodes(TreeNode* root, int l, int h, int& sum){
        if(!root) return;
        if(root->val >= l && root->val <= h){
            sum += root->val;
        }
        sumNodes(root->left, l,h,sum);
        sumNodes(root->right,l,h,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        sumNodes(root, low, high, sum);
        return sum;
    }
16/int path(TreeNode* root, int& patho){
        if(!root) return 0;
        int left = path(root->left, patho);
        int right = path(root->right,patho);
        patho = max(patho, left+right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int patho = 0;
        path(root, patho);
        return patho;
    }
17/ bool isSymmetricHelp(TreeNode* l, TreeNode* r) {
        if(l == nullptr || r == nullptr) return l == r;
        if(l->val != r->val) return false;
        return isSymmetricHelp(l->left, r->right) && isSymmetricHelp(l->right, r->left);
       }
 
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSymmetricHelp(root->left, root->right);
 
       }
18/int lengthOfLongestSubstring(string s) {
        unordered_map<char, size_t> mp;
        int longest = 0;
        int currentStart = 0;
        for(size_t i = 0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= currentStart){
                currentStart = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            if(longest < i - currentStart + 1) longest = i - currentStart + 1;
        }
        return longest;
    }
19/bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for(int i = 0;i<s.size();i++){
            if(mp1.find(s[i]) != mp1.end()){
                if(mp1[s[i]] != t[i])return false;
            }
            if(mp2.find(t[i]) != mp2.end()){
                if(mp2[t[i]] != s[i])return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];

        }
        return true;
    }
20/int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr = 0;
        int longest = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) curr--;
            else curr++;
 
            if(mp.find(curr) != mp.end()){
                longest = max(longest, i-mp[curr]);
            }
            else mp[curr] = i;
        }
        return longest;
    }
21/bool dfs(int node,int dst, vector<int>& visited, unordered_map<int,vector<int>>& mp){
        if(node == dst)return true;
        for(auto e:mp[node]){
            if(!visited[e]){
                visited[e] = true;
                if(dfs(e,dst,visited,mp))return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]].push_back(edges[i][0]);
            mp[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> visited(n);
        return dfs(source,destination,visited,mp);
    }

22/Remove obstacles
 bool isValid(int x,int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 1e9));
        deque<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push_front({0,0});
        dist[0][0] = 0;
        while(!q.empty()){
        auto el = q.front();
        q.pop_front();
        int x = el.first;
        int y = el.second;
 
        vector<pair<int, int>> nbs = {{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}};
        for(int i = 0;i<4;i++){
            int dx = nbs[i].first;
            int dy = nbs[i].second;
            if(!isValid(dx,dy,n, m))continue;
            //if(dist[dx][dy] != -1)continue;
            if(grid[dx][dy] == 1){
                if(dist[dx][dy] > dist[x][y] + 1){
                dist[dx][dy] = dist[x][y] + 1;
                q.push_back({dx,dy});
                }
            }
            else{
                if(dist[dx][dy] > dist[x][y]){
                dist[dx][dy] = dist[x][y];
                q.push_front({dx,dy});
                }
            }
        }
 
        }
        return dist[n-1][m-1];

23/struct Node{
    pair<int,int> index;
    int distance;

    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
    };
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<Node> pq;
        dist[0][0] = 0;
        pq.push({{0,0}, 0});

        while(!pq.empty()){
            auto el = pq.top();
            int x = el.index.first;
            int y = el.index.second;
            pq.pop();
            if(el.distance > dist[x][y])continue;
            vector<pair<int, int>> vec = {{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}};
            for(int i = 0;i<4;i++){
                int dx = vec[i].first;
                int dy = vec[i].second;
                if(!isValid(dx,dy,n,m))continue;
                int effort = max(dist[x][y], abs(heights[dx][dy] - heights[x][y]));
                if(dist[dx][dy] > effort){
                    dist[dx][dy] = effort;
                    pq.push({{dx,dy}, effort});
                }
            }

        }
        return dist[n-1][m-1];
    }
24/ struct Edge{
        int to,weight;
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<int> dist(n, 1e9);
      unordered_map<int, vector<Edge>> mp;
      dist[src] = 0;
      for(int i = 0;i<flights.size();i++){
        mp[flights[i][0]].push_back({flights[i][1], flights[i][2]});
      }
      for(int i = 0;i<=k;i++){
        vector<int> temp = dist;
        for(auto f:flights){
            int u = f[0];
            int v = f[1];
            int w = f[2];
            if(dist[u] != 1e9){
                temp[v] = min(dist[u] + w,temp[v]);
            }
        }
        dist = temp;

      }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
25/int ans(int i, int j, string word1, string word2, vector<vector<int>>& dist){
 
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dist[i][j] != -1) return dist[i][j];
        if(word1[i] == word2[j]){
            return dist[i][j] = ans(i-1,j-1,word1,word2, dist);
        }
        int del = 1 + ans(i-1,j,word1,word2, dist);
        int ins = 1 + ans(i, j-1,word1,word2, dist);
        int rep = 1 + ans(i-1,j-1,word1,word2, dist);

        return dist[i][j] = min(min(del, ins), rep);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        return ans(n-1,m-1,word1,word2, dist);
    }
26/  int ans(int i, int j, string& t1, string& t2, vector<vector<int>>& dist){
        if(i < 0 || j < 0)return 0;
        if(dist[i][j] != -1)return dist[i][j];

        if(t1[i] == t2[j]){
            return dist[i][j] = 1 + ans(i-1,j-1,t1,t2,dist);
        }

        return dist[i][j] = max(ans(i-1,j,t1,t2,dist), ans(i,j-1,t1,t2,dist));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        return ans(n-1,m-1,text1,text2,dist);
    }

27/int ans(int i, int j, string& t, vector<vector<int>>& dist){
        if(i == j) return 1;
        if(i > j) return 0;
        if(dist[i][j] != -1) return dist[i][j];
        if(t[i] == t[j]){
            return dist[i][j] = 2 + ans(i+1,j-1,t,dist);
        }

        return dist[i][j] = max(ans(i,j-1,t,dist), ans(i+1,j,t,dist));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));

        return ans(0,n-1,s,dist);
    }

28/int ans(int i, int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dist){
        if(i < 0 || j < 0)return 0;
        if(dist[i][j] != -1)return dist[i][j];
        if(nums1[i] == nums2[j]){
            return dist[i][j] = 1 + ans(i-1,j-1,nums1,nums2, dist);
        }
        return dist[i][j] = max(ans(i-1,j,nums1,nums2,dist), ans(i,j-1,nums1,nums2, dist));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        return ans(n-1,m-1,nums1,nums2,dist);
    }

29/ int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(size_t i = 0;i < nums.size(); i++){
            dp[i] = 1;
            for(size_t j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

30/ int ans(int i, int j, vector<vector<int>>& dist,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(dist[i][j] != -1) return dist[i][j];
        if(i == 0){
            return dist[i][j] = ans(i,j-1,dist,grid) + grid[i][j];
        }
        if(j == 0){
            return dist[i][j] = ans(i-1,j,dist,grid) + grid[i][j];
        }
        return dist[i][j] = min(ans(i-1,j,dist,grid), ans(i,j-1,dist,grid)) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        return ans(n-1,m-1,dist,grid);
    }
31/int ways(vector<int>& coins, int amount,vector<vector<int>>& dp, int idx){
        if(amount == 0)return 0;
        if(idx >= coins.size()) return 1e9;
        if(dp[amount][idx] != -1){
            return dp[amount][idx];
        }
        int take = 1e9;
        if(amount >= coins[idx]){
            take = 1 + ways(coins,amount - coins[idx], dp, idx);
        }
        int skip = ways(coins, amount, dp, idx+1);
        return dp[amount][idx] = min(skip, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(), -1));
        int k = ways(coins,amount,dp, 0);
        if(k == 1e9) return -1;
        return k;
    }
32/int dp[1000][1000];
int A[1000];
int W[1000];
int ans(int X, int n){
    if(n == 0) return 0;
    if(dp[n][X] != 0)return dp[n][X];
    if(X < W[n-1]){
        return dp[n][x] = ans(X,n-1);
    }
    return dp[n][x] = max(ans(X,n-1), ans(x-W[n-1], n-1) + A[n-1]));
}

33/struct Comparator{

        bool operator()(const pair<int, int>& A, const pair<int, int>& B) const{
            return A.first > B.first;
        }
    };
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int,vector<int>, greater<int>> chairs;
        int n = times.size();
        for(int i = 0;i<n;i++){
            chairs.push(i);
        }
        vector<vector<int>> help(n);
        for(int i = 0;i<n;i++){
            help[i] = {times[i][0], times[i][1], i};
        }
        sort(help.begin(), help.end(), [](const vector<int>& A, const vector<int>& B){
            return A[0] < B[0];
        });
        priority_queue<pair<int, int>, vector<pair<int,int>>, Comparator> pq;
        for(int i = 0;i < n;i++){
            while(!pq.empty() && pq.top().first <= help[i][0]){
                auto el = pq.top();
                chairs.push(el.second);
                pq.pop();
            }
            int chair = chairs.top();
            chairs.pop();
            pq.push({help[i][1], chair});
            if(targetFriend == help[i][2]) return chair;

        }
        return -1;
    }

34/struct Comparator{
        bool operator()(const pair<char,int>& A, const pair<char,int>& B)const{
            return A.second < B.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(int i = 0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, Comparator> pq;
        for(auto e :mp){
            pq.push({e.first, e.second});
        }
        queue<pair<int, pair<char,int>>> cool;
        int time = 0;
        while(!pq.empty() || !cool.empty()){
            if(!cool.empty() && cool.front().first == time){
                pq.push(cool.front().second);
                cool.pop();
            }
            if(!pq.empty()){
                auto el = pq.top();
                pq.pop();
                el.second--;
                if(el.second > 0){
                    cool.push({time + n+1, {el.first, el.second}});
                }
 
            }
            time++;
 
        }
         return time;
    }

35/int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& A,const vector<int>& B){
            return A[0] < B[0];
        });
 
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i = 0;i<n;i++){
            rooms.push(i);
        }
        vector<int> count(n);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long, int>>> pq;
        for(int i = 0;i<meetings.size();i++){
            while(!pq.empty() && pq.top().first <= meetings[i][0]){
                auto el = pq.top();
                pq.pop();
                rooms.push(el.second);
            }
            if(!rooms.empty()){
                int room = rooms.top();
                rooms.pop();
                count[room]++;
                pq.push({meetings[i][1], room});
                continue;
            }
            auto el = pq.top();
            pq.pop();
            count[el.second]++;
            pq.push({el.first + (meetings[i][1] - meetings[i][0]), el.second});

        }
        int maxi = *max_element(count.begin(), count.end());
        for(int i = 0;i<n;i++){
            if(maxi == count[i])return i;
        }
        return -1;
 
    }

36/struct Comparator{
bool operator()(const vector<int>& A, const vector<int>& B) const{
    return A[0] > B[0];
}
};
int main() {
    int Q;
    cin>>Q;
    while(Q--){
        int N,C;
        cin>>N>>C;
        vector<vector<int>> p;
        for(int i = 0;i<N;i++){
            int K,start, end;
            cin>>K>>start>>end;
            p.push_back({start,end,K});
 
        }
        sort(p.begin(), p.end(), [](const vector<int>& A, const vector<int>& B){
return A[0] < B[0];});
        int freeSeats = C;
        bool flag = false;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        for(int i = 0;i<N;i++){
            while(!pq.empty() && pq.top()[0] <= p[i][0]){
                freeSeats += pq.top()[1];
                pq.pop();
            }
            if(freeSeats-p[i][2]<0){flag = true;break;}
 
            freeSeats-=p[i][2];
            pq.push({p[i][1], p[i][2]});
        }
        if(flag)cout<<0<<'\n';
        else cout<<1<<'\n';
    }

37/int checkBalance(TreeNode* root){
        if(!root)return 0;
        int leftH = checkBalance(root->left);
        if(leftH == -1)return -1;
        int rightH = checkBalance(root->right);
        if(rightH == -1)return -1;
        if(abs(leftH - rightH) > 1) return -1;
        return max(leftH,rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }

EXAM TASKS
1/ int N;
    cin>>N;
    unordered_map<string, int> mp;
    for(int i = 0;i<N;i++){
        string t;
        cin>>t;
        mp[t]++;
    }
    
    int cnt = 0;
    for(auto m:mp){
        cnt += m.second/3;
    }
    cout<<cnt;
2/int canPlace(vector<long long>& ar, long long D, int K){
    long long last = ar[0];
    int cnt = 1;
    for(size_t i = 0;i < ar.size(); i++){
        if(ar[i]-last >= D){
        cnt++;
        last = ar[i];
        }
    }
    return cnt >= K;
}
int main()
{
    int N, K;
    cin>>N>>K;
    vector<long long> ar(N);
    for(int i = 0;i<N;i++){
        cin>>ar[i];
    }
    sort(ar.begin(), ar.end());
    long long high = ar[N-1]-ar[0];
    long long low = 1;
    while(low <= high){
        long long mid = low + (high - low)/2;
        if(canPlace(ar,mid,K)){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout<<high;
3/struct unionFind{
  vector<int> parent;
  vector<int> sizes;
  vector<int> sums;
  unionFind(int n){
      parent.resize(n);
      sizes.resize(n, 0);
      for(int i = 0;i<n;i++){
          parent[i] = i;
      }
      sums.resize(n, 0);
  }
    
  int find(int a){
      if(parent[a] != a){
          parent[a] = find(parent[a]);
      }
      return parent[a];
  }
bool unite(int a, int b, int w){
    a = find(a);
    b = find(b);
    
    if(a == b)return false;
   
    if(sizes[a]<sizes[b])swap(a,b);
    parent[b] = a;
     sums[a] += sums[b];
     sums[a] += w;
    if(sizes[a] == sizes[b])sizes[a]++;
   
    return true;
}
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int V,E,K;
    cin>>V>>E>>K;
    unionFind un(V);
    int comps = V;
    vector<vector<int>> edges;
    for(int i = 0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges.push_back({x,y,w});
        
    }
    sort(edges.begin(), edges.end(), [](const vector<int>& A, const vector<int>& B){
       return A[2]>B[2]; 
    });
    for(int i = 0;i<E;i++){
        if(comps == K)break;
        if(un.unite(edges[i][0], edges[i][1], edges[i][2]))comps--;
        
    }
    unordered_map<int, int> mp;
    for(int i = 0;i<V;i++){
      //  cout<<un.sums[un.find(i)]<<' ';
        mp[un.find(i)] = un.sums[un.find(i)];
    }
    vector<int> temp;
    for(auto m:mp){
        temp.push_back(m.second);
    }
    sort(temp.begin(),temp.end());
    for(size_t i = 0;i<temp.size();i++){
        cout<<temp[i]<<' ';
    }

4/working only for edge cases version
only for crossroads triangles -> OA, OB, AB
// Faculty_number: 
#include <bits/stdc++.h>
using namespace std;
bool isCross(vector<vector<int>>& vec,set<pair<int, int>>& edges){
    for(size_t i = 0;i<vec.size();i++){
        if(vec[i].size() == 4){
            int cnt = 0;
            int n = vec[i].size();
            set<int> nodes;
            for(int k = 0;k<n;k++){
                for(int j = k+1;j<n;j++){
                   pair<int, int> p1 = {vec[i][k], vec[i][j]};
                    pair<int, int> p2 = {vec[i][j], vec[i][k]};
                    if(edges.count(p1) || edges.count(p2)){
                        cnt++;
                        nodes.insert(p1.first);
                        nodes.insert(p1.second);
                    }
                }
            }
            if(cnt >= 2 && nodes.size() == 4)return true;
            }
        }
    
return false;
}
int main()
{
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Q;
    cin>>Q;
    int cnt = 0;
    for(int i = 0;i<Q;i++){
    int V,E;
    cin>>V>>E;
    
    vector<vector<int>> graph(V);
        
        set<pair<int, int>> edges;
        for(int i = 0;i<E;i++){
         int x, y;
          cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            edges.insert({x,y});
            
        }
        if(isCross(graph, edges)){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
/second attempt for checking nbrs cycles
// Faculty_number: 
#include <bits/stdc++.h>
using namespace std;
bool hasCycle(int X, int Y, int O, vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n);
    visited[O] = true;
    queue<int> q;
    q.push(X);
    visited[X] = true;
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        for(auto e:graph[el]){
            if(e == Y)return true;
            if(!visited[e]){
                q.push(e);
                visited[e] = true;
            }
        }
    }
    return false;
}
bool isCross(vector<vector<int>>& vec,set<pair<int, int>>& edges){
    for(size_t i = 0;i<vec.size();i++){
        if(vec[i].size() == 4){
           // int cnt = 0;
            int O = i;
           // int n = vec[i].size();
            int A = vec[i][0];
            int B = vec[i][1];
            int C = vec[i][2];
            int D = vec[i][3];
           
            if(hasCycle(A,B,O,vec) && hasCycle(C,D,O,vec))return true;
            if(hasCycle(A,C,O,vec) && hasCycle(B,D,O,vec))return true;
            if(hasCycle(A,D,O,vec) && hasCycle(C,B,O,vec))return true;
        }
    }
return false;
}
int main()
{
    
    int Q;
    cin>>Q;
    int cnt = 0;
    for(int i = 0;i<Q;i++){
    int V,E;
    cin>>V>>E;
    
    vector<vector<int>> graph(V);
        
        set<pair<int, int>> edges;
        for(int i = 0;i<E;i++){
         int x, y;
          cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            edges.insert({x,y});
            
        }
        if(isCross(graph, edges)){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
5/struct Task{
    long long arrive;
    int id;
    long long duration;
    int priority;
};
struct Compare{
  bool operator()(const Task& A, const Task& B){
    if(A.priority != B.priority)return A.priority < B.priority;
      if(A.arrive != B.arrive)return A.arrive > B.arrive;
      return A.id > B.id;
  }  
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int S,E;
    cin>>S>>E;
    priority_queue<Task, vector<Task>, Compare> tasks;
    vector<tuple<string, long long, int, long long, int>> input;
    priority_queue<long long, vector<long long>, greater<long long>> freeS;
    
    for(int i = 0;i<E;i++){
        string cmd;
        cin>>cmd;
        if(cmd == "ADD"){
            long long arrive, duration;
            int id, priority;
            cin>>arrive>>id>>duration>>priority;
         input.push_back({cmd,arrive, id, duration, priority});
        }
        else if(cmd == "CANCEL"){
         int id;
            long long time;
            cin>>time>>id;
            input.push_back({cmd,time, id, 0,0});
        }
    }
    
    int i = 0;
    unordered_set<int> cancelled;
    vector<int> result;
    long long currentTime = 0;
    
    while(i < E|| !freeS.empty() || !tasks.empty()){
    long long nextEvent = LLONG_MAX;
        if(i < E)nextEvent = get<1>(input[i]);
        long long nextFree = LLONG_MAX;
        if(!freeS.empty())nextFree = freeS.top();
        currentTime = min(nextEvent, nextFree);
        while(!freeS.empty() && freeS.top()<=currentTime)freeS.pop();
    
    
    while(i < E && get<1>(input[i]) == currentTime){
        auto [cmd,t,id,dur,pr] = input[i];
        if(cmd == "ADD")tasks.push({t,id,dur,pr});
        else if(id != -1)cancelled.insert(id);
        i++;
    }
    while((int)freeS.size()<S && !tasks.empty()){
    Task t = tasks.top();
        tasks.pop();
        if(cancelled.count(t.id))continue;
        result.push_back(t.id);
        freeS.push(currentTime + t.duration);
    }
        
    }
    for(int id:result){
    cout<<id<<' ';
    }
    return 0;
}
