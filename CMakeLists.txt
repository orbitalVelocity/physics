cmake_minimum_required (VERSION 2.8)

project (physics)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

file(GLOB src_files
	"src/*.cpp"
)

add_library(physics	${src_files})
add_executable(test-vectord	${src_files}	test/test-vectord.cpp)
add_executable(test-integration	${src_files}	test/test-integration.cpp)
add_executable(test-twobody	${src_files}	test/test-twobody.cpp)
add_executable(test-rotation	${src_files}	test/test-rotation.cpp)
