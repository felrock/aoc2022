#include "helper.h"
#include <math.h>

int dist(int x1, int y1, int x2, int y2)
{
  int dx = x1 - x2;
  int dy = y1 - y2;
  return static_cast<int>(std::sqrt(dx*dx + dy*dy));
}

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  std::unordered_set<std::string> visited;
  visited.insert("0,0");   // add start pos

  // head coords
  int hx = 0;
  int hy = 0;
  int prev_hx = 0;
  int prev_hy = 0;

  // tail coords
  int tx = 0;
  int ty = 0;
  
  for (auto& line : fc)
  {
    // parse
    auto split_line = helper::split(line, " ");
    char dir = split_line[0][0];
    int steps = std::stoi(split_line[1]);
    
    // create a direction vector
    std::pair<int, int> walk_vec;
    switch (dir)
    {
      case 'R':
        walk_vec = {1, 0};
        break;
      case 'L':
        walk_vec = {-1, 0};
        break;
      case 'U':
        walk_vec = {0, 1};
        break;
      case 'D':
        walk_vec = {0, -1};
        break;
    }
    while(steps)
    {
      // save previous position
      prev_hx = hx;
      prev_hy = hy;
      
      // make a step
      hx += walk_vec.first;
      hy += walk_vec.second;

      // check distance between head and tail
      int d = dist(hx, hy, tx, ty);
      if (d > 1)
      {
        tx = prev_hx;
        ty = prev_hy;
        
        // add position to visit set
        std::string pos = std::to_string(tx) + "," + std::to_string(ty);
        visited.insert(pos);
      }
      steps--;
    }
  }
  std::cout << "ans: " << visited.size() << std::endl;

  return 0;
}
