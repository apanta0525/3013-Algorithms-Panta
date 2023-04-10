/*****************************************************************
 *
 *  Author:           Ashish Panta
 *  Email:            apanta0525@gmail.com
 *  Label:            P01
 *  Title:            Database Indexes
 *  Course:           3013 Algorithm
 *  Semester:         Spring 2023
 *
 *  Description:
 *             This program takes all the data from the json file and adds the
 *data to a binary search tree sorted according to eight different fields. The
 *program also allows the user to search for information as they please with
 *different fields.
 *
 *
 *  Usage:
 *       N/A
 *
 *  Files:
 *       main.cpp                   : driver program
 *       json.hpp                   : json library
 *       actual_person_data.json    : file with the 
 * data
 *****************************************************************************/

#include "json.hpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
using json = nlohmann::json;

/**
 * PersonalDetails
 *
 * Description:
 *      This struct provides the structure for PersonalDetails data.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for PersonalDetails data.
 *
 */

struct PersonalDetails {
  int id;
  string first_name;
  string last_name;
  string email;
  string address;
  string city;
  string state;
  double latitude;
  double longitude;
  string car;
  string car_model;
  string car_color;
  string favorite_movie;
  string pet;
  string job_title;
  string phone_number;
  vector<string> stocks;
};

/**
 * BST
 *
 * Description:
 *      This struct provides the structure for Binary Search Tree Algo.
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

/**
 * toLowerCase
 *
 * Description:
 *      The function converts the given string into lower case.
 *
 * Params:
 *      string     :  the string to be converted into lower string
 *
 * Returns:
 *      string     : string in lower case
 */
string toLowerCase(string searchWord) {
  transform(searchWord.begin(), searchWord.end(), searchWord.begin(),
            ::tolower);
  return searchWord;
}

/**
 * ListNode
 *
 * Description:
 *      This struct provides the structure for nodes in the linked list.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for linked list.
 *
 */

struct ListNode {
  PersonalDetails data;
  struct ListNode *next;
};

/**
 * insert_LinkedList
 *
 * Description:
 *      The function adds new node in the linked list.
 *
 * Params:
 *      ListNode     :
 *      Employee     :  object of the struct Employee
 * Returns:
 *      N/A
 */

void insert_LinkedList(ListNode **root, PersonalDetails details) {
  ListNode *new_node = new ListNode();
  new_node->data = details;
  new_node->next = NULL;
  if (*root == NULL) {
    *root = new_node;
  } else {
    ListNode *lastnode = *root;
    while (lastnode->next != NULL) {
      lastnode = lastnode->next;
    }
    lastnode->next = new_node;
  }
}

/**
 * searchList
 *
 * Description:
 *      The function searches for a node in the linked list with string key.
 *
 * Params:
 *      ListNode     :  node to search
 *      string       :  key to search the node with
 * Returns:
 *      ListNode     : node being searched for
 */

