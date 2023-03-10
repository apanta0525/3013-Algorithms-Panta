#include "AvlTree.hpp"
#include "Timer.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class avlTree {
public:
  avlTree() {}
  avlTree(string key) {}
};

/**
 * A Bst or Avl tree manager class that will let you create
 * and use multiple binary trees.
 */
class TreeManager {

  map<string, AvlTree *> manager; // stl map of binary trees accessed by the
                                  // key the tree is sorted by
  /**
   * Add a binary tree and sort it based on key passed in.
   */
  void addTree(string key) { manager[key] = new AvlTree(); }

public:
  /**
   * A search method would need the key to access the map of trees
   * in order to search the correct tree, and a key to actually search for.
   */
  string search(string treeKey, string searchKey) {
    manager[treeKey]->search(stoi(searchKey));
  }
};

int main() {
  vector<string, AvlTree *> treeManager; // make a tree manager
  string searchKey = "fname";            // which key to order on
  treeManager.push_back(new avlTree(searchKey));
  // make the tree and push it on the treeManager
  // obviously lots of stuff will be going on in these methds! But this is just
  // an idea of how to organize.
}
