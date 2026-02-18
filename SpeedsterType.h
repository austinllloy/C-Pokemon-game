#ifndef SPEEDSTERTYPE_H
#define SPEEDSTERTYPE_H
#include "PokemonPiece.h" 
#include <string>
using namespace std;

// Character class representing a character in the Star Wars universe
class SpeedsterType : public PokemonPiece  {
 
public:
    // Default constructor
SpeedsterType(bool);


bool move(char, int, char, int, PokemonPiece ***);
virtual ~SpeedsterType();


};

#endif