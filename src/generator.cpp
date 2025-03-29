#include <generator.hpp>

#include <colorcodes.hpp>

namespace bf_compiler
{
    void __init(std::ofstream& out);
    void __epilogue(std::ofstream& out);
    void __handlePlus(std::ofstream& out);
    void __handleMinus(std::ofstream& out);
    void __handleLeft(std::ofstream& out);
    void __handleRight(std::ofstream& out);
    void __handleLoopStart(std::ofstream& out, std::size_t loop_id);
    void __handleLoopEnd(std::ofstream& out, std::size_t loop_id);
    void __handleInput(std::ofstream& out);
    void __handleOutput(std::ofstream& out);

    void generate(
        const std::vector<char>& terms,
        std::ofstream& out
    )
    {
        std::streambuf* cout_buf = std::cout.rdbuf();
        std::cout.rdbuf(out.rdbuf());
        
        __init(out);

        std::size_t loop_id = 0;
        std::stack<std::size_t> loop_stack;

        for (const auto& t : terms)
        {
            switch (t)
            {
            case '+':
                __handlePlus(out);
                break;
            case '-':
                __handleMinus(out);
                break;
            case '<':
                __handleLeft(out);
                break;
            case '>':
                __handleRight(out);
                break;
            case '[':
                __handleLoopStart(out, loop_id);
                loop_stack.push(loop_id);
                loop_id++;
                break;
            case ']':
                if (!loop_stack.empty())
                {
                    __handleLoopEnd(out, loop_stack.top());
                    loop_stack.pop();
                }
                break;
            case ',':
                __handleInput(out);
                break;
            case '.':
                __handleOutput(out);
                break;
            default:
                break;
            }
        }

        __epilogue(out);
        std::cout.rdbuf(cout_buf);

        std::cout << SUCCESS_GREEN << "[SUCCESS]" << RESET_COLOR << ": Code generation completed successfully!" << std::endl;

        out.close();
    }

    void __init(std::ofstream& out)
    {
        #ifdef __APPLE__ || __MACH__
            out << ".text" << "\n";
            out << "    .globl _main" << "\n\n";
            
            out << "_main:" << "\n";
        #elif __linux__
            out << ".section .text" << "\n";
            out << "    .globl _start" << "\n\n";
            
            out << "_start:" << "\n";
        #endif

        out << "    sub $30000, %rsp" << "\n";
        out << "    mov %rsp, %rbx" << "\n\n";
    }

    void __epilogue(std::ofstream& out)
    {
        out << "    add $30000, %rsp" << "\n";
        
        #ifdef __APPLE__ || __MACH__
            out << "    mov $0x2000001, %rax" << "\n";
        #elif __linux__
            out << "    mov $0x3c, %rax" << "\n";
        #endif

        out << "    xor %rdi, %rdi" << "\n";
        out << "    syscall" << "\n";
    }

    void __handlePlus(std::ofstream& out)
    {
        out << "    incb (%rbx)" << "\n";
    }

    void __handleMinus(std::ofstream& out)
    {
        out << "    decb (%rbx)" << "\n";
    }

    void __handleLeft(std::ofstream& out)
    {
        out << "    dec %rbx" << "\n";
    }

    void __handleRight(std::ofstream& out)
    {
        out << "    inc %rbx" << "\n";
    }

    void __handleLoopStart(std::ofstream& out, std::size_t loop_id)
    {
        out << "\n";
        out << "loop_start_" << loop_id << ":" << "\n";
        out << "    cmpb $0, (%rbx)" << "\n";
        out << "    je loop_end_" << loop_id << "\n\n";
    }

    void __handleLoopEnd(std::ofstream& out, std::size_t loop_id)
    {
        out << "    jmp loop_start_" << loop_id << "\n";
        out << "loop_end_" << loop_id << ":" << "\n\n";
    }

    void __handleInput(std::ofstream& out)
    {
        #ifdef __APPLE__ || __MACH__
            out << "    mov $0x2000003, %rax" << "\n";
        #elif __linux__
            out << "    mov $0, %rax" << "\n";
        #endif

        out << "    mov $0, %rdi" << "\n";
        out << "    mov %rbx, %rsi" << "\n";
        out << "    mov $1, %rdx" << "\n";
        out << "    syscall" << "\n\n";
    }

    void __handleOutput(std::ofstream& out)
    {
        #ifdef __APPLE__ || __MACH__
            out << "    mov $0x2000004, %rax" << "\n";
        #elif __linux__
            out << "    mov $1, %rax" << "\n";
        #endif

        out << "    mov $1, %rdi" << "\n";
        out << "    mov %rbx, %rsi" << "\n";
        out << "    mov $1, %rdx" << "\n";
        out << "    syscall" << "\n\n";
    }
}
