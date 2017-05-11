An example cross-platform CMake-based project.

This project uses SDL2 and OpenGL to render a spinning 3D logo to a desktop window. You can build it on Windows, MacOS or Linux.

![](http://preshing.com/images/cmakedemo-preview.png)

## Requirements

### Windows (Visual Studio)

CMakeDemo expects to find the SDL2 headers and libraries in a subfolder named `extern\SDL-2.0.5`. You can download and extract them automatically by running the Python 3 script `setup-win32.py`. If you don't have Python installed, [download and extract them by hand](https://www.libsdl.org/release/SDL2-devel-2.0.5-VC.zip).

On Windows, CMakeDemo uses its own OpenGL headers and loads `opengl32.dll` dynamically at runtime. Nothing else is needed at build time.

### MacOS (Xcode)

Install the SDL2 headers and libraries using [MacPorts](https://www.macports.org/).

    sudo port install libsdl2
    
OpenGL headers and libraries are installed by Xcode. CMake will find them automatically.

### Ubuntu

Install the SDL2 headers and libraries.

    sudo apt install libsdl2-dev
    
OpenGL headers and libraries are already present on the system. CMake will find them automatically.

## Build Instructions

For build instructions, see the blog post [How to Build a CMake-Based Project](http://preshing.com/20170511/how-to-build-a-cmake-based-project).
