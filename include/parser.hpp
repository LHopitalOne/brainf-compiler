#ifndef PARSER_HPP
#define PARSER_HPP

#include <stack>
#include <vector>

#include <string>
#include <iostream>

#include <scanner.hpp>

#include <colorcodes.hpp>

namespace bf_compiler
{
    bool parse(
        const std::vector<char>& _terms
    );
}

#endif // PARSER_HPP
