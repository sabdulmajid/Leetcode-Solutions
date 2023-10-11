#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

*/

class Trie {
public:
    vector<string> words;
    Trie() {}
    void insert(string word) {
        words.push_back(word);
    }
    
    bool search(string word) {
        auto it = find(words.begin(), words.end(), word);
        if (it != words.end()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            if (s.substr(0, prefix.size()) == prefix) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */