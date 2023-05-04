#include "PlayState.hpp"
#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "LoseState.hpp"
#include "PauseState.hpp"
#include "TextureManager.hpp"
#include "WinState.hpp"
#include <iostream>

const std::string PlayState::stateID = "PLAY";

void PlayState::update() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
    GameStateMachine::Instance()->pushState(new PauseState());
    return;
  }

  Vector2D *mousePos = InputHandler::Instance()->getMousePosition();
  const int card_width = 113;
  const int card_height = 150;

  for (int i = 0; i < board_sizes; i++) {
    for (int j = 0; j < board_sizes; j++) {
      Card &card = Game::Instance()->board[i][j];
      if (card.state == HIDDEN && mousePos->getX() >= card.x &&
          InputHandler::Instance()->getMouseButtonState(LEFT) &&
          mousePos->getX() >= card.x &&
          mousePos->getX() < card.x + card_width &&
          mousePos->getY() >= card.y &&
          mousePos->getY() < card.y + card_height) {
        card.state = SHOWING;
        Game::Instance()->v.push_back(&card);
        Game::Instance()->cnt += 1;
        if (Game::Instance()->cnt == 2)
          Game::Instance()->lastTime = SDL_GetTicks();
      }
    }
  }

  if (Game::Instance()->cnt == 2) {
    if (SDL_GetTicks() - Game::Instance()->lastTime > 350) {
      if (Game::Instance()->v[0]->value == Game::Instance()->v[1]->value) {
        Game::Instance()->v[0]->state = SOLVED;
        Game::Instance()->v[1]->state = SOLVED;
        Game::Instance()->cnt_win++;
        Game::Instance()->v.clear();
      } else {
        Game::Instance()->v[0]->state = HIDDEN;
        Game::Instance()->v[1]->state = HIDDEN;
        Game::Instance()->moves--;
        Game::Instance()->v.clear();
      }
      Game::Instance()->cnt = 0;
    }
  }

  if (Game::Instance()->moves == 0) {
    GameStateMachine::Instance()->changeState(new LoseState());
  }

  if (Game::Instance()->cnt_win == 8) {
    GameStateMachine::Instance()->changeState(new WinState());
  }
};

void PlayState::render() {
  TextureManager::Instance()->draw(
      "play_state_background", 0, 0, Game::Instance()->getGameWidth(),
      Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());

  const int card_width = 113;
  const int card_height = 150;
  for (int i = 0; i < board_sizes; i++) {
    for (int j = 0; j < board_sizes; j++) {
      Card &card = Game::Instance()->board[i][j];
      SDL_Rect cardRect = {card.x, card.y, card_width, card_height};

      switch (card.state) {
      case HIDDEN:
        TextureManager::Instance()->draw("hidden", card.x, card.y, card_width,
                                         card_height,
                                         Game::Instance()->getRenderer());
        break;
      case SHOWING:
        drawCard(Game::Instance()->board[i][j].value, card.x, card.y,
                 card_width, card_height, Game::Instance()->getRenderer());
        break;
      case SOLVED:
        break;
      }
    }
  }

  Game::Instance()->print("moves: " + std::to_string(Game::Instance()->moves),
                          100, 100, 50);
};

bool PlayState::onEnter() {
  std::cout << "Enter PlayState" << std::endl;
  Game::Instance()->createBoard();
  Game::Instance()->cnt_win = 0;
  Game::Instance()->moves = 12;
  return true;
};

bool PlayState::onExit() {
  std::cout << "Exit PlayState" << std::endl;
  return true;
};

std::string PlayState::getStateID() const { return stateID; };

void PlayState::drawCard(int value, int x, int y, int width, int height,
                         SDL_Renderer *renderer) {
  switch (value) {
  case 0:
    TextureManager::Instance()->draw("showing", x, y, width, height, renderer);
    break;

  case 1:
    TextureManager::Instance()->draw("showing1", x, y, width, height, renderer);
    break;

  case 2:
    TextureManager::Instance()->draw("showing2", x, y, width, height, renderer);
    break;

  case 3:
    TextureManager::Instance()->draw("showing3", x, y, width, height, renderer);
    break;

  case board_sizes:
    TextureManager::Instance()->draw("showing4", x, y, width, height, renderer);
    break;

  case 5:
    TextureManager::Instance()->draw("showing5", x, y, width, height, renderer);
    break;

  case 6:
    TextureManager::Instance()->draw("showing6", x, y, width, height, renderer);
    break;

  case 7:
    TextureManager::Instance()->draw("showing7", x, y, width, height, renderer);
    break;
  }
};
