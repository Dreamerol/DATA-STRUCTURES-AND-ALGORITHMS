STACK and QUEUE
zad1 - remove min el
   queue<int> q;
    q.push(9);
    q.push(33);
    q.push(23);
    q.push(99);
    int mini = q.front();
    int size = q.size();
    for(int i = 0;i<size;i++){
    int current = q.front();
    if(mini > current) mini = current;
    q.pop();
    q.push(current);
        
    }
    
    for(int i = 0;i<size;i++){
    int current = q.front();
    if(mini == current) q.pop();
    else{
    q.pop();
    q.push(current);
    }        
    }
    for(int i = 0;i<size-1;i++) {
        int current = q.front();
        cout<<current<<' ';
        q.pop();
        q.push(current);
        
    }

HAMMING NUMBERS GENERATOR
 queue<int> two;
    two.push(2);
    
    queue<int> three;
    three.push(3);
    
    queue<int> five;
    five.push(5);
    int N;
    cin>>N;
    for(int i = 0;i<N;i++){
        int cur2 = two.front();
        int cur3 = three.front();
        int cur5 = five.front();
        int acc = min(cur2, min(cur3, cur5));
        
        if(cur2 == acc){
           
           two.pop();
        }
        if(cur3 == acc){
           three.pop();
            
        }
        if(acc == cur5){
            
            five.pop();
        }
        cout<<acc<<' ';
        two.push(2*acc);
        three.push(3*acc);
        five.push(5*acc);
    }
zadachi_SEMINAR
1/    queue<int> q; 
    int ping(int t) {
       
        q.push(t);
        while(!q.empty() && t - q.front() > 3000){
            q.pop();
        }
        return q.size();
        
    }
2/BFS with oranges
    bool isValidPos(int x, int y, int n, int m){
        return (x>= 0 && x<=n-1 && y>=0 && y<=m-1);
    }
    vector<pair<int, int>> nbrs(int x, int y){
        vector<pair<int, int>> vec;
        vec.push_back({x, y-1});
        vec.push_back({x, y+1});
        vec.push_back({x-1, y});
        vec.push_back({x+1, y});
        return vec;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] ==2){
                    q.push({i, j});
                }
            }
        }
        int cnt = 0;
        while(!q.empty()){
           int size = q.size();
           for(int i = 0;i<size;i++){
            vector<pair<int, int>> helper = nbrs(q.front().first, q.front().second);
            for(int k = 0;k<4;k++){
                int x = helper[k].first;
                int y = helper[k].second;
            if(isValidPos(x, y, n, m) && grid[x][y] == 1){
                grid[x][y] = 2;
                q.push({x, y});
            }
            }
            q.pop();

           }
           cnt++;

        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] ==1){
                    return -1;
                }
            }
        }
        if(cnt >0) return --cnt;
        return 0;
    }
3/char MirrorHelper(char c){
        if(c == '}') return '{';
        else if(c == ')') return '(';
        else return '[';
    }
    bool isValid(string s) {
        stack<char> parent;
        int size = s.length();
        for(int i = 0;i<size;i++){
            char a = s[i];
            if(a == '(' || a == '{'|| a=='['){               
                parent.push(a);
        
            }
            else if(a == ')' || a == '}'|| a == ']'){
                if(!parent.empty() && parent.top()== MirrorHelper(a)){
                    parent.pop();     
                }
                else {
                    return false;
                }
             }
            
        }
        return parent.size()==0;
    }
    
//     bool isValid(string s){
//         stack<int> st;
//       for(int i = 0;i<s.length();i++){
//         char a = s[i];
//         if(a == '(' || a == '{' || a == '['){
// st.push(a);
//         }
//         else{
//             char top = st.top();
//             st.pop();
//             if(a == ')' && top !='(')return false;
//             if(a == ']' && top != '[') return false;
//             if(a == '}' && top != '{')return false;

//         }
//       }
//       return st.size() == 0;
//     }

