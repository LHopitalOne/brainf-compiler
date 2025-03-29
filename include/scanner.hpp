#ifndef BF_SCANNER_HPP
#define BF_SCANNER_HPP

#include <fstream>

#include <string>
#include <cctype>
#include <cstring>

#include <algorithm>

#include <initializer_list>

#include <colorcodes.hpp>

namespace bf_compiler
{
    void scan(
        const std::string& path,
        std::vector<char>& terms
    );
}

#endif // BF_SCANNER_HPP

