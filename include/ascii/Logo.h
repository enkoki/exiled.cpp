#pragma once
#include <iostream>
#include "Colors.h"

namespace ASCII {

    inline void printLogo() {

        std::cout << Color::Red << Color::Bold;

        std::cout << R"(

              ███████╗██╗  ██╗██╗██╗     ███████╗██████╗
              ██╔════╝╚██╗██╔╝██║██║     ██╔════╝██╔══██╗
              █████╗   ╚███╔╝ ██║██║     █████╗  ██║  ██║
              ██╔══╝   ██╔██╗ ██║██║     ██╔════╝██║  ██║
              ███████╗██╔╝ ██╗██║███████╗███████╗██████╔╝
              ╚══════╝╚═╝  ╚═╝╚═╝╚══════╝╚══════╝╚═════╝

)";

        std::cout << Color::Reset;

        std::cout
            << Color::Gray
            << "                    A Tarnished Adventure\n"
            << Color::Reset;
    }
}