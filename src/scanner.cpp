#include <iostream>

#include <vector>

#include <scanner.hpp>

namespace bf_compiler
{
    void scan(
        const std::string& path,
        std::vector<char>& terms
    )
    {
        std::initializer_list<char> valid_tokens = {'>', '<', '+', '-', '.', ',', '[', ']'};
        std::ifstream file(path, std::ios::binary);
        
        if (!file.is_open())
        {
            std::cerr << ERROR_RED << "[ERROR]" << RESET_COLOR << ": Could not open file " << path << std::endl;
            return;
        }
        
        char chunk;
        while (file.get(chunk))
        {
            if (std::find(valid_tokens.begin(), valid_tokens.end(), chunk) != valid_tokens.end())
                terms.push_back(chunk);
            else if (std::isspace(chunk))
                continue;
        }
        
        file.close();
    }
}
