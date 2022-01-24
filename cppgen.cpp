#include <fstream>
#include <iostream>
int main(int argc, char* argv[]) {
    std::string filename;
    std::fstream file_cpp;
    std::fstream file_in;
    filename = argv[1];
    file_cpp.open(filename + ".cpp", std::ios::in);
    if (file_cpp.is_open()) {
        std::cout << filename << ".cpp exists...\n";
    } else {
        file_cpp.open(filename + ".cpp", std::ios::out);
        file_in.open(filename + ".in", std::ios::out);
        file_cpp << "#include <bits/stdc++.h>\n"
                 << "using namespace std;\n"
                 << "int main() {\n"
                 << "    ios_base::sync_with_stdio(false);\n"
                 << "    cin.tie(0);\n"
                 << "    return 0;\n"
                 << "}\n"
                 << "//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 " << filename << ".cpp ; ./a.out <" << filename << ".in";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -O3 cppgen.cpp -o /home/linuxbrew/.linuxbrew/bin/cppgen