4/   bool backspaceCompare(string s, string t) {
     stack<int> st1;
     stack<int> st2;

     for(int i = 0;i<s.length();i++){
        if(s[i]=='#'){
            if(!st1.empty()){
            st1.pop();
            }
            continue;
        }
        st1.push(s[i]);
     }
     for(int i = 0;i<t.length();i++){
        if(t[i]=='#'){
            if(!st2.empty()){
            st2.pop();
            }
            continue;
        }
        st2.push(t[i]);
     }   
    
    if(st1.size() != st2.size()) {cout<<st1.size();return false;}
    while(!st1.empty() && !st2.empty()){
        if(st1.top() != st2.top()){
            return false;
        }
        st1.pop();
        st2.pop();
    }

    return true;
    }
5/Meteor Coillision
 vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> finals;
        vector<int> finali;
        int i = 0;
        while(i < asteroids.size() && asteroids[i]<0){
            finali.push_back(asteroids[i]);
            i++;
        }
        for(;i<asteroids.size();i++){
            if(asteroids[i]<0){
               while(true){
                
                if(finals.empty()){
                    finals.push(asteroids[i]);
                    break;
                }
                if(finals.top() * asteroids[i]>0){finals.push(asteroids[i]);break;};
                if(abs(asteroids[i])>=finals.top()){
                    if(abs(asteroids[i]) == finals.top()){
                        finals.pop();
                        break;
                    }
                    finals.pop();
                }
                
                else{
                    break;
                }
            }
            continue;
            }
            
            finals.push(asteroids[i]);
        }
        vector<int> helper;      
        while(!finals.empty()){
            helper.push_back(finals.top());
            finals.pop();
        }
        reverse(helper.begin(), helper.end());
        for(int y = 0;y<helper.size();y++){
            finali.push_back(helper[y]);
        }
        return finali;
    }
6/Polish Notation
  int calcResult(int a, int b, string s){
       
       if(s == "+") return a + b;
       if(s == "-") return a-b;
       if(s == "*")return a*b;
       if(s == "/") return a/b;
       return 1;
       
    }
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> ops;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "*" || tokens[i] == "/" ||tokens[i]=="+"||tokens[i]=="-"){
                if(ops.empty()) return res;
                int b = ops.top();
                ops.pop();
                int a = ops.top();
                ops.pop();
                ops.push(calcResult(a, b, tokens[i]));
                continue;

            }
            ops.push(stoi(tokens[i]));
        }
        return ops.top();
    }

ZADACHI HOMEWORK
zadacha 1
bool isValidPos(int n, int m, int x, int y){
return (x >= 0 && x<=n-1 && y>=0&& y<=m-1);}
vector<pair<int, int>> helper(int n, int m, int x, int y){
    vector<pair<int, int>> h;
    if(isValidPos(n, m ,x-1, y)) h.push_back({x-1, y});
    if(isValidPos(n, m ,x+1, y)) h.push_back({x+1, y});
    if(isValidPos(n, m ,x, y-1)) h.push_back({x, y-1});
    if(isValidPos(n, m ,x, y+1)) h.push_back({x, y+1});
    return h;
    
}
int goodApples(int N, int M, int T, queue<pair<int, int>>& q, vector<vector<int>>& grid){
int cnt = M*N - q.size();
  
    int c = q.size();
   
    for(int i = 0;i<T;i++){
   size_t size = q.size();
       
        for(size_t j = 0;j<size;j++){
              vector<pair<int, int>> help = helper(N, M, q.front().first, q.front().second);
              for(size_t u = 0;u<help.size();u++){
               
                  if(grid[help[u].first][help[u].second] != 1){
                      grid[help[u].first][help[u].second] = 1;
                      q.push(help[u]);
                      c++;
                  }
              }
            q.pop();
        
        }
        cnt -= q.size();
    }
    return cnt;
    
}

