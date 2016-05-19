#include <iostream>
#include <SDL2/SDL.h>
#include "gameEngine.hpp"

GameEngine game;

int main(int, char**){
	game.setup();

	bool quit = false;
	SDL_Event e;



	game.myChar.setPos(100,100);
	game.myChar.setVelocity(0,1);

	while(!quit){
		//Handle events on queue
		 while( SDL_PollEvent( &e ) != 0 )
		 {
				 //User requests quit
				 if( e.type == SDL_QUIT )
				 {
						 quit = true;
				 }
		 }

		 game.myChar.move();

		 game.render();
	}


	game.cleanup();
	return 0;
}
