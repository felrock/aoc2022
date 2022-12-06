#include "helper.h"

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  for (auto& line : fc)
  {
    for (int i=13; i < line.size(); ++i)
    {
      bool found_duplicate = false;
      std::unordered_set<char> seen;
      for (int j=i-13; j < i; ++j)
      {
        if (seen.find(line[j]) != seen.end())
        {
          found_duplicate = true;
          break;
        }
        seen.insert(line[j]);
      }
      if (!found_duplicate)
      {
        std::cout << "ans: " << i+1 << std::endl;
        break;
      }
    }
  }
  return 0;
}
