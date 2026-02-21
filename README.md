*This project has been created as part of the 42 curriculum by bcausseq, salabbe.*

# cub3D

## Overview

**cub3D** is a 3D graphics project developed at the 42 School.  
The objective is to implement a basic 3D rendering engine using the **raycasting** technique, inspired by early first-person games such as Wolfenstein 3D.

The program takes a 2D map as input and renders a first-person perspective view in real time.  
It simulates depth, wall textures, and player movement using mathematical calculations rather than a true 3D engine.

This project focuses on:

- Understanding raycasting and projection principles  
- Implementing a rendering pipeline in C  
- Managing textures and colors  
- Handling user input and real-time events  
- Ensuring robust parsing and memory management  

---

## Project Goals

The main objectives of cub3D are:

- Parse and validate a `.cub` configuration file  
- Render textured walls depending on orientation (North, South, East, West)  
- Display customizable floor and ceiling colors  
- Implement smooth player movement and camera rotation  
- Detect and prevent wall collisions  
- Manage graphical window events properly  
- Maintain clean and leak-free memory management  

---

## How It Works

The engine uses the **Digital Differential Analyzer (DDA)** algorithm to cast rays from the player's position.  

For each vertical stripe of the screen:

1. A ray is projected into the 2D map.
2. The engine calculates where it hits a wall.
3. The distance to the wall determines the height of the rendered slice.
4. The correct texture is selected based on wall orientation.
5. The textured vertical slice is drawn to the screen.

This creates a real-time pseudo-3D effect from a purely 2D map.

---

## Compilation

To compile the project:

```bash
$> make

$> make bonus
```

This generates the executable:
```./cub3D
```
To use with ``*.cub`` maps

## Controls
**W** — Move forward

**S** — Move backward

**A** — Strafe left

**D** — Strafe right

**Left Arrow** — Rotate camera left

**Right Arrow** — Rotate camera right

**ESC** — Exit the program

## ``.cub`` File Structure

A valid .cub file must contain:

1. Texture paths
``NO ./textures/north.jpg``
``SO ./textures/south.jpg``
``WE ./textures/west.jpg``
``EA ./textures/east.jpg``

2. Floor and ceiling colors
``F 220,100,0``
``C 225,30,0``

3. The map layout
``111111\n100001
100N01
100001
111111
``

### Rules:

The map must be completely enclosed by walls (1)

Only one player starting position is allowed (N, S, E, or W)

Empty spaces must be properly handled

Invalid configurations must trigger an error

## References

Wolfenstein 3D — Historical inspiration

Lode Vandevenne — Raycasting Tutorial
https://lodev.org/cgtutor/raycasting.html

MacroLibX documentation (42 Angouleme own Minilibx)

Trigonometry and vector mathematics resources

Youtube Video (3DSage)
https://youtu.be/gYRrGTC7GtA?si=_EGTegxmG_gGa2cl

## AI Usage

Artificial intelligence tools were used to:

Clarify mathematical concepts behind raycasting

Assist with debugging logical errors

Improve documentation structure and clarity

All implementation details were written, tested, and validated manually to ensure full understanding and compliance with project requirements.
