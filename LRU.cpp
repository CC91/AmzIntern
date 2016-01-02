// 146. LRU Cache
class LRUCache{
    struct Node {
        int val;
        int key; 
        Node *next;
        Node *prev;
        Node(int k, int v):key(k), val(v) {}
    };
    
    int maxSize;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> key2node;
    
    void insert2end(int key, int value) {
        if (isFull() || key2node.count(key)!=0) return;
        Node* n = new Node(key, value);
        key2node[key] = n;
        if (!head) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = tail->next;
        }
    }
    
    void removeHead() {
        if (!head) return;
        key2node.erase(head->key);
        Node* tmp = head;
        if (head==tail) head=tail=NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete tmp;
    }
    
    void move2end(int key) {
        if (key2node.count(key)==0 || key2node[key]==tail) return;
        Node *n = key2node[key];
        if (n==head) {
            head = head->next;
            head->prev = NULL;
        }
        else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        tail->next = n;
        n->prev = tail;
        n->next = NULL;
        tail = tail->next;
    }
    
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        head = NULL;
        tail = NULL;
        key2node.clear();
    }
    
    int get(int key) {
        if (key2node.count(key)==0) return -1;
        move2end(key);
        return key2node[key]->val;
    }
    
    void set(int key, int value) {
        if (get(key)!=-1) {
            key2node[key]->val = value;
            return;
        }
        
        if (isFull()) removeHead();
        insert2end(key, value);
    }
    
    bool isFull() {
        return key2node.size()>=maxSize;
    }
};