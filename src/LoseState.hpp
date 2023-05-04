#ifndef LOSE_STATE_HPP
#define LOSE_STATE_HPP

#include "GameState.hpp"
#include <string>
#include <vector>

class LoseState : public GameState {
public:
  ~LoseState() {}

  void update();
  void render();

  bool onEnter();
  bool onExit();

  std::string getStateID() const;

private:
  static const std::string stateID;
};

#endif
