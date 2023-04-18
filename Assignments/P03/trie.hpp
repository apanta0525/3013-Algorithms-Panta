/*****************************************************************************
*
*  Author:           Ashish Panta
*  Email:            apanta0525@gamil.com
*  Label:            P03
*  Title:            Processing in Trie Tree Time
*  Course:           CMPS 3013
*  Semester:         Spring 2023
*
*  Description:
*        The class loads all of the values in the Trie Tree. It also allows the user to search for matching
* words in the trie tree.
*
*  Usage:
*      Creates and loads a trie tree with words.
*  Files:
*       N/A
*****************************************************************************/
//trie.hpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * class TrieNode
 * 
 * Description:
 *      Node used to store the words from the json file into
 * 		  the trie tree
 * 
 * Public Methods:
 *            TrieNode   :  constructor  
 * 
 * Private Methods:
 *                N/A
 *       
 * 
 * Usage: 
 *       N/A
 * 
 *      
 */

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;  
    bool isEndOfWord;    

/**
 * Public: TrieNode
 * 
 * Description:
 *          Constructor 
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/

    TrieNode() {
        isEndOfWord = false;
    }
};

/**
 * Class Trie
 *
 * Description:
 *            Implements the trie tree. It has the functionality to insert word in the trie tree.
 * The class also has the functionality to search for matching word in the tree.
 *
 * Private Methods:
 *         void       findWords(TrieNode* node, string prefix, vector<string>& result)
 *         
 * Public Methods:
 *                    Trie()
 *         void       insert(string word)
 *         vector<string> search(string word)
 *
 * Usage:
 *       N/A
 */

class Trie {
private:
/**
     * Private : findWords
     *
     * Description:
     *            finds all the matching word in the trie tree with
     * the prefix and adds them to the vector of string.
     *
     * Params:
     *        TrieNode*    :    node of the trie tree
     *        string       :    prefix to search
     *        vector       :    vector to add the matching word
     *
     * Returns:
     *        N/A
     */
void findWords(TrieNode* node, string prefix, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(prefix);
        }
        for (auto& [c, child] : node->children) {
            findWords(child, prefix + c, result);
        }
    }
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

/**
     * Public : insert
     *
     * Description:
     *            Inserts a word in the trie tree
     *
     * Params:
     *       string   :   word to insert 
     *
     * Returns:
     *      void
     */

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

/**
     * Public : search
     *
     * Description:
     *            Searches for the matching prefix in the trie tree.
     *
     * Params:
     *        string   : prefix to search
     *
     * Returns:
     *        vector   : vector of matching words
     */

vector<string> search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return vector<string>();
            }
            current = current->children[c];
        }
        vector<string> result;
        findWords(current,word, result);
        return result;
    }
};
