TREE

PREORDER - NODE LEFT RIGHT
POSTORDER - LEFT RIGHT NODE
INOREDER - LEFT ROOT RIGHT

1/TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right); 
        return root;

    }
2/  void dfs(TreeNode* root, string str, vector<string>& res){
        if(!root) return;
        if(!root->left && !root->right){
            str+=to_string(root->val);
            res.push_back(str);
        }
        str += to_string(root->val);
        dfs(root->left, str + "->", res);
        dfs(root->right, str + "->", res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string str = "";
        dfs(root, str, res);
        return res;
    }

3/int rangeSumBST(TreeNode* root, int low, int high) {
      if(!root) return 0;
      int currentVal = (root->val <= high && root->val >= low) ? root->val : 0;
      int leftSum = rangeSumBST(root->left, low, high);
      int rightSum = rangeSumBST(root->right, low, high);

      return currentVal + leftSum + rightSum;

4/ TreeNode* build(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int m = left + (right - left)/2;
        TreeNode* curr = new TreeNode(nums[m]);
        curr->left = build(nums, left, m-1);
        curr->right = build(nums, m+1, right);

        return curr;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

5/  int maxLevelSum(TreeNode* root) {
        int maxSum = -99999;
        int currentSum = 0;
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel = 0;
        int maxLevel = 0;
        while(!q.empty()){
            currentLevel++;
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                currentSum += curr->val;
                cout<<currentSum<<' ';
                q.pop();
            }
            if(currentSum > maxSum) {maxSum = currentSum;
            maxLevel = currentLevel;}
            currentSum = 0;
        }
        return maxLevel;
    }
6/ int keepBalanceIdxs(TreeNode* root, vector<int>& balances){
        if(!root) return 0;

       int leftH = keepBalanceIdxs(root->left, balances);
       int rightH = keepBalanceIdxs(root->right, balances);
       balances.push_back(rightH-leftH); 
       return 1 + max(leftH, rightH);
       
    }
    int nodesCount(TreeNode* root){
        if(!root) return 0;
        return 1 + nodesCount(root->left) + nodesCount(root->right);

    }
    bool isBalanced(TreeNode* root) {
        vector<int> balances;
        keepBalanceIdxs(root,balances);
        for(int i = 0;i<balances.size();i++){
            if(abs(balances[i]) > 1) return false;
        }
        return true;
    }
7/ int findingTiltSums(TreeNode* root, int& finalSum){
        if(!root) return 0;
       
        int leftSum = findingTiltSums(root->left, finalSum);
        int rightSum = findingTiltSums(root->right, finalSum);
         finalSum += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
    int findTilt(TreeNode* root)
{
    int finalSum = 0;
    findingTiltSums(root,finalSum);
    return finalSum;
}

HOMEWORK
1/struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    long long val;
    TreeNode(long long val){
      this->val = val;
        left = right = nullptr;
    }
    
};
void computeMaxMin(TreeNode* root, int x, int& minX, int& maxX){
    if(!root) return;
    if(x < minX) minX = x;
    if(x > maxX) maxX = x;
    computeMaxMin(root->left, x-1, minX, maxX);
    computeMaxMin(root->right,x+1, minX, maxX);
}
// int findMinX(TreeNode* root){
//     int cnt = 0;
// while(root->left){
// root = root->left;
// cnt++;}
//     return cnt;
// }
// int findMaxX(TreeNode* root){
//  int cnt = 0;
// while(root->right){
// root = root->right;
// cnt++;}
//     return cnt;
// }

void find_sums(TreeNode* curr, vector<long long>& sums, int x, int minX){
    if(!curr) return;
     sums[x-minX] += curr->val;
    find_sums(curr->left, sums, x-1, minX);
    find_sums(curr->right, sums, x+1, minX);
    
    
}
void printTree(TreeNode* root){
    if(!root) return;
 cout<<root->val;
    printTree(root->left);
    printTree(root->right);
}


int main() {
    int N;
    cin>>N;
    vector<TreeNode*> tree(N);
    vector<pair<int, int>> children(N);
    for(int i = 0;i<N;i++){
      int l, r;
        long long val;
        cin>>val>>l>>r;
        tree[i] = new TreeNode(val);
        children[i] = {l, r};
    }
    for(int i = 0;i<N;i++){
        if(children[i].first != -1){
           tree[i]->left = tree[children[i].first];
        }
        if(children[i].second != -1){
           tree[i]->right = tree[children[i].second];
        }
        
    }
    TreeNode* root = tree[0];
    int minX = 0;
    int maxX = 0;
    computeMaxMin(root, 0, minX, maxX);
    int size = maxX-minX+1;
    
//     int size = findMaxX(root) + findMinX(root) + 1;
//     int minX = -findMinX(root);
    // printTree(root);
    // cout<<findMaxX(root);
    vector<long long> sums(size,0);
    find_sums(root, sums, 0, minX);
    for(int i = 0;i<size;i++){
        if(sums[i] != 0){
        cout<<sums[i]<<' ';}
    }
    
2/
struct TreeNode{
TreeNode* left;
TreeNode* right;
long long val;
    TreeNode(long long val){
      this->val = val;
        left = right = nullptr;
    }
};
void printOrder(TreeNode*& root){
   if(!root) return;
    cout<<root->val<<' ';
    printOrder(root->left);
    printOrder(root->right);
}
TreeNode* buildTreeByCoordinates(){
    
    int N;
    cin>>N;
    vector<TreeNode*> tree(N);
    vector<pair<int, int>> childs(N);
    for(int i = 0;i<N;i++){
    long long val;
        int l, r;
        cin>>val>>l>>r;
       tree[i] = new TreeNode(val);
        childs[i] = {l, r};
    }
    
    for(int i = 0;i<N;i++){
     if(childs[i].first != -1){
       tree[i]->left = tree[childs[i].first];
     }
    if(childs[i].second != -1){
      tree[i]->right = tree[childs[i].second];
    
    }
       
    }
    //printOrder(tree[0]);
    return tree[0];
    
}
bool isBSTUtil(TreeNode* root, int& prev){
if(!root) return true;
    if(!isBSTUtil(root->left, prev)) return false;
    if(root->val <= prev) return false;
    prev = root->val;
    
    return isBSTUtil(root->right, prev);
}
bool isBST(TreeNode* root){
int prev = 0;
    return isBSTUtil(root, prev);
}
int main() {
    int T;
    cin>>T;
    for(int i = 0;i<T;i++){
     TreeNode* root = buildTreeByCoordinates();
      //  printOrder(root);
     cout<<isBST(root)<<'\n';    
    }

3/using namespace std;
void dfs(int root, vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, int& timer){
    tin[root] = timer++;
    for(int u : adj[root]){
       dfs(u, adj, tin, tout, timer);
    }
    tout[root] = timer++;
}
bool isAncestor(int x, int y, vector<int>& tin, vector<int>& tout){
return (tin[x]<=tin[y] && tout[y]<= tout[x]);
}

int main() {
//for speed
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<vector<int>> adj(N);
    vector<int> parent(N, -1);
    for(int i = 0;i<N-1;i++){
      int dad, son;
        cin>>dad>>son;
        adj[dad].push_back(son);
        parent[son] = dad;
    }
    int root = -1;
    for(int i=0;i<N;i++){
      if(parent[i] == -1) root = i;
    }
    vector<int> tin(N), tout(N);
    //int root = 0;
    int timer = 0;
    dfs(root, adj, tin, tout, timer);
    int Q;
    cin>>Q;
    while(Q--){
    int x, y;
        cin>>x>>y;
        isAncestor(x, y, tin, tout) ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
    
    }
     
    return 0;
}

//half-working solution
#include <algorithm>
using namespace std;
struct TreeNode{
TreeNode* left;
TreeNode* right;
int val;
TreeNode(int val){
this->val = val;
right = left = nullptr;
}
};
void printOrder(TreeNode* root){
    if(!root) return;
cout<<root->val;
printOrder(root->left);
printOrder(root->right);
}
bool canReach(TreeNode* dad, TreeNode* son){
    if(!dad) return false;
    if(dad == son) return true;
    return canReach(dad->left, son)||canReach(dad->right, son);
    
    
}
int main() {
    
    int N;
    cin>>N;
    vector<TreeNode*> tree(N);
   
for(int i = 0;i<N;i++){
tree[i] = new TreeNode(i);}

for(int i = 0;i<N-1;i++){
int dad, son;
cin>>dad>>son;
    // build the structure directly
   if(!tree[dad]->left)tree[dad]->left = tree[son];
    else tree[dad]->right = tree[son];
       
}
    // vector<vector<int>> childs(N);
    // for(int i = 0;i<N-1;i++){
    //    int dad, son;
    //     cin>>dad>>son;
    //     tree[i] = new TreeNode(i);
    //     childs[dad].push_back(son);
    // }
    // tree[N-1] = new TreeNode(N-1);
    // for(size_t i = 0;i<childs.size();i++){
    //     if(childs[i].size() == 1){
    //         tree[i]->left = tree[childs[i][0]];
    //     }
    //     else if(childs[i].size() == 2){
    //         tree[i]->left = tree[childs[i][0]];
    //         tree[i]->right = tree[childs[i][1]];
    //     }
    // }
    int Q;
    cin>>Q;
//     for(int i = 0;i<childs.size();i++){
//     for(int j = 0;j<childs[i].size();j++){
// cout<<childs[i][j]<<' ';}
//         cout<<'\n';
//     }
  //  printOrder(tree[0]);
    for(int i =0;i<Q;i++){
     int x, y;
      cin>>x>>y;
    if(canReach(tree[x], tree[y]))cout<<"YES";
        else cout<<"NO";
    cout<<'\n';
    
    }
 
    return 0;
}


zadachi seminar
Recursive Approach
1/ TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        if(root->val < val){
           return searchBST(root->right, val);
        }   
        else{
            return searchBST(root->left, val);
        }
        
         }

Iterative approach
TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        while(root){
           if(root->val == val) return root;
           if(root->val > val) root = root->left;
           else root = root->right;
        }

        return nullptr;//if we havent found anything
        //return root;

2/Iterative
  TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while(cur){
            prev = cur;
            if(cur->val > val){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }

        }
        if(prev->val > val){
            prev->left = new TreeNode(val);
        }
        else{
            prev->right = new TreeNode(val);
        }
        return root;
        
    }

/Recursive
 TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        if(root->val == val) return root;
        if(root->val > val){
           root->left = insertIntoBST(root->left, val);
        }
        else{
            root->right = insertIntoBST(root->right, val);
        }

        return root;

Traversals
//LEFT ROOT RIGHT
 1/ void dfs(TreeNode* cur, vector<int>& v){
        // lqvo,koren, dqsno
        if(!cur) return;
       
        dfs(cur->left, v);
         v.push_back(cur->val);
        dfs(cur->right, v);

    
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        dfs(root, vec);
        return vec;
    }
LEFT RIGHT ROOT
2/ void helper(TreeNode* root, vector<int>& vec){
        //left, right, koren
        if(!root) return;
        helper(root->left, vec);
        helper(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(root, vec);
        return vec;
    }
ROOT LEFT RIGHT
3/ void helper(TreeNode* root, vector<int>& vec){
        //root, left, right
        if(!root) return;
         vec.push_back(root->val);
        helper(root->left, vec);
        helper(root->right, vec);
       
    }
   
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> vec;
        helper(root, vec);
        return vec;
    }
4/int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
5/ bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
6/Symmetry
 bool mirror(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2)return true;
        if(!t1 || !t2) return false;
        if(t1->val != t2->val) return false;

        return mirror(t1->left, t2->right) && mirror(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root){
        return mirror(root->left, root->right);
    }
7/  int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        res = max(l+r, res);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
         dfs(root, res);
        return res;
    }
8/Level order
 vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>> finali;
        if(!root) return finali;
      
        queue<TreeNode*> q;
        q.push(root);
        // cout<<q.front()->val;
        while(!q.empty()){
           int size = q.size();
           vector<int> helper;
           for(int i = 0;i<size;i++){
             TreeNode* cur = q.front();
             helper.push_back(cur->val);
             if(cur->left)q.push(cur->left);
             if(cur->right)q.push(cur->right);
             q.pop();
           }
           finali.push_back(helper);

        }
        return finali;
    }

