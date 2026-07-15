class Trie {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* children[26];
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        for(int i = 0 ; i < 26 ; i++){
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    TrieNode* root;

    Trie(){
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            if(crawl->children[ch - 'a'] == NULL)
                crawl->children[ch - 'a'] = getNode();
            crawl = crawl->children[ch - 'a'];
        }
        crawl->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            if(crawl->children[ch - 'a'] == NULL)
                return false;
            crawl = crawl->children[ch - 'a'];
        }
        return crawl->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawl = root;
        for(char ch : prefix){
            if(crawl->children[ch - 'a'] == NULL)
                return false;
            crawl = crawl->children[ch - 'a'];
        }
        return true;
    }
};