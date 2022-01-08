# set the minimum version of cmake to be compatible with
cmake_minimum_required(VERSION 3.15)

# set project name
project("conways_game_of_life")

# NOTE: use vcpkg on windows and specify -DCMAKE_TOOLCHAIN_FILE=<PATH_TO_VCPKG_TOOLCHAIN> to cmake command
find_package(SFML COMPONENTS graphics window system REQUIRED)

# get source files
file(GLOB SRCFILES CONFIGURE_DEPENDS "src/*.cpp")
# add the main executable as our target
add_executable("${PROJECT_NAME}" "${SRCFILES}")

target_link_libraries("${PROJECT_NAME}" PRIVATE sfml-system sfml-graphics sfml-window)