//ZADACHI_EXERCISE
//LINKED LIST
1/Print elements
void printLinkedList(SinglyLinkedListNode* head) {
   SinglyLinkedListNode* current = head;
   while(current != nullptr){
    cout<<current->data<<'\n';
    current = current->next;
   }

}
2/insertNodeAtTail
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if(head == nullptr) {
        head = node;
        return head;
    };
    SinglyLinkedListNode* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
        
    }
    current->next = node;
    
    return head;

}

3/insert Node
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    node->next = llist;
    return node;

}
4/
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
SinglyLinkedListNode* current = llist;
SinglyLinkedListNode* previous = nullptr;
if(position == 0){
    if(llist == nullptr){
        llist = node;
        return llist;
    }
    else{
        node->next = llist;
        return node;
    }
}
for(int i = 0;i<position;i++){
    if(current != nullptr){
    previous = current;
    current = current->next;}
    else{
        
    }
    
}
previous->next = node;
node->next = current;

return llist;

}
5/SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(llist == nullptr) return llist;
    if(position == 0){
        llist = llist->next;
        return llist;
    }
    
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    for(int i = 0;i<position;i++){
        if(current != nullptr){
        previous = current;
        current = current->next;
        }
        else{
            break;
        }
    }
    previous->next = current->next;
    delete current;
    
    return llist;
    

}

6/void reversePrint(SinglyLinkedListNode* llist) {
   vector<int> vec;
   SinglyLinkedListNode* current = llist;
   while(current != nullptr){
    vec.push_back(current->data);
    current = current->next;
   }
//    cout<<vec.size()<<'\n';
   for(int i = vec.size()-1;i>=0 ;i--){
    cout<<vec[i]<<'\n';
   }
}

7/REVERSE LINKED LIST
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if(llist == nullptr) return llist;
  SinglyLinkedListNode* current = llist;
  SinglyLinkedListNode* previous = nullptr;
  while(current != nullptr){
    
    SinglyLinkedListNode* helper1 = current->next;
    current->next = previous;
    previous = current;
    current = helper1;    
    
  }
  return previous;
}
8/bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
SinglyLinkedListNode* current1 = head1;
SinglyLinkedListNode* current2 = head2;
while(current1 != nullptr && current2 != nullptr){
    if(current1->data != current2->data) return false;
    current1 = current1->next;
    current2 = current2->next;
}

if(current1 == current2 && current2== nullptr)return true;
return false;
}

9/SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* newHead = nullptr;
    if(head1 == nullptr) return head2;
    if(head2 == nullptr)return head1;
     SinglyLinkedListNode* current1 = head1;
      SinglyLinkedListNode* current2 = head2;
      SinglyLinkedListNode* prev = nullptr;
    if(head1->data < head2->data){
        newHead = new SinglyLinkedListNode(head1->data);
       // newHead->next = current1;
     //   newHead = head1;
        current1 = current1->next;
    }
    else{
        prev = current2;
       // newHead = head2;
        newHead = new SinglyLinkedListNode(head2->data);
        //newHead->next = head2;
        current2 = current2->next;
    }
    
   // SinglyLinkedListNode* prev = newHead;
    
    SinglyLinkedListNode* currentNew=newHead;
    while(current1 != nullptr && current2!=nullptr){
        if(current1->data < current2->data){
            
            SinglyLinkedListNode* node = new SinglyLinkedListNode(current1->data);
            currentNew->next = node;
            currentNew = node;
           // prev->next = current1;
            current1 = current1->next;
        }
        else{
            SinglyLinkedListNode* node = new SinglyLinkedListNode(current2->data);
            currentNew->next = node;
            currentNew = node;
            current2 = current2->next;
        }
        
    
    }
    while(current1 != nullptr){
        SinglyLinkedListNode* node = new SinglyLinkedListNode(current1->data);
        currentNew->next = node;
        currentNew = node;
        current1 = current1->next;
    }
     while(current2 != nullptr){
        SinglyLinkedListNode* node = new SinglyLinkedListNode(current2->data);
        currentNew->next = node;
        currentNew = node;
        current2 = current2->next;
    }
    
    return newHead;
    

}
10/int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* current = llist;
    int cnt = 0;
    while(current != nullptr){
        cnt++;
        current = current->next;
    }
    
    current = llist;
    for(int i = 0;i<cnt - positionFromTail;i++){
        if(current == nullptr) return -1;
      //  if(current->next != nullptr){
        current = current->next;
        //}
    }
    return current->data;
}
11/Delete duplicates 
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist->next == nullptr) return llist;
SinglyLinkedListNode* current = llist->next;
//SinglyLinkedListNode* prev = llist;
SinglyLinkedListNode* newHead = llist;
SinglyLinkedListNode* currentNew = newHead;
while(current != nullptr){
    while(current != nullptr && currentNew->data == current->data){
        current = current->next;
    }
    if(current != nullptr){
        SinglyLinkedListNode* node = new SinglyLinkedListNode(current->data);
    currentNew->next = node;
    currentNew = node;
    current = current->next;}
}
currentNew->next = nullptr;
return newHead;

}
12/
bool has_cycle(SinglyLinkedListNode* head) {
SinglyLinkedListNode* slow = head;
SinglyLinkedListNode* fast = head;
while(fast!= nullptr){
    slow = slow->next;
    if(fast->next == nullptr) return false;
    fast = fast->next->next;
    if(fast == slow) return true;
}
return false;
}