//rightView
vector<int> rightSideView(TreeNode* root) {
     vector<vector<int>> finali = levelOrder(root);
     vector<int> rightView;
     for(int i = 0;i<finali.size();i++){
        rightView.push_back(finali[i][finali[i].size()-1]);
     }   
     return rightView;
    }

9/ bool validateHelper(TreeNode* root, long& prev){
        if(root){ 
        if(!validateHelper(root->left, prev)) return false;
        if(prev >= root->val)return false;
        prev = root->val;
        return validateHelper(root->right, prev);
        }
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return validateHelper(root, prev);
    }
10/TOP VIEW OF A TREE
vector<int> topView(TreeNode* root){
    deque<int> v;
    vector<int> a;
    queue<pair<TreeNode*, int>> q;
    if(root == nullptr)return a;
    q.push({root, 0});
    a.push_back(root->val);
    int l = 0;
    int r = 0;

    while(!q.empty()){
        int size = q.size();
     
        TreeNode* cur = q.front().first;
        int vh = q.front().second;
        q.pop();
        if(vh > r){
            r = vh;
            v.push_back(cur->val);
        }
        if(vh < l){
            l = vh;
            v.push_front(cur->val);
        }
        if(cur->left)q.push_back({cur->left, vh-1});
        if(cur->right)q.push_back({cur->right, vh+1});
    }

    while(v.size()){
        int d = v.front();
        a.push_back(d);
        v.pop_front();
    }

    return a;


}

