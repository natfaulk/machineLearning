#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL.h>
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
  bool gameOver(void);
  int getHeightJumped(void);

  // The window stuff should be moved out of game engine into another class
  // then this function can be removed. Currently here so debug can access the renderer
  SDL_Renderer* getRenderer();
  const std::vector<Platform>& getPlatforms(void);
  const Character& getCharacter(void);

  Character myChar;
  ScoreText* mScoreText;

private:
  std::vector<Platform> mPlatforms;
  SDL_Window *mSdlWindow;
  SDL_Renderer* mSdlRenderer;
  int mHeightJumped;
};

#endif
