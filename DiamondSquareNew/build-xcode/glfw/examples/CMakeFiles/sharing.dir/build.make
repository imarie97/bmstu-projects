# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mariakovega/Desktop/DiamondSquareNew

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode

# Include any dependencies generated for this target.
include glfw/examples/CMakeFiles/sharing.dir/depend.make

# Include the progress variables for this target.
include glfw/examples/CMakeFiles/sharing.dir/progress.make

# Include the compile flags for this target's objects.
include glfw/examples/CMakeFiles/sharing.dir/flags.make

glfw/examples/sharing.app/Contents/Resources/glfw.icns: ../glfw/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content glfw/examples/sharing.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/mariakovega/Desktop/DiamondSquareNew/glfw/examples/glfw.icns glfw/examples/sharing.app/Contents/Resources/glfw.icns

glfw/examples/CMakeFiles/sharing.dir/sharing.c.o: glfw/examples/CMakeFiles/sharing.dir/flags.make
glfw/examples/CMakeFiles/sharing.dir/sharing.c.o: ../glfw/examples/sharing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw/examples/CMakeFiles/sharing.dir/sharing.c.o"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/sharing.c.o   -c /Users/mariakovega/Desktop/DiamondSquareNew/glfw/examples/sharing.c

glfw/examples/CMakeFiles/sharing.dir/sharing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/sharing.c.i"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mariakovega/Desktop/DiamondSquareNew/glfw/examples/sharing.c > CMakeFiles/sharing.dir/sharing.c.i

glfw/examples/CMakeFiles/sharing.dir/sharing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/sharing.c.s"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mariakovega/Desktop/DiamondSquareNew/glfw/examples/sharing.c -o CMakeFiles/sharing.dir/sharing.c.s

glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.requires:

.PHONY : glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.requires

glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.provides: glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.requires
	$(MAKE) -f glfw/examples/CMakeFiles/sharing.dir/build.make glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.provides.build
.PHONY : glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.provides

glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.provides.build: glfw/examples/CMakeFiles/sharing.dir/sharing.c.o


glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o: glfw/examples/CMakeFiles/sharing.dir/flags.make
glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o: ../glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/__/deps/glad.c.o   -c /Users/mariakovega/Desktop/DiamondSquareNew/glfw/deps/glad.c

glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/__/deps/glad.c.i"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mariakovega/Desktop/DiamondSquareNew/glfw/deps/glad.c > CMakeFiles/sharing.dir/__/deps/glad.c.i

glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/__/deps/glad.c.s"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mariakovega/Desktop/DiamondSquareNew/glfw/deps/glad.c -o CMakeFiles/sharing.dir/__/deps/glad.c.s

glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.requires:

.PHONY : glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.requires

glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.provides: glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.requires
	$(MAKE) -f glfw/examples/CMakeFiles/sharing.dir/build.make glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.provides.build
.PHONY : glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.provides

glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.provides.build: glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o


# Object files for target sharing
sharing_OBJECTS = \
"CMakeFiles/sharing.dir/sharing.c.o" \
"CMakeFiles/sharing.dir/__/deps/glad.c.o"

# External object files for target sharing
sharing_EXTERNAL_OBJECTS =

glfw/examples/sharing.app/Contents/MacOS/sharing: glfw/examples/CMakeFiles/sharing.dir/sharing.c.o
glfw/examples/sharing.app/Contents/MacOS/sharing: glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o
glfw/examples/sharing.app/Contents/MacOS/sharing: glfw/examples/CMakeFiles/sharing.dir/build.make
glfw/examples/sharing.app/Contents/MacOS/sharing: glfw/src/libglfw3.a
glfw/examples/sharing.app/Contents/MacOS/sharing: glfw/examples/CMakeFiles/sharing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable sharing.app/Contents/MacOS/sharing"
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw/examples/CMakeFiles/sharing.dir/build: glfw/examples/sharing.app/Contents/MacOS/sharing
glfw/examples/CMakeFiles/sharing.dir/build: glfw/examples/sharing.app/Contents/Resources/glfw.icns

.PHONY : glfw/examples/CMakeFiles/sharing.dir/build

glfw/examples/CMakeFiles/sharing.dir/requires: glfw/examples/CMakeFiles/sharing.dir/sharing.c.o.requires
glfw/examples/CMakeFiles/sharing.dir/requires: glfw/examples/CMakeFiles/sharing.dir/__/deps/glad.c.o.requires

.PHONY : glfw/examples/CMakeFiles/sharing.dir/requires

glfw/examples/CMakeFiles/sharing.dir/clean:
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/sharing.dir/cmake_clean.cmake
.PHONY : glfw/examples/CMakeFiles/sharing.dir/clean

glfw/examples/CMakeFiles/sharing.dir/depend:
	cd /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mariakovega/Desktop/DiamondSquareNew /Users/mariakovega/Desktop/DiamondSquareNew/glfw/examples /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples /Users/mariakovega/Desktop/DiamondSquareNew/build-xcode/glfw/examples/CMakeFiles/sharing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw/examples/CMakeFiles/sharing.dir/depend

