#include "gameEngine.hpp"
#include <iostream>

GameEngine::GameEngine(){
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit (EXIT_FAILURE);
	}

  //Initialize SDL_ttf
  if( TTF_Init() == -1 ){
    std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
    exit (EXIT_FAILURE);
  }

	mSdlWindow = SDL_CreateWindow("Hello World!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mSdlWindow == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit (EXIT_FAILURE);
	}

	mSdlRenderer = SDL_CreateRenderer(mSdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mSdlRenderer == nullptr){
		SDL_DestroyWindow(mSdlWindow);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit (EXIT_FAILURE);
	}

  mHeightJumped = 0;
  mScoreText = new ScoreText;

  mPlatforms.push_back(Platform(GAME_WIDTH/2, -100, GAME_WIDTH));
  int tempyval = -100;
  while(tempyval<JUMPING_THRESHOLD_HEIGHT){
    tempyval += rand()%(MAX_PLATFORM_Y_SPACING - MIN_PLATFORM_Y_SPACING) + MIN_PLATFORM_Y_SPACING;
    mPlatforms.push_back(Platform(rand()%GAME_WIDTH, tempyval, PLATFORM_WIDTH));
  }
}

void GameEngine::cleanup(void){
  delete mScoreText;
  SDL_DestroyRenderer(mSdlRenderer);
	SDL_DestroyWindow(mSdlWindow);
  TTF_Quit();
	SDL_Quit();
}

void GameEngine::render(void){
  SDL_SetRenderDrawColor( mSdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear( mSdlRenderer );

  for(int i = 0; i<mPlatforms.size(); i++){
    mPlatforms.at(i).draw(mSdlRenderer, mHeightJumped);
  }

  myChar.draw(mSdlRenderer, mHeightJumped);
  mScoreText->draw(mSdlRenderer, mHeightJumped);

  //Update screen
  SDL_RenderPresent( mSdlRenderer );
}

void GameEngine::update(void){
  myChar.setVelocity(myChar.getXvelocity(),myChar.getYvelocity() - GRAVITY);
  double tempCharX = myChar.getXpos();
  double tempCharY = myChar.getYpos();
  myChar.move();

  for(int j = 0; j<mPlatforms.size(); j++){

    int tempDiffX = myChar.getXpos() - tempCharX;
    int tempDiffY = tempCharY - myChar.getYpos();
    if (tempDiffY!=0){
      for(int i = 0; i<=tempDiffY;i++){
        if(mPlatforms.at(j).checkCollision(tempCharX + i*tempDiffX/tempDiffY, tempCharY + i)){
          myChar.setVelocity(myChar.getXvelocity(), CHAR_JUMP_VELOCITY);
          myChar.setPos(tempCharX + i*tempDiffX/tempDiffY, tempCharY + i);
          break;
        }
      }
    }
  }

  if(myChar.getXpos()<0){
    myChar.setXpos(GAME_WIDTH);
  }
  if(myChar.getXpos()>GAME_WIDTH){
    myChar.setXpos(0);
  }

  if(myChar.getYpos() > mHeightJumped){
    mHeightJumped = myChar.getYpos();
  }

  if (myChar.getTransformedYpos(mHeightJumped) > GAME_HEIGHT){
    std::cout << "GAME_OVER" << std::endl;
    myChar.setPos(myChar.getXpos(), 100);
  }
}

void GameEngine::managePlatforms(void){
  std::cout << "Number of platforms: " << mPlatforms.size() << std::endl;
  // back undefined if vector empty. Shouldn't ever be empty but just incase...
  if(mPlatforms.size() == 0 || mPlatforms.back().getTransformedYpos(mHeightJumped)>=0){
    int newXpos = rand()%GAME_WIDTH;
    int newYpos = mHeightJumped + JUMPING_THRESHOLD_HEIGHT + rand()%(MAX_PLATFORM_Y_SPACING - MIN_PLATFORM_Y_SPACING) + MIN_PLATFORM_Y_SPACING;
    mPlatforms.push_back(Platform(newXpos, newYpos, PLATFORM_WIDTH));
  }
  if(mPlatforms.size() > 0 && mPlatforms.front().getTransformedYpos(mHeightJumped)>GAME_HEIGHT){
    mPlatforms.erase(mPlatforms.begin());
  }
}
