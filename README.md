# MiniRT - Ray Tracing Project in C

## Introduction
MiniRT (mini Ray Tracer) is a simple ray tracing engine developed in C. This project is an introduction to the beautiful world of ray tracing, allowing you to render simple Computer-Generated Images (CGIs).

## Features
- Basic ray tracing capabilities.
- Implementation using C language adhering to the Norm.
- Creation of simple 3D scenes with basic geometric objects (planes, spheres, cylinders).
- Implementation of basic lighting models, including ambient and diffuse lighting.
- Handling of different camera views and scene configurations.
- Management of window and image rendering using miniLibX.

## Requirements
- Your project must compile with `-Wall -Wextra -Werror`.
- Proper memory management, no memory leaks.
- Usage of miniLibX library for graphical output.
- Program must handle errors gracefully and exit properly in case of incorrect configurations.
- Basic geometric objects: plane, sphere, and cylinder.
- Light and camera setup as per specifications.

## Installation and Usage
- Compile the project using the provided Makefile.
- Run `./miniRT <scene_file.rt>` to render a scene.
- Scene files must follow the specified `.rt` format.

## Scene File Format
- The `.rt` file format specifies the scene setup, including camera, lighting, and objects.
- The format follows a strict order and structure, which is detailed in the project specifications.

## Bonus Features (If Implemented)
- Advanced lighting models (Phong, specular reflection).
- Additional geometric objects (cones, paraboloids).
- Complex effects like reflections, textures, or bump mapping.

## Development and Testing
- Extensively test with different scenes and configurations.
- Ensure compatibility with different systems and miniLibX versions.

## Made by...

[salee2](https://github.com/hleesa)

[gychoi](https://github.com/sideseal)
