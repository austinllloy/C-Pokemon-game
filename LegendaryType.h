#ifndef LEGENDARYTYPE_H
#define LEGENDARYTYPE_H
#include "PokemonPiece.h" 
#include <string>
using namespace std;

// Character class representing a character in the Star Wars universe
class LegendaryType : public PokemonPiece {
 
public:
    // Default constructor
   
LegendaryType(bool);
bool move(char, int, char, int , PokemonPiece ***);
virtual ~LegendaryType();



};

#endif