#include "PauseState.hpp"
#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "TextureManager.hpp"
#include <SDL2/SDL_scancode.h>
#include <iostream>

const std::string PauseState::stateID = "PAUSE";

void PauseState::update() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
    GameStateMachine::Instance()->popState();
  }
};

void PauseState::render() {
  std::cout << "Pause state render" << std::endl;
  TextureManager::Instance()->draw(
      "pause_state_background", 0, 0, Game::Instance()->getGameWidth(),
      Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());
};

bool PauseState::onEnter() {
  std::cout << "Enter PauseState" << std::endl;
  return true;
};

bool PauseState::onExit() {
  std::cout << "Exit PauseState" << std::endl;
  return true;
};

std::string PauseState::getStateID() const { return stateID; };
