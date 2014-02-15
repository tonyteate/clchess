/*
  Assumes board is no larger than 9x9 (sorry)
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int boardsize = 9;
string board[9][9];

void clearBoard();
void printBoard();
void initBoard();
string int2str(int i);
void move(string pos1, string pos2);

string char_map = "/abcdefgh";
string plyr_map = "PRNBKQBNR";

int main(){

  initBoard();
  printBoard();
  
  string input;

  while (input.compare("quit") != 0){

    cout << "Enter a move: ";  
    getline(cin, input);

    if (input.compare("quit") == 0)
      return 0;

    // remove whitespace
    input.erase( remove( input.begin(), input.end(), ' '), input.end() );

    // move chess piece or start over
    if (input.length()==4)
      move(input.substr(0, 2), input.substr(2, 2));
    else
      cout << "That is not a valid move" << endl;

    printBoard();

  }
  return 0;


}

void move(string pos1, string pos2){
  int c1 = char_map.find(pos1[0]);
  int r1 = atoi(pos1.substr(1,1).c_str());
  int c2 = char_map.find(pos2[0]);
  int r2 = atoi(pos2.substr(1,1).c_str());

  if (c1 != string::npos && c2 != string::npos 
      && r1 < boardsize && r2 < boardsize
      && r1 != 0 && r2 != 0){

    string piece = board[r1][c1];
    if (piece.compare("-") != 0){
      board[r1][c1] = "-";
      board[r2][c2] = piece;
    }

  }else{
    cout << "That is not a valid move" << endl;
  }

}

void clearBoard(){
  for (int i=0; i<boardsize; i++){
    for (int j=0; j<boardsize; j++){
      if (i == 0)
	board[0][j] = char_map[j];
      else
	board[i][j] = "-";
    }
    if (i != 0)
      board[i][0] = int2str(i);
  }
}

void initBoard(){
  clearBoard();
  for (int c=1; c<boardsize; c++){
    board[1][c] = plyr_map[c];
    board[2][c] = "P";
    board[8][c] = plyr_map[c];
    board[7][c] = "P";
  }
}

void printBoard()
{
  cout << "--------------" << endl;
  for (int i=0; i<boardsize; i++){
    for (int j=0; j<boardsize; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << "--------------" << endl;
}


string int2str(int i){
  std::stringstream out;
  out << i;
  return out.str();
}
