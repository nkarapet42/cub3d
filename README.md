# cub3D

A Wolfenstein-style first-person renderer written in C with MiniLibX, built solo as part of the 42 curriculum.

## Features

- Raycasting with the DDA algorithm: one ray per screen column, wall distance correction, textured walls per side (N/S/E/W)
- `.cub` scene parser: texture paths, floor and ceiling colors, map grid
- Map validation: closed walls, one player start, allowed characters only, clear error messages
- Movement with wall collision, keyboard and mouse rotation
- Minimap overlay
- Doors that open and close
- Animated weapon sprite
- Memory cleanup on every exit path

## Build and run

macOS (the bundled MiniLibX uses OpenGL/AppKit):

```sh
make
./cub3d maps/simple.cub
```

## Controls

| Key | Action |
|---|---|
| W / S | Move forward / back |
| A / D | Strafe |
| ← / → or mouse | Rotate |
| E | Open / close door |
| M | Toggle minimap |
| Esc | Quit |

## Code layout

| File | Purpose |
|---|---|
| `ft_parsing.c`, `ft_validation*.c`, `ft_init_*.c` | Scene parsing and validation |
| `ft_raycasting.c`, `ft_algoritms.c` | Ray setup, DDA, wall distance |
| `ft_draw.c`, `ft_set_textures.c` | Texture sampling and drawing |
| `ft_move.c`, `ft_view.c` | Movement, collisions, rotation |
| `ft_minimap.c`, `ft_anim.c` | Minimap, weapon animation |
| `ft_free.c`, `ft_game_exit.c` | Cleanup |
