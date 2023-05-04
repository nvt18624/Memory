#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include "GameState.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

class PlayState : public GameState {
public:
  ~PlayState() {}

  void update();
  void render();

  bool onEnter();
  bool onExit();
  std::string getStateID() const;

private:
  static const std::string stateID;
  void drawCard(int value, int x, int y, int width, int heigth,
                SDL_Renderer *renderer);
};

#endif
