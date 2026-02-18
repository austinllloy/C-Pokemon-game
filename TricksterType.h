#ifndef TRICKSTERTYPE_H
#define TRICKSTERTYPE_H

#include <string>
#include "PokemonPiece.h" 

using namespace std;

// Character class representing a character in the Star Wars universe
class TricksterType  : public PokemonPiece  {
  

public:
    // Default constructor
   
TricksterType(bool);
 bool move(char, int, char, int , PokemonPiece ***);
virtual ~TricksterType();



};

#endif