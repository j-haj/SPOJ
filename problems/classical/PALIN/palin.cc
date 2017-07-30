#include <iostream>
#include <string>

bool is_palindrom(const std::string& s) {
  int n = s.size();
  int midpoint = s % 2 == 0 ? s / 2 - 1 : int(s / 2);
  for (int i = 0; i < midpoint; i++) {
    if (s[i] != s[n - i]) {
      return false;
    }
  }
  return true;
}

std::string make_palindrom(const std::string& s) {
    

}
