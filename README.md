# MineClone

This is a minecraft clone.

---

## 🚀 Getting Started

### Prerequisites

- C++17 or higher
- CMake (3.10+)
- MinGW or MSVC (on Windows)
- GLFW, Glad, GLM (included in `external/` or install separately)

## Building

### 1. Set your environment variables so as to direct cmake to use GCC

Run this in the shell
$env:CC="C:\ProgramData\mingw64\mingw64\bin\gcc.exe"
$env:CXX="C:\ProgramData\mingw64\mingw64\bin\g++.exe"

### 2. Generate the CMAKE files

cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_C_COMPILER="C:/ProgramData/mingw64/mingw64/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/ProgramData/mingw64/mingw64/bin/g++.exe"

### 3. Build the project

cmake --build build

## Steps to take in the project

📌 Development Roadmap
✅ Current Progress

Project setup with CMake

GLFW window creation

Glad integration for OpenGL

Compiles and runs 🎉

🛠️ Next Steps

1. **Game Loop**

Create a while (!glfwWindowShouldClose(window)) { … } loop.

Handle input with glfwPollEvents().

Clear the screen and swap buffers.

2. **OpenGL Setup**

Set background color with glClearColor.

Enable depth testing (glEnable(GL_DEPTH_TEST)).

Render a simple test shape.

3. **Shaders**

Write and compile a vertex shader + fragment shader.

Pass a triangle through them.

4. **Cube Rendering**

Define cube vertices (positions + UVs).

Use VAOs/VBOs to draw a 3D cube.

Render with your shader.

5. **Camera**

Implement free-look camera (glm::lookAt).

Move with WASD, rotate with mouse.

6. **Chunk System**

Store blocks in a 3D array (chunk[16][256][16]).

Render only visible faces for efficiency.

Start with dirt/stone cubes.

7. **Input Handling**

Keyboard & mouse controls for moving.

Place/remove blocks like Minecraft.

📦 Useful Libraries

GLM
→ Math (matrices, vectors).

stb_image
→ Texture loading.

FastNoiseLite
→ Procedural terrain generation.

Dear ImGui
→ Debug UI (optional).

🗺️ Long-Term Goals

World generation (Perlin/Noise-based terrain)

Block types & textures

Lighting system

Save/load worlds

Basic player mechanics (jumping, breaking, placing blocks)