ListNode *searchList(ListNode *node, string searchKey) {
  int comp = 0;
  if (node == NULL) {
    return node;
  }
  while (node != NULL) {
    comp++;
     if(toLowerCase(node->data.first_name).find(searchKey) != string::npos ||
        toLowerCase(node->data.last_name).find(searchKey) != string::npos ||
        toLowerCase(node->data.email).find(searchKey) != string::npos ||
        toLowerCase(node->data.address).find(searchKey) != string::npos ||
        toLowerCase(node->data.city).find(searchKey) != string::npos ||
        toLowerCase(node->data.state).find(searchKey) != string::npos ||
        toLowerCase(node->data.car).find(searchKey) != string::npos ||
        toLowerCase(node->data.phone_number).find(searchKey) != string::npos) {
      cout << "Compared " << comp << " Nodes." << endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared " << comp << " Nodes." << endl;
  return node;
}
/**
 * searchList
 *
 * Description:
 *      Overloaded searchList. The function searches for a node in the linked
 * list with integer key.
 *
 * Params:
 *      ListNode     :  node to search
 *      int          :  key to search the node with
 * Returns:
 *      ListNode     : node being searched for
 */

ListNode *searchList(ListNode *node, int search_key) {
  int comp = 0;
  if (node == NULL) {
    return node;
  }
  while (node != NULL) {
    comp++;
    if (node->data.id == search_key) {
      cout << "Compared " << comp << " Nodes." << endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared " << comp << " Nodes." << endl;
  return node;
}

/**
 * searchList
 *
 * Description:
 *      Overloaded searchList. The function searches for a node in the linked
 * list with longitude and latitude.
 * Params:
 *      ListNode     :  node to search
 *      int          :  latitude to search the node with
 *      int          :  lngitude to search the node with
 * Returns:
 *      ListNode     : node being searched for
 */

ListNode *searchList(ListNode *node, double latitude, double longitude) {
  int comp = 0;
  if (node == NULL) {
    return node;
  }
  while (node != NULL) {
    comp++;
    if (node->data.latitude == latitude && node->data.longitude == longitude) {
      cout << "Compared " << comp << " Nodes." << endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared " << comp << " Nodes." << endl;
  return node;
}

int option;       // option choice for user to search data with
string searchKey; // searchkey for the functions


/**
 * choice
 *
 * Description:
 *      The function provides the user with all the fields that they can search
 * the employee data with.
 * Params: N/A
 *
 * Returns:
 *      int     :  integer with the coice information
 */
int getChoice() {
  cout << "Select the field you want to search data on:\n"
       << "0.Id\n"
       << "1.First Name\n"
       << "2.Last Name\n"
       << "3.Address\n"
       << "4.Email\n"
       << "5.City\n"
       << "6.State\n"
       << "7.Car\n"
       << "8.Phone number\n"
       << "9.GPS (Longitude and Latitude)\n"
       << "10.Exit\n";
  cout << "Enter Your Choice:";
  cin >> option;
  cin.ignore();

  return option;
}

int main() {

  BST *bstId = NULL;
  BST *bstFname = NULL;
  BST *bstLname = NULL;
  BST *bstAddress = NULL;
  BST *bstEmail = NULL;
  BST *bstCity = NULL;
  BST *bstState = NULL;
  BST *bstCar = NULL;
  BST *bstPhone_number = NULL;
  BST *bstGps = NULL;
  ListNode *linkedlist = NULL;

  // data from the json file
  ifstream file("random_person_data.json");
  string str;
  vector<PersonalDetails> details; // vector of the PersonalDetails
  json j;
  file >> j;

  for (size_t i = 0; i < j.size(); i++) {
    vector<string> stocks; // Vector for the stocks

    for (const auto &elements : j[i]["stocks"]) {
      stocks.push_back(elements.get<string>());
    }

    PersonalDetails detail = {j[i]["id"],
                         j[i]["first_name"],
                         j[i]["last_name"],
                         j[i]["email"],
                         j[i]["address"],
                         j[i]["city"],
                         j[i]["state"],
                         j[i]["latitude"],
                         j[i]["longitude"],
                         j[i]["car"],
                         j[i]["car_model"],
                         j[i]["car_color"],
                         j[i]["favorite_movie"],
                         j[i]["pet"],
                         j[i]["job_title"],
                         j[i]["phone_number"],
                         stocks};
    details.push_back(detail);
  }
  // shuffling the data
  shuffle(details.begin(), details.end(), random_device());

  // inserting data into BST
  for (auto data : details) {
    insert(bstId, data, data.id);
    insert(bstFname, data, toLowerCase(data.first_name));
    insert(bstLname, data, toLowerCase(data.last_name));
    insert(bstAddress, data, toLowerCase(data.address));
    insert(bstEmail, data, toLowerCase(data.email));
    insert(bstCity, data, toLowerCase(data.city));
    insert(bstState, data, toLowerCase(data.state));
    insert(bstCar, data, toLowerCase(data.car));
    insert(bstPhone_number, data, toLowerCase(data.phone_number));
    insert(bstGps, data, (data.latitude + data.longitude));
    insert_LinkedList(&linkedlist, data);
  }

  int optionNum;
  int idSearchData;
  optionNum = getChoice();

  // timer variables

  auto t_start = std::chrono::high_resolution_clock::now();
  auto t_end = std::chrono::high_resolution_clock::now();
  auto t_end2 = std::chrono::high_resolution_clock::now();
  double time;

  BST *e;
  ListNode *e2;
  double latitude;
  double longitude;

  while (optionNum != 10) {
    if (optionNum == 9) {
      cout << "Enter latitude:";
      cin >> latitude;
      cout << "Enter longitude:";
      cin >> longitude;
      cin.ignore();
    } else {
      cout << "Enter string to be search Data:";
      getline(cin, searchKey);
    }
    if (optionNum == 0) {
      idSearchData = stoi(searchKey);
    }
    searchKey = (searchKey);
    t_start = std::chrono::high_resolution_clock::now();
    if (optionNum == 0) {
      e = search(bstId, idSearchData);
    } else if (optionNum == 1) {
      e = search(bstFname, searchKey);
    } else if (optionNum == 2) {
      e = search(bstLname, searchKey);
    } else if (optionNum == 3) {
      e = search(bstAddress, searchKey);
    } else if (optionNum == 4) {
      e = search(bstEmail, searchKey);
    } else if (optionNum == 5) {
      e = search(bstCity, searchKey);
    } else if (optionNum == 6) {
      e = search(bstState, searchKey);
    } else if (optionNum == 7) {
      e = search(bstCar, searchKey);
    } else if (optionNum == 8) {
      e = search(bstPhone_number, searchKey);
    } else if (optionNum == 9) {
      e = search(bstGps, latitude, longitude);
    }
    t_end = std::chrono::high_resolution_clock::now();
    if (optionNum != 9) {
      e2 = searchList(linkedlist, searchKey);
    } else if (optionNum == 0) {
      e2 = searchList(linkedlist, stoi(searchKey));
    } else {
      e2 = searchList(linkedlist, latitude, longitude);
    }
    t_end2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::micro>(t_end - t_start).count();
    cout << "Completed search in BST in " << time << " micro sec" << endl;
    time = std::chrono::duration<double, std::micro>(t_end2 - t_end).count();
    cout << "Completed search in Linked List in " << time << " micro sec"
         << endl;

    if (e != NULL) {
      cout << "Found String " + searchKey + " in " << e->personalDetails.first_name
           << endl;
      string stocks;
      for (vector<string>::const_iterator i = e->personalDetails.stocks.begin();
           i != e->personalDetails.stocks.end(); ++i)
        stocks += *i + ", ";
      // Printing the information the user is looking for
      cout << "Details:" << endl;
      cout << "id : " << e->personalDetails.id
           << "\nfirst_name : " << e->personalDetails.first_name
           << "\nlast_name : " << e->personalDetails.last_name
           << "\nemail: " << e->personalDetails.email
           << "\naddress: " << e->personalDetails.address
           << "\ncity: " << e->personalDetails.city << "\nstate: " << e->personalDetails.state
           << "\nlatitude: " << e->personalDetails.latitude
           << "\nlongitude: " << e->personalDetails.longitude
           << "\ncar: " << e->personalDetails.car
           << "\ncar_model: " << e->personalDetails.car_model
           << "\ncar_color: " << e->personalDetails.car_color
           << "\nfavorite_movie: " << e->personalDetails.favorite_movie
           << "\npet: " << e->personalDetails.pet
           << "\njob_title: " << e->personalDetails.job_title
           << "\nphone_number: " << e->personalDetails.phone_number
           << "\nstocks: " << stocks << endl;
    } else {
      cout << "Not Found" << endl; // if the information doesn't exist.
    }
    cout << endl;
    optionNum = getChoice();
  }
  return 0;
}
