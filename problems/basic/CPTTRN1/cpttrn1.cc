// cpttrn1.cpp
//
// Jeff Hajewski
// 3/20/2017

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <sstream>

std::tuple<int, int> parse_line(const std::string& line) {
    std::istringstream ss(line);
    std::string m_str, n_str;
   
    // Get m and n as strings
    while (!ss.eof()) {
        getline(ss, m_str, ' ');
        getline(ss, n_str);
    }
   
    // Convert m and n to integers 
    std::stringstream convert(m_str);
    int m, n;
    if (!(convert >> m)) {
        std::cout << "error - bad input.\nFailed to convert: " << convert.str() << std::endl;
    }
    convert.clear();
    convert.str(n_str);
    if (!(convert >> n)) {
        std::cout << "error - bad input.\nFailed to convert: " << convert.str() << std::endl;
    }
    
    return std::make_tuple(m, n);    
}

std::vector<std::tuple<int, int>> parse_lines(const std::vector<std::string>& lines) {
    int n = lines.size();
    std::vector<std::tuple<int, int>> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = parse_line(lines[i]);
    }
    return result;
}

void print_boards(const std::vector<std::tuple<int, int>>& boards) {
    for (const std::tuple<int, int>& x : boards) {
        int num_rows = std::get<0>(x);
        int num_cols = std::get<1>(x);
        bool is_star_row = true;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (is_star_row) {
                    std::cout << (j % 2 == 0 ? "*" : ".");
                } else {
                    std::cout << (j % 2 == 1 ? "*" : ".");
                }
            }
            std::cout << "\n";
            is_star_row = !is_star_row;
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    // Get number of lines
    std::string n_str;
    getline(std::cin, n_str);
    std::stringstream ss(n_str);
    int num_lines;
    ss >> num_lines;
    
    // Read input
    std::vector<std::string> lines(num_lines);
    for (int i = 0; i < num_lines; i++) {
        std::string line;
        getline(std::cin, line);
        lines[i] = line;
    }
    std::vector<std::tuple<int, int>> input_tups = parse_lines(lines);
    
    // Print boards
    print_boards(input_tups);

    return 0;
}
