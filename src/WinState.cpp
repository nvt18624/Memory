

#include "WinState.hpp"
#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "PlayState.hpp"
#include "TextureManager.hpp"
#include <iostream>

const std::string WinState::stateID = "WIN_STATE";

void WinState::update() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
    GameStateMachine::Instance()->changeState(new PlayState());
  }
};

void WinState::render() {
  TextureManager::Instance()->draw(
      "win_state_background", 0, 0, Game::Instance()->getGameWidth(),
      Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());

  Game::Instance()->print("Press enter to start", 800, 500, 100);
};

bool WinState::onEnter() {
  std::cout << "Enter WinState" << std::endl;
  return true;
};

bool WinState::onExit() {
  std::cout << "Exit WinState" << std::endl;
  return true;
};

std::string WinState::getStateID() const { return stateID; };
