#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <algorithm>



/* function palindromic */
bool isPalindromic( const std::string& word){


  // we invert the word and compare the palindromic
  if (word == std::string(word.rbegin(), word.rend())) {
    return true;
  }

  return false;
}

/* read file or dictionary */
std::vector<std::string> readWords(const std::string &filename){

  
  std::vector<std::string> words;

  std::string line;
  std::ifstream file (filename);

  if (file.is_open())
  {
    while ( getline (file,line) )
    {
      words.push_back(line);
    }

    file.close();
  }

  return words;
}

int main() {
  /*
   *Read in the system dictionary, and print out the number of palindromic words
   */
  const auto words = readWords("/usr/share/dict/words");
  /*
   *Print out the number of palindromic words in this container
   */
  std::cout << std::count_if(words.begin(),
                             words.end(),
                             [](const std::string & word) {
                              return isPalindromic(word);
                              }) << std::endl;

  /*
   *Note: this is a suggested function signature, feel free to implement
   whatever you see fit!
   */
}
