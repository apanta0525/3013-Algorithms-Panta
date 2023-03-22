/*****************************************************************
 *
 *  Author:           Aashish Panta
 *  Email:            liverpool.ashish.ap@gmail.com
 *  Label:            P01
 *  Title:            Database Indexes
 *  Course:           CMPS 3013
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
 *       main.cpp                   : main driver program
 *       json.hpp                   : json parser library
 *       random_person_data.json    : json file with the data
 *****************************************************************************/
#include "PersonalDetails.cpp"
#include "ListNode.cpp"
#include "BST.cpp"
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
 * lower
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
string lower(string searchWord) {
  transform(searchWord.begin(), searchWord.end(), searchWord.begin(),
            ::tolower);
  return searchWord;
}

/**
 * PersonalDetails
 *
 * Description:
 *      This struct provides the structure for personalDetails data.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for personalDetails data.
 *
 */

int option;       // option choice for user to search data with
string searchKey; // searchkey for the functions

/**
 * choice
 *
 * Description:
 *      The function provides the user with all the fields that they can search
 * the personalDetails data with.
 * Params: N/A
 *
 * Returns:
 *      int     :  integer with the coice information
 */
int choice() {
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

  // fetch person data from the json file
  ifstream file("random_person_data.json");
  string str;
  vector<PersonalDetails> PersonalDetails; // vector of the PersonalDetails
  json j;
  file >> j;

  for (size_t i = 0; i < j.size(); i++) {
    vector<string> stocks; // Vector for the stocks

    for (const auto &elements : j[i]["stocks"]) {
      stocks.push_back(elements.get<string>());
    }

    PersonalDetails personalDetails = {j[i]["id"],
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
    PersonalDetails.push_back(personalDetails);
  }
  // shuffling the data
  shuffle(PersonalDetails.begin(), PersonalDetails.end(), random_device());

  // inserting data into BST
  for (auto personalDetails : PersonalDetails) {
    insert(bstId, personalDetails, personalDetails.id);
    insert(bstFname, personalDetails, lower(personalDetails.first_name));
    insert(bstLname, personalDetails, lower(personalDetails.last_name));
    insert(bstAddress, personalDetails, lower(personalDetails.address));
    insert(bstEmail, personalDetails, lower(personalDetails.email));
    insert(bstCity, personalDetails, lower(personalDetails.city));
    insert(bstState, personalDetails, lower(personalDetails.state));
    insert(bstCar, personalDetails, lower(personalDetails.car));
    insert(bstPhone_number, personalDetails, lower(personalDetails.phone_number));
    insert(bstGps, personalDetails, (personalDetails.latitude + personalDetails.longitude));
    insert_LinkedList(&linkedlist, personalDetails);
  }

  int optionNum;
  int idSearchData;
  optionNum = choice();

  // Timer Variables for displaying time spent

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
    searchKey = lower(searchKey);
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
      
      // Displaying the personal information of the user in
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
    optionNum = choice();
  }
  return 0;
}
