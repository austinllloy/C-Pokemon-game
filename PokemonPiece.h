#ifndef POKEMONPIECE_H
#define POKEMONPIECE_H
 
#include <string>
using namespace std;

// Character class representing a character in the Star Wars universe
class PokemonPiece {
private:
  bool teamColor;


public:
    // Default constructor
  PokemonPiece(bool);
  virtual bool move(char, int, char, int , PokemonPiece ***) = 0;
  bool getTeamType() const;
  virtual ~PokemonPiece();
void outputBattlefield(PokemonPiece ***board);
void clearBattlefield(PokemonPiece ***board);
bool gameOver(PokemonPiece ***board);



};

#endif