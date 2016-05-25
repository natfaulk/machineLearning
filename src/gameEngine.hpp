#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL2/SDL.h>
#include "baseClasses.hpp"
#include "character.hpp"
#include "platform.hpp"
#include "Constants.hpp"
#include "scoreText.hpp"
#include <vector>

class GameEngine{
public:
  GameEngine();
  void cleanup(void); // move to a destructor function?
  void render(void);
  void update(void);
  void managePlatforms(void);

  Character myChar;
  ScoreText* mScoreText;

private:
  std::vector<Platform> mPlatforms;
  SDL_Window *mSdlWindow;
  SDL_Renderer* mSdlRenderer;
  int mHeightJumped;
};

#endif
