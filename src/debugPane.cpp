#include "debugPane.hpp"

void DebugPane::draw(SDL_Renderer *ren){
  // X and Y positions are SCREEN_WIDTH - DEBUG_PANE_WIDTH etc in case other panes are added
  SDL_Rect backgroundRect = { SCREEN_WIDTH - DEBUG_PANE_WIDTH, SCREEN_HEIGHT - DEBUG_PANE_HEIGHT, DEBUG_PANE_WIDTH, DEBUG_PANE_HEIGHT };
  SDL_SetRenderDrawColor( ren, 0x00, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect( ren, &backgroundRect );
}