BOTTOM VIEW
vector<int> topView(TreeNode* root){
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    vector<int> a;
    if(!root) return a;
    while(!q.empty()){
        auto [node, hd] = q.front();
        q.pop();
        mp[hd] = node->data;
        if(node->left) q.push({node->left, hd-1});
        if(node->right) q.push({node->right, hd+1});
    }
    for(auto& p: mp){
        a.push_back(p.second);
    }
}

DELETE NODE
TreeNode* getSuc(TreeNode* root){
        root = root->right;
        while(root->left && root){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root) return root;
       if(root->val > key){
        root->left = deleteNode(root->left, key);
       }
       else if(root->val < key){
       root->right = deleteNode(root->right, key);
       }
       else{
           if(!root->left){
             TreeNode* temp = root->right;
              delete root;
              return temp;
           }
           if(!root->right){
             TreeNode* temp = root->left;
              delete root;
              return temp;
           }
         TreeNode* succ = getSuc(root);
         root->val = succ->val;
         root->right = deleteNode(root->right, succ->val);
       }
       return root;
    }

10/Removes subtree with 1 
TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0) return nullptr;
        return root;
    }

11/Greater tree - sum nodes
  int sum = 0;
    void convert(TreeNode* cur){
        if(!cur) return;
        convert(cur->right);
        sum += cur->val;
        cur->val = sum;
        convert(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }

12/removing nodes outside the interval
TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root->val < low) return trimBST(root->right, low, high);
        if(root->val > high) return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root; 
    }

