cmake_minimum_required(VERSION 3.15)

project(paint)

# NOTE: use vcpkg on windows and specify -DCMAKE_TOOLCHAIN_FILE=E:\vcpkg\vcpkg\scripts\buildsystems\vcpkg.cmake to the cmake command
find_package(wxWidgets REQUIRED)

if(MSVC)
    set(TARGET_OPTIONS WIN32)
endif()

file(GLOB SRCFILES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${PROJECT_NAME} "${TARGET_OPTIONS}" "${SRCFILES}")

target_include_directories(${PROJECT_NAME} PRIVATE "${wxWidgets_INCLUDE_DIRS}")
target_link_libraries(${PROJECT_NAME} PRIVATE "${wxWidgets_LIBRARIES}")
