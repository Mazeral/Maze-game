# Maze Game

### Created by Mohammad Omar Siddiq Ahmad

Welcome to the **Maze Game**! This game takes you through a thrilling maze where you must search for the exit. The project was built with SDL2, SDL2_image, and SDL2_ttf libraries, and is compliant with the Betty coding style.

---

## How to Play

- **Welcome Screen**: When the game starts, you'll be greeted with a welcome screen for 4 seconds.
- **Movement**:
  - `Up Arrow`: Move forward.
  - `Down Arrow`: Move backward.
  - `Left Arrow`: Tilt your vision to the left.
  - `Right Arrow`: Tilt your vision to the right.

Your goal is to navigate the maze and find the exit!

---

## Build Instructions

### Building the Project
1. Clone the repository or download the project.
2. Navigate to the project root.
3. Run the following command to create the executable in the `build` folder:
   ```bash
   ./create_maze
   ```
   The executable will be created in the `build` directory.

### Manual Build with GCC
To manually build the project using `gcc`, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -g -o Maze src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -lm
```

---

## Dependencies

The Maze Game requires the following libraries to be installed:

- **SDL2**
- **SDL2_image**
- **SDL2_ttf**

### Installation Instructions

#### On Linux

##### Ubuntu/Debian:
```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

##### Fedora:
```bash
sudo dnf install SDL2-devel SDL2_image-devel SDL2_ttf-devel
```

##### Arch Linux:
```bash
sudo pacman -S sdl2 sdl2_image sdl2_ttf
```

#### On Windows

1. Download the precompiled development libraries from:
   - [SDL2](https://libsdl.org/download-2.0.php)
   - [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
   - [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

2. Follow the SDL documentation for your development environment (e.g., Visual Studio) to add the necessary libraries and headers.

---

## Notes

- **Betty Compliance**: The project is fully compliant with the Betty coding style, ensuring clean and readable C code.
- **Debugging**: For debugging purposes, the `gcc` command includes the `-g` flag to include debugging information.

---

Enjoy navigating the maze and finding the exit!
