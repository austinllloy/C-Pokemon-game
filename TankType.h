#ifndef TANKTYPE_H
#define TANKTYPE_H
#include "PokemonPiece.h" 
#include <string>
using namespace std;

// Character class representing a character in the Star Wars universe
class TankType  : public PokemonPiece  {
 
public:
    // Default constructor
    TankType(bool);
    bool move(char, int, char, int , PokemonPiece ***);
 virtual    ~TankType();
    
};

#endif