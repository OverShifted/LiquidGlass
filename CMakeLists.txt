cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_CXX_STANDARD 17)
project(LiquidGlass
        VERSION 0.0
        LANGUAGES C CXX)

option(OVERENGINE_BUILD_SANDBOX "Build the Sandbox demo" OFF)
add_subdirectory(vendor/OverEngine)

file(GLOB_RECURSE lg_source_files "src/*.cpp")
file(GLOB_RECURSE lg_header_files "src/*.h")

add_executable(LiquidGlass
	${lg_source_files}
	${lg_header_files}
)

set_property(TARGET LiquidGlass PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LiquidGlass PRIVATE OverEngine)
