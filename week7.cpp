Maps

1/int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int lastPrefix = 0;
        int curPrefix = 0;
        mp[0]++; //because when we reach 0 that means that definitely the
        //sum to the el with sum_remainder = 0 is divisible by k
        //so we need to add to ans = 1;

        for(int i = 0;i<nums.size();i++){
              
            curPrefix = (lastPrefix + nums[i]) % k;

            if(curPrefix < 0) curPrefix += k;
            lastPrefix = curPrefix;
            cout<<curPrefix<<' ';
            ans += mp[curPrefix];
            mp[curPrefix]++;
            
      

        }
     
        return ans;

    }
2/   int hash(string s1){
        int p = 5;
        int cnt = 0;

        for(int i = 0;i<s1.size();i++){
          cnt = p*cnt + (s1[i]-'A' + 1);
        }
        return cnt;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vec1;
        if(s.size() <10)return vec1;
    unordered_set<string> vec;
        unordered_map<int, int> mp;
        for(int i = 0;i<=s.size()-10;i++){
            string t = s.substr(i, 10);
            mp[hash(t)]++;
            if(mp[hash(t)] > 1) vec.insert(t);
        }
      
        for(auto it : vec){
            vec1.push_back(it);
        }

        return vec1;
        
    }
2 nachin
 int hash(string s1){
        int p = 5;
        int cnt = 0;

        for(int i = 0;i<s1.size();i++){
          cnt = p*cnt + (s1[i]-'A' + 1);
        }
        return cnt;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vec1;
        if(s.size() <10)return vec1;
    unordered_set<string> vec;
        unordered_map<int, int> mp;
        string t = s.substr(0, 10);
        int x = hash(t);
        int p = 5;
        for(int i = 0;i<=s.size()-10;i++){
            string t = s.substr(i, 10);
            mp[x]++;
            if(mp[x] > 1) vec.insert(t);
            x -= pow(p, 9) * ((s[i]) -'A' + 1);
            x = x*p + s[i+10]-'A' + 1;
        }
      
        for(auto it : vec){
            vec1.push_back(it);
        }

        return vec1;
        
    }

3/ int lengthOfLongestSubstring(string s){
    if(s.size() <= 1) return s.size();
     unordered_map<int, int> lastSeq;
     int longest = 0;
     int windowsStartIdx = 0;

    for(int i = 0;i<s.length();i++){
        if(lastSeq.find(s[i]) != lastSeq.end())
        {
             longest = max(longest, i - windowsStartIdx);
            //  if(longest > i - windowsStartIdx)longest = i-windowsStartIdx;
             windowsStartIdx = max(windowsStartIdx, lastSeq[s[i]] + 1);
             lastSeq[s[i]] = i;
        }
        else{
            lastSeq[s[i]] = i;
        }
         longest = max(longest, i - windowsStartIdx+1);
        // longest = max(longest, i - windowsStartIdx + 1);
       // lastSeq[s[i]] = i;
     }
     return longest;

4/Happy Preffix
part-working solution
 long long hash(string current){
        int p = 27;
        long long h = 0;
        for(int i = 0;i<current.size();i++){
            h = p*h + current[i]-'a' + 1;
        }
        return h;
    }
    string longestPrefix(string s) {
        // int mid = s.size()/2;
        // int i = 0;
        // int j = mid+1;
        unordered_map<long long, long long> mp;
        long long x = hash(s.substr(0, 1));
        mp[x]++;
        for(int i = 1; i<s.size()-1; i++){
        
            //cout<<x<<' ';
            x = x*27 + s[i]-'a' + 1;
            mp[x]++;
            
        }
        //int cnt = s.size()-mid;       
        for(int j = 1;j<s.size();j++){
           // if(cnt <= mid) break;
            if(mp.find(hash(s.substr(j, s.size()-j))) != mp.end()){
                return s.substr(j, s.size()-j);
            }
        }
        return "";
    }
//better chat gpt version
 string longestPrefix(string s) {
        const long long MOD = 1000000007;
        //unoredered_map<long long, long long> mp;
        const int P = 27;
        int best = -1;
        long long PowP = 1;
        long long suffix = 0, prefix = 0;
        for(int i = 0;i<s.size()-1;i++){
            long long left = s[i] - 'a' + 1;
            long long right = s[s.size() - i -1] -'a' + 1;
            
            prefix = (prefix * P + left) % MOD;
            suffix = (right* PowP + suffix) % MOD;
            
            PowP = (PowP*P) % MOD;
            if(suffix == prefix){
                best  = i+1;
            }
        }
        if(best == -1) return "";
        return s.substr(0, best);
    }
5/    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> ms;
        unordered_map<char, int> mt;
        if(s.length() != t.length())return false;

        for(int i = 0;i<s.length();i++){
            char sc = s[i];
            char tc = t[i];
            if(ms.count(sc) && ms[sc] != tc) return false;
            if(mt.count(tc) && mt[tc] != sc) return false;

            ms[sc] = tc;
            mt[tc] = sc;
        }
        return true;
    }
    //     for(int i = 0;i<s.length();i++){
    //         ms[s[i]]++;
    //     }
    //     for(int j=0;j<t.length();j++){
    //         mt[t[j]]++;
    //     }

    //   //  if(ms.count() != mt.count())return false;
    //     for(auto k,l: ms, mt){
    //         if(k.second != l.second) return false;
    //     }
    //     return true;
    // }

