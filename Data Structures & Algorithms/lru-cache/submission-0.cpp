
class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int key,int val){
                this -> key = key;
                this -> val = val;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
        
    }

    void addNode(Node* node){
        Node* temp = head -> next;

        node -> next = temp;
        node -> prev = head;

        head -> next = node;
        temp -> prev = node;
    }

    void deleteNode(Node* node){
        Node* prevv = node -> prev;
        Node* nextt = node -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {

        if(m.find(key) != m.end()){
            Node* node = m[key];
            int ans = node -> val;
            deleteNode(node);
            addNode(node);
            return ans;
        }

        return -1;
        
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end()){
            Node* curr = m[key];
            curr -> val = value;
            deleteNode(curr);
            addNode(curr);
            return;
        }

        if(cap == m.size()){
            Node* lru = tail -> prev;
            deleteNode(lru);
            m.erase(lru -> key);
            delete lru;
        }

        addNode(new Node(key,value));
        m[key] = head -> next;
        
    }
};
