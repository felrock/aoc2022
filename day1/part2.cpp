#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
  std::ifstream file(argv[1]);
  std::string line;
  std::vector<int> elves;
  int current_elf;
  if (file.is_open())
  {
    while (std::getline(file, line))
    {
      if (line == "")
      {
          elves.push_back(current_elf);
          current_elf = 0;
      }
      else
      {
          current_elf += std::stoi(line);
      }
    }
  }
  std::sort(elves.begin(), elves.end(), std::greater<int>());
  std::cout << "ans: " << elves[0] + elves[1] + elves[2] << std::endl;
  return 0;
}
