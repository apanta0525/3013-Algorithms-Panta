/*****************************************************************************
*
*  Author:           Ashish Panta
*  Email:            apanta0525@gmail.com
*  Label:            P03
*  Title:            Processing in Trie Tree Time
*  Course:           CMPS 3013
*  Semester:         Spring 2023
*
*  Description:
*        Loads all of the words in the trie tree. It shows how
* long does it to load all the words into the trie tree. It also looks up for
* words in trie tree and shows the time taken to search. Displays the first ten matching words found.
*
*  Usage:
*       Provides autosuggestions to the user when the user looks for words.
*  Files:
*   main.cpp         : driver program
*   tries.hpp        : header file for the trie tree
*   timer.hpp        :  header file to calculate time
*   mygetch.hpp      : header files to capture of keyboard input, without 
*                      hitting the enter key 
*   termcolor.hpp    : header file for the color of the text
*   dict_w_defs.json : input file with words
*   output.md        : file with output
*****************************************************************************/
//main.cpp
#include "json.hpp"
#include "my_getch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include "trie.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace nlohmann;

/**
 * loadWords
 *
 * Description:
 *     The function loads all of the words in "dict_w_defs.json" into a
 *     trie tree.
 * Params:
 *      N/A
 *
 * Returns:
 *     trie  :   the trie tree filled with words
 */

Trie loadWords() {
  Trie getTrie;

  cout << "Words load in Tries started " << endl;
  ifstream inputfile("Algo/AlgoP02/dict_w_defs.json");
  if (!inputfile.is_open()) {
    cout << "Error to open files" << endl;
  }

  json jsonData = json::parse(inputfile);

  for (auto item : jsonData.items()) {
    getTrie.insert(item.key());
  }
  return getTrie;
}


int main() {
  char k;
  string word = "";
  Trie trie;
  Timer timer;

  timer.Start();
  trie = loadWords();
  timer.End();

  float time;
  time = timer.NanoSeconds() / 1e9;

  cout << "Words load completed in  " << time << " seconds" << endl;
  cout << endl;

  vector<string> matches;
  cout << "Type the word you would like to search (letter by letter). Type "
          "capital Z to quit."
       << endl;

  while ((k = getch()) != 'Z') {
    timer.Start();

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

    matches = trie.search(word);
    timer.End();
    cout << endl;

    float time;
    time = timer.NanoSeconds() / 1e9;

    cout << "User input: " << termcolor::red << word << endl;

    cout << matches.size() << " words found in " << time << " seconds" << endl;

    cout << termcolor::green;
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
};
