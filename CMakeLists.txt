cmake_minimum_required(VERSION 3.8)

project("AdventOfCode2021")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# regex for matching folders and files
set(regex_filename "part[0-9]+")
set(regex_foldername "day[0-9]+")

set(helper "helper")

# add all days and parts to build
file(GLOB files
    "${PROJECT_SOURCE_DIR}/**/*.cpp"
)

include_directories(${helper})

message("-- Adding executables...")
foreach(file ${files})

  # extract name from path
  string(REGEX MATCH ${regex_foldername} day ${file})
  string(REGEX MATCH ${regex_filename} part ${file})
  set(exec_name "${day}${part}")
  message("-- [+] found ${day} and ${part} in filename")

  add_executable(${exec_name} ${file})

  message("-- [+] Added ${file} as ${exec_name}")
endforeach()