13/Building BST with parent vector
TreeNode* buildTreeByParentArray(vector<int>& nums){
    vector<TreeNode*> tree(nums.size());
    TreeNode* root = nullptr;
    for(int i = 0;i<nums.size();i++){
        tree[i] = new TreeNode(i);
    }
    for(int y = 0;y<nums.size();y++){
        if(nums[y] == -1){root = tree[y];continue;}
        if(!tree[nums[y]]->left)tree[nums[y]]->left = tree[y];
        else tree[nums[y]]->right = tree[y];
    }
    return root;
}

14/Continuous subarrays
long long continuousSubarrays(vector<int>& nums) {
        int l = 0;
        long long res = 0;
        deque<int> minD, maxD;

        for(int r = 0;r<nums.size();r++){
            while(!minD.empty() && nums[minD.back()] >= nums[r]) minD.pop_back();
            while(!maxD.empty() && nums[maxD.back()] <= nums[r]) maxD.pop_back();

            minD.push_back(r);
            maxD.push_back(r);

            while(nums[maxD.front()]- nums[minD.front()] > 2){
                l++;
                if(minD.front()<l)minD.pop_front();
                if(maxD.front()<l)maxD.pop_front();
            }

            res += r-l+1;
        }

        return res;
    }

14/Flatten tree to linkedlist
 void preorder(TreeNode* root, vector<TreeNode*>& vec){
        if(!root) return;
        vec.push_back(root);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> vec;
        preorder(root, vec);
        for(int i = 0;i<vec.size()-1;i++){
            vec[i]->left = nullptr;
            vec[i]->right = vec[i+1];
        }
    }

15/
 pair<int, TreeNode*> helper(TreeNode* node){
        if(!node) return {0, nullptr};

        auto left = helper(node->left);
        auto right = helper(node->right);

        if(left.first == right.first) return {left.first+1, node};
        else if(left.first > right.first) return {left.first +1, left.second};
        else return {right.first + 1, right.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }


16/TreeNode* build(vector<int>& preorder, int& i, int bound){
        if(preorder.size() == 0) return nullptr;
        if(i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder,i, INT_MAX);
    }
};

17/ vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
   
        vector<vector<int>> nodes;
        if(!root) return nodes;
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            vector<int> helper;
            int size = q.size();
            while(size--){
               
                TreeNode* cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();

                helper.push_back(cur->val);

            }
            if(cnt % 2 == 1) reverse(helper.begin(), helper.end());
            nodes.push_back(helper);
            cnt++;
        }
        return nodes;
    }

18/Print leaves
if(!root) return nodes;
         if(!root->left && !root->right)
{ cout<<root->val<<'\n';nodes.push_back(root->val);}
         printLeaves(root->left);
         printLeaves(root->right);

19/   bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(root->left && root->left->val != root->val)return false;
        if(root->right && root->right->val != root->val) return false;

        return isUnivalTree(root->right) && isUnivalTree(root->left);
    }
20/ bool evaluateTree(TreeNode* root) {
       // if(!root->right && !root->left) return root->val;
        if(root->val == 2) return evaluateTree(root->right) || evaluateTree(root->left);
        if(root->val == 3) return evaluateTree(root->right) && evaluateTree(root->left); 

        return root->val;
    }
21/

