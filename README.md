# Pounce!

A single-player 2D platformer I built in C++ with OpenGL. You guide a bouncing
ball across floating platforms, collect coins, grab a super-coin that turns the
enemies edible, eat them, dodge a boss that chases you, and slip through the
door to the next level.

I originally wrote this as my Object-Oriented Programming semester project, so
the whole game is modelled with a small class hierarchy — the enemies and the
boss are specialised balls, the moving platform is a specialised platform, and
so on.

## Built with

- **C++** — the game logic and class hierarchy.
- **OpenGL** (immediate mode) — all the rendering, in a 2D orthographic
  projection so everything is positioned in pixel coordinates.
- **GLUT** — windowing, the input callbacks, and the timer that drives the
  frame loop.
- **SOIL** — loads the PNG menu and level artwork as textures.
- **Visual Studio** (MSVC, Win32) — the build. GLUT and SOIL are vendored under
  `third_party/`, so there's nothing extra to install.

## Features

- A menu-driven flow: main menu → level select → gameplay, plus a death screen.
- A ball with simple bounce/jump physics and screen-edge clamping.
- Static platforms and a horizontally patrolling moving platform.
- Coins to collect, and a super-coin that makes the enemies edible.
- Patrolling enemies that kill you on contact — until you power up and eat them.
- A boss on level 2 that tracks the player's position.
- Teleport doors and a next-level door that only opens once you've cleared the
  level's coins and enemies.

## Controls

| Key | Action |
| --- | --- |
| ← / → | Move the ball left / right |
| ↑ | Jump |
| Mouse click | Select menu items |
| Esc | Quit |

## Screenshots

> Drop gameplay screenshots in here, e.g. `![Main menu](assets/Game Menu Main.png)`.

## Getting started

### Prerequisites

- Windows with **Visual Studio** and the *Desktop development with C++* workload.
- The build targets **Win32 (x86)**; GLUT and SOIL are included under
  `third_party/`, so no extra SDKs are required.

### Build and run

1. Open `Pounce.sln` in Visual Studio.
2. If prompted, retarget the project to your installed platform toolset and
   Windows SDK (the solution was authored against the v120 toolset).
3. Select the **Debug | x86** configuration and build.
4. Run from Visual Studio. The project sets its working directory to the project
   root so the `assets/` textures load. If you launch the executable directly,
   run it from the project root and make sure `glut32.dll` sits next to it (the
   build copies it into the output folder for you).

## Project structure

```
Pounce-Game/
├── src/
│   └── main.cpp          # the whole game: classes, game loop, GLUT callbacks
├── assets/               # menu and level artwork loaded at runtime
├── third_party/          # vendored GLUT and SOIL headers, libs, and glut32.dll
├── Pounce.sln            # Visual Studio solution
├── Pounce.vcxproj        # project (Win32, links SOIL + GLUT/OpenGL)
├── .clang-format         # formatting style for the source
└── LICENSE
```

## What I learned

This was where object-oriented design finally clicked for me. Modelling the
enemies and the boss as subclasses of the ball, and reusing the same collision
and drawing code through that hierarchy, made the gameplay much easier to extend
than my earlier procedural attempts. It was also my first time wiring up a real
render/update loop — handling input, timing, and drawing on a GLUT timer rather
than a blocking `main`.

## Acknowledgements

- Texture loading uses the [SOIL](https://www.lonesock.net/soil.html) library.

## License

Released under the [MIT License](LICENSE).
