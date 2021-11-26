# Space Shooter
Space Shooter is a 2d shooting game made with C++ and [SDL2](https://www.libsdl.org/)

## Compiling

Project depends on `SDL2` libs.

### On Windows

Download and unpack devel packages for [SDL2](https://www.libsdl.org/download-2.0.php), [SDL2_image](https://www.libsdl.org/projects/SDL_image/) and [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/).\
Set paths to them in `CMakeLists.txt`, see suggested placement in `/external`.\
Compile with CMake.

### On Linux

Install devel packages for `SDL2`, `SDL2_image` and `SDL2_ttf`.\
Compile with CMake