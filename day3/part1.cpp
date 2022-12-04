#include "helper.h"
#include <cctype>

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  int tot_prio = 0;
  for (auto &rucksack : fc)
  {
    bool found = false;
    for (int i=0; i < rucksack.size()/2; ++i)
    {
      for (int j=rucksack.size()/2; j < rucksack.size(); ++j)
      {
        if (rucksack[i] == rucksack[j])
        {
          if (std::islower(rucksack[i]))
          {
            tot_prio += static_cast<int>(rucksack[i]) - 96;  // - 'a'
          }
          else 
          {
            tot_prio += static_cast<int>(rucksack[i]) - 38;  // - 'A' + 26
          }
          found = true;
          break;
        }
      }
      if (found)
      {
        break;
      }
    }
  }
  std::cout << "ans: " << tot_prio << std::endl;
  return 0;
}
