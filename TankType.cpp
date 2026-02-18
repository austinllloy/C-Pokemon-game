/*
   Name: Austin Loyd, 2002553501, Assignment 2, 0
Description: Prints to log hello code grade.
Input: EXPECTED_PROGRAM_INPUT.
Output: Class output.
*/
#include "TankType.h"
#include "PokemonPiece.h" 
#include <iostream>
#include <string>
#include <fstream>

 

 
TankType::TankType(bool teamColor) : PokemonPiece(teamColor) {
 

} 

bool TankType::move(char startRow, int startCol, char endRow, int endCol, PokemonPiece*** board) {

    // Convert start and end positions to board indices
    int startRowIndex = startRow - 'A';  // Convert 'A'-'H' to 0-7
    int startColIndex = startCol - 1;    // Convert 1-8 to 0-7
    int endRowIndex = endRow - 'A';      // Convert 'A'-'H' to 0-7
    int endColIndex = endCol - 1;        // Convert 1-8 to 0-7

    // Check if the destination is within bounds
    if (endRowIndex < 0 || endRowIndex >= 8 || endColIndex < 0 || endColIndex >= 8) {
        return false;  // Out of bounds
    }

    // Tank Pokémon can move in a straight line, horizontally or vertically
    // Check if movement is either horizontal or vertical and if it's along a continuous path
    if (startRowIndex == endRowIndex) {  // Horizontal movement
        int colDiff = abs(endColIndex - startColIndex);
        for (int col = min(startColIndex, endColIndex) + 1; col <max(startColIndex, endColIndex); col++) {
            if (board[startRowIndex][col] != nullptr) {  // Path is blocked
                return false;
            }
        }
        return true;  // Valid horizontal move

    } else if (startColIndex == endColIndex) {  // Vertical movement
        int rowDiff = abs(endRowIndex - startRowIndex);
        for (int row = min(startRowIndex, endRowIndex) + 1; row < max(startRowIndex, endRowIndex); row++) {
            if (board[row][startColIndex] != nullptr) {  // Path is blocked
                return false;
            }
        }
        return true;  // Valid vertical move
    }

    return false;  // Invalid move (neither vertical nor horizontal)
}

  
 

  TankType::~TankType() {

 //  delete TankType;
cout << endl;

    cout << "Tank Pokemon knocked out!" << endl;

    
    } 
    
    
