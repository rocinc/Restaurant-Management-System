# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RestaurantManagementSystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RestaurantManagementSystem_autogen.dir\\ParseCache.txt"
  "RestaurantManagementSystem_autogen"
  )
endif()