13/int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
SinglyLinkedListNode* cur1 = head1;
SinglyLinkedListNode* cur2 = head2;
while(cur1 != nullptr){
    while(cur2 != nullptr){
        if(cur2 == cur1) return cur1->data;
        cur2 = cur2->next;
    }
    cur2 = head2;
    cur1 = cur1->next;
     
}
14/
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {

DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
DoublyLinkedListNode* current = llist;
if(data <= current->data){
    node->next = llist;
    node->prev = nullptr;
    llist = node;
    return llist;
}
DoublyLinkedListNode* prev1 = llist;
current = llist->next;
//bool flag = false;
while(current != nullptr){
    if(prev1->data <= data && data <= current->data){
       // flag = true;
        prev1->next = node;
        node->prev = prev1;
        node->next = current;
        current->prev = node;
        return llist;
       
    }
    prev1 = current;
    //prev = prev->next;
    current = current->next;
}
if(current == nullptr){
    prev1->next = node;
    node->next = nullptr;
    node->prev = prev1;
}
return llist;

}

15/REVERSE DOUBLE LINKED LIST
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {

DoublyLinkedListNode* current = llist;
DoublyLinkedListNode* newHead = nullptr;

while(current->next != nullptr){
    current = current->next;
    
}

newHead = new DoublyLinkedListNode(current->data);
DoublyLinkedListNode* currentHelper = newHead; 
newHead->prev = nullptr;

DoublyLinkedListNode* prev = nullptr;
current = current->prev;
while(current!= nullptr){
    DoublyLinkedListNode* node=new DoublyLinkedListNode(current->data);
    currentHelper->next = node;
    currentHelper->prev = prev;
    prev = currentHelper;
    currentHelper = node;
    current = current->prev;
    
}
return newHead;


//HOMEWORK
zad
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
if(position == 0){
    node->next = llist;
    return node;
}
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* prev = nullptr;
for(int i = 0;i<position;i++){
    if(current == nullptr) break;
    prev = current;
    current = current->next;
}
    prev->next = node;
    node->next = current;
    return llist;
}

zad3
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(llist == nullptr) return llist;
 if(position == 0){
     SinglyLinkedListNode* temp = llist;
     llist = llist->next;
     delete temp;
     return llist;
}
     SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist;
    for(int i = 0;i<position;i++){
        if(current == nullptr) return llist;
        prev = current;
        current = current->next;
        
    }
   // if(current->next == nullptr)
    prev->next = current->next;
    delete current;
    return llist;
}

zad4
//One test working solution
using namespace std;
struct myNode{
    pair<int,int> el;
    myNode* next;
    
    myNode(int key, int val){
        el = {key, val};
        next = nullptr;
    }
};
struct myLlist{
    myNode* head;
    myNode* tail;
    int cap=0;
    int size=0;
    
    myLlist(int cap){
        this->cap = cap;
        head = nullptr;
        tail = nullptr;
    }
    // void pop_back(){
    //     if(head == nullptr)return;
    //      myNode* cur = head;
    //      myNode* pr = nullptr;
    //     while(cur->next){
    //         pr = cur;
    //         cur = cur->next;
            
    //     }
    //     tail = pr;
    //     delete cur;
    //     size--;
            
