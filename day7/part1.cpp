#include "helper.h"

int main(int argc, char** argv)
{
  auto fc = helper::getFileContent(argv[1]);

  std::vector<std::string> current_path;
  std::unordered_map<std::string, long long> size_map;
   
  for (auto& line : fc)
  {
    auto split_line = helper::split(line, " ");

    if (split_line[0] == "$")
    {
      if (split_line[1] == "cd")
      {
        if (split_line[2] == "..")
        {
          current_path.pop_back();
        }
        else
        {
          current_path.push_back(split_line[2]);
        }
      }
    }
    else
    {
      if (split_line[0] != "dir")
      {
        std::vector<std::string> temp_path;
        for (auto& p : current_path)
        {
          temp_path.push_back(p);
          size_map[helper::join(temp_path)] += std::stoi(split_line[0]);
        }
      }
    }
  }

  long long size = 0;
  for (auto& itm : size_map)
  {
    if (itm.second <= 100000)
    {
      size += itm.second;
    }
  }
  std::cout << "ans: " << size << std::endl;
  return 0;
}
