# 2048 C++ - Linux Version

This version of 2048 puzzle is the same game from
apple/google store "2048 puzzle" but made in C++.

**C++ version author:** John

## Features

✅ Full tile movement in all 4 directions (WASD)
✅ Proper tile merging when identical numbers collide
✅ Random tile spawning (90% chance for 2, 10% chance for 4)
✅ 4x4 grid gameplay

## How to Compile

```bash
g++ -o 2048 cpp2048.cpp
```

## How to Play

Run the compiled executable:
```bash
./2048
```

**Controls:**
- `w` - Move tiles up
- `s` - Move tiles down
- `a` - Move tiles left
- `d` - Move tiles right

**Objective:**
Slide tiles in four directions to combine matching numbers. When two tiles with the same number collide, they merge into one tile with their sum (e.g., 2 + 2 = 4, 8 + 8 = 16). Try to create a tile with the value 2048!

## Game Mechanics

- After each move, a new tile (2 or 4) appears in a random empty position
- Tiles slide as far as possible in the chosen direction
- Adjacent tiles with the same value merge when they collide
- Only one merge happens per tile per move

## Updates

### Version 1.0 (Complete)
- ✅ Fixed tile merging algorithm with proper 3-step process:
  - Compact tiles to remove gaps
  - Merge adjacent equal tiles (prevents double-merging)
  - Compact again after merging
- ✅ Fixed random tile placement to cover entire 4x4 grid
- ✅ Added 10% probability for spawning 4 tiles

### beta 0.5
- Basic tile movement functionality
- Grid display and user input handling
