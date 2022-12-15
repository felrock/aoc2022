#include "helper.h"

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  
  std::vector<std::vector<int>> forrest;
  for (auto& line : fc)
  {
    std::vector<int> row;
    for (auto& chr : line)
    {
      row.push_back(static_cast<int>(chr-'0'));
    }
    forrest.push_back(row);
  }
  
  int height = forrest.size();
  int width = forrest[0].size();
  int best_scenic_score = 0;
  for (int y=0; y < height; ++y)
  {
    for (int x=0; x < width; ++x)
    {
      int lft_score = 0;
      for (int lft=x-1; lft >= 0; --lft)
      {
        lft_score++;
        if (forrest[y][x] <= forrest[y][lft])
        {
          break;
        }
      }
      int rgt_score = 0;
      for (int rgt=x+1; rgt < width; ++rgt)
      {
        rgt_score++;
        if (forrest[y][x] <= forrest[y][rgt])
        {
          break;
        }
      }
      int up_score = 0;
      for (int up=y-1; up >= 0; --up)
      {
        up_score++;
        if (forrest[y][x] <= forrest[up][x])
        {
          break;
        }
      }
      int dwn_score = 0;
      for (int dwn=y+1; dwn < height; ++dwn)
      {
        dwn_score++;
        if (forrest[y][x] <= forrest[dwn][x])
        {
          break;
        }
      }
      int current_scenic_score = lft_score * rgt_score * up_score * dwn_score;
      if (current_scenic_score > best_scenic_score)
      {
        best_scenic_score = current_scenic_score;
      }
    }
  }
  std::cout << "ans: " << best_scenic_score << std::endl;
  return 0;
}
