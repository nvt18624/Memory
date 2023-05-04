#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameState.hpp"
#include <string>
#include <vector>

class MainMenuState : public GameState {
public:
  ~MainMenuState() {}

  void update();
  void render();

  bool onEnter();
  bool onExit();

  std::string getStateID() const;

private:
  static const std::string stateID;
};

#endif
