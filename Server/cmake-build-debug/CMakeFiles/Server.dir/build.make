# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/121/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/121/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/main.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Server.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/main.c.o   -c /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/main.c

CMakeFiles/Server.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/main.c > CMakeFiles/Server.dir/main.c.i

CMakeFiles/Server.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/main.c -o CMakeFiles/Server.dir/main.c.s

CMakeFiles/Server.dir/Json.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Json.c.o: ../Json.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Server.dir/Json.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Server.dir/Json.c.o   -c /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/Json.c

CMakeFiles/Server.dir/Json.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server.dir/Json.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/Json.c > CMakeFiles/Server.dir/Json.c.i

CMakeFiles/Server.dir/Json.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server.dir/Json.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/Json.c -o CMakeFiles/Server.dir/Json.c.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/main.c.o" \
"CMakeFiles/Server.dir/Json.c.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/main.c.o
Server: CMakeFiles/Server.dir/Json.c.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug /home/danium/Documents/TEC/Lenguajes/paCEmanServer/Server/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

