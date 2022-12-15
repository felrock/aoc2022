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
  int visible_trees = 0;
  for (int y=0; y < height; ++y)
  {
    for (int x=0; x < width; ++x)
    {
      bool vis_lft = true;
      bool vis_rgt = true;
      bool vis_up = true;
      bool vis_dwn = true;
      for (int lft=x-1; lft >= 0; --lft)
      {
        if (forrest[y][x] <= forrest[y][lft])
        {
          vis_lft = false;
          break;
        }
      }
      for (int rgt=x+1; rgt < width; ++rgt)
      {
        if (forrest[y][x] <= forrest[y][rgt])
        {
          vis_rgt = false;
          break;
        }
      }
      for (int up=y-1; up >= 0; --up)
      {
        if (forrest[y][x] <= forrest[up][x])
        {
          vis_up = false;
          break;
        }
      }
      for (int dwn=y+1; dwn < height; ++dwn)
      {
        if (forrest[y][x] <= forrest[dwn][x])
        {
          vis_dwn = false;
          break;
        }
      }
      if (vis_lft || vis_rgt || vis_up || vis_dwn)
      {
        visible_trees++;
      }
    }
  }
  std::cout << "ans: " << visible_trees << std::endl;
  return 0;
}
