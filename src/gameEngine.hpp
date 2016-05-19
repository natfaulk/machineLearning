#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL2/SDL.h>
#include "baseClasses.hpp"
#include "character.hpp"
#include <vector>

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

class GameEngine{
public:
  void setup(void);
  void cleanup(void);
  void render(void);

  Character myChar;



private:
  std::vector<std::unique_ptr<DrawableObject>> mDrawableObjects;
  SDL_Window *mSdlWindow;
  SDL_Renderer* mSdlRenderer;
};

#endif
