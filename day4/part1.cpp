#include "helper.h"

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  int pairs = 0;
  for (auto &line : fc)
  {
    auto elf_str = helper::split(line, ",");
    auto first_section = helper::split(elf_str[0], "-");
    auto second_section = helper::split(elf_str[1], "-");
    int fs= std::stoi(first_section[0]);
    int fe= std::stoi(first_section[1]);
    int ss= std::stoi(second_section[0]);
    int se= std::stoi(second_section[1]);
    if ((fs <= ss && fe >= se) ||
        (fs >= ss && fe <= se))
    {
      pairs++;
    }
  }
  std::cout << "ans: " << pairs << std::endl;
  return 0;
}
