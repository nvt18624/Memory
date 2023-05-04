#ifndef PAUSE_STATE_HPP
#define PAUSE_STATE_HPP

#include "GameState.hpp"
#include <string>
#include <vector>

class PauseState : public GameState {
public:
  ~PauseState() {}

  void update();
  void render();

  bool onEnter();
  bool onExit();
  std::string getStateID() const;

private:
  static const std::string stateID;
};

#endif
