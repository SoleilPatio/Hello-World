cmake_minimum_required (VERSION 3.5)

project (main_app)


#[CLS][Case1]:	source build
#		"source build" must before "lib build",or "redefine target" will happen
#add_subdirectory(../lib_rtos/ ${CMAKE_CURRENT_BINARY_DIR}/lib_rtos)


#[CLS][Case2]: lib build
#	   export.cmake just like "c include header", check #ifdef at the beginning, 
#	   so no need to worry about redefine target
#	   install() command will generate code to calculate _IMPORT_PREFIX	
#set(SDK_HOME	${CMAKE_CURRENT_SOURCE_DIR}/../SDK_HOME)
#include ("${SDK_HOME}/cmake/librtos.cmake")



#link_libraries(rtos)
add_executable(main_app ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

#[CLS]: include directory
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


#[CLS] compiler option
# add_compile_options(-std=c++11)
# target_compile_options(main_app -std=c++11)

#[CLS] link option
# add_link_options(-static)
# target_link_options(main_app -static)
# target_link_libraries(main_app -static)
