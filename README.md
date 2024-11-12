# FdF 🌐

This project is a 3D wireframe renderer that visualizes 2D height maps in an isometric view. Built from scratch in C, **FdF** provides an interactive experience that brings flat maps to life through projection and basic transformations.

## Contents

- [Overview](#overview)
- [Installation](#installation)
- [How to Use](#how-to-use)
- [Features](#features)
- [Understanding Isometric Projection](#understanding-isometric-projection)
- [Author](#author)

## Overview

The **FdF** project, part of the [42 School](https://42.fr/) curriculum, is about understanding graphics programming by building a lightweight 3D renderer. Given a file with elevation data, **FdF** draws a wireframe of the corresponding landscape using isometric projection.

The main challenges tackled in this project are:
- Parsing data to generate a 3D model.
- Implementing an isometric projection algorithm.
- Building an interactive graphics window with basic controls.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/asut00/fdf.git
   cd fdf
   ```

2. **Compile the program**:
   ```bash
   make
   ```
   This command generates an executable `fdf` that can render a map from a specified file.

## How to Use

Run **FdF** with the path to a `.fdf` file containing height data. For example:

```bash
./fdf maps/42.fdf
```

This command opens a window displaying the 3D wireframe view of the specified map.

### Example Map File Format

The **.fdf** files are simple text files where each number represents the height at that point:

```plaintext
0  0  0  0  0
0  1  1  1  0
0  1  10 1  0
0  1  1  1  0
0  0  0  0  0
```

## Features

- **Isometric Projection**: Transforms 2D height maps into a 3D isometric view.
- **Adjustable Colors**: Dynamic color rendering based on hexadecimal values.
- **Responsive Rendering**: Smooth display updates with minimal lag.

## Understanding Isometric Projection

Isometric projection simulates 3D on a 2D plane by rotating the map along its axes and adjusting for perspective. **FdF** uses this method to produce a realistic 3D effect without requiring full 3D rendering. In this approach, points are rotated and scaled based on their height values to generate a perspective that appears 3D when viewed on a flat screen.

## Author

- GitHub: [@asut00](https://github.com/asut00)  
- 42 Intra: `asuteau`
