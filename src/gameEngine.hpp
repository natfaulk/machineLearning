#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL2/SDL.h>
#include "baseClasses.hpp"
#include "character.hpp"
#include "platform.hpp"
#include <vector>

const int SCREEN_WIDTH  = 400;
const int SCREEN_HEIGHT = 600;
const double GRAVITY = 0.5;

class GameEngine{
public:
  void setup(void);
  void cleanup(void);
  void render(void);
  void update(void);

  Character myChar;
  Platform ground;



private:
  std::vector<std::unique_ptr<DrawableObject>> mDrawableObjects;
  SDL_Window *mSdlWindow;
  SDL_Renderer* mSdlRenderer;
};

#endif
