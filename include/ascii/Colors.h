#pragma once
#include <string>

namespace Color {

    inline const std::string Reset  = "\033[0m";

    inline const std::string Red    = "\033[31m";
    inline const std::string Green  = "\033[32m";
    inline const std::string Yellow = "\033[33m";
    inline const std::string Blue   = "\033[34m";
    inline const std::string Cyan   = "\033[36m";
    inline const std::string White  = "\033[37m";
    inline const std::string Gray   = "\033[90m";

    inline const std::string Bold   = "\033[1m";
}