# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guilherme/drive/research/ic-glauco/kuka-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guilherme/drive/research/ic-glauco/kuka-cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/kukacpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kukacpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kukacpp.dir/flags.make

CMakeFiles/kukacpp.dir/main.cpp.o: CMakeFiles/kukacpp.dir/flags.make
CMakeFiles/kukacpp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/drive/research/ic-glauco/kuka-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kukacpp.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kukacpp.dir/main.cpp.o -c /home/guilherme/drive/research/ic-glauco/kuka-cpp/main.cpp

CMakeFiles/kukacpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kukacpp.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/drive/research/ic-glauco/kuka-cpp/main.cpp > CMakeFiles/kukacpp.dir/main.cpp.i

CMakeFiles/kukacpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kukacpp.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/drive/research/ic-glauco/kuka-cpp/main.cpp -o CMakeFiles/kukacpp.dir/main.cpp.s

CMakeFiles/kukacpp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/kukacpp.dir/main.cpp.o.requires

CMakeFiles/kukacpp.dir/main.cpp.o.provides: CMakeFiles/kukacpp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/kukacpp.dir/build.make CMakeFiles/kukacpp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/kukacpp.dir/main.cpp.o.provides

CMakeFiles/kukacpp.dir/main.cpp.o.provides.build: CMakeFiles/kukacpp.dir/main.cpp.o


CMakeFiles/kukacpp.dir/udp_client_server.cpp.o: CMakeFiles/kukacpp.dir/flags.make
CMakeFiles/kukacpp.dir/udp_client_server.cpp.o: ../udp_client_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/drive/research/ic-glauco/kuka-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kukacpp.dir/udp_client_server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kukacpp.dir/udp_client_server.cpp.o -c /home/guilherme/drive/research/ic-glauco/kuka-cpp/udp_client_server.cpp

CMakeFiles/kukacpp.dir/udp_client_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kukacpp.dir/udp_client_server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/drive/research/ic-glauco/kuka-cpp/udp_client_server.cpp > CMakeFiles/kukacpp.dir/udp_client_server.cpp.i

CMakeFiles/kukacpp.dir/udp_client_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kukacpp.dir/udp_client_server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/drive/research/ic-glauco/kuka-cpp/udp_client_server.cpp -o CMakeFiles/kukacpp.dir/udp_client_server.cpp.s

CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.requires:

.PHONY : CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.requires

CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.provides: CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/kukacpp.dir/build.make CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.provides.build
.PHONY : CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.provides

CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.provides.build: CMakeFiles/kukacpp.dir/udp_client_server.cpp.o


CMakeFiles/kukacpp.dir/robotKuka.cpp.o: CMakeFiles/kukacpp.dir/flags.make
CMakeFiles/kukacpp.dir/robotKuka.cpp.o: ../robotKuka.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/drive/research/ic-glauco/kuka-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/kukacpp.dir/robotKuka.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kukacpp.dir/robotKuka.cpp.o -c /home/guilherme/drive/research/ic-glauco/kuka-cpp/robotKuka.cpp

CMakeFiles/kukacpp.dir/robotKuka.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kukacpp.dir/robotKuka.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guilherme/drive/research/ic-glauco/kuka-cpp/robotKuka.cpp > CMakeFiles/kukacpp.dir/robotKuka.cpp.i

CMakeFiles/kukacpp.dir/robotKuka.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kukacpp.dir/robotKuka.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guilherme/drive/research/ic-glauco/kuka-cpp/robotKuka.cpp -o CMakeFiles/kukacpp.dir/robotKuka.cpp.s

CMakeFiles/kukacpp.dir/robotKuka.cpp.o.requires:

.PHONY : CMakeFiles/kukacpp.dir/robotKuka.cpp.o.requires

CMakeFiles/kukacpp.dir/robotKuka.cpp.o.provides: CMakeFiles/kukacpp.dir/robotKuka.cpp.o.requires
	$(MAKE) -f CMakeFiles/kukacpp.dir/build.make CMakeFiles/kukacpp.dir/robotKuka.cpp.o.provides.build
.PHONY : CMakeFiles/kukacpp.dir/robotKuka.cpp.o.provides

CMakeFiles/kukacpp.dir/robotKuka.cpp.o.provides.build: CMakeFiles/kukacpp.dir/robotKuka.cpp.o


# Object files for target kukacpp
kukacpp_OBJECTS = \
"CMakeFiles/kukacpp.dir/main.cpp.o" \
"CMakeFiles/kukacpp.dir/udp_client_server.cpp.o" \
"CMakeFiles/kukacpp.dir/robotKuka.cpp.o"

# External object files for target kukacpp
kukacpp_EXTERNAL_OBJECTS =

kukacpp: CMakeFiles/kukacpp.dir/main.cpp.o
kukacpp: CMakeFiles/kukacpp.dir/udp_client_server.cpp.o
kukacpp: CMakeFiles/kukacpp.dir/robotKuka.cpp.o
kukacpp: CMakeFiles/kukacpp.dir/build.make
kukacpp: CMakeFiles/kukacpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guilherme/drive/research/ic-glauco/kuka-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable kukacpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kukacpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kukacpp.dir/build: kukacpp

.PHONY : CMakeFiles/kukacpp.dir/build

CMakeFiles/kukacpp.dir/requires: CMakeFiles/kukacpp.dir/main.cpp.o.requires
CMakeFiles/kukacpp.dir/requires: CMakeFiles/kukacpp.dir/udp_client_server.cpp.o.requires
CMakeFiles/kukacpp.dir/requires: CMakeFiles/kukacpp.dir/robotKuka.cpp.o.requires

.PHONY : CMakeFiles/kukacpp.dir/requires

CMakeFiles/kukacpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kukacpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kukacpp.dir/clean

CMakeFiles/kukacpp.dir/depend:
	cd /home/guilherme/drive/research/ic-glauco/kuka-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guilherme/drive/research/ic-glauco/kuka-cpp /home/guilherme/drive/research/ic-glauco/kuka-cpp /home/guilherme/drive/research/ic-glauco/kuka-cpp/build /home/guilherme/drive/research/ic-glauco/kuka-cpp/build /home/guilherme/drive/research/ic-glauco/kuka-cpp/build/CMakeFiles/kukacpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kukacpp.dir/depend
