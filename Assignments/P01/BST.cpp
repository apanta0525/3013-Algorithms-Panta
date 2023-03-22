#include "PersonalDetails.cpp"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/**
 * BST
 *
 * Description:
 *      This struct provides the structure for binary search tree.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for binary search tree.
 *
 */

struct BST {
  string key;
  PersonalDetails personalDetails;
  BST *left;
  BST *right;
};

/**
 * insert
 *
 * Description:
 *      The function adds new node in the binary search tree.
 *
 * Params:
 *      BST                 :  root of the binary search tree.
 *      PersonalDetails     :  data of the personalDetails to add in the node.
 *      string              :  key to insert the data with
 * Returns:
 *      N/A
 */

void insert(BST *&root, PersonalDetails data, string key) {
  if (root == NULL) {
    root = new BST;
    root->key = key;
    root->personalDetails = data;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (key < root->key) {
      insert(root->left, data, key);
    } else {
      insert(root->right, data, key);
    }
  }
}

/**
 * insert
 *
 * Description:
 *      Overloaded insert. The function adds new node in the binary search tree
 * with integer key.
 *
 * Params:
 *      BST                  :  root of the binary search tree.
 *      PersonalDetails      :  data of the personalDetails to add in the node.
 *      int                  :  integer key to insert the data with
 * Returns:
 *      N/A
 */

void insert(BST *&root, PersonalDetails data, int key) {
  if (root == NULL) {
    root = new BST;
    root->key = to_string(key);
    root->personalDetails = data;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (key < stoi(root->key)) {
      insert(root->left, data, key);
    } else {
      insert(root->right, data, key);
    }
  }
}

/**
 * insert
 *
 * Description:
 *      Overloaded insert. The function adds new node in the binary search tree
 * with the combination of longitude and latitude as the key.
 *
 * Params:
 *      BST          :  root of the binary search tree.
 *      PersonalDetails     :  data of the personalDetails to add in the node.
 *      double       :  combination of longitude and latitude as a key to insert
 * the data with
 * Returns:
 *   N/A
 */

void insert(BST *&root, PersonalDetails data, double key) {
  if (root == NULL) {
    root = new BST;
    root->key = to_string(key);
    root->personalDetails = data;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (data.latitude + data.longitude < stod(root->key)) {
      insert(root->left, data, key);
    } else {
      insert(root->right, data, key);
    }
  }
}

/**
 * *search
 *
 * Description:
 *       The function searches for a node in the binary
 * search tree with integer key.
 *
 * Params:
 *      BST          :  root of the BST
 *      int          :  key to search the node with
 * Returns:
 *      BST          : node with the key
 */

BST *search(BST *root, int searchKey) {
  static int count = 0;
  count++;
  if (!root) {
    cout << endl;
    cout << "Node count:" << count << endl;
  } else if (root->personalDetails.id == searchKey) {
    cout << endl;
    cout << "Node count:" << count << endl;
    return root;
  } else if (searchKey < root->personalDetails.id) {
    return search(root->left, searchKey);
  } else {
    return search(root->right, searchKey);
  }
}

/**
 * *search
 *
 * Description:
 *       Overloaded *search function. The function searches for a node in the
 * binary search tree with integer key.
 *
 * Params:
 *      BST          :  root of the BST
 *      string       :  string key to search the node with
 * Returns:
 *      BST          : node with the key
 */

BST *search(BST *root, string searchKey) {
  static int count = 0;
  count++;
  if (root == NULL || root->key.find(searchKey) != string::npos) {
    cout << endl;
    cout << "Node count:" << count << endl;
    return root;

  } else if (searchKey < root->key) {
    return search(root->left, searchKey);
  } else {
    return search(root->right, searchKey);
  }
}

/**
 * *search
 *
 * Description:
 *       Overloaded *search function. The function searches for a node in the
 * binary search tree with longitude and latitude as key.
 *
 * Params:
 *      BST          :  root of the BST
 *      double       :  latitude
 *      double       :  longitude
 * Returns:
 *      BST          : node with the key combination of longitude and latitude
 */

BST *search(BST *root, double latitude, double longitude) {
  static int count = 0;
  count++;
  if (root == NULL || root->personalDetails.latitude + root->personalDetails.longitude ==
                          (latitude + longitude)) {
    cout << endl;
    cout << "Node count:" << count << endl;
    return root;

  } else if ((latitude + longitude) <
             (root->personalDetails.latitude + root->personalDetails.longitude)) {
    return search(root->left, latitude, longitude);
  } else {
    return search(root->right, latitude, longitude);
  }
}
