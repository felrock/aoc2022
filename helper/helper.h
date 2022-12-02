#pragma once

#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <math.h>

namespace helper
{

std::vector<std::string> getFileContent(const std::string filename)
{
   std::vector<std::string> content;
   std::ifstream file(filename);
   std::string line;
   while(std::getline(file, line))
   {
      line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
      content.push_back(line);
   }

   return content;
}

std::vector<std::string> split(std::string str, const std::string delimiter=" ")
{
   std::vector<std::string> strings;
   size_t pos = 0;
   std::string token;
   while ((pos = str.find(delimiter)) != std::string::npos) {
      token = str.substr(0, pos);
      strings.push_back(token);
      str.erase(0, pos + delimiter.length());
   }
   strings.push_back(str);

   return strings;
}

std::vector<std::string> split_ud(std::string str, const char delimiter=' ')
{
   // uneven delim
   std::vector<std::string> strings;
   size_t pos = 0;
   std::string token;
   for (int i=0; i < str.size(); ++i)
   {
      if (str[i] == delimiter && token.empty())
      {
         continue;
      }
      else if(str[i] == delimiter)
      {
         strings.push_back(token);
         token.clear();
      }
      else
      {
         token += str[i];
      }
   }
   strings.push_back(token);

   return strings;
}

std::vector<int> stoi(const std::vector<std::string>& strings)
{
   std::vector<int> numbers;
   for (const auto& str : strings)
   {
      numbers.push_back(std::stoi(str));
   }

   return numbers;
}


using Point = std::pair<int, int>;
using Line = std::pair<Point, Point>;

Point add(Point p1, Point p2)
{
  return Point(p1.first + p2.first, p1.second + p2.second);
}

bool equal(Point p1, Point p2)
{
  return p1.first == p2.first && p1.second == p2.second;
}

Point direction_simple(Line line)
{
  // only horizontal or vertical lines
  Point start = line.first;
  Point end = line.second;
  int dx = end.first - start.first;
  int dy = end.second - start.second;
  int mag = std::sqrt(dx*dx + dy*dy);
  Point vec = Point(dx/mag, dy/mag);

  return vec;
}

Point direction_adv(Line line)
{
  // horizontal, vertical and 45% degrees
  Point start = line.first;
  Point end = line.second;
  int dx = end.first - start.first;
  int dy = end.second - start.second;
  if ( dx != 0 && dy == 0)
  {
    return Point(dx/std::abs(dx), dy);
  }
  else if (dx == 0 && dy != 0)
  {
    return Point(dx, dy/std::abs(dy));
  }
  else
  {
    return Point(dx/abs(dx), dy/std::abs(dy));
  }
}

template<typename T>
void printArray(std::vector<T> array)
{
  for (auto itm : array)
  {
    std::cout << itm << " ";
  }
  std::cout << std::endl;
}

bool isStringLowerCase(const std::string& str)
{
  for (size_t i=0; i < str.size(); ++i)
  {
    if (std::isupper(str[i]))
    {
      return false;
    }
  }
  return true;
}

} // namespace helper
