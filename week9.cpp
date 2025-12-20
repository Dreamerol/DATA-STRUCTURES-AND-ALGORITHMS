//Practicum
//1
vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
        vector<int> vecfinal;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
    }
    for(auto& el: mp){
        if(el.second == 0) continue;
        q.push({el.second, el.first});
        if(q.size() > k) q.pop();
    }

   while(!q.empty()){

    vecfinal.push_back(q.top().second);
    q.pop();
   }
        return vecfinal;

    }
//2
int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums): k(k) {
        for(int num : nums){
            if(minHeap.size() < k){
                minHeap.push(num);
            }
            else if(num > minHeap.top()){
                minHeap.push(num);
                if(minHeap.size()>k) minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size() < k) minHeap.push(val);
        else if(val > minHeap.top()){
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }

3//half-working way
 vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        unordered_map<string, int> mp;
        for(int i = 0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto& el:mp){
            q.push({el.second, el.first});
            if(q.size() > k) q.pop();
        }
        vector<pair<string, int>> vec;
        while(!q.empty()){
            vec.push_back({q.top().second, q.top().first});
            q.pop();
        }
        sort(vec.begin(), vec.end(), [](const pair<string, int>& A, const pair<string, int> B){
            if(A.second != B.second) return A.second>B.second;
            else return A.first < B.first;
        
        });
        vector<string> v;
        for(auto& el:vec){
            v.push_back(el.first);
        }

        return v;
    }

//2 nachin
struct Compare{
        bool operator()(const pair<int, string>& A, const pair<int, string>& B){
            if(A.first!=B.first) return A.first>B.first;
            else return A.second < B.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>,Compare> q;
        unordered_map<string, int> mp;
        for(int i = 0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto& el:mp){
            q.push({el.second, el.first});
            if(q.size() > k) q.pop();
        }
        vector<string> vec;
        while(!q.empty()){
            vec.push_back(q.top().second);
            q.pop();
        }
      
        reverse(vec.begin(), vec.end());
        return vec;
    }

//4 -IMPORTANT - chairs
int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> arrivals;
        int n = times.size();
        for(int i = 0;i<n;i++){
            arrivals.push_back({times[i][0], i});
            
        }
        sort(arrivals.begin(), arrivals.end());
        priority_queue<int, vector<int>, greater<int>> chairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavetime;
        for(int i = 0;i<n;i++)chairs.push(i);
        for(auto& [arrivetime, friendidx]: arrivals){
            while(!leavetime.empty() && leavetime.top().first <= arrivetime){
                chairs.push(leavetime.top().second);
                leavetime.pop();

            }
            auto curchair = chairs.top();
            leavetime.push({times[friendidx][1],curchair});
            chairs.pop();
            if(friendidx == targetFriend) return curchair;
        }
        return -1;
    }

//5
  string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> q;
        unordered_map<int, int> mp;
        for(auto x: s){
        mp[x]++;
        }
        for(auto x : mp){
            int freq = x.second;
            char el = x.first;
            q.push({freq, el});
        }
        int n = s.length();
        if(2*q.top().first > n+1)return "";
        string ans = "";
        while(q.size() > 1){
            pair<int, char> a = q.top();
            q.pop();
            pair<int, char> b = q.top();
            q.pop();
            ans += a.second;
            ans += b.second;
            a.first--;
            b.first--;
            if(a.first > 0)q.push(a);
            if(b.first > 0)q.push(b);
            
        }

        if(!q.empty()){
            pair<int, char> last = q.top();
            if(last.first > 1) return "";
            ans += last.second;
        }
        return ans;
    }

6//TRAPPING RAIN WATER || - HARDEST TASK EVER
bool isValid(int x, int y, int n, int m){
        return (x>=0 && y >= 0 && y<m && x < n);
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
       int n = heightMap.size();
       int m = heightMap[0].size();

       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
       if(n<3||m<3) return 0;

       int water = 0;
       vector<vector<bool>> grid(n, vector<bool>(m, 0));
       for(int i = 0;i<n;i++){
          q.push({heightMap[i][0], i, 0});
          q.push({heightMap[i][m-1],i, m-1});
          grid[i][0] = true;
          grid[i][m-1] = true;

       }
       for(int j = 1;j<m-1;j++){
          q.push({heightMap[0][j], 0, j});          
          q.push({heightMap[n-1][j],n-1, j});
          grid[0][j] = true;
          grid[n-1][j] = true;  
       }
       while(!q.empty()){
        auto cur = q.top();
        q.pop();
        int x = cur[1];
        int y = cur[2];
        int curH = cur[0];
        grid[x][y] = true;
        
        vector<vector<int>> vec = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
        for(int i = 0;i<4;i++){
            int dx = vec[i][0];
            int dy = vec[i][1];
           if(!isValid(dx, dy, n, m)) continue;
           if(grid[dx][dy]) continue;
           int h = heightMap[dx][dy] ;
           if(h < curH) water += curH-h;
            h =max(curH, h);

           q.push({h, dx, dy});
    
           grid[dx][dy] = true;
        }

       }
       return water;
    }

