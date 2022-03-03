# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("ELECTRON")


set (CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_SOURCE_DIR}/Dependencies/glfw/")
add_subdirectory("${CMAKE_SOURCE_DIR}/Dependencies/glew/")
add_subdirectory("${CMAKE_SOURCE_DIR}/Dependencies/assimp/")
add_subdirectory("${CMAKE_SOURCE_DIR}/Dependencies/glm/")

# Include sub-projects.
add_subdirectory ("ELECTRON")
message(${CMAKE_CXX_STANDARD})


target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_SOURCE_DIR}/Dependencies/glfw/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_SOURCE_DIR}/Dependencies/glew/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_SOURCE_DIR}/Dependencies/assimp/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_SOURCE_DIR}/Dependencies/glm/)


