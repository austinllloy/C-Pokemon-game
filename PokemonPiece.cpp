
#include "PokemonPiece.h"
#include "LegendaryType.h"
#include "TankType.h"
#include "SpeedsterType.h"
#include "TricksterType.h"

#include <iostream>
#include <string>
#include <fstream>

 
 
PokemonPiece::PokemonPiece(bool teamColor) {
this->teamColor = teamColor;

} 

void PokemonPiece::outputBattlefield(PokemonPiece ***board) {
     
      cout << "   1  2  3  4  5  6  7  8 \n";  // Print column headers
      for (int row = 0; row < 8; ++row) {
          cout << char('A' + row) << " ";  // Print row label (A-H)
          for (int col = 0; col < 8; ++col) {
              if (board[row][col] == nullptr) {
                  cout << " - ";  // Empty space
              } else {
                  // dynamic casting for pokemon type 
                  if (dynamic_cast<LegendaryType*>(board[row][col])) cout << " L ";
                  else if (dynamic_cast<TankType*>(board[row][col])) cout << " T ";
                  else if (dynamic_cast<SpeedsterType*>(board[row][col])) cout << " S ";
                  else if (dynamic_cast<TricksterType*>(board[row][col])) cout << " X ";
              }
          }
          cout << endl;  //print a new line after finishing the row 
      }
 
  
}

void PokemonPiece::clearBattlefield(PokemonPiece ***board) {
   for (int i = 0; i < 8; ++i) {
       for (int j = 0; j < 8; ++j) {
           if (board[i][j] != nullptr) {
               delete board[i][j];  // Deallocate Pokémon piece
               board[i][j] = nullptr;
           }
       }
       delete[] board[i];  // Deallocate row
   }
   delete[] board;  // Deallocate battlefield


}

//virtual bool move(char startRow, int startCovl, char endRow, int endCol, PokemonPiece*** board) = 0;
 
bool  PokemonPiece::getTeamType() const {


return this->teamColor;



}

bool PokemonPiece::gameOver(PokemonPiece ***board) {
    bool redTeamAlive = false, blueTeamAlive = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getTeamType()) {
                    redTeamAlive = true;
                } else {
                    blueTeamAlive = true;
                }
            }
        }
    }
 
    if (!redTeamAlive) {
        this->outputBattlefield(board);
 
        cout << "Blue Wins" << endl;
        cout << endl;

        return true;
    }
    if (!blueTeamAlive) {
       this->outputBattlefield(board);
 
        cout << "Red Wins!" << endl;
        cout << endl;
        
        return true;
    }
    return false;
 }
 

PokemonPiece::~PokemonPiece() {

  // delete PokemonPiece;
cout << endl;


    cout << "Pokemon piece back in the pokeball." << endl;


    } 
    
    