//zadachi - seminar

1/ int lastStoneWeight(vector<int>& stones) {
        //priority_queue<int, vector<int>, less<int>> q;
        priority_queue<int> q(stones.begin(), stones.end());

        while(q.size() > 1){
            //left is bigger than the left
            int left = q.top();
            //to get the top is logN
            q.pop();
            int right = q.top();
            q.pop();
            if(left != right){
                q.push(left-right);
            }
        }
        if(q.size() == 0) return 0;
        return q.top();

    }

2/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int countMaxRooms(vector<vector<int>>& rooms){
    sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });
    priority_queue<int, vector<int>, greater<int>> q;
    size_t result = 0;
    for(auto el: rooms){
        while(!q.empty() && q.top() <= el[0]){
            q.pop();
        }
        q.push(el[1]);
        result = max(result, q.size());
    }
    return result;
}

int main()
{
    vector<vector<int>> vec = {{1, 2}, {3, 4}, {3, 5}, {3, 8}};
    
    std::cout<<countMaxRooms(vec);

    return 0;
}

3/long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        for(int i = 0;i<k;i++){
            int x = pq.top();
            score += x;
            if(x == 1){
                score += k-1-i;
                break;
            }
            pq.pop();
            pq.push((x+2)/3);
        }
        return score;
    }
4/int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i = 0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();

5/int cookies(int k, vector<int> A) {
priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
int cnt = 0;
while(pq.size() > 1){
    if(pq.top() >= k) return cnt;
 int a = pq.top();
 pq.pop();
 int b = pq.top();
 pq.pop();
 pq.push(a + 2*b);
 cnt++;
    
}
if(pq.top() >= k) return cnt;
return -1;
}

//another way
// while(pq.size() > 1 && pq.top() < k){
// int a = pq.top();
// pq.pop();
// int b = pq.top();
// pq.pop();
// pq.push(a + 2*b);
// cnt++;
    
//}

6/int main() {
        int N;
    cin>>N;
    vector<pair<int, int>> pairs;
    for(int i = 0;i<N;i++){
        int x,y;
        cin>>x>>y;
        if(x == y)continue;
        pairs.push_back({x, y});
    }
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b){
return a.first < b.first;});
    priority_queue<int, vector<int>, greater<int>> q;
    size_t maxi = 0;
    for(int i = 0;i<(int)pairs.size();i++){
        while(!q.empty() && q.top() <= pairs[i].first){
q.pop();}
        q.push(pairs[i].second);
        maxi  = max(maxi, q.size());
    }
    cout<<maxi;

7/BANICAAA - IMPORTART HARD TASK
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Comparator{
bool operator()(const vector<long long>& A, const vector<long long>& B){
// if(A[0] != B[0]){
// return A[0] < B[0];}
   // else 
       if(A[1] != B[1]) return A[1] > B[1];
else return A[2] > B[2];
}
};

int main() {
    int N;
    cin>>N;
    vector<vector<long long>> vec;
    for(int i = 0;i<N;i++){
     long long t, f;
        cin>>t>>f;
        vec.push_back({t, f, i});
        
    }
    sort(vec.begin(), vec.end(), [](const vector<long long>& A, const vector<long long>& B){
        return A[0] < B[0];
    });
    priority_queue<vector<long long>, vector<vector<long long>>, Comparator> q;
    vector<bool> isMade(N);
    long long currentTime = 0;
    int nextjob = 0;
    while(nextjob < N || !q.empty()){
        while(nextjob < N && vec[nextjob][0] <= currentTime){
         q.push(vec[nextjob]);
            nextjob++;
        }
        if(q.empty()){
            if(nextjob>=N)continue;
           currentTime = vec[nextjob][0];
            continue;
        }
        auto el = q.top();
        currentTime = max(currentTime, el[0]) + el[1];
        q.pop();
        cout<<el[2]<<' ';
        
    }
//     for(int i = 0;i<N;i++){
//         int j = 0;
//       while(j <= i && vec[j][0] <= currentTime){
//           if(!isMade[j]) q.push({vec[j][0], vec[j][1], j});
//           j++;
         
//       }
//         if(q.empty()){
//             isMade[i] = true;
//            currentTime = vec[i][0];
//             cout<<vec[i][2]<<' ';
//         }
//         else{
//            currentTime =max(q.top()[0], currentTime)+ q.top()[1];
//             cout<<q.top()[2]<<' ';
//             isMade[q.top()[2]] = true;
//             q.pop();
//         }
         
//     }
       
    return 0;
}

