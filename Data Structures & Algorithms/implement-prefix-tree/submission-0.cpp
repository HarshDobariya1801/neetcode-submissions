struct Node{
    Node* links[26];
    bool flag = false;

    bool isContainKeys(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool getEnd(){
        return flag;
    }

};

class PrefixTree {
private:
     Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {

        int n = word.size();
        Node* node = root;

        for(int i = 0; i < n; i++){
            if(!node -> isContainKeys(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
        
    }
    
    bool search(string word) {

        int n = word.size();
        Node* node = root;

        for(int i = 0; i < n; i++){
            if(!node->isContainKeys(word[i])){
                return false;
            }
            node = node -> get(word[i]);
        }

        return node -> getEnd();
        
    }
    
    bool startsWith(string prefix) {

        int n = prefix.size();
        Node* node = root;

        for(int i = 0; i < n; i++){
            if(!node->isContainKeys(prefix[i])){
                return false;
            }
            node = node -> get(prefix[i]);
        }

        return true;
        
    }
};
