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
        total += me + 1;
        if (me == op) {
            total += draw;
        } else if (me == 0 && op == 2) {
            // rock wins over scissor
            total += win;
        } else if (me == 1 && op == 0) {
            // paper wins over rock
            total += win;
        } else if (me == 2 && op== 1) {
            // scissor wins over paper
            total += win;
        }
    }
    std::cout << "ans: " << total << std::endl;
  }
  return 0;
}