    // }
    void pop_back(){
        if(tail==nullptr)return;
        if(tail == head){
            delete head;
            head = tail = nullptr;
        }
        myNode* current = head;
        myNode* previous = nullptr;
        
        while(current != tail){
            previous = current;
            current=current->next;
        }
        tail = previous;
        previous->next = nullptr;
        delete current;
        size--;
        
    }
    void pushFront(myNode* node){
        
        node->next = head;
        head = node;
        size++;
    }
    void putNode(int k, int v){
        myNode* node = new myNode(k, v);
         if(head == nullptr){
            head = node;
            tail = node;
            size++;
            return;
       
        }
        myNode* pr = nullptr;
        myNode* cur = head;
        bool flag = false;
        while(cur){
            
            if(cur->el.first == k){
                cur->el.second = v;
                flag = true;
                if(cur == head){
                    return;
                }
                if(cur == tail){
                    myNode* help = new myNode(tail->el.first, tail->el.second);
                    pushFront(help);
                    pop_back();
                    return;
                }
         
                pr->next = cur->next;
                myNode* help = new myNode(cur->el.first, cur->el.second);
                pushFront(help);
                delete cur;
                break;
                
            }
            pr = cur;
            cur = cur->next;
            
        }
        if(flag)return;
        
        if(size == cap){
        
              pop_back();
             pushFront(node);
            
            return;
            
        }
        
       
        pushFront(node);
        
    }
    void printEl(int key){
        myNode* cur = head;
        int idx = -1;
        while(cur){
            if(cur->el.first == key) {idx = cur->el.second;break;}
            cur = cur->next;
        }
        cout<<idx<<'\n';
        if(idx != -1){
        putNode(key, cur->el.second);
        }
    }
    void print(){
         myNode* cur = head;
    
        while(cur){
            cout<<cur->el.first<<' '<<cur->el.second<<'\n';
            cur = cur->next;
        }
        cout<<'\n';
        
    }
    
};

int main() {
    
    int N;
    int Q;
    int K;
    cin>>N>>Q>>K;
    cin.ignore();
    myLlist llist(N);
    int j = 0;
    for(int i = 0;i<Q;i++){
        
        string str;
        getline(cin, str);
        stringstream ss(str);
        string command;
        ss >> command;
        
       
        if(command == "put"){
        
              int key,value;
        ss>>key>>value;  
        
            llist.putNode(key, value);
           // llist.print();
        }
        else if(command == "get"){
            int getKey;
            ss>>getKey;
          
            llist.printEl(getKey);
    
        }
         if((j+1) % K == 0){
         llist.pop_back();
        }
        j++;
        
    }
     
    return 0;
}

//Final ChatGpt version
using namespace std;
struct Node{
    Node* prev=nullptr;
    Node* next=nullptr;
    int key, value;
    
    Node(int key, int value) : key(key), value(value){};
};
struct HashEntry{
int key;
    Node* node;
    bool used;
    HashEntry() : key(0), node(nullptr), used(false){};
    
};
struct MyHash{
vector<HashEntry> table;
    int M;
    
    MyHash(int size = 200003){
M=size;
        table.resize(M);
    }
    int h(int key){return (key%M+M)%M;}
    Node* get(int key){
        int idx = h(key);
        for(int i = 0;i<M;i++){
         int j = (idx + i) % M;
            if(!table[j].used) return nullptr;
            if(table[j].used && table[j].key == key) return table[j].node;
        }
        return nullptr;
}
    void put(int key, Node* node){
        int idx = h(key);
     for(int i = 0;i<M;i++){
         int j = (idx + i)%M;
         if(!table[j].used || table[j].key == key){
             table[j].key= key;
             table[j].used = true;
             table[j].node = node;
             return;
}
}
    }
    void erase(int key){
int idx = h(key);
    for(int i = 0;i<M;i++){
    int j = (idx + i) % M;
        if(!table[j].used) return;
        if(table[j].used && table[j].key == key){
             table[j].node = nullptr;
            table[j].used = false;
            return;
        
        }
    }
    }
};

class DlList{
int cap, size;
    Node* head;
    Node* tail;
    MyHash table;
    
    void detach(Node* node){

        if(node == nullptr) return;
   
        if(node->prev) node->prev->next = node->next;
        else head = node->next;
        if(node->next) node->next->prev=node->prev;
        else tail = node->prev;
        node->prev = node->next = nullptr;
        //delete node;
            
    
    }
    
