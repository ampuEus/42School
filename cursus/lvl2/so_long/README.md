# [SoLong](https://www.youtube.com/watch?v=N_dUmDBfp6k)
***Officially finished at 2022-12-xx / Grade: xxx of 100 / Versión en [español](LEEME.md)***

This project is a small 2D game. It's designed to make you work with textures and sprites and some other basic gameplay elements. It will help you improve your skills in these areas: windows, colors, events, textures, etc.

The campus graphic library **MiniLibX** will be used. This library has been developed in-house and includes the basic tools needed to open a window, create images, and work with keyboard and mouse events.

## Table of contents
***TODO***

## Enunciado del ejercicio
  - The game
     - The objective is to collect all the objects on the map and leave following the shortest path possible.
     - The player can move in 4 directions: up, down, left and right.
     - The number of moves must be displayed in the terminal.
     - You have to use a 2D perspective.
     - The player cannot enter inside the walls.
   - Graphics Management
     - The program will display the image in a window.
     - The management of your window must be clean (change window, minimize, etc).
     - Pressing the ESC key or pressing the X in the window should close the window and the program.
     - The use of miniLibX images is mandatory
   - The map
     - It consists of 5 components (represented by ASCII characters):
       - Open space (0), Walls (1) and objects (C).
       - Exit from the map (E) and starting position of the player (P).
     - Mandatory that the map has at least one object, only one exit and one starting position.
     - Must be rectangular
     - Must be closed/surrounded by walls.
     - There must be a valid path to be able to collect the items and exit.

> In case of configuration failures of any kind found in the file, the program should terminate successfully and return “Error\n” followed by an explicit message of your choice.

## Bonuses
>The use of other functions to complete the extra part is allowed,
as long as its use is justified during the evaluation.

Extra points are earned if:
  - You make the player lose when he touches an enemy patrol.
  - Add some sprite animations.
  - You show the movement counter directly on the screen instead of in the terminal.


## References

---
Made by daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)
