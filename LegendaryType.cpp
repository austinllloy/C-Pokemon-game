
#include "LegendaryType.h"
#include "PokemonPiece.h" 
#include <iostream>
#include <string>
#include <fstream>

 
 
LegendaryType::LegendaryType(bool teamColor) : PokemonPiece(teamColor) {
 

} 

bool LegendaryType::move(char startRow, int startCol, char endRow, int endCol, PokemonPiece*** board) {
   // Convert board positions to indices
   int startRowIndex = startRow - 'A';  // Convert 'A'-'H' to 0-7
   int startColIndex = startCol - 1;    // Convert 1-8 to 0-7
   int endRowIndex = endRow - 'A';      // Convert 'A'-'H' to 0-7
   int endColIndex = endCol - 1;        // Convert 1-8 to 0-7

   // Check if the move stays within bounds
   if (endRowIndex < 0 || endRowIndex >= 8 || endColIndex < 0 || endColIndex >= 8) {
       return false;  // Move is out of bounds
   }

   // Calculate differences in rows and columns
   int rowDiff = abs(endRowIndex - startRowIndex);
   int colDiff = abs(endColIndex - startColIndex);

   // Check for diagonal movement (rowDiff == colDiff)
   if (rowDiff == colDiff) {
       // Diagonal movement is valid, check for obstructions along the diagonal
       int rowStep, colStep;

       if (endRowIndex > startRowIndex) {
           rowStep = 1;
       } else {
           rowStep = -1;
       }

       if (endColIndex > startColIndex) {
           colStep = 1;
       } else {
           colStep = -1;
       }

       int row = startRowIndex + rowStep;
       int col = startColIndex + colStep;

       while (row != endRowIndex && col != endColIndex) {
           if (board[row][col] != nullptr) {
               return false;  // Path is blocked
           }
           row += rowStep;
           col += colStep;
       }
   } 
   // Check for horizontal or vertical movement (either rowDiff == 0 or colDiff == 0, but not both)
   else if (rowDiff == 0 || colDiff == 0) {
       // Horizontal or vertical movement is valid, check for obstructions along the path
       int rowStep = 0;
       int colStep = 0;

       if (rowDiff == 0) {
           if (endColIndex > startColIndex) {
               colStep = 1;
           } else {
               colStep = -1;
           }
       } else {
           if (endRowIndex > startRowIndex) {
               rowStep = 1;
           } else {
               rowStep = -1;
           }
       }

       int row = startRowIndex + rowStep;
       int col = startColIndex + colStep;

       while (row != endRowIndex || col != endColIndex) {
           if (board[row][col] != nullptr) {
               return false;  // Path is blocked
           }
           row += rowStep;
           col += colStep;
       }
   } 
   else {
       return false;  // Not a valid move (neither diagonal nor horizontal/vertical)
   }

   // If the destination is occupied by a Pokémon of the same team, return false
   if (board[endRowIndex][endColIndex] != nullptr && board[endRowIndex][endColIndex]->getTeamType() == getTeamType()) {
       return false;  // Can't land on a Pokémon of the same team
   }

   return true;  // Valid move
}



  


  LegendaryType::~LegendaryType() {
cout << endl;

    
    cout << "A Legendary Pokemon has fallen!" << endl;
 
    } 
    
    

