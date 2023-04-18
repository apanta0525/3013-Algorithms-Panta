/*****************************************************************************
*  Author:           Ashish Panta
*  Email:            apanta0525@gmail.com
*  Label:            P02
*  Title:            AutoComplete in Linear Time
*  Course:           3013 Algorithm
*  Semester:         Spring 2023
*
*  Description:
*        Loads all of the words in the linked list. It times how 
* long does it to load all the words into the linked list. It also looks up for words in  
* linked list and time how long it takes. Displays the first ten words found. 
*
*  Usage:
*       Provides autosuggestions to the user when the user lookd for words.
*  Files:
*   main.cpp       : driver program
*   LinkedList.hpp : header file for the linked list
*   timer.hpp      :  header file to calculate time
*   mygetch.hpp    : header files to capture of keyboard input, without
*                    hitting the enter key
*   termcolor.hpp  : header file for the color of the text
*   dictionary.txt : input file with words
*   output.txt     : file with output   
*****************************************************************************/
// main.cpp

#include "linkedlist.hpp"
#include "my_getch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * loadWords
 * 
 * Description:
 *     The function loads all of the words in "dictionry.txt" into a linked 
 *     list.
 * Params:
 *      N/A
 * 
 * Returns:
 *     list  :   the linked list filled with words 
*/

LinkedList loadWords(){
  LinkedList list;
  cout << "Words load in LinkedList started " << endl;

  fstream new_file;
  
  new_file.open("dictionary.txt", ios::in);

  
  if (new_file.is_open()) {
    string word;
    
    while (getline(new_file, word)) {
      
      list.Insert(word);
    }
    new_file.close();
  } else {
    cout << "File couldnot be opened"<<endl;
  }

  return list;
}


int main() {
  LinkedList list;
  char k;           
  string word = ""; 
  Timer T; 
  T.Start();
  list=loadWords();
  T.End(); 

  //calculating time in seconds
  float time;
  time = T.NanoSeconds() / 1e9;
  
  cout << "Words load completed in  " << time<< " seconds"
       << endl;
  cout << endl;

  vector<string> matches; 
  cout << "Type the word you would like to search (letter by letter). Type "
          "capital Z to quit."
       << endl;

  
  while ((k = getch()) != 'Z') {
    T.Start(); 

   
    if ((int)k == 127) {
      if (word.size() > 0) {
        word = word.substr(0, word.size() - 1);
      }
    } else {
      
      if (!isalpha(k)) {
        cout << "Letters only!" << endl;
        continue;
      }


      if ((int)k < 97) {
        k += 32;
      }
      word += k; 
    }

    
    matches = list.searchWords(word);

    T.End(); 
    cout << endl;

    float time;
  time = T.NanoSeconds() / 1e9;

    
    cout << "User input: "<<termcolor::red << word << endl;

    
    cout << matches.size() << " words found in " << time
         << " seconds" << endl;


    cout<<termcolor::green;
    int count = 0;
    for (string word : matches) {
      if (count >= 10) {
        break;
      }
      cout << word << " ";
      count++;
    }
    cout << termcolor::reset << endl;
    cout << endl;
  }
}