int main() {
    int N;
    int M;
    int T;
    cin>>N>>M>>T;
    int x,y;
    
      vector<vector<int>> grid;
   
    for(int i = 0;i<N;i++){
vector<int> vec(M);
    grid.push_back(vec);}
    
    
    queue<pair<int,int>> q;
    while(cin>>x>>y) {
        grid[x-1][y-1] = 1;
        q.push({x-1, y-1});}
    cout<<goodApples(N, M ,T, q, grid);

    return 0;

zadacha 2
void IQbattle(vector<int>& persons, int N){
vector<int> result;
    int i = 0;
    while(i < N && persons[i]< 0){
        result.push_back(persons[i]);
        i++;
    }
    for(;i<N;i++){
    if(persons[i] > 0){
        result.push_back(persons[i]);
        continue;
    }
        while(result.size() > 0 && result.back() > 0 && result.back() < abs(persons[i])){
           result.pop_back();
        }
        if(result.size() == 0 || result.back() < 0){
            result.push_back(persons[i]);
        }
        else if(result.back() == abs(persons[i])){
            result.pop_back();
        }
        
    }
     if(result.size() == 0){ cout<<'\n';return;}
        for(size_t i = 0;i<result.size();i++){
cout<<result[i]<<' ';}
}
zadacha 3
long long findMinEls(vector<long long>& nums, int N, int k){
deque<long long> deq;
    long long sum = 0;
   // vector<int> result;
    for(int i = 0;i<N;i++){
        while(!deq.empty() && nums[i] <= nums[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
        if(deq.front() <= i-k){
          deq.pop_front();
        }
        if(i >= k-1){
            sum+=nums[deq.front()];
//result.push_back(nums[deq.front()]);}
    }
    }
  
    return sum;

}
int main() {
    int N, k;
    cin>>N>>k;
    
    vector<long long> nums;
    for(int i = 0;i<N;i++){
        long long a;
        cin>>a;
       nums.push_back(a);
    }
    cout<<findMinEls(nums, N, k);
7/IMPORTANT ZADACHA - FIND MIN ELS ON THE RIGHT
//GIVEN ON INTERVIEWS
   vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> helper(nums.size(), -1);
        
        int n = nums.size();
        for(int i = 2*n-1;i>=0;i--){
           
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
              if(!st.empty()){
                helper[i%n] = st.top();
            }
            st.push(nums[i%n]);
           

        }
        return helper;
    }
8/Finding Greater Element Linked List
int findSize(ListNode* head){
        ListNode* cur = head;
        int cnt = 0;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        
        //ListNode* cur = head;
        int size = findSize(head);
        vector<int> res(size);
        stack<int> ms, mv;
        //ms - collects idxs
        //mv - collects values
        int counter = 0;
        while(head){
           while(!mv.empty() && mv.top() < head->val){ //[1 2]->[2]
                res[ms.top()] = head->val;//the second we find a greater element 2>1
                                           //that means we have found the a greater el 
                                         //so we say res[idx of 1] = cur->val demek 2
               ms.pop();
               mv.pop();
            

            }
           
            ms.push(counter);
            mv.push(head->val);

            counter++;
            head = head->next;
        }
        return res;

    }
9/DailyTemperatures
  vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            int count = 0;
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                count++;
                st.pop();
            }
            if(st.empty()){
                res[i] = 0;
            }
            else{
                res[i] = st.top() - i;
            }

            st.push(i);
        }
        return res;
    }

10/Jungle - half working solution

