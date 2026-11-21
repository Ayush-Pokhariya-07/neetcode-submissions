class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addAfterFirst(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

    }
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void removeLast(){
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
    }

    int get(int key) {
        int ans = -1;
        if(mp.find(key) == mp.end()){
            return ans;
        }
        Node* node = mp[key];
        ans = node->val;
        removeNode(node);
        addAfterFirst(node);
        
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addAfterFirst(node);
            return;
        }

        if(mp.size() == cap){
            Node* node = tail->prev;
            mp.erase(node->key);
            removeLast();
        }

        Node* newNode = new Node(key, value);
        addAfterFirst(newNode);
        mp[key] = newNode;
        return;
    }
};
