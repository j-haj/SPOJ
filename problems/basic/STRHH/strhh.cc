#include <iostream>
#include <string>
#include <vector>

void print_first_half(const std::string& s) {
  int midpoint_idx = s.size() / 2 - 1;
  for (int i = 0; i <= midpoint_idx; i += 2) {
    std::cout << s[i];
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int n;
  // Get number of lines
  std::cin >> n;
  std::cin.ignore();
  std::vector<std::string> i_strings(n);
  for (int i = 0; i < n; i++) {
      std::string s;
      std::getline(std::cin, s);
      i_strings[i] = s;
  }

  for (const std::string& x : i_strings) {
      print_first_half(x);
  }
  return 0;
}