int bestView(vector<int>& trees, int N){
    stack<int> st;
    int maxCounter = 0;
    int maxIdx = -1;
    for(int i = N-1;i>=0;i--){
       int counter = 0;
        bool flag = false;
        while(st.empty() || trees[i]<trees[st.top()]){
              counter++;
            st.push(i);
            flag = true;
        }
        if(!flag){
        st.push(i);}
        
        if(maxCounter <= counter){
           maxCounter = counter;
            maxIdx = st.top();
        }
        
    }
    return maxIdx;
}
int main() {
    int N;
    cin>>N;
    vector<int> trees(N);
    for(int i = 0;i<N;i++){
       cin>>trees[i];
    }
    cout<<bestView(trees, N);

//Working solution

int bestView(vector<int>& trees, int N){
    stack<int> st;
    int maxCounter = 0;
    int maxIdx = -1;
    for(int i = N-1;i>=0;i--){
       while(!st.empty() && trees[i] >= trees[st.top()]){
st.pop();
       }
        st.push(i);
        
        if(maxCounter <= st.size()){
           maxCounter = st.size();
            maxIdx = st.top();
        }
        
    }
    return maxIdx;
}
int main() {
    int N;
    cin>>N;
    vector<int> trees(N);
    for(int i = 0;i<N;i++){
       cin>>trees[i];
    }
    cout<<bestView(trees, N);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;

10/baseball game
 int calPoints(vector<string>& operations) {
        stack<int> record;
  
        int sum = 0;
        for(int i = 0;i<operations.size();i++){
          if(operations[i] == "D"){
            int a = record.top() * 2;
            record.push(a);

          }
          else if(operations[i] == "C"){
            record.pop();
          }
          else if(operations[i] == "+"){
            int a = record.top();
            record.pop();
            int b = record.top();

            int c= a+b;
            record.push(a);
            record.push(c);
          }
          else {
            record.push(stoi(operations[i]));
          }
        }
        while(!record.empty()){
            int a = record.top();
            sum += a;
            record.pop();
        }
        return sum;
    }

//Min Stack
class MinStack {
    stack<long long> container;
    stack<long long> minCon;
    long long minVal = 0;

public:
     
    MinStack() {}
    
    void push(int val) {
        container.push(val);
        if(minCon.empty() || val <= minCon.top()) minCon.push(val);
    }
    
    void pop() {
        if(container.top() == minCon.top())minCon.pop();
        container.pop();
    }
    
    int top() {
        if(container.empty()) return -1;
        return container.top();
    }
    
    int getMin() {
       if(minCon.empty()) return -1;
       return minCon.top();     
    }
};

11/  int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt = 0;
       while(true){
        if(students.size() == sandwiches.size() && sandwiches.size() == 0) return 0;
        if(cnt == students.size()) return students.size();
        if(students.front() == sandwiches.front()){
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
            cnt = 0;
        }
        else{
            cnt++;
            int a = students.front();
            students.push_back(a);
            students.erase(students.begin());
        }
       }
    }

12/int findsize(ListNode* head){
    int cnt = 0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
}
    int pairSum(ListNode* head) {
        int size = findsize(head);
        stack<int> st;
        for(int i = 0;i<size/2;i++){
            st.push(head->val);
            head = head->next;
        }
        int maxVal = 0;
         for(int i = 0;i<size/2;i++){
            int curr = head->val + st.top();
            if(curr > maxVal) maxVal = curr;
            st.pop();
            head = head->next;
        }
        return maxVal;

    }

13/string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(!st.empty() && st.top() == s[i])st.pop();
            else st.push(s[i]);
        
        }
        string fin = "";
        while(!st.empty()){
            fin += st.top();
            st.pop();
        }
        reverse(fin.begin(), fin.end());
        return fin;
    }

14/ String stack mirror - half working solution
  long long calculateScore(string s) {
        int cnt = 0;
        stack<char> st;
        vector<stack<int>> letters(26);
        for(int i = s.size()-1;i>=0;i--){
            letters[s[i]-'a'].push(i);
        }
        for(int j = 0;j<13;j++){
            if(!letters[j].empty() && !letters[26-j-1].empty()) {
                cnt += abs(letters[j].top() - letters[26-j-1].top());
            }
        }
        return cnt;
15/long long calculateScore(string s) {
        long long cnt = 0;
        stack<char> st;
        vector<stack<int>> letters(26);
        for(int i = 0;i<s.size();i++){
            if(!letters[25-(s[i]-'a')].empty())
               {cnt += i - letters[25 - (s[i]-'a')].top();
                letters[25-(s[i]-'a')].pop();}
            
            else{
            letters[s[i]-'a'].push(i);
            }
        }
        return cnt;