    void pushFront(Node* node){
     node->next = head;
        node->prev = nullptr;
        if(head) head->prev= node;
        head = node;
        if(!tail) tail=node;
        
    }
    public:
    DlList(int capacity) :  cap(capacity), size(0), table(200003){
        tail = head = nullptr;
    };
    void get(int key){
     Node* node = table.get(key);
        if(!node){
           cout<<-1<<'\n';
            return;
        }
        cout<<node->value<<'\n';
        detach(node);
        pushFront(node);
        table.put(key,node);
    }
    void put(int key, int value){
     if(cap == 0) return;
        Node* node = table.get(key);
        if(node){
        node->value = value;
            detach(node);
            pushFront(node);
            table.put(key, node);
            return;
        }
        if(size == cap){
            table.erase(tail->key);
            Node* old = tail;
            detach(old);
            
            delete old;
            size--;
        }
        Node* newNode = new Node(key, value);
        table.put(key, newNode);
        pushFront(newNode);
        size++;
        
    }
    void overheat(){
        if(!tail) return;
        Node* old = tail;
        detach(old);
        table.erase(old->key);
        delete old;
        size--;
    }
    bool empty() {
return (size == 0);}

};

int main() {
    int N, Q, K;
    cin>>N>>Q>>K;
    cin.ignore();
    DlList cache(N);
    int opCount = 0;
    for(int i = 0;i<Q;i++){
     string cmd;
        cin>>cmd;
        
        if(cmd == "put"){
int k, v;
        cin>>k>>v;
        cache.put(k, v);}
        else if(cmd =="get"){
int k;
            cin>>k;
            cache.get(k);
        }
        if((opCount+1)% K == 0 && !cache.empty()){
cache.overheat();}
        opCount++;
    }
   
}
//zad5
Half-working solution
struct Node{
    int num;
Node* next;
Node(int x) : num(x), next(nullptr){};
};
struct SlList{
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    void pop_back(){
     if(!tail) return;
        
        if(head == tail){
            size = 0;
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while(cur->next!=nullptr){
        prev = cur;
        cur = cur->next;
        }
        prev->next = nullptr;
        tail=prev;
        delete cur;
        size--;
    }
    void pushBack(int num){
     Node* node = new Node(num);
     if(head == tail && tail == nullptr){
         head = tail = node;
         size++;
         return;
     }
        tail->next = node;
        tail = node;
        size++;
        
    }
    int getSize() const {return size;}
    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur->num<<' ';
            cur = cur->next;
        }
    }
    void reArrange(){
        Node* prev = nullptr;
        Node* cur = head;
        if(size <= 1)return;
        int lim = size/2;
        
        for(int i = 0;i<lim;i++){
            prev = cur;
            cur = cur->next;
        }
       // cout<<size<<' ';
        prev->next = nullptr;
        tail->next = head;
        tail = prev;
        head = cur;
        //tail = prev;
        
        
    }
    
    
};

int main() {
    int N;
    cin>>N;
    SlList llist;
    for(int i = 0;i<N;i++){
        string cmd;
        cin>>cmd;
        if(cmd == "add"){
            int k;
            cin>>k;
            llist.pushBack(k);
            
            
        }
        else if(cmd == "gun"){
            llist.pop_back();
        }
        else if(cmd == "milen"){
            llist.reArrange();
        }
    }
    cout<<llist.size<<'\n';
    llist.print();

//5-Final
struct Node{
    int num;
Node* next;
    Node* prev;
Node(int x) : num(x), next(nullptr), prev(nullptr){};
};
struct DlList{
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;
    void pop_back(){
     if(!tail) return;
        
        if(head == tail){
            size = 0;
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* newNode = tail;
        tail = newNode->prev;
        tail->next = nullptr;
        delete newNode;
        
        size--;
        if(size%2==0)mid = mid->prev;
    }
    void pushBack(int num){
     Node* node = new Node(num);
     if(tail == nullptr){
         head = tail = mid = node;
         size++;
         return;
     }
        tail->next = node;
        node->prev = tail;
        tail = node;
        size++;
        if(size%2 == 1)mid = mid->next;
        
    }
    int getSize() const {return size;}
    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur->num<<' ';
            cur = cur->next;
        }
    }
    void reArrange(){
        // cout<<mid->num<<' ';
        if(size <= 1) return;
        if(size%2==1 && mid->prev != nullptr) mid=mid->prev;
         Node* newHead = mid->next;
         mid->next = nullptr;
         if(newHead){newHead->prev = nullptr;}
         
         head->prev = tail;
         tail->next = head;
         
         head = newHead;
     
         Node* h = tail;
         tail = mid;
         mid = h;
        
    }
    
    
};

