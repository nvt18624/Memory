
#include "LoseState.hpp"
#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "PlayState.hpp"
#include "TextureManager.hpp"
#include <iostream>

const std::string LoseState::stateID = "LOSE_STATE";

void LoseState::update() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
    GameStateMachine::Instance()->changeState(new PlayState());
  }
};

void LoseState::render() {
  TextureManager::Instance()->draw(
      "lose_state_background", 0, 0, Game::Instance()->getGameWidth(),
      Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());

  Game::Instance()->print("Press enter to start", 800, 500, 100);
};

bool LoseState::onEnter() {
  std::cout << "Enter LoseState" << std::endl;
  return true;
};

bool LoseState::onExit() {
  std::cout << "Exit LoseState" << std::endl;
  return true;
};

std::string LoseState::getStateID() const { return stateID; };
