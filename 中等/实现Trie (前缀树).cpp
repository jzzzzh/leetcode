//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
#include<iostream>
using namespace std;
class Trie {
    Trie *Word[26];
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < 26; i++)
        {
            Word[i] = NULL;
            isEnd = false;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* now = this;
        int c;
        for(char ch : word)
        {
            int i = ch - 'a';
            c = i;
            if(now->Word[i] == NULL)
            {
                now->Word[i] = new Trie();
            }
            now = now->Word[i];
        }
        now->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* now = this;
        int i;
        for(char ch : word)
        {
            i = ch - 'a';
            if(now->Word[i] == NULL)
            {
                return false;
            }
            now = now->Word[i];
        }
        return now->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* now = this;
        int i;
        for(char ch : prefix)
        {
            i = ch - 'a';
            if(now->Word[i] == NULL)
            {
                return false;
            }
            now = now->Word[i];
        }
        return true;
    }
};