int main() {
    int N;
    cin>>N;
    DlList llist;
    for(int i = 0;i<N;i++){
        string cmd;
        cin>>cmd;
        if(cmd == "add"){
            int k;
            cin>>k;
            llist.pushBack(k);
            
            
        }
        else if(cmd == "gun"){
            llist.pop_back();
        }
        else if(cmd == "milen"){
            llist.reArrange();
        }
    }
    cout<<llist.size<<'\n';
    llist.print();
    
}

//zadachi - seminar
1/  bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
         if(head == nullptr) return false;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast=  fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
2/  ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;

        }
        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }
        ListNode* node = head;
        while(node != slow){
            slow = slow->next;
            node = node->next;

        }
         return node;

    }
3/
void SinglyLinkedList::replace(int X)
{
    Node* cur = head;
   // Node* prev = nullptr;
    int i = 0;
    while(cur && i <size){
        Node* help = cur->next;
        if(cur->value == X){
          for(int j = 0;j<X;j++){
              //Node* node = new Node(1);
              add(1, i);
              i++;
          }
            remove(i);
        }
        else{
        i++;}
        cur = help;
        
    }
4/public:
    ListNode* nodePos(int pos, ListNode* head){
        ListNode* cur = head;
        for(int i = 0;i<pos;i++){
            if(cur == nullptr) return nullptr;
            cur=cur->next;
        }
        return cur;
    }
    int size(ListNode* head){
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            curr= curr->next;
        cnt++;
        }
        return cnt;
    }
    bool isPalindrome(ListNode* head) {
      int s = size(head)/2;
      int s1 = size(head);
      ListNode* cur = head;
      for(int i = 0;i<s;i++){
         if(cur->val != nodePos(s1-i-1, head)->val)return false;
         cur = cur->next;
      }
      return true;

    }
//Better solution
  ListNode* reverseList(ListNode* head){
       ListNode* prev = nullptr;
       ListNode* cur = head;
       ListNode* help=nullptr;
     
       while(cur != nullptr){
       help = cur->next;
       cur->next= prev;
       prev = cur;
       cur = help;
      // cur = cur->next;
       }
       return prev;

    }
     ListNode* reverseListCopy(ListNode* head){
       ListNode* newHead = nullptr;
       while(head){
        ListNode* newNode = new ListNode(head->val);
        newNode->next = newHead;
        newHead = newNode;


        head = head->next;
       }
       return newHead;

     }
    bool isPalindrome(ListNode* head){
        ListNode* head1 = reverseListCopy(head);
        ListNode* c1 = head1;
        ListNode* c2 = head;
        while(c1 != nullptr && c2 != nullptr){
            if(c1->val != c2->val) return false;
            c1 = c1->next;
            c2 = c2->next;

        }
        return true;
    }

5/  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        int cnt1 = 0;
     
        while(cur1 != cur2){
            if(cur1 == nullptr){ cur1 = headB;continue;cnt1++;}
            if(cnt1 > 1) return nullptr;
            if(cur2 == nullptr) {cur2 = headA;continue;}
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
6/ void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        node->next = node->next->next;

    }
7/  ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* odd =  head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even != nullptr && even->next !=nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next= even->next->next;
            even = even->next;

          //  cur = 
        }
        odd->next = evenHead;
        return head;
    }
8/Reverse SubLinkedList
ListNode* nodePos(int pos, ListNode* head){
        if(pos<=0)return head;
       if(head == nullptr) return nullptr;
       ListNode* cur = head;
       for(int i = 0;i<pos-1;i++){
        if(cur->next == nullptr)return cur;
        cur = cur->next;
        

       }
       return cur;
    }
    void reverseList(ListNode* left, ListNode* right){
        ListNode* prev = nullptr;
        ListNode* curr = left;
        ListNode* help1 = right->next;
     
        while(curr != right){
            ListNode* help = curr->next;
            curr->next = prev;
            prev = curr;
            curr = help;
            
        }
        curr->next = prev;
        left->next = help1;
    //    ListNode* c=curr;
    //     while(c){
    //         cout<<c->val;
    //         c=c->next;
    //     }
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr) return nullptr;
        if(left - right == 0) return head;
        ListNode* l = nodePos(left, head);
        ListNode* r = nodePos(right, head);
        reverseList(l, r);
        if(left > 1){
        ListNode* l1 = nodePos(left-1, head);
        l1->next = r;
        }
        if(left == 1) head = r;
        return head;
    }

