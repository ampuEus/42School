# [SoLong](https://www.youtube.com/watch?v=N_dUmDBfp6k)
***Officially finished at 2023-10-24 / Grade: 125 of 100 / Versión en [español](LEEME.md)***

This project is a small 2D game. It's designed to make you work with textures and sprites and some other basic gameplay elements. It will help you improve your skills in these areas: windows, colors, events, textures, etc.

The campus graphic library **MiniLibX** will be used. This library has been developed in-house and includes the basic tools needed to open a window, create images, and work with keyboard and mouse events.

# TODO
INSERT GIF GAME
> Context: Based on the meme ["Bicho blanco"](https://www.youtube.com/watch?v=3FsFJ5a1k7I). You are Twelve, the Street Fighter character, at a Rave. You have to collect all the peaches and save your bro Q from being drunk.
>
> Note: Being a *being of light* as you are, flowers will sprout wherever you step.

## Table of contents
- [SoLong](#solong)
- [TODO](#todo)
  - [Table of contents](#table-of-contents)
  - [Excercise](#excercise)
  - [Bonuses](#bonuses)
  - [What is MiniLibX?](#what-is-minilibx)
    - [Useful functions for the project](#useful-functions-for-the-project)
  - [Steps that I have followed to make the program](#steps-that-i-have-followed-to-make-the-program)
    - [1. Error management](#1-error-management)
    - [2. Upload all necessary images](#2-upload-all-necessary-images)
    - [3. Show the map in a window](#3-show-the-map-in-a-window)
    - [4. Move the character](#4-move-the-character)
    - [5. Animate the sprites](#5-animate-the-sprites)
  - [References](#references)
  - [Annex: Tools for editing images](#annex-tools-for-editing-images)


## Excercise
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


## What is MiniLibX?
> For complete documentation go to [harm-smits](https://harm-smits.github.io/42docs/libs/minilibx) or [gontjarow](https://gontjarow.github.io/MiniLibX/).

MiniLibX is a basic graphics library that allows you to render things on the screen without any knowledge of [X-Window](https://www.x.org/wiki/) and [Cocoa](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/CocoaDrawingGuide/Introduction/Introduction.html). It allows you to create windows, provides a drawing and imaging tool and basic event management.

### Useful functions for the project
<table>
<thead>
   <tr>
     <th>Prototype</th>
     <th>Description</th>
     <th>Return</th>
   </tr>
</thead>
<tbody>
   <tr>
     <td><code>void *mlx_init()</code></td>
     <td>Starts the connection between the program and the PC screen.</td>
     <td>An identifier to identify future calls to library routines.</td>
   </tr>
   <tr>
     <td><code>void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)</code></td>
     <td>Creates a new window, defined in <code>mlx_ptr</code>. Give the dimensions <code>size_x</code> and <code>size_y</code> with the title <code>title</code> in the top bar of the window.</td>
     <td><br>Success creating window: <code>mlx_ptr != NULL</code></br>
         <br>Error creating window: <code>mlx_ptr = NULL</code></br></td>
   </tr>
   <tr>
     <td><code>int mlx_destroy_window(void *mlx_ptr, void *win_ptr)</code></td>
     <td>Close the window with the id <code>mlx_ptr<code>.</td>
     <td>For now they do not return anything.</td>
   </tr>
   <tr>
     <td><code>int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)</code></td>
     <td>Paints the image in the chosen window, at the selected coordinate</td>
     <td><br>Success: <code>img_ptr = NULL</code></br>
         <br>Error: <code>img_ptr != NULL</code></br></td>
   </tr>
   <tr>
     <td><code>void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)</code></td>
     <td>Saves a new image in memory.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_destroy_image(void *mlx_ptr, void *img_ptr)</code></td>
     <td>Deletes the indicated image from memory.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_loop(void *mlx_ptr)</code></td>
     <td>NECESSARY TO RECEIVE THE EVENTS. It is an infinite loop that waits for an event to call a user-defined function associated with this event.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)</code></td>
     <td>It is the generic function to "catch" the events and execute the associated function.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)</code></td>
     <td>Particular function for key events.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param)</code></td>
     <td>Particular function for the event when the user activates (focuses) the selected window.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)</code></td>
     <td>The associated function will be executed when no event occurs.</td>
     <td>-</td>
   </tr>
   <tr>
     <td><code>int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)</code></td>
     <td>Draws the specified text (with the desired color), starting at the specified coordinates.</td>
     <td>.</td>
   </tr>
</tbody>
</table>

Where:
   - `mlx_ptr` is the display identifier pointer
   - `win_ptr` is the window where it will be drawn
   - `img_ptr` is the image to draw

## Steps that I have followed to make the program
### 1. Error management
Basically 3 things have been proven:
   - That **the file exists**.
   - Has the **appropriate extension**, `.ber`.
   - That the **map meets** with **the requirements** set by the exercise.

To check the map, I read it using the `get_next_line` function and saved it in a `char **` variable within the data structure that I will use throughout the game.

### 2. Upload all necessary images
Using the `mlx_xpm_file_to_image` function, the images necessary for the graphical part of the game have been loaded. Each sprite has been located in its corresponding array waiting to be used in the different phases of the game.

> NOTE: Once the game is finished, remember to free the memory space used by these images using the `mlx_destroy_image` function.

### 3. Show the map in a window
Once the map and images have been dumped, the necessary dimensions of the game window have been calculated to be able to display it. Having initiated a connection with the display using `mlx_init` and created the window with `mlx_new_window`, the map has been painted with the basic textures (wall and floor) and obtained the initial positions of each item to be rendered later.

### 4. Move the character
To move the character, the `mlx_key_hook` function has been used, which executes a function every time the "input detected" event is activated. Afterwards, this function is responsible for calculating what the character's next action will be depending on the current state of the game and the square they want to go to.

### 5. Animate the sprites
To give "life" to the items, the `mlx_loop_hook` function has been used, which every X seconds executes the function that refresh the sprites of the buffer that has been loaded for each item.

## References
  - https://harm-smits.github.io/42docs/libs/minilibx.html
  - https://gontjarow.github.io/MiniLibX/

## Annex: Tools for editing images
   - [Basic online image editor](https://ezgif.com)
   - [To separate the gifs by frames](https://ezgif.com/split)
   - [Go from PNG to XPM](https://anyconv.com/png-to-xpm-converter/)

---
Made by daampuru | LinkedIn: [David Ampurua](https://www.linkedin.com/in/david-ampurua)