6/  bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int len = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(mp.count(nums[i])){
                len = min(len, i-mp[nums[i]]);
                if(len <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }

7/ unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for(auto x: s){
            int len = 1;
            if(!s.count(x-1)){
                while(s.count(x+1)){
                    len++;
                    x++;
                }
                longest = max(longest, len);

            }
        }

        return longest;

8/vector<int> hash(string& s){
        vector<int> vec(26);
       for(int i = 0;i<s.size();i++){
          vec[s[i]-'a']++;
       }
       return vec;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto str:strs){
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>> finali;
        for(auto it:mp){
            finali.push_back(it.second);
        }

        return finali;


    }

9/   long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
       
       
        long long goodPairs = 0;
        for(int i = 0;i<nums.size();i++){
            int key = nums[i] - i;
            goodPairs += mp[key];
            mp[key]++;
        }
        long long n = nums.size();
        return n*(n-1)/2- goodPairs;
    }
10/long long countTriplets(vector<long long>& nums, int N, int M){
unordered_map<int, int> right;
unordered_map<int, int> left;
    long long result = 0;
    for(auto it: nums){
        right[it]++;
    }
    
    for(auto x: nums){
    right[x]--;
        if(x % M == 0){
        long long countA = left[x/M];
        long long countB = right[x*M];
        result += countA * countB;
        }
        left[x]++;
    }
    return result;


}
int main() {
     int N;
    long long M;
    cin>>N>>M;
    vector<long long> vec(N);
    for(int i = 0;i<N;i++){
cin>>vec[i];
    }
    cout<<countTriplets(vec, N, M);

11/ int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for(auto num: nums){
            sum += num;
           if(mp.find(sum-k) != mp.end()){
            count += mp[sum - k];
           }
           mp[sum]++;
        }
        return count;
       // vector<int> prefix(nums.size());
        // int prev = 0;
        // for(int i =0;i<nums.size();i++)
        // {
        // prefix[i] = prev+nums[i];
        // //cout<<prefix[i]<<' ';
        // prev = prefix[i];
        // }
        
        // int count = 0;
       // unordered_map<int, int> mp;

        // for(int i = 0;i<prefix.size();i++){
          
        //     for(int j= i+1;j<prefix.size();j++){
        //         if(i == 0){
        //             if(prefix[j] == k)count++;
        //         }
        //         else{ 
        //         if(prefix[j] - prefix[i-1] == k)count++;
        //     }}
        // }
    //return count;
    
    }

