cmake_minimum_required(VERSION 3.20)

project(tinyimagelibrary DESCRIPTION "Tiny Image library")

# C++ standard version.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding subfolder property.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# External packages.
find_package(absl CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)

# Add submodules
add_subdirectory(submodules/Frame)

# Sources
add_subdirectory(TinyImageLibrary)
add_subdirectory(TinyImageLibraryTest)
add_subdirectory(ZoomApp)