9/class MyLinkedList {
    ListNode* head;
    ListNode* tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(head == nullptr || tail == nullptr) return -1;
        if(index < 0) return -1;
        if(index >=size)return -1;

        ListNode* cur = head;
        for(int i = 0;i<index;i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* l = new ListNode(val);
        if(head == nullptr){
            head = tail = l;
            size++;
            return;
        }
        l->next = head;
        head = l;
        size++;

    }
    
    void addAtTail(int val) {
           ListNode* l = new ListNode(val);
        if(tail == nullptr){
            head = tail = l;
            size++;
            return;
        }
        tail->next = l;
        tail = l;
        size++;

    }
    void addAtIndex(int index, int val) {
        if(index <0 ||index > size)return;

        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        ListNode* prev = head;
        for(int i = 0;i<index-1;i++)prev = prev->next;
      
         
        ListNode* newnode = new ListNode(val);
        newnode->next = prev->next;
        prev->next = newnode;
        
        size++;
    }
 
  void deleteAtIndex(int index) {
       
         if(index <0 || index > size-1)return;
         if(size == 1){
            delete head;
            head = tail = nullptr;

         }
         if(index==0){
            if(head == nullptr) return;
            ListNode* help = head;
            head = head->next;
            delete help;
            size--;
            return;
        }
        ListNode* prev = head;
    
        
        for(int i = 0;i<index-1;i++)prev=prev->next;
        ListNode* cur = prev->next;
        prev->next = cur->next;
        if(cur == tail) tail = prev;
        delete cur;
        size--;
    }

  
    
    };
10/ ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* less = new ListNode(0);
        ListNode* great = new ListNode(0);

        ListNode* l = less;
        ListNode* g = great;

        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                l->next = temp;
                l = l->next;
            }else{
                g->next = temp;
                g = g->next;
            }
            temp = temp->next;
        }
        l->next = great->next;
        g->next = nullptr;
        ListNode* res = less->next;
        delete great;
        delete less;
     return res;


    }
11/ ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        if(head == nullptr) return head;
        while(head!=nullptr && head->val == val) {head = head->next;}
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
          return head;
    }
12/  ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = nullptr;
        ListNode* n2 = nullptr;

        for(auto p = head; p != nullptr;p = p->next){
            n2 = n2 == nullptr ? nullptr : n2->next;
            if (--k == 0){
                n1 = p;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);
    return head;
    }
13/  ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        for(int i = 0;i<n;i++){
            head = head->next;
        }

        while(head != nullptr){
            head = head->next;
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;

        ListNode* result = res->next;
        delete res;
        return result;
    }
14/InsertionSort
int size(ListNode* head){
    int cnt = 0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
}
    void insertionSort(vector<int>& ar){
        int n = ar.size();
        for(int i = 1;i<n;i++){
            int key = ar[i];
            int j = i-1;
            while(j>=0 && key < ar[j]){
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = key;
        }
    }
    ListNode* getNode(int idx, ListNode* head){
        if(idx < 0) return head;
       ListNode* cur = head;
       for(int i = 0;i<idx;i++){
        cur=cur->next;
       }
       return cur;
    }
    void putNode(int val, int idx, ListNode*& head){
        ListNode* newNode = new ListNode(val);
        ListNode* cur = head;
        if(idx == 0){
            newNode->next = head;
            head = newNode;
            return;
        }
        ListNode* prev = nullptr;
        for(int i = 0;i<idx;i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = newNode;
        newNode->next = cur;
    }
    void removeNode(int idx, ListNode*& head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        if(idx == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        for(int i = 0;i<idx;i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;

     int l = size(head);
     ListNode* key = head;
     for(int i = 1;i<l;i++){
        key =getNode(i, head);
        int val = key->val;
        int pos = 0;
        ListNode* cur = head;
        while(pos < i && cur&& cur->val < val)
        {
            cur = cur->next;
            pos++;
        }
       
         removeNode(i, head);
        putNode(val, pos, head);
     } 
     return head;    
    }