12/class LRUCache {
  
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){
       Node* temp = head->next;
       newNode->next = temp;
       newNode->prev = head;

       head->next = newNode;
       temp->prev = newNode;

    }
    void deleteNode(Node* delNode){
        Node* prevv = delNode->prev;
        Node* nextt = delNode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            int ans = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return ans;

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

13/
class LFUCache {
public:
    struct Node{
        int frequent;
        int key;
        int val;

        Node* prev;
        Node* next;

        Node(int key, int val){
            this->val = val;
            this->key = key;
            frequent = 1;
        }
    };
    struct DLL{
        int size;
        Node* head;
        Node* tail;
        DLL(){
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            tail->prev = head;
            head->next = tail;
            size = 0;
        }
        void deln(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        void ins(Node* node){
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            size++;
        }
    };


    map<int, Node*> cache; //key -> Node
    map<int, DLL*>  freq; //frequency -> DLL list of nodes
    int cap,minfreq, cursize;

    LFUCache(int capacity) {
        cap = capacity;
        cursize = 0;
        minfreq = 0;
     
    }
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            update(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0)return;
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value;
            update(node);
        }
        else{
            if(cursize >= cap){
                Node* node = freq[minfreq]->tail->prev;
                cache.erase(node->key);
                freq[minfreq]->deln(node);
                cursize--;
            }
            Node* newn = new Node(key, value);
            minfreq = 1;
            DLL* list = new DLL();
            if(freq.find(minfreq) != freq.end()) list = freq[minfreq];
            list->ins(newn);
            freq[minfreq] = list;
            cache[key] = newn;
            cursize++;
        }
    }

    void update(Node* node){
        freq[node->frequent]->deln(node);
        if(node->frequent == minfreq && freq[node->frequent]->size == 0)minfreq++;
        DLL* list = new DLL();
        if(freq.find(node->frequent + 1) != freq.end()){
            list = freq[node->frequent + 1];
        }
        node->frequent++;
        list->ins(node);
        freq[node->frequent] = list;
    }
};

14/   int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int count = 0;
        int maxL = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                count-=1;
            }
            else{
                count+= 1;
            }
            if(mp.find(count) != mp.end()){
                maxL = max(maxL, i - mp[count]);

            }
            else{
                mp[count] = i;
            }
        }
        return maxL;
    }

15/int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        vector<int> suffixSum(n);
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
             prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i = n-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + nums[i];
        }

        for(int i = 0;i<n;i++){
            if(suffixSum[i] == prefixSum[i]){
                return i;
            }
        }
        return -1;
    }

16/
bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
         mp[0] = -1;
        int n = nums.size();
        for(int i = 0;i<n;i++){
       
            sum += nums[i];
            int remainder = sum % k;

            if(mp.find(remainder) != mp.end()){
                if(i - mp[remainder] > 1) return true;
            }
            else{
                mp[remainder] = i;
            }
        }
        return false;
    }

17/    vector<int> productExceptSelf(vector<int>& nums) {
//normal solution
   //     int n = nums.size();

        // vector<int> product(n);
        // vector<int> productPrefix(n);
        // vector<int> productSuffix(n);

        // productPrefix[0] = 1;
        // productSuffix[n-1] = 1;

        // for(int i = 1;i<n;i++){
        //     productPrefix[i] = productPrefix[i-1] * nums[i-1];
        // }
        
        // for(int i = n-2;i>=0;i--){
        //     productSuffix[i] = productSuffix[i+1] * nums[i+1];
        // }

        // for(int i = 0;i<n;i++){
        //     product[i]=productPrefix[i] * productSuffix[i];
        // }
//most optimal solution
        int n = nums.size();
        vector<int> product(n, 1);
        int curr = 1;
        for(int i = 0;i<n;i++){
          product[i] *= curr;
          curr *= nums[i];
        }
        curr = 1;
        for(int j = n-1;j>= 0; j--){
            
            product[j]*=curr;
            curr *=nums[j];
        }
        return product;


        // int n = nums.size();
        
        // vector<int> finali(n);
        // productPrefix[0] = nums[0];
        // productSuffix[n-1] = nums[n-1];
        // for(int i = 1;i<n;i++){
        //   productPrefix[i] = productPrefix[i-1]*nums[i];
        // }

        //  for(int i = n-2;i>=0;i--){
        //   productSuffix[i] = productPrefix[i+1]*nums[i];
        // }

        // for(int i = 0;i<n;i++){
        //     if(num)
        //     finali[i] = productPrefix[i] * productSuffix[i]/ (nums[i] * nums[i]);
        // }
        // return finali;
    }