8/
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }    
    }
    //first - max heap
    //second - min heap
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        return (double) (left.top() + right.top()) / 2;
    }
};

9/ ListNode* merge(ListNode* l1, ListNode* l2){
      ListNode* dummy = new ListNode(0);
      ListNode* curr = dummy;
      while(l1 && l2){
        if(l1->val < l2->val){
            curr->next = l1;
            l1 = l1->next;
        }
        else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
      }
        curr->next = l1 ? l1 : l2;
        // while(l1){
        //     curr->next = l1;
        //     l1 = l1->next;
        // }
        // while(l2){
        //     curr->next = l2;
        //     l2 = l2->next;
        // }

        return dummy->next;
      

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* curr = lists[0];
        for(int i = 1;i<lists.size();i++){
           curr = merge(curr, lists[i]);
        }
        return curr;
    }

// ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start int end){
    //     if(start == end) return lists[start];
    //     if(start+1 ==end){
    //         return merge(lists[start], lists[end]);
    //     }
    //     int mid = start+(end-start)/2;
    //     ListNode* left = mergeKListsHelper(lists, start, mid);
    //     ListNode* right = mergeKListsHelper(lists, mid+1, end);
    //     return merge(left, right);
    // }
    // return mergeKListsHelper(lists, 0, lists.size());

10//
struct Comparator{
    bool operator()(const pair<char, int>& A, const pair<char, int>& B){
        return  A.second < B.second;
    }
};
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto task: tasks){
            mp[task]++;
        }
        priority_queue<pair<char, int>, vector<pair<char,int>>, Comparator> pq;
        queue<pair<int, pair<char, int>>> cool;
        for(auto el: mp){
            pq.push({el.first, el.second});
        }
        int time = 0;
        while(!cool.empty() || !pq.empty()){
           if(!cool.empty() && cool.front().first == time){
            pq.push(cool.front().second);
            cool.pop();
           }
           if(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            int newTime = n+time+1;
            int freq = el.second-1;
            if(freq > 0)cool.push({newTime, {el.first, freq}});
           }
time++;
        }
        return time;
    }

//11
   int mostBooked(int n, vector<vector<int>>& meetings) {
     
        sort(meetings.begin(), meetings.end(),[](const vector<int>& a, const vector<int>& b){
               return a[0] < b[0];});
       
            vector<int> counts(n);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTimes;
        for(int i = 0;i<n;i++){
            freeRooms.push(i);
        }
        for(int i = 0;i<meetings.size();i++){
            while(!endTimes.empty() && endTimes.top().first <= meetings[i][0]){
               
                freeRooms.push(endTimes.top().second);
                endTimes.pop();
            }
            if(!freeRooms.empty()){
            counts[freeRooms.top()]++;
            endTimes.push({meetings[i][1], freeRooms.top()});
            freeRooms.pop();}
            else{
               auto el = endTimes.top();
               endTimes.pop();
               long long res = el.first + (meetings[i][1] - meetings[i][0]);
               endTimes.push({res, el.second});
               //freeRooms.push(el.second);
               counts[el.second]++;

            }
        }
        int maxi = *max_element(counts.begin(), counts.end());
        for(int i = 0;i<counts.size();i++){
            if(maxi == counts[i]) return i;
        }
        return -1;

10.1//  ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int,ListNode*>>> q;
        for(int i = 0;i<lists.size();i++){
            ListNode* start = lists[i];
            while(start){
                q.push({start->val, start});
                start = start->next;
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!q.empty()){
            auto el = q.top();
          //  cout<<el.first<<'\n';
            curr->next = el.second;
            curr = curr->next;
            q.pop();
        }
        return dummy->next;;

//zadachi - heap from vector
void siftUp(vector<int>& nodes, int currentIdx){
    int parentIdx = (currentIdx - 1) /2;
    while(currentIdx > 0 && nodes[parentIdx] < nodes[currentIdx]){
        swap(nodes[parentIdx], nodes[currentIdx]);
        currentIdx = parentIdx;
        parentIdx = (currentIdx - 1) /2;
    }
}

void siftDown(vector<int>& nodes, int currentIdx){
    int largestIdx = currentIdx;
    int leftChildIdx = currentIdx*2 + 1;
    int rightChildIdx= currentIdx*2 + 2;
   
    if(leftChildIdx < nodes.size() && nodes[largestIdx]< nodes[leftChildIdx]){
        largestIdx = leftChildIdx;
    }
    if(rightChildIdx < nodes.size()&& nodes[largestIdx] < nodes[rightChildIdx]){
        largestIdx = rightChildIdx;
    }
   
    if(currentIdx != largestIdx){
        swap(nodes[largestIdx], nodes[currentIdx]);
        siftDown(nodes, largestIdx);
    }
}
void makeHeap(vector<int>& nodes){
   
    for(int i = 0;i<nodes.size() - 1 /2 ;i++){
        siftDown(nodes, i);
    }
}

//HOMEWORK
1//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool canPlace(int C, vector<vector<int>>& p){
sort(p.begin(), p.end());
    int cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for(auto& el : p){
        int x = el[0];
        int y = el[1];
        int k = el[2];
        while(!q.empty() && q.top().first <= x){
            int l = q.top().second;
            q.pop();
            cnt -= l;
            
        }
        q.push({y, k});
            cnt += k;
                if(cnt > C) return false;
    }
    return true;

}
int main() {
    int Q;
    cin>>Q;
    for(int i = 0;i<Q;i++){
        int lines, C;
        cin>>lines>>C;
        vector<vector<int>> passengers(lines);
        
        for(int j = 0;j<lines;j++){
           int K,x,y;
            cin>>K>>x>>y;
            passengers[j] = {x,y, K};
            
        }
        if(canPlace(C, passengers)) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
    }
 
}

2//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Compare{
bool operator()(const pair<long long, pair<int, int>>& A, const pair<long long, pair<int, int>>& B){
    if(A.first != B.first) return A.first < B.first;
    else if(A.second.first != B.second.first) return A.second.first<B.second.first;
    else return A.second.second < B.second.second;
}
};
void printFirstK(int X, int Y, int K, vector<pair<int, int>>& crds){
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, Compare> q;
    
    
    for(auto& el:crds){
    int x = el.first;
    int y = el.second;
        long long dx = X- x;
        long long dy = Y-y;
    long long len = dx*dx + dy*dy;
    
          
            q.push({len,{x, y}});
        if((int)q.size()>K)q.pop();
  
    
    }
    
    
    //cout<<crds.size();
    vector<pair<int, int>> vec;
    while(!q.empty()){
     auto el = q.top();
        vec.push_back(el.second);
        q.pop();
    }
    
    reverse(vec.begin(), vec.end());
    for(int i = 0;i<K;i++){
cout<<vec[i].first<<' '<<vec[i].second<<'\n';}



}
int main() {
    int X, Y,N,K;
    cin>>X>>Y>>N>>K;
    vector<pair<int, int>> crds(N);
    for(int i = 0;i<N;i++){
        int x, y;
        cin>>x>>y;
        crds[i] = {x, y};
     
}
    printFirstK(X, Y, K, crds);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

3//
#include <algorithm>
using namespace std;
int chairIdx(vector<pair<int, int>>& guests, int N, int target){
priority_queue<int, vector<int>, greater<int>> chairs;
for(int i = 0;i<N;i++)chairs.push(i);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaveTimes;
    vector<pair<int, int>> arrivals;
    for(int i = 0;i<N;i++){
        arrivals.push_back({guests[i].first, i});
    }
    sort(arrivals.begin(), arrivals.end());
    for(auto& el : arrivals){
       int arrive = el.first;
        int idx = el.second;
        while(!leaveTimes.empty() && leaveTimes.top().first <= arrive){
            auto el = leaveTimes.top();
            chairs.push(el.second);
            leaveTimes.pop();
        }
        auto chair = chairs.top();
        chairs.pop();
        if(idx == target) return chair;
        leaveTimes.push({guests[idx].second,chair});
    }
    return -1;
}

int main() {
    int N;
     cin>>N;
    vector<pair<int, int>> guests(N);
    for(int i = 0;i<N;i++){
        int ar, l;
        cin>>ar>>l;
        guests[i] = {ar, l};}
     int T;
     cin>>T;
    cout<<chairIdx(guests, N, T); 
    return 0;
}
