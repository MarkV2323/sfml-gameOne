# sfml-gameOne
This repo is dedicated to creating one of my first "polished" games using SFML. I am working off Youtube lectures for inspiration.

## Build Guide
This is where I will place the final build instructions once the project is completed!

## UML Diagram
![UML Diagram](/docs/sfml-gameOne.png "")

## Requirements
The player shall have the following,
* Represented by a shape which is defined in a config file.
* Must spawn in the center of the screen.
* Can move in three directions with a speed, these all being
  defined inside of the config file.
* The player is confined to the bounds of the screen.
* Can shoot "bullets" towards the mouse upon a left click.
* Bullet speed, size and lifespan are defined in the config file.
* Some sort of special ability. This is not defined in the config file.

The enemies shall have the following,
* Must spawn in random locations on the screen every X frames, spawn 
  timer should be defined in the config file.
* Enemies shapes should have a random number of vertices, with the 
  min and max being defined in the config file.
* Enemies should be given a random color and speed upon spawning, the 
  speed min and max should be defined in the config file.
* Enemies should bounce off the bounds of the screen.
* Enemies that collide with bullets or player should be destroyed.
* Upon death, N small enemies should spawn in the same place with N
  being the number of vertices of the orginal entity.
* Baby enemies have the same color and verticies as the parent.
* Babies should travel out at angles equal to (360 / vertices).

Score shall have the following,
* Each time an enemy spawns, it's given a score component of N*100,
  where N is the number of vertices it has. Babies get double this.
* If a player kills an enemy, increase the score.
* Display the score in the top left with the font configured via
  the config file.

Drawing shall have the following,
* All entities should be given a slow rotation.
* Any entity with a life spawn should have its Color Alpha slowly
  changed until it dies.

Config file shall have the following,
* Allow configuration of window size, fullscreen and frame limit.
* Anything else from the above should be added to the config.

Anything else,
* The P key should pause the game.
* The ESC key should exit the game.