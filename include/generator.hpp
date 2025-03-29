#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <fstream>
#include <iostream>

#include <vector>

#include <string>

#include <colorcodes.hpp>

namespace bf_compiler
{
    void generate(
        const std::vector<char>& terms,
        std::ofstream& out
    );
}

#endif // GENERATOR_HPP
