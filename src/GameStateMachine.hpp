#ifndef GAME_STATE_MACHINE_HPP
#define GAME_STATE_MACHINE_HPP

#include "GameState.hpp"
#include <vector>

class GameStateMachine {
public:
  static GameStateMachine *Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new GameStateMachine();
      return s_pInstance;
    }

    return s_pInstance;
  }

  void update();
  void render();

  void pushState(GameState *pState);
  void changeState(GameState *pState);
  void popState();

  void clean();

  std::vector<GameState *> &getGameStates() { return m_gameStates; }

private:
  GameStateMachine() {}
  ~GameStateMachine() {}
  GameStateMachine(const GameStateMachine &);
  GameStateMachine &operator=(const GameStateMachine &);

  static GameStateMachine *s_pInstance;
  std::vector<GameState *> m_gameStates;
};

#endif 
