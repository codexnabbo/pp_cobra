#include <fstream>
#include <ostream>
#include <string>

#ifndef CHAMP
#define CHAMP

class champion {
private:
  std::string name;
  int attack;
  int defense;
  int life;
  std::ifstream OpenFile(std::string);
public:
  bool failbit;
  static std::string FLOPPY_PATH;
  static std::string LOCAL_PATH;
  champion(int);
  void LoseLife(int);
  std::string GetName() const;
  int GetAttack() const;
  int GetDefense() const;
  int GetLife() const;

};

std::ostream& operator<<(std::ostream&, const champion&);

#endif //DEBUG
