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
  auto max_elf = *std::max_element(elves.begin(), elves.end());
  std::cout << "ans: " << max_elf << std::endl;
  return 0;
}
