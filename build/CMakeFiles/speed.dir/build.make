# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build"

# Include any dependencies generated for this target.
include CMakeFiles/speed.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/speed.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/speed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/speed.dir/flags.make

CMakeFiles/speed.dir/my_test.cpp.o: CMakeFiles/speed.dir/flags.make
CMakeFiles/speed.dir/my_test.cpp.o: /home/amgalan/Downloads/Telegram\ Desktop/ProjectAiP/my_test.cpp
CMakeFiles/speed.dir/my_test.cpp.o: CMakeFiles/speed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/speed.dir/my_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/speed.dir/my_test.cpp.o -MF CMakeFiles/speed.dir/my_test.cpp.o.d -o CMakeFiles/speed.dir/my_test.cpp.o -c "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/my_test.cpp"

CMakeFiles/speed.dir/my_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/speed.dir/my_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/my_test.cpp" > CMakeFiles/speed.dir/my_test.cpp.i

CMakeFiles/speed.dir/my_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/speed.dir/my_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/my_test.cpp" -o CMakeFiles/speed.dir/my_test.cpp.s

CMakeFiles/speed.dir/functions.cpp.o: CMakeFiles/speed.dir/flags.make
CMakeFiles/speed.dir/functions.cpp.o: /home/amgalan/Downloads/Telegram\ Desktop/ProjectAiP/functions.cpp
CMakeFiles/speed.dir/functions.cpp.o: CMakeFiles/speed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/speed.dir/functions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/speed.dir/functions.cpp.o -MF CMakeFiles/speed.dir/functions.cpp.o.d -o CMakeFiles/speed.dir/functions.cpp.o -c "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/functions.cpp"

CMakeFiles/speed.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/speed.dir/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/functions.cpp" > CMakeFiles/speed.dir/functions.cpp.i

CMakeFiles/speed.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/speed.dir/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/functions.cpp" -o CMakeFiles/speed.dir/functions.cpp.s

# Object files for target speed
speed_OBJECTS = \
"CMakeFiles/speed.dir/my_test.cpp.o" \
"CMakeFiles/speed.dir/functions.cpp.o"

# External object files for target speed
speed_EXTERNAL_OBJECTS =

speed: CMakeFiles/speed.dir/my_test.cpp.o
speed: CMakeFiles/speed.dir/functions.cpp.o
speed: CMakeFiles/speed.dir/build.make
speed: _deps/raylib-build/raylib/libraylib.a
speed: /usr/lib/x86_64-linux-gnu/libOpenGL.so
speed: /usr/lib/x86_64-linux-gnu/libGLX.so
speed: /usr/lib/x86_64-linux-gnu/libGLU.so
speed: _deps/raylib-build/raylib/external/glfw/src/libglfw3.a
speed: /usr/lib/x86_64-linux-gnu/librt.a
speed: /usr/lib/x86_64-linux-gnu/libm.so
speed: CMakeFiles/speed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable speed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/speed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/speed.dir/build: speed
.PHONY : CMakeFiles/speed.dir/build

CMakeFiles/speed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/speed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/speed.dir/clean

CMakeFiles/speed.dir/depend:
	cd "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP" "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP" "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build" "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build" "/home/amgalan/Downloads/Telegram Desktop/ProjectAiP/build/CMakeFiles/speed.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/speed.dir/depend

