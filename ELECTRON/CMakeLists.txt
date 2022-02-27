# CMakeList.txt : CMake project for ELECTRON, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


set(PathToFille )

file(GLOB Filles 
"${CMAKE_SOURCE_DIR}/ELECTRON/Aplication/*.cpp"
"${CMAKE_SOURCE_DIR}/ELECTRON/Core/Window/*.cpp"
"${CMAKE_SOURCE_DIR}/ELECTRON/Core/Camera/*.cpp"
"${CMAKE_SOURCE_DIR}/ELECTRON/Core/Shader/*.cpp"
"${CMAKE_SOURCE_DIR}/ELECTRON/Core/Event/*.cpp"
)






# Add source to this project's executable.
add_executable (ELECTRON ${Filles} )



include_directories(&{PROJECT_NAME}  ${CMAKE_SOURCE_DIR}/ELECTRON/Aplication)
include_directories(&{PROJECT_NAME}  ${CMAKE_SOURCE_DIR}/ELECTRON/Core)



# TODO: Add tests and install targets if needed.
target_link_libraries(${PROJECT_NAME}
	glfw
	assimp
	libglew_static
	glm
)