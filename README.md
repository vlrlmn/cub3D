# cub3D

Cub3D is a 3D game rendering project inspired by classic raycasting games like Wolfenstein 3D. It combines mathematics, graphics, and robust error handling to deliver a comprehensive learning experience in computer graphics and game development.
This project is implemented using the `MiniLibX (MLX) library`, providing low-level graphic functionalities to draw and manipulate elements on the screen. While the primary focus is on implementing the raycasting algorithm for realistic wall rendering, significant emphasis is placed on parsing and validating input to ensure that the application handles edge cases effectively.

![cub3d](https://github.com/vlrlmn/cub3D/blob/main/img/screen.gif)

## 📜 Project Description

The project involves the following key components:
1. Graphics and Raycasting
A raycasting engine is used to render a 3D view of a 2D map in real time. Walls, textures, and player interactions are simulated to provide a first-person view experience.

2. Parsing and Validation
The application parses configuration files (.cub) to load the game map and other settings. It handles error detection for invalid configurations or corrupted files.

3. Testing and Edge Case Handling
The project includes various test cases to validate the robustness of input parsing and error reporting.

## 🗺️ Maps and Configuration
The repository includes several .cub map files located in the maps/ directory for testing purposes:
```bash
maps/valid.cub
```
This file contains a valid map configuration. It serves as the main example for a properly formatted input file that the program can load and render successfully. 

Files other than `valid.cub` are intentionally invalid configurations. These files are used to test the program's ability to detect and handle various errors, such as:
- Missing or misformatted map elements
- Invalid characters in the map
- Incorrect file structure

By focusing on rigorous testing, this project ensures that the parser is robust and capable of identifying edge cases.
## 💡 Features

- 2D to 3D rendering using raycasting.
- Textured walls for a realistic game environment.
- Player movement and rotation for interactive navigation.
- Robust input validation, detecting and handling invalid configurations gracefully.
- Edge case testing through a suite of .cub files.

## 🚀 How to Run

1. Clone the repository:
```bash
git clone https://github.com/vlrlmn/cub3D.git
cd cub3D
```

2. Build the project:
```bash
make
```

3. Run the program with a map file:
```bash
./cub3D maps/valid.cub
```

4. To test invalid cases, try other files in the maps/ directory:
```bash
./cub3D maps/map0.cub
```

🧪 Testing and Validation

The `maps/` directory is a core part of this project, `valid.cub` demonstrates a proper configuration.
Other .cub files test scenarios such as:
- Missing walls around the map
- Invalid characters in the map
- Incorrect formatting of texture paths or RGB values
