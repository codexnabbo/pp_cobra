#ifndef FUNCTION
#define FUNCTION
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "../headers/champion.h"
#include "../headers/functions.h"

void wait(int n=0){
  if(n == 1) std::system("echo premi enter per inserire il secondo personaggio");
  std::system("read");
};

void ErrorChamp(){
  
  std::cout << "Errore nel caricamento del campione dal floppy disk" << std::endl;
  std::cout << "Premi INVIO PER TORNARE AL MENU'";
  wait();
}

void AttackTurn(champion& c1, champion& c2,int n){
  int dmg = 0;
  if(n){
    std::cout << c1.GetName() << " >>> ATTACK >>> "<< c2.GetName() << "\n";
    dmg = c1.GetAttack()-c2.GetDefense();
    c2.LoseLife(dmg);
  }
  else {
    std::cout << c1.GetName() << " <<< ATTACK <<< "<< c2.GetName() << "\n";
    dmg = c2.GetAttack()-c1.GetDefense();
    c1.LoseLife(dmg);
  }
};

void CaseOne(){
  champion c1(1);
  if(c1.failbit){ErrorChamp(); return;}
  champion bot(0);
  std::cout << "Creati i campioni" << std::endl;
  wait();
  std::srand((unsigned)time(NULL));
  system("clear");
  std::cout << "Avvio combattimento" << std::endl;
  while(true){
    if(c1.GetLife() <= 0) break;
    if(bot.GetLife() <= 0) break;
    int random = rand();
    if(random%2) AttackTurn(c1, bot, 1);
    else AttackTurn(c1,bot,0);
    sleep(1);
  }
  std::cout << "combattimento finito" << std::endl;
  std::cout << c1.GetName() << "   |   " << bot.GetName() << "\n";
  std::cout << c1.GetAttack() << "   |   " << bot.GetAttack() << "\n";
  std::cout << c1.GetDefense() << "   |   " << bot.GetDefense() << "\n";
  std::cout << c1.GetLife() << "   |   " << bot.GetLife() << "\n";
  wait();
}

void CaseTwo(){
  champion player1(1);
  if(player1.failbit){ErrorChamp(); return;}
  wait(1);
  champion player2(1);
  if(player2.failbit){ErrorChamp(); return;}
  std::cout << "Creati i 2 campioni" << std::endl;
  wait();
  /*
  std::cout << player1 << std::endl;
  std::cout << player2 << std::endl;
  wait();
  */
  std::srand((unsigned)time(NULL));
  system("clear");
  std::cout << "Avvio combattimento" << std::endl;
  while (true) {
    std::cout << player1.GetLife() << " " << player2.GetLife() << "\n";
    if(player1.GetLife() <= 0) break;
    if(player2.GetLife() <= 0) break;
    int random = rand();
    if(random%2) AttackTurn(player1,player2,1);
    else AttackTurn(player1,player2,0);
    sleep(1);
  }
  std::cout << "combattimento finito" << std::endl;
  std::cout << player1.GetName() << "   |   " << player2.GetName() << "\n";
  std::cout << player1.GetAttack() << "   |   " << player2.GetAttack() << "\n";
  std::cout << player1.GetDefense() << "   |   " << player2.GetDefense() << "\n";
  std::cout << player1.GetLife() << "   |   " << player2.GetLife() << "\n";
  wait();
};
#endif // !DEBUG
