#include "helper.h"

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  for (auto& line : fc)
  {
    for (int i=0; i < line.size()-3; ++i)
    {
      if (line[i] != line[i+1] && line[i+1] != line[i+2] &&
          line[i+2] != line[i+3] && line[i] != line[i+3] &&
          line[i+1] != line[i+3] && line[i] != line[i+2])
      {
        std::cout << "ans: " << i+4 << std::endl;
        break;
      }
    }
  }
  return 0;
}
