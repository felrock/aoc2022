#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
  std::ifstream file(argv[1]);
  std::string line;
  int win=6, draw=3, loss=0;
  int total=0;
  if (file.is_open())
  {
    while (std::getline(file, line))
    {
        int op = line[0] - 'A';
        int me = line[2] - 'X';
        if (me == 0) {
            if (op == 0) {
              total += 3;
            } else if (op == 1) {
              total += 1;
            } else {
              total += 2;
            }
        } else if (me == 1) {
            if (op == 0) {
              total += 1;
            } else if (op == 1) {
              total += 2;
            } else {
              total += 3;
            }
            total += draw;
        } else if (me == 2) {
            // paper wins over rock
            if (op == 0) {
              total += 2;
            } else if (op == 2) {
              total += 1;
            } else {
              total += 3;
            }
            total += win;
        }
    }
    std::cout << "ans: " << total << std::endl;
  }
  return 0;
}
