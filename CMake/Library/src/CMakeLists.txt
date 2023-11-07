cmake_minimum_required(VERSION 3.15)

# CMake instructions to make the static lib

add_library( mylib STATIC )

target_sources(mylib PRIVATE 
	sum.c
	)		 

# CMake instructions to test using the static lib
add_executable( my_exe
                main.c ) 

target_include_directories(my_exe 
	PUBLIC 
	includes
)

target_link_libraries( my_exe
                       mylib )
