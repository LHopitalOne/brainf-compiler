#include <parser.hpp>

namespace bf_compiler
{
    bool parse(
        const std::vector<char>& _terms
    )
    {
        std::stack<std::size_t> loop_stack;
        std::vector<std::size_t> loop_pairs;
        
        for (std::size_t i = 0; i < _terms.size(); i++)
        {
            if (_terms[i] == '[')
                loop_stack.push(i);
            else if (_terms[i] == ']')
            {
                if (loop_stack.empty())
                {
                    std::cerr << ERROR_RED << "[ERROR]" << RESET_COLOR << ": Unmatched \"]\" at position " << i << std::endl;
                    return false;
                }
                
                loop_pairs.push_back(loop_stack.top());
                loop_pairs.push_back(i);
                
                loop_stack.pop();
            }
        }
        
        if (!loop_stack.empty())
        {
            std::cerr << ERROR_RED << "[ERROR]" << RESET_COLOR << ": Unmatched \"[\" at position " << loop_stack.top() << std::endl;
            return false;
        }
        
        for (std::size_t i = 0; i < loop_pairs.size(); i += 2)
        {
            if (_terms[loop_pairs[i]] != '[' || _terms[loop_pairs[i + 1]] != ']')
            {
                std::cerr << ERROR_RED << "[ERROR]" << RESET_COLOR << ": Invalid loop pair at positions " << loop_pairs[i] << " and " << loop_pairs[i + 1] << std::endl;
                return false;
            }
        }

        std::cout << SUCCESS_GREEN << "[SUCCESS]" << RESET_COLOR << ": Parsing completed successfully!" << std::endl;

        return true;
    }
}
