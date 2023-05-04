#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "MainMenuState.hpp"
#include "SoundManager.h"
#include "TextureManager.hpp"
#include <SDL2/SDL_stdinc.h>
#include <iostream>

using namespace std;

Game *Game::s_pInstance = 0;

Game::Game()
    : m_pWindow(0), m_pRenderer(0), m_bRunning(false), cnt_win(0), cnt(0),
      lastTime(0), moves(12) {}

Game::~Game() {
  m_pRenderer = 0;
  m_pWindow = 0;
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags = 0;

  m_gameWidth = width;
  m_gameHeight = height;

  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    cout << "SDL init fail\n";
    return false;
  }

  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

  if (m_pWindow == 0) {
    cout << "window init fail\n";
    return false; // window init fail
  }

  cout << "window creation success\n";
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (m_pRenderer == 0) {
    cout << "renderer init fail\n";
    return false; // renderer init fail
  }
  load();
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

  TTF_Init();
  m_font = TTF_OpenFont("assets/monogram.ttf", 28);
  if (m_font == nullptr) {
    std::cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << std::endl;
    return false;
  }

  GameStateMachine::Instance()->changeState(new MainMenuState());

  m_bRunning = true;
  return true;
}

void Game::render() {
  SDL_RenderClear(m_pRenderer);

  GameStateMachine::Instance()->render();

  SDL_RenderPresent(m_pRenderer);
}

void Game::update() { GameStateMachine::Instance()->update(); }

void Game::handleEvents() { InputHandler::Instance()->update(); }

void Game::clean() {
  cout << "cleaning game\n";

  InputHandler::Instance()->clean();

  GameStateMachine::Instance()->clean();

  TextureManager::Instance()->clearTextureMap();

  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::createBoard() {
  const int card_width = 113;
  const int card_height = 150;
  int cardValues[CARD_TYPES];
  for (int i = 0; i < CARD_TYPES; i++) {
    cardValues[i] = i;
  }
  for (int i = 0; i < CARD_TYPES; i++) {
    int j = rand() % CARD_TYPES;
    int temp = cardValues[i];
    cardValues[i] = cardValues[j];
    cardValues[j] = temp;
  }
  std::vector<int> cardIndex = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7};
  srand(time(NULL));
  for (int i = 0; i < board_sizes; i++) {
    for (int j = 0; j < board_sizes; j++) {
      board[i][j].x =
          j * (card_width + card_padding) + 1250 / 2 - card_width * 2;
      board[i][j].y =
          i * (card_height + card_padding) + 800 / 2 - card_height * 2;
      int n = cardIndex.size();
      if (n != 0) {
        int randomIndex = rand() % n;
        board[i][j].value = cardValues[cardIndex[randomIndex] % CARD_TYPES];
        cardIndex.erase(cardIndex.begin() + randomIndex);
        board[i][j].state = HIDDEN;
      }
    }
  }
}

void Game::load() {
  TextureManager::Instance()->load("assets/main_menu.jpg", "main_menu_background",
                                   m_pRenderer);

  TextureManager::Instance()->load("assets/background.png",
                                   "play_state_background", m_pRenderer);

  TextureManager::Instance()->load("assets/image1.png",
                                   "pause_state_background", m_pRenderer);

  TextureManager::Instance()->load("assets/lose.png", "lose_state_background",
                                   m_pRenderer);

  TextureManager::Instance()->load("assets/win.png", "win_state_background",
                                   m_pRenderer);

  TextureManager::Instance()->load("assets/image1.png", "hidden", m_pRenderer);
  TextureManager::Instance()->load("assets/solved.jpeg", "solved", m_pRenderer);

  TextureManager::Instance()->load("assets/showing.jpeg", "showing",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing1.jpeg", "showing1",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing2.jpeg", "showing2",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing3.jpeg", "showing3",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing4.jpeg", "showing4",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing5.jpeg", "showing5",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing6.jpeg", "showing6",
                                   m_pRenderer);
  TextureManager::Instance()->load("assets/showing7.jpeg", "showing7",
                                   m_pRenderer);

  SoundManager::Instance()->load("assets/background.mp3", "background",
                                 SOUND_MUSIC);
  SoundManager::Instance()->playMusic("background", 99);
}

void Game::print(const std::string &text, const int x, const int y,
                 const int size) {

  if (m_font == nullptr) {
    return;
  }

  TTF_SetFontSize(m_font, size);

  SDL_Surface *pSurface =
      TTF_RenderText_Blended(m_font, text.c_str(), {255, 255, 255, 255});
  if (pSurface == nullptr) {
    return;
  }

  SDL_Texture *texture =
      SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), pSurface);

  if (texture == nullptr) {
    SDL_FreeSurface(pSurface);
    return;
  }

  SDL_Rect dest_rect = {x - pSurface->w / 2, y - pSurface->h / 2, pSurface->w,
                        pSurface->h};
  SDL_RenderCopy(Game::Instance()->getRenderer(), texture, nullptr, &dest_rect);

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(pSurface);
}
