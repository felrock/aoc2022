#include "helper.h"

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  std::vector<int> items(52);
  int tot_prio = 0;
  for (int i=0; i < fc.size()-2; i+=3)
  {
    bool found = false;
    for (int j=0; j < fc[i].size(); ++j)
    {
      for (int k=0; k < fc[i+1].size(); ++k)
      {
        for (int u=0; u < fc[i+2].size(); ++u)
        {
          if (fc[i][j] == fc[i+1][k] && fc[i+1][k] == fc[i+2][u])
          {
            std::cout << fc[i][j] << std::endl;
            if (fc[i][j] >= 97)
            {
              tot_prio += fc[i][j] - 96;
            }
            else
            {
              tot_prio += fc[i][j] - 38;
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
      if (found)
      {
        break;
      }
    }
  }
  std::cout << "ans: " << tot_prio << std::endl;
  return 0;
}
