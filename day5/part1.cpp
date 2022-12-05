#include "helper.h"
#include <stack>

int main(int argc, char** argv)
{
  const char EMPTY = ' ';
  const std::string NUM_RGX("[0-9]+");

  auto fc = helper::getFileContent(argv[1]);
  std::vector<std::string> stacks;
  int start_of_moves = 0;
  for (auto& line : fc)
  {
    start_of_moves++;
    if (line == "")
    {
      break;
    }
    stacks.push_back(line);
  }
  const int nr = stacks.size()-1;
  std::vector<std::stack<char>> stx;
  for (int i=0; i < stacks[nr].size(); ++i)
  {
    if (stacks[nr][i] != EMPTY)
    {
      std::stack<char> s;
      for (int j=nr; j >= 0; --j)
      {
        if (stacks[j][i] != EMPTY)
        {
          s.push(stacks[j][i]);
        }
      }
      stx.push_back(s);
    }
  }
  for (int i=start_of_moves; i < fc.size(); ++i)
  {
    std::string sequence = fc[i];  
    auto matches = helper::findMultipleRgx(NUM_RGX, sequence);
  
    int num = std::stoi(matches[0]);
    int from = std::stoi(matches[1]) - 1;
    int to = std::stoi(matches[2]) - 1;
    for (int k=0; k < num; ++k)
    {
      auto item = stx[from].top();
      stx[from].pop();
      stx[to].push(item);
    }
  }

  std::cout << "ans: ";
  for (int i=0; i < stx.size(); ++i)
  {
    std::cout << stx[i].top();
  }
  std::cout << std::endl;

  return 0;
}
