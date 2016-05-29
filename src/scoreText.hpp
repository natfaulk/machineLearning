#ifndef SCORE_TEXT_HPP
#define SCORE_TEXT_HPP

#ifdef __APPLE__
	#include <SDL2_ttf/SDL_ttf.h>
#elif __linux__
	#include <SDL2/SDL_ttf.h>
#else
#   error "Unknown compiler"
#endif

#include "baseClasses.hpp"
#include "Constants.hpp"

class ScoreText: public DrawableObject{
public:
  ScoreText();
  ~ScoreText();
  void draw(SDL_Renderer *ren, int heightJumped);
private:
  int mWidth;
  int mHeight;
  TTF_Font* mRobotoTTF;
  SDL_Surface* mSurfaceMessage;
  SDL_Texture* mMessage;
  SDL_Rect mMessageRect;
};

#endif
