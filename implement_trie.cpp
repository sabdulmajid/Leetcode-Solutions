#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The Trie class provides a rudimentary representation of a trie (prefix tree) data structure, though it's not implemented as a typical trie. Instead of using nodes and edges to represent character sequences, it uses a vector named words to store the entire words. The class has three primary functions:

1. insert: This function adds a word to the words vector.
2. search: This function checks if a given word is present in the words vector using the find function from the standard library. If the word is found, it returns true, otherwise it returns false.
3. startsWith: This function checks if there's any word in the words vector that starts with a given prefix. It does this by iterating over each word and comparing the prefix of the word (obtained using the substr function) with the given prefix. If a match is found, it returns true, otherwise it returns false after checking all words.


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