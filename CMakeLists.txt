# Projects Settings
cmake_minimum_required (VERSION 3.1)
project (3D_scenario)

set (CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    src/*.h
    src/*.cpp
    src/Models/*.h
    src/Models/*.cpp

)

# The main executable
add_executable(3D_scenario
  ${SOURCES}
)

set_property(TARGET 3D_scenario PROPERTY CXX_STANDARD 11)
target_compile_options(3D_scenario PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glew-cmake EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

target_link_libraries(3D_scenario
  PRIVATE glfw
  PRIVATE libglew_static
  PRIVATE glm
)

target_include_directories(3D_scenario
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src 
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/models
)

