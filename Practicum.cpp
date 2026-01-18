Practicum preparation
1/ string shortestPalindrome(string s) {
        int n = s.size();
        long long hash1 = 0;
        long long hash2 = 0;
        long long mod = 1e9;
        int len = 0;
        int p = 27;
        long long power = 1;
        for(int i = 0;i<n;i++){
            hash1 = hash1 * p + s[i]-'a' + 1;
            hash1 %=mod;
            hash2 = power * (s[i] - 'a' + 1) + hash2;
            hash2 %= mod;
            if(hash1 == hash2) len = i+1;
            power *= p;
            power %= mod;
        }
        string help = s.substr(len, n-len);
        reverse(help.begin(), help.end());
        return  help + s;
2/ string shiftingLetters(string s, vector<int>& shifts) {
      //  vector<int> newShifts(shifts.size());
        int n = shifts.size();
       // newShifts[n-1] = shifts[n-1];
        for(int i = shifts.size() - 2;i>=0;i--){
           shifts[i] = (shifts[i] + shifts[i+1]) % 26;
           cout<<shifts[i]<<' '; 
        }
        string t = "";
        for(int i = 0;i<n;i++){
            t += (shifts[i] + s[i] - 'a') % 26 + 'a';
        }
        return t;
    }
3/vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> helper(n);
        for(int i = 0;i<bookings.size();i++){
            helper[bookings[i][0]-1]+=bookings[i][2];
            if(bookings[i][1] == n) continue;
            helper[bookings[i][1]] -= bookings[i][2]; 
        }

        for(int i = 1;i<n;i++){
            helper[i] += helper[i-1];
        }

        return helper;
    }
4/using namespace std;
struct Node{
    Node* right;
    Node* left;
    int key;
    Node(int val){
        key = val;
        right = left = nullptr;
    }
};

Node* insertNode(Node* root, int k){
if(root == nullptr){
return new Node(k);
}
    if(root->key > k){
root->left = insertNode(root->left, k);
    }
    else{
        root->right = insertNode(root->right, k);
    }
    return root;
}
vector<int> topNodes(Node* root){
map<int, int> mp;
queue<pair<int, Node*>> q;
    vector<int> result;
    
    q.push({0, root});
    
    while(!q.empty()){
       auto el = q.front();
        Node* node = el.second;
        int hd = el.first;
        q.pop();
        
        if(mp.find(el.first) == mp.end()){
mp[el.first] = el.second->key;}
        
        if(node->left){
            q.push({hd-1,node->left});
}
        if(node->right){
            q.push({hd+1, node->right});
        }
    }
    for(auto e:mp){
  result.push_back(e.second);
    }
    for(size_t i = 0;i<result.size();i++){
        cout<<result[i] << ' ';
    }
    cout<<'\n';
    return result;
    
}
int main() {
    int T;
    cin>>T;
    while(T--){
       int N;
        Node* root = nullptr;
        cin>>N;
        for(int i = 0;i<N;i++){
            int n;
            cin>>n;
            root = insertNode(root, n);
        }
       topNodes(root); 
    }

5/ bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ind(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        vector<int> conseq;
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(ind[i] == 0)
            {q.push(i);conseq.push_back(i);}
        }
        cout<<q.size()<<'\n';
        while(!q.empty()){
            auto el = q.front();
            q.pop();
            for(auto e:graph[el]){
            ind[e]--;
            if(ind[e] == 0) {q.push(e); conseq.push_back(e);};   
            }
        }
        cout<<conseq.size()<<'\n';
        return conseq.size() == numCourses;
    }

6/int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> ost(nums.size());
        ost[0] =(nums[0]%k + k)%k;
        for(int i = 1;i<nums.size();i++){
             ost[i] = ((((nums[i] + ost[i-1])%k)+k)%k);
        }
        for(int i = 0;i<nums.size();i++){
            cout<<ost[i]<<' ';
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        for(int i = 0;i<ost.size();i++){
            count += mp[ost[i]];
            mp[ost[i]]++;

        }
        return count;
    }

7/  int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int longest = 0;
        mp[0]=-1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1) sum++;
            else sum--;
            if(mp.find(sum) != mp.end()){
                longest = max(longest, i - mp[sum]);
            }
            else mp[sum]=i;;
        }
        return longest;
    }

8/ int minPathsum(vector<vector<int>>& grid, vector<vector<int>>& dist,int m, int n,int x, int y){
        if(x < 0|| y < 0)return 0;
        if(dist[x][y] != -1) return dist[x][y];
        if(x == 0)return dist[x][y] = minPathsum(grid, dist,m,n,x,y-1) + grid[x][y];
        if(y == 0)return dist[x][y] = minPathsum(grid, dist,m,n,x-1,y) + grid[x][y];
        return dist[x][y] = min(minPathsum(grid, dist,m,n,x-1,y), minPathsum(grid, dist,m,n,x,y-1)) + grid[x][y];
        }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        return minPathsum(grid, dist,n, m,n-1,m-1);
    }

9/    int n, E, K;
    cin>>n>>E>>K;
    unordered_map<int,vector<int>> mp;
    for(int i = 0;i<E;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    
    int cnt = 0;
    vector<bool> visited(n);
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            queue<int> q;
            int nodes = 0;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                auto el = q.front();
                nodes++;
                q.pop();
                for(auto e:mp[el]){
                    if(!visited[e]){
                        visited[e] = true;
                        q.push(e);
                    }
                }
            }
            if(nodes % K == 0)cnt++;
        }
    }
    cout<<cnt;
10/using namespace std;
struct unionFind{
    vector<int> parent, sizes;
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
        
        if(a == b) return false;;
        if(sizes[a]< sizes[b])swap(a,b);
        parent[b] = a;
        if(sizes[a] == sizes[b])sizes[a]++;
        return true;
    }
};
int main()
{
    int n, E, K;
    cin>>n>>E>>K;
    unionFind un(n);
    unordered_map<int,vector<int>> mp;
    for(int i = 0;i<E;i++){
        int x,y;
        cin>>x>>y;
        un.unite(x,y);
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    unordered_map<int, int> counts;
    for(int i = 0;i<n;i++){
        counts[un.find(i)]++;
    }
    int cnt=0;
    for(auto m:counts){
        if(m.second % K)cnt++;
    }

11/isCycle 
bool isCycle(int a,int b){
        return find(a)==find(b);
    }

12/int dfs(vector<vector<int>>& graph, int i, int& nodes, vector<bool>& visited){
    for(auto e:graph[i]){
        if(!visited[e]){
        nodes++;
        visited[e] = true;
        dfs(graph,e,nodes,visited);
    }
}
for(int i = 0;i<n;i++){
    if(!visited[i]){
        int nodes = 0;
        dfs(graph,i,nodes,visited);
        cout<<nodes % K == 0;
    }
}

