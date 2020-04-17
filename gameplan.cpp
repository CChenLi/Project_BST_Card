#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  Player p1("Alice");
  Player p2("Bob");

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    card c(line[0], line[2]);
    p1.insert(c);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    card c(line[0], line[2]);
    p2.insert(c);
  }
  cardFile2.close();

  // Start the game

  bool now = 1;
  cout << p1;
  cout << p2;
  while(now){
    now = p1.Myturn(p2);
    now = p2.Myturn(p1);
  }

  cout << p1;
  cout << p2;

  return 0;
}
