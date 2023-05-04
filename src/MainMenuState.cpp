#include "MainMenuState.hpp"
#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "PlayState.hpp"
#include "TextureManager.hpp"
#include <iostream>

const std::string MainMenuState::stateID = "MAIN_MENU";

void MainMenuState::update() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
    GameStateMachine::Instance()->changeState(new PlayState());
  }
};

void MainMenuState::render() {
  TextureManager::Instance()->draw(
      "main_menu_background", 0, 0, Game::Instance()->getGameWidth(),
      Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());

  Game::Instance()->print("press enter to start", 800, 600, 100);
};

bool MainMenuState::onEnter() {
  std::cout << "Enter MainMenuState" << std::endl;
  return true;
};

bool MainMenuState::onExit() {
  std::cout << "Exit MainMenuState" << std::endl;
  return true;
};

std::string MainMenuState::getStateID() const { return stateID; };
