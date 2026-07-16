class WordDictionary {
    struct trieNode{
        bool isEnd;
        trieNode* children[26];
    };

public:
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for(int i = 0 ; i < 26 ; i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    trieNode* root;

    WordDictionary() {
        root = getNode();
    }

    void addWord(string word) {
        trieNode* crawl = root;
        for(char ch : word){
            if(crawl->children[ch - 'a'] == NULL)
                crawl->children[ch - 'a'] = getNode();
            crawl = crawl->children[ch - 'a'];
        }
        crawl->isEnd = true;
    }

    bool searchHelper(string &word, int idx, trieNode* node) {
        if(node == NULL)
            return false;

        if(idx == word.size())
            return node->isEnd;

        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(searchHelper(word, idx + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        return searchHelper(word, idx + 1, node->children[word[idx] - 'a']);
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};