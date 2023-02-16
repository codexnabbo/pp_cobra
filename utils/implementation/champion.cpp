#include "../headers/champion.h"
#include <bits/chrono.h>
#include <cstdlib>
#include <ostream>
#include <time.h>
#include <fstream>
#include <iterator>
#include <string>
#include <unistd.h>
#include <iostream>
#include <chrono>

std::string champion::FLOPPY_PATH = "/mnt/floppy/champion.txt";
std::string champion::LOCAL_PATH = "/home/riccardop/pp_cobra/utils/champion.txt";

std::ifstream champion::OpenFile(std::string file){
  std::ifstream exprFile(file);
  auto start = std::chrono::high_resolution_clock::now();
  while (exprFile.fail()) {
    usleep(500);
    exprFile.open(file);
    auto end = std::chrono::high_resolution_clock::now();
    if(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() > 10) break;
  }

  return exprFile;

};

champion::champion(int c){ 
  failbit = 1;
  std::ifstream exprFile;
  switch (c) {

    case 1:    
      std::cout << "Caricamento file da floppy..." << std::endl;
      exprFile = OpenFile(FLOPPY_PATH);
      if(exprFile.good()){std::cout << "Caricamento completato!" << std::endl; failbit = 0;}
      else std::cout << "Tempo scaduto, caricamento fallito" << std::endl;
      break;
    case 0:
      std::cout << "Caricamento file da local..." << std::endl;
      exprFile = OpenFile(LOCAL_PATH);
      if(exprFile.good()){std::cout << "Caricamento completato!" << std::endl; failbit =0;}
      else std::cout << "Tempo scaduto, caricamento fallito" << std::endl;
      break;
  }

  exprFile >> name;
  exprFile >> attack;
  exprFile >> defense;
  exprFile >> life;
 
};

void champion::LoseLife(int n){
  life -= n;
};

int champion::GetAttack() const {return attack;};

int champion::GetDefense() const {return defense;};

int champion::GetLife() const {return life;};

std::string champion::GetName() const {return name;};

std::ostream& operator<<(std::ostream& s, const champion& c){
  return  s << c.GetName() << "\n"
    << c.GetAttack() << "\n"
    << c.GetDefense() << "\n"
    << c.GetLife();
}
