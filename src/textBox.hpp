#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#ifdef __APPLE__
	#include <SDL2_ttf/SDL_ttf.h>
#elif __linux__
	#include <SDL2/SDL_ttf.h>
#else
#   error "Unknown compiler"
#endif

#include <string>

class TextBox{
public:
	TextBox();
  TextBox(double xpos, double ypos);
  ~TextBox();
  void draw(SDL_Renderer *ren);
	void updateText(std::string text);
	void setColour(SDL_Color textColor);
	void setXpos(double xpos);
  void setYpos(double ypos);
private:
	void init(void);
	double mXpos;
	double mYpos;
  TTF_Font* mRobotoTTF;
  SDL_Surface* mMessageSurface;
  SDL_Texture* mMessageTexture;
  SDL_Rect mMessageRect;
	std::string mText;
	SDL_Color mTextColor;
};

#endif
