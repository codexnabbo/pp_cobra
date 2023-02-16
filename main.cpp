#include <iostream>
#include "utils/headers/champion.h"
#include "utils/headers/functions.h"
#include <cstdlib>

int main ()
{
  system("mount /dev/sda /mnt/floppy/");
  bool loop = true;
  while (loop) { 
    std::system("clear");
    int opt = 0;
    std::cout << "----------------------------------------" << "\n"
            << "            MAIN MENU" << "\n"
            << "----------------------------------------" << "\n"
            << "\n"
            << "1) PLAYER VS BOT\n"
            << "2) PLAYER VS PLAYER\n"
            << "3) EXIT\n" << std::endl;
    std::cout << "INSERT OPTION: ";
    std::cin >> opt;
    switch (opt) {
      case 1:
        CaseOne();
        break;
      case 2:
        CaseTwo();
        break;
      case 3:
        loop = false;
        break;
      default:
          std::cout << "Opzione non valida" << std::endl;
    };
  }
  system("umount /dev/sda");
  return 0;
}
