# About

An attempt at some basic machine learning. Inspired by the Google Go AI that recently beat a human.

Doodle jump style jumping game

Switched from HTML/JS to c++ early on

Using SDL2 for rendering

Font taken from https://github.com/google/fonts/tree/master/apache/roboto
Download Roboto-Regular.ttf and put in the res folder

Potentially need this for sdl_ttf setup on osx http://www.cs.nyu.edu/courses/fall09/V22.0201-002/SDL_ttf_instructions.html

Currently only tested on OSX and on raspberry PI (runs very slowly on pi - due to software rendering I think)

# Progress
Basic game completed, VERY primitive AI implemented (randomly presses left and right), working on machine learning / neural network implementation

# Build instructions
## Linux

* Install the SDL2 library `sudo apt-get install libsdl2-dev` (Debian / Ubuntu derivatives)
* Install the SDL2 TTF library `sudo apt-get install libsdl2-ttf-dev`
* Download [Roboto-Regular.ttf](https://github.com/google/fonts/tree/master/apache/roboto) and put in the res folder
* Make and run the program
```
make
bin/ml
```
