#include "helper.h"
#include <math.h>

int dist(std::pair<int, int> p1, std::pair<int, int> p2)
{
  int dx = p1.first - p2.first;
  int dy = p1.second - p2.second;
  return static_cast<int>(std::sqrt(dx*dx + dy*dy));
}

std::pair<int, int> get_vec(std::pair<int, int> p1, std::pair<int, int> p2)
{
  int dx = p1.first - p2.first;
  int dy = p1.second - p2.second;
  if (dx == 0 && dy != 0)
  {
    return { p2.first, p2.second + (dy/std::abs(dy)) };
  }
  else if (dx != 0 && dy == 0)
  {
    return { p2.first + (dx/std::abs(dx)), p2.second };
  }
  else if (dx != 0 && dy != 0)
  {
    return { p2.first + (dx/std::abs(dx)), p2.second + (dy/std::abs(dy)) };
  }
  else
  {
    return p2;
  }
}

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);
  std::unordered_set<std::string> visited;

  // create all talis
  std::vector<std::pair<int, int>> snake;
  for (int i=0; i < 10; ++i)
  {
    snake.emplace_back(0, 0);
  }

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
    while (steps)
    {
      // step head
      snake[0] = { snake[0].first + walk_vec.first, snake[0].second + walk_vec.second };
      for (int i=1; i < snake.size(); ++i)
      {
        int d = dist(snake[i-1], snake[i]);
        if (d > 1)
        {
          snake[i] = get_vec(snake[i-1], snake[i]);
        }
        else
        {
          break;
        }
      }
      // add final tail pos
      std::string pos = std::to_string(snake[9].first) + "," + std::to_string(snake[9].second);
      visited.insert(pos);
      steps--;
    }
  }
  std::cout << "ans: " << visited.size() << std::endl;

  return 0;
}
