#include "Strings.h"

bool Strings::endsWith (std::string const &str, std::string const &ending)
{
    if (ending.length() > str.length()) {
        return false;
    }

    size_t index = str.length() - ending.length();
    return (str.compare(index, ending.length(), ending) == 0);
}