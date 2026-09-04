#include "ascii/UI.h"
#include "ascii/Colors.h"

#include <iostream>
#include <unistd.h>

namespace UI {

void clearScreen() { std::cout << "\033[2J\033[1;1H"; }

void printLine(char character, int length) {

  std::cout << Color::Gray;

  for (int i = 0; i < length; i++) {
    std::cout << character;
  }

  std::cout << Color::Reset << '\n';
}

void pause() {

  std::cout << "\n"
            << Color::Gray << "Press ENTER to continue..." << Color::Reset;

  std::cin.ignore();
  std::cin.get();
}

void logoutAnimation() {

  clearScreen();

  std::cout << "\n\n";

  std::cout << Color::Red << Color::Bold
            << "                 Leaving the Lands...\n"
            << Color::Reset;

  std::cout << "\n                 Logging Off ";

  std::cout.flush();

  for (int i = 0; i < 5; i++) {

    usleep(500000);

    std::cout << ". ";
    std::cout.flush();
  }

  std::cout << "\n\n";

  printLine();
}

void mainMenu() {

  std::cout << Color::Bold << Color::White
            << "                         MAIN MENU\n"
            << Color::Reset;

  printLine('-');

  std::cout << "\n";

  std::cout << "      " << Color::Yellow << "[1]" << Color::Reset
            << "  ⚔  Battle\n";

  std::cout << "      " << Color::Yellow << "[2]" << Color::Reset
            << "  ⚑  Dungeon\n";

  std::cout << "      " << Color::Yellow << "[3]" << Color::Reset
            << "  ♙  Status\n";

  std::cout << "      " << Color::Yellow << "[4]" << Color::Reset
            << "  ◈  Inventory " << Color::Gray << "(WIP)" << Color::Reset
            << "\n";

  std::cout << "      " << Color::Red << "[5]" << Color::Reset << "  ✕  Exit\n";

  std::cout << "\n";

  printLine('-');

  std::cout << "\n  " << Color::Cyan << "Select Action" << Color::Reset << ": ";
}

} // namespace UI