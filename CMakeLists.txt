cmake_minimum_required(VERSION 3.10)

# Set project name
project(Maze C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Define source and header directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Add all .c files from the src directory
file(GLOB SRC_FILES "${SRC_DIR}/*.c")

# Include directories
include_directories(${SRC_DIR} /usr/include/SDL2)

# Find SDL2
find_package(SDL2 REQUIRED)

# Specify the paths for SDL2_image and SDL2_ttf
set(SDL2_IMAGE_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_IMAGE_LIB "/usr/lib/x86_64-linux-gnu/libSDL2_image.so")
set(SDL2_TTF_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_TTF_LIB "/usr/lib/x86_64-linux-gnu/libSDL2_ttf.so")

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link the SDL2, SDL2_image, SDL2_ttf, and math libraries to your project
target_link_libraries(${PROJECT_NAME} 
    SDL2::SDL2 
    SDL2::SDL2main 
    ${SDL2_IMAGE_LIB} 
    ${SDL2_TTF_LIB}
    m  # Link the math library
)

# Include SDL2_image and SDL2_ttf header directories
include_directories(${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
link_directories(/usr/lib/x86_64-linux-gnu)
