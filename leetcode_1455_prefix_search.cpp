/*

Given a sentence that consists of some words separated by a single space, and a searchWord.

You have to check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).

If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string S is any leading contiguous substring of S.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
Example 4:

Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4
Example 5:

Input: sentence = "hello from the other side", searchWord = "they"
Output: -1
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.

*/

// solution using tree
class Trie {
public:
    Trie *children[26];
    bool isEndofWord;
    int word_number;
    /** Initialize your data structure here. */
    Trie() {
        for (int i=0;i<26;++i) {
            children[i] = nullptr;
        }
        isEndofWord = false;
        word_number = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word,int wn) {
        int size = word.size();
        Trie *root = this;
        for(int i=0;i<size;++i) {
            if(!root->children[word[i]-'a']) {
                root->children[word[i]-'a'] = new Trie();
            }
            if (root->word_number == 0) root->word_number = wn;
            root = root->children[word[i]-'a'];
        }
        if(root->word_number == 0) root->word_number = wn;
        root->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       Trie *root = this;
        int size = word.size();
        for (int i=0;i<size;++i) {
            if (!root->children[word[i]-'a']) return false;
            root = root->children[word[i]-'a'];
        }
        return root->isEndofWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    int startsWith(string prefix) {
        Trie *root = this;
        int size = prefix.size();
        for (int i=0;i<size;++i) {
            if (!root->children[prefix[i]-'a']) return -1;
            root = root->children[prefix[i]-'a'];
            cout<<root->word_number;
        }
        return root->word_number;
    }
};

class Solution {
public:
    
    int isPrefixOfWord(string sentence, string searchWord) {
        Trie *obj = new Trie();
        int wn = 0;
        istringstream ss(sentence); 
        do {
            string word; 
            ss >> word;
            obj->insert(word,++wn);
        } while (ss); 
       return obj->startsWith(searchWord);
        
        
        //solution 1
        /* int size = sentence.size();
        int search_size = searchWord.size();
        if (search_size > size) return -1;
        int i =0;
        int flag = false;
        int spaces =0;
        for (int k = 0;k<size;++k) {
            if (sentence[k] == ' ') {
                ++spaces;
            }
            if (sentence[k] == searchWord[i]) {
                if (i==0  && ((k!=0 && sentence[k-1] == ' ') || k ==0)) {
                    ++i;
                    flag = true;
                } else if (i!=0) {
                    ++i;
                }
            } else if (flag) {
                i = 0;
            }
            if (i == search_size) return spaces+1; 
        }
        return -1;*/
    }
};