18/ class TrieNode{
        private:
        TrieNode* children[26];
        public:
        bool isEndOfWord = false;
        bool contains(char c){
            return children[c-'a'] != nullptr;
        }
        TrieNode* getKey(char ch) const{
            return children[ch-'a'];
        }
        void setKey(char c, TrieNode* node){
            children[c-'a'] = node;
        }
    };

class Trie {
public:
   

    TrieNode* root;
    TrieNode* searchEndNode(const string& word){
         TrieNode* iter = root;
         for(char s : word){
            if(!iter->contains(s)){
                return nullptr;
            }
            iter = iter->getKey(s);
         }
         return iter;
    }
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* iter = root;
        for(char c: word){
            if(!iter->contains(c)){
                iter->setKey(c, new TrieNode());
               // return;
            }
           
            iter = iter->getKey(c);
        }
        iter->isEndOfWord = true;
    }
    
    bool search(string word) {
        auto node = searchEndNode(word);
        return node && node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
return searchEndNode(prefix);
    }
};

19/struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* iter = root;
       for(char c: word){
        if(iter->children.find(c) == iter->children.end()){
            iter->children[c] = new TrieNode();
        }
        iter = iter->children[c];
       } 
       iter->isEndOfWord = true;
    }

    bool searchUtil(std::string_view word, TrieNode* root){
        TrieNode* iter = root;
        for(size_t i = 0;i<word.length();i++){
            if(word[i] == '.'){
                auto substr = word.substr(i+1);
                for(auto& kv : iter->children){
                    if(searchUtil(substr, kv.second)){
                        return true;
                    }
                }
                return false;
            }
            if(!iter->children.count(word[i])){
                return false;
            }
            iter = iter->children[word[i]];
        }
        return iter->isEndOfWord;

    } 
    bool search(string word) {
        return searchUtil(std::string_view(word), root);
    }
};

20/class TrieNode{
    TrieNode* children[26];
    public:
    bool isEndOfWord = false;
    bool containsKey(char c){
        return children[c -'a'] != nullptr;
    }
    TrieNode* getKey(char c) const{
        return children[c -'a'];
    }
    void setKey(char c, TrieNode* node){
        children[c-'a'] = node;
    }
};
class Trie{
public:
 TrieNode* root;
 Trie() : root(new TrieNode()){};
 void insert(string word){
    TrieNode* iter = root;
    for(char c: word){
        if(!iter->containsKey(c)){
            iter->setKey(c, new TrieNode());
        }
        iter = iter->getKey(c);
    }
    iter->isEndOfWord = true;
 }


};
class Solution {
public:
    void gatherDFS(TrieNode* curr, vector<string>& result, string& word){
        if(!curr){
            result.push_back(word);
            return;
        }
        if(curr->isEndOfWord){
            result.push_back(word);
        }

        if(result.size() == 3){
            return;
        }

        for(auto ch='a'; ch<='z';ch++){
            if(curr->containsKey(ch)){
                word += ch;
                gatherDFS(curr->getKey(ch), result, word);
                word.pop_back();
            }
            if(result.size() == 3){
                return;
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
     vector<vector<string>> result(searchWord.size(), vector<string>());
     Trie trie;
     for(auto p:products){
        trie.insert(p);
     }   
     string prefix = "";
     auto node = trie.root;
     for(size_t i = 0;i<searchWord.size();i++){
        prefix += searchWord[i];
        node = node->getKey(searchWord[i]);
        if(!node){
            break;
        }
        vector<string> resultInner;
        gatherDFS(node,resultInner, prefix);
        result[i] = std::move(resultInner);
     }
     return result;
    }
};
21/    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for(int i = 0;i<text.size();i++){
            mp[text[i]]++;
        }
        int count = 0;

        while(mp['b']>= 1 && mp['a']>=1 && mp['l'] >= 2&& mp['o'] >= 2 && mp['n'] >= 1){
            count++;
            mp['b']--;
            mp['a']--;
            mp['o']-= 2;
            mp['l']-=2;
            mp['n']--;
        }
        return count;
    }
22/int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int count = 0;
        for(int num: nums){
            sum += num;
            if(prefixCount.find(sum-goal)!= prefixCount.end()){
                count+=prefixCount[sum-goal];
            }
            prefixCount[sum]++;
        }
        return count;
    }
23/approach 1
  string longestDupSubstring(string s) {
        unordered_map<string, int> mp;
        for(int start = 0;start<=s.length()-1;start++){
            for(int end = start+1;end<=s.length();end++){
                string sub = s.substr(start, end-start);
                mp[sub]++;
            }
        }
string longest;
int maxi = 0;
for(auto s: mp){
if(s.second>=2){
    int len = s.first.length();
    if (maxi < len){
        maxi = len;
        longest = s.first;
    }
}
}
return longest;
    }

another half-working solution
  long long hash(string substr){
        const long long MOD = 1e9 + 7;
        int n = substr.length();
        long long res = substr[0] - 'a' + 1;
        for(int i = 1;i<n;i++){
           res = (res* 27 + substr[i] - 'a' + 1) % MOD;
        }
        return res;
    }

    string twoDuplicates(string& s, int L){
        unordered_map<long long, int> mp;
        const long long MOD = 1e9 +7;
        long long start = hash(s.substr(0, L));
        mp[start]++;
        long long powL = 1;
        for(int i = 0;i<L-1;i++) powL =(powL* 27) % MOD;
        for(int i = 1;i<=s.length() - L;i++){
            long long curr =( 27 * (start - powL*(s[i-1] - 'a' + 1)) + s[i+L-1] - 'a' + 1) % MOD;
            mp[curr]++;
            start = curr;
            if(mp[curr]>=2)return s.substr(i, L);
        }
        return "";
    }
    string longestDupSubstring(string s) {
      string longest = "";
      int n = s.length();
      int low = 1;
      int high = n-1;

      while(low < high){
        int mid = low + (high - low)/2;
        string res = twoDuplicates(s, mid);
        if(res != ""){
            low = mid+1;
            longest = res;
        }
        else{
            high = mid;
        }
      }

      return longest;
    }
    string longestDupSubstring(string S)
    {
        string_view longest;
        unordered_set<string_view> set;
        size_t beg = 1;
        size_t end = S.size() - 1;
        while(beg <= end){
         auto len = beg + (end - beg)/2;
         bool found = false;
         for(size_t i = 0;i<S.size() - len + 1;i++){
            const auto [it, inserted] = set.emplace(S.data() + i, len);
            if(!inserted){
                found = true;
                longest = *it;
                break;
            }
         }
         if(found){
            beg = len + 1;
         }
         else{
            end = len - 1;
         }
        set.clear();

        }
        return {longest.begin(), longest.end()};

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void add(unordered_map<int, unordered_set<int>>& mp, int el){
      unordered_set<int> m1;
                m1.insert(el);
    if(mp.empty()) {mp.insert({1, m1});
    return;}
    
    for(auto& m: mp){
        int freq = m.first;
        if(m.second.count(el)){
            m.second.erase(el);
            mp[freq+1].insert(el);
            return;
            // if(mp.count(freq+1)){
            //     mp[freq+1].insert(el);
            //     return;
            // }
            // else{
              
            //     mp.insert({freq+1, m1});
            //     return;
            // }
        }
        
    }
    mp[1].insert(el);
}

int maxEl(unordered_map<int, unordered_set<int>>& mp){
    int maxi = 0;
    for(auto& el:mp){
        if(maxi < el.first) maxi = el.first;
    }
    return maxi;
    
}
int maxNum(unordered_set<int>& s){
    int maxi = -1;
    for(auto& el: s){
        if(maxi < el)maxi = el;
    }
    return maxi;
}
int getMostFrequent(unordered_map<int, unordered_set<int>>& mp){
    int maxFreq = maxEl(mp);
    int maxEl = (maxNum(mp[maxFreq]));
    
    mp[maxFreq].erase(maxEl);
    return maxEl;
    
}
void print( unordered_map<int, unordered_set<int>>& mp){
     for(auto& z: mp){
        cout<<z.first<<' ';
        for(auto& s: z.second){
            cout<<s<<' ';
        }
        cout<<'\n';
    }
}
int main()
{
    unordered_map<int, unordered_set<int>> mp;
    add(mp, 1);
    add(mp, 1);
    add(mp, 1);
    add(mp, 2);
    print(mp);
    cout<< getMostFrequent(mp);
    cout<<'\n';
    print(mp);
   
    return 0;
}

  HOMEWORK_SDA
1/    unordered_map<int, int> babi;
    int N;
    cin>>N;
    vector<int> vec(N);
    for(int i = 0;i<N;i++){
cin>>vec[i];
    }
    
    int mini = INT_MAX;
    for(int i = 0;i<N;i++){
        if(babi.find(vec[i]) != babi.end()){
            mini = min(i- babi[vec[i]], mini);
            babi[vec[i]] = i;
        }
        else{
            babi[vec[i]] = i;
        }
        
    }
    if(mini == INT_MAX)cout<<0;
    cout<<mini;

2/// long long countTriplets(vector<long long>& nums, int N, long long M){
//     unordered_map<long long, int> mp;
//     unordered_set<long long> first_els;
//     sort(nums.begin(), nums.end());
//     long long total = 0;
//     for(auto x:nums){mp[x]++;first_els.insert(x);}
//     for(auto a:first_els){
//         long long b = M * a;
//         long long c = M * b;
//         if(mp.count(b) && mp.count(c)){
//             total+=mp[a]*mp[b]*mp[c];
//             //cout<<a<<' '<<b<<' '<<c<<' '<<total<<'\n';
// }
//     }
//     return total;
// }

long long countTriplets(vector<long long>& nums, int N, long long M){
    unordered_map<long long, long long> left;
    unordered_map<long long, long long> right;
    long long total = 0;
    for(auto x:nums)right[x]++;
    
    for(auto b : nums){
        
         right[b]--;
        if(b % M == 0){
            long long countA = left[(b/M)];
            long long countC = right[(b*M)];
            
            total += countA * countC;
            
            
        }
       
        left[b]++;
    }
    return total;
}


int main() {
    int N;
    long long M;
    cin>>N>>M;
    vector<long long> vec(N);
    for(int i = 0;i<N;i++){
cin>>vec[i];
    }
    cout<<countTriplets(vec, N, M);
    
//zad prac test 1
bool lol(vector<int>& nums, int n, int m, int k, int day){
    int groups = 0;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        while(i<n && nums[i]<=day){
            cnt++;
            if(cnt == k){groups++;break;}
            i++;
        }
    }
    return (groups>=m);
}

3/
using namespace std;

int main() {
    //unordered_set<string> names;
    unordered_map<string, int> mp;
    unordered_set<string> prefixes;
    
    int N;
    cin>>N;
    
    for(int i = 0;i<N;i++){
        string t;
        cin >> t;
        if(mp[t] > 0){
           mp[t]++;
            cout<<t<<' '<<mp[t]<<'\n';
            continue;
        }
        string prefix = "";
        string answer = "";
        for(size_t i = 0;i<t.length();i++){
            prefix += t[i];
          if(!prefixes.count(prefix)){
              answer = prefix;
              //prefixes.insert(prefix);
              //cout<<prefix<<'\n';
              break;
          }
        }
        if(answer == "") answer = t;
        cout<<answer<<'\n';
        string helper = "";
        for(size_t i = 0;i<t.length();i++){
            helper += t[i];
            prefixes.insert(helper);
        }
        mp[t] = 1;
        
    }
    // for(int i = 0;i<N;i++){
    //    string t;
    //     cin>>t;
    //     helper.insert({t, 1});
    //     if(mp[t]>0){
    //        mp[t]++;
    //         cout<<t<<' '<<mp[t]<<'\n';
    //     }
    //     string prefix = "";
    //     for(size_t i = 1;i<t.length();i++){
    //         prefix += t[i-1];
    //         for(auto& z :helper){
    //             if(prefix != z.first.substr(0, i)) 
    //             {cout<<prefix<<'\n';break;}
          //  }
            // if(mp[prefix] == 0){
            //     mp.insert({prefix, 1});
            // cout<<prefix<<'\n';
            //     break;
            // }
        //}
        
   // }
    return 0;
}
