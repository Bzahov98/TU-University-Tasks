# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /mnt/sda6/bobo/Programs/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /mnt/sda6/bobo/Programs/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TaxiRouteSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TaxiRouteSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TaxiRouteSystem.dir/flags.make

CMakeFiles/TaxiRouteSystem.dir/main.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/main.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/main.cpp"

CMakeFiles/TaxiRouteSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/main.cpp" > CMakeFiles/TaxiRouteSystem.dir/main.cpp.i

CMakeFiles/TaxiRouteSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/main.cpp" -o CMakeFiles/TaxiRouteSystem.dir/main.cpp.s

CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.o: ../model/serializable/Serializable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/serializable/Serializable.cpp"

CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/serializable/Serializable.cpp" > CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.i

CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/serializable/Serializable.cpp" -o CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.s

CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.o: ../model/car/Car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/car/Car.cpp"

CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/car/Car.cpp" > CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.i

CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/car/Car.cpp" -o CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.s

CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.o: ../model/Route/Route.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Route/Route.cpp"

CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Route/Route.cpp" > CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.i

CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Route/Route.cpp" -o CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.s

CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.o: ../model/Taxi/Taxi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Taxi/Taxi.cpp"

CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Taxi/Taxi.cpp" > CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.i

CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Taxi/Taxi.cpp" -o CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.s

CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.o: ../model/Point/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Point/Point.cpp"

CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Point/Point.cpp" > CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.i

CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/model/Point/Point.cpp" -o CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.s

CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.o: CMakeFiles/TaxiRouteSystem.dir/flags.make
CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.o: ../exceptions/InvalidInputException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.o -c "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/exceptions/InvalidInputException.cpp"

CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/exceptions/InvalidInputException.cpp" > CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.i

CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/exceptions/InvalidInputException.cpp" -o CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.s

# Object files for target TaxiRouteSystem
TaxiRouteSystem_OBJECTS = \
"CMakeFiles/TaxiRouteSystem.dir/main.cpp.o" \
"CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.o" \
"CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.o" \
"CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.o" \
"CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.o" \
"CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.o" \
"CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.o"

# External object files for target TaxiRouteSystem
TaxiRouteSystem_EXTERNAL_OBJECTS =

TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/main.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/model/serializable/Serializable.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/model/car/Car.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/model/Route/Route.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/model/Taxi/Taxi.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/model/Point/Point.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/exceptions/InvalidInputException.cpp.o
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/build.make
TaxiRouteSystem: CMakeFiles/TaxiRouteSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable TaxiRouteSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TaxiRouteSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TaxiRouteSystem.dir/build: TaxiRouteSystem

.PHONY : CMakeFiles/TaxiRouteSystem.dir/build

CMakeFiles/TaxiRouteSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TaxiRouteSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TaxiRouteSystem.dir/clean

CMakeFiles/TaxiRouteSystem.dir/depend:
	cd "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem" "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem" "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug" "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug" "/home/bzahov/Documents/gitRepos/TU-University-Tasks/Programming Languages(PE) C++/TaxiRouteSystem/cmake-build-debug/CMakeFiles/TaxiRouteSystem.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TaxiRouteSystem.dir/depend

