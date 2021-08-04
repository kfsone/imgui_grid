CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

PROJECT(imgui_grid)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

INCLUDE(FetchContent)
FetchContent_Declare(
	imguiwrap
	GIT_REPOSITORY	https://github.com/kfsone/imguiwrap.git
	GIT_TAG			origin/main
)
FetchContent_MakeAvailable(imguiwrap)

ADD_EXECUTABLE(
	imgui_grid
	main.cpp
  )

TARGET_LINK_LIBRARIES(
	imgui_grid
	PUBLIC imguiwrap
)
