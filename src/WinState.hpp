
#ifndef WIN_STATE_HPP
#define WIN_STATE_HPP

#include "GameState.hpp"
#include <string>
#include <vector>

class WinState : public GameState {
public:
  ~WinState() {}

  void update();
  void render();

  bool onEnter();
  bool onExit();

  std::string getStateID() const;

private:
  static const std::string stateID;
};

#endif
