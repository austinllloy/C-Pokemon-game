/*
   Name: Austin Loyd, 2002553501, Assignment 2, 0
Description: Prints to log hello code grade.
Input: EXPECTED_PROGRAM_INPUT.
Output: Class output.
*/
#include "SpeedsterType.h"
#include "PokemonPiece.h" 
#include <iostream>
#include <string>
#include <fstream>

 

 
SpeedsterType::SpeedsterType(bool teamColor) : PokemonPiece(teamColor) {
 

} 

bool SpeedsterType::move(char startRow, int startCol, char endRow, int endCol, PokemonPiece*** board) {
    // Convert board positions
    int startRowIndex = startRow - 'A';  // Convert 'A'-'H' to 0-7
    int startColIndex = startCol - 1;    // Convert 1-8 to 0-7
    int endRowIndex = endRow - 'A';      // Convert 'A'-'H' to 0-7
    int endColIndex = endCol - 1;        // Convert 1-8 to 0-7

    // Check if the move stays inside bounds
    if (endRowIndex < 0 || endRowIndex >= 8 || endColIndex < 0 || endColIndex >= 8) {
        return false;  // Move is out of bounds
    }

    int rowDiff = abs(endRowIndex - startRowIndex);
    int colDiff = abs(endColIndex - startColIndex);

    // Ensure the move is strictly diagonal (equal row and column change)
    if (rowDiff != colDiff) {
        return false;  // Not a diagonal move
    }

    // Determine movement direction for both row and column
    int rowStep, colStep;

    // Set rowStep based on the direction of movement (up or down)
    if (endRowIndex > startRowIndex) {
        rowStep = 1;
    } else {
        rowStep = -1;
    }

    // Set colStep based on the direction of movement (right or left)
    if (endColIndex > startColIndex) {
        colStep = 1;
    } else {
        colStep = -1;
    }

    // Check for obstructions in the diagonal path
    int row = startRowIndex + rowStep;
    int col = startColIndex + colStep;
    while (row != endRowIndex && col != endColIndex) {
        if (board[row][col] != nullptr) {
            return false;  // Path is blocked
        }
        row += rowStep;
        col += colStep;
    }

    return true;  // Valid diagonal move
}

  
 

  SpeedsterType::~SpeedsterType() {

   //delete SpeedsterType;
   cout << endl;

    
    cout << "Speedster down!" << endl;

    
    } 
    
    
