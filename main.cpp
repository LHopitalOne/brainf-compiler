#include <string>
#include <cstdlib>
#include <iostream>

#include <brainfuck.hpp>

int main(int argc, char* argv[])
{
    std::string input_file;
    std::string output_file;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--filename") == 0 || strcmp(argv[i], "-f") == 0)
            if (i + 1 < argc)
                input_file = argv[i++ + 1];
                
        if (input_file.empty())
            input_file = argv[1];

        if (strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0)
            if (i + 1 < argc)
                output_file = argv[i++ + 1];
    }
    
    if (input_file.empty())
    {
        std::cerr << ERROR_RED << "[ERROR]" << RESET_COLOR << ": No input file provided." << std::endl;
        return 1;
    }
    
    if (output_file.empty())
        output_file = "program";
    
    std::vector<char> terms;
    
    std::ofstream output_file_stream(output_file + ".s");
    if (!output_file_stream.is_open())
    {
        std::cerr << ERROR_RED << "[ERROR]" << RESET_COLOR << ": Could not open output file." << std::endl;
        return 1;
    }
    
    bf_compiler::scan(input_file, terms);
    if (bf_compiler::parse(terms))
        bf_compiler::generate(terms, output_file_stream);
    else
        return 1;

    output_file_stream.close();

    std::string compile_assembly_command = "as " + output_file + ".s -o " + output_file + ".o";
    std::string compile_link_command     = "ld " + output_file + ".o -o " + output_file;
    std::string clean_files_command      = "rm " + output_file + ".o " + output_file + ".s";
    
    system((compile_assembly_command + " && " + compile_link_command + " && " + clean_files_command).c_str());

    std::cout << SUCCESS_GREEN << "[SUCCESS]" << RESET_COLOR << ": Compilation completed successfully!" << std::endl;   

    return 0;
}
