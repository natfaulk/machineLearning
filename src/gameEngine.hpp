#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL2/SDL.h>
#include "baseClasses.hpp"
#include "character.hpp"
#include "platform.hpp"
#include "Constants.hpp"
#include <vector>

class GameEngine{
public:
  void setup(void);
  void cleanup(void);
  void render(void);
  void update(void);

  Character myChar;

private:
  std::vector<Platform> mPlatforms;
  SDL_Window *mSdlWindow;
  SDL_Renderer* mSdlRenderer;
};

#endif
