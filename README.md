*This project has been created as part of the 42 curriculum by dajesus-, alexanfe, vinda-si*

# cub3D

A ray-casting engine in C inspired by Wolfenstein 3D. Renders a first-person 3D view of a maze from a `.cub` scene file using the MiniLibX library.

## Description

cub3D is a first-person 3D maze engine built in C from scratch, using ray-casting — the same technique behind Wolfenstein 3D. It takes a `.cub` scene file describing a 2D map, wall textures, and floor/ceiling colors, and renders a navigable perspective view in real time.

### Project Structure

```
cub3D/
├── src/
│   ├── main.c
│   ├── events/       # keyboard and window-close handlers
│   ├── init/         # framebuffer setup
│   ├── render/       # game loop / render callback
│   ├── player/       # movement, rotation, collision
│   └── parsing/      # .cub file parsing and validation
├── include/          # headers and structs
├── assets/textures/  # XPM wall textures
├── maps/             # example .cub scene files
├── tests/            # unit and integration tests
└── lib/
    ├── libft/
    └── minilibx-linux/
```
## Instructions

### Dependencies

#### Linux
- X11: `libX11-dev`, `libxext-dev`
- `gcc-10`, `make`

### Build & run

```sh
# Compilation
make

# Usage
./cub3D <`.cub` FILE>
```

### Controls

| Key | Action |
|---|---|
| `W` `A` `S` `D` | Move |
| `←` `→` | Rotate view |
| `ESC` / window close | Exit |



## Resources

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [permadi.com — Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [MiniLibX docs](https://harm-smits.github.io/42docs/libs/minilibx)

### AI usage

AI tools were used for scaffolding, debugging, and discussing algorithm design. All generated code was reviewed, understood, and validated by the team before being committed.
