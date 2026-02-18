/*
   Name: Austin Loyd, 2002553501, Assignment 2, 0
Description: Prints to log hello code grade.
Input: EXPECTED_PROGRAM_INPUT.
Output: Class output.
*/
#include "TricksterType.h"
#include "PokemonPiece.h" 
#include <iostream>
#include <string>
#include <fstream>

 

 
TricksterType::TricksterType(bool teamColor) : PokemonPiece(teamColor) {
 

} 

 bool TricksterType::move(char startRow, int startCol, char endRow, int endCol, PokemonPiece*** board) {
    int startRowIndex = startRow - 'A';  // Convert 'A'-'H' to 0-7
    int startColIndex = startCol - 1;    // Convert 1-8 to 0-7
    int endRowIndex = endRow - 'A';      // Convert 'A'-'H' to 0-7
    int endColIndex = endCol - 1;        // Convert 1-8 to 0-7

    // Check if the destination is within bounds
    if (endRowIndex < 0 || endRowIndex >= 8 || endColIndex < 0 || endColIndex >= 8) {
        return false;  // Out of bounds
    }

    // Trickster Pokémon can move in an L-shape (like a knight in chess)
    int rowDiff = abs(endRowIndex - startRowIndex);
    int colDiff = abs(endColIndex - startColIndex);

    // Knight-like movement (2 squares in one direction, 1 square in the other direction)
    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
        // Check if the destination is occupied by a piece of the same team
        if (board[endRowIndex][endColIndex] != nullptr && 
            board[endRowIndex][endColIndex]->getTeamType() == getTeamType()) {
            return false;  // Destination occupied by same team
        }
        return true;  // Valid move
    }

    return false;  // Invalid move

  }
  
 

  TricksterType::~TricksterType() {

  // delete TricksterType;
  cout << endl;

    cout << "Trickster Pokemon faints!" << endl;

    
    } 
    
    
