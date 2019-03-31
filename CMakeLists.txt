cmake_minimum_required(VERSION 3.0)
project (CoreFramework)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CoreFrameworkLib)

add_subdirectory(libraries/glfw EXCLUDE_FROM_ALL)
add_subdirectory(libraries/glew EXCLUDE_FROM_ALL)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif()

# Macro to map filters to folder structure for MSVC projects
macro(GroupSources curdir)
    if(MSVC)        
		file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

        foreach(child ${children})
            if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
                GroupSources(${curdir}/${child})
            else()
                string(REPLACE "/" "\\" groupname ${curdir})
                source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
            endif()
        endforeach()
    endif()
endmacro()

# Generate build information
include(GetGitRevisionDescription)

function(get_timestamp _var)
    string(TIMESTAMP timestamp UTC)
    set(${_var} "${timestamp}" PARENT_SCOPE)
endfunction()

get_git_head_revision(GIT_REF_SPEC GIT_REV)
git_describe(GIT_DESC --always --long --dirty)
git_branch_name(GIT_BRANCH)
get_timestamp(BUILD_DATE)

include_directories("src")
include_directories("src/utils")
include_directories("src/math")
#include_directories("graphics")
#include_directories("graphics/buffers")
include_directories("src/input")
include_directories("libraries/stb")

file(GLOB_RECURSE SOURCE_FILES *.cpp utils/*.cpp math/*.cpp graphics/*.cpp graphics/buffers/*.cpp input/*.cpp)
file(GLOB_RECURSE HEADER_FILES *.h utils/*.h math/*.h graphics/*.h graphics/buffers/*.h input/*.h)

GroupSources(src)

add_executable(CoreFramework ${SOURCE_FILES} ${HEADER_FILES})

set_property(TARGET CoreFramework PROPERTY CXX_STANDARD 11)

# glfw
target_link_libraries(CoreFramework PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
target_link_libraries(CoreFramework PRIVATE libglew_static)
