# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /Users/katy/MASLAB/vision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/katy/MASLAB/vision

# Include any dependencies generated for this target.
include CMakeFiles/filtergreen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/filtergreen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/filtergreen.dir/flags.make

CMakeFiles/filtergreen.dir/filtergreen.cpp.o: CMakeFiles/filtergreen.dir/flags.make
CMakeFiles/filtergreen.dir/filtergreen.cpp.o: filtergreen.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/katy/MASLAB/vision/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/filtergreen.dir/filtergreen.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/filtergreen.dir/filtergreen.cpp.o -c /Users/katy/MASLAB/vision/filtergreen.cpp

CMakeFiles/filtergreen.dir/filtergreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/filtergreen.dir/filtergreen.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/katy/MASLAB/vision/filtergreen.cpp > CMakeFiles/filtergreen.dir/filtergreen.cpp.i

CMakeFiles/filtergreen.dir/filtergreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/filtergreen.dir/filtergreen.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/katy/MASLAB/vision/filtergreen.cpp -o CMakeFiles/filtergreen.dir/filtergreen.cpp.s

CMakeFiles/filtergreen.dir/filtergreen.cpp.o.requires:
.PHONY : CMakeFiles/filtergreen.dir/filtergreen.cpp.o.requires

CMakeFiles/filtergreen.dir/filtergreen.cpp.o.provides: CMakeFiles/filtergreen.dir/filtergreen.cpp.o.requires
	$(MAKE) -f CMakeFiles/filtergreen.dir/build.make CMakeFiles/filtergreen.dir/filtergreen.cpp.o.provides.build
.PHONY : CMakeFiles/filtergreen.dir/filtergreen.cpp.o.provides

CMakeFiles/filtergreen.dir/filtergreen.cpp.o.provides.build: CMakeFiles/filtergreen.dir/filtergreen.cpp.o

# Object files for target filtergreen
filtergreen_OBJECTS = \
"CMakeFiles/filtergreen.dir/filtergreen.cpp.o"

# External object files for target filtergreen
filtergreen_EXTERNAL_OBJECTS =

filtergreen: CMakeFiles/filtergreen.dir/filtergreen.cpp.o
filtergreen: CMakeFiles/filtergreen.dir/build.make
filtergreen: /usr/local/lib/libopencv_videostab.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_video.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_ts.a
filtergreen: /usr/local/lib/libopencv_superres.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_stitching.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_photo.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_ocl.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_objdetect.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_nonfree.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_ml.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_legacy.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_imgproc.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_highgui.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_gpu.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_flann.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_features2d.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_core.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_contrib.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_calib3d.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_nonfree.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_ocl.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_gpu.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_photo.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_objdetect.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_legacy.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_video.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_ml.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_calib3d.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_features2d.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_highgui.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_imgproc.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_flann.2.4.10.dylib
filtergreen: /usr/local/lib/libopencv_core.2.4.10.dylib
filtergreen: CMakeFiles/filtergreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable filtergreen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filtergreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/filtergreen.dir/build: filtergreen
.PHONY : CMakeFiles/filtergreen.dir/build

CMakeFiles/filtergreen.dir/requires: CMakeFiles/filtergreen.dir/filtergreen.cpp.o.requires
.PHONY : CMakeFiles/filtergreen.dir/requires

CMakeFiles/filtergreen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/filtergreen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/filtergreen.dir/clean

CMakeFiles/filtergreen.dir/depend:
	cd /Users/katy/MASLAB/vision && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/katy/MASLAB/vision /Users/katy/MASLAB/vision /Users/katy/MASLAB/vision /Users/katy/MASLAB/vision /Users/katy/MASLAB/vision/CMakeFiles/filtergreen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/filtergreen.dir/depend
