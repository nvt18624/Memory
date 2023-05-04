#ifndef GAME_HPP
#define GAME_HPP

#include "GameStateMachine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

const int CARD_TYPES = 8;
const int card_padding = 25;
const int board_sizes = 4;

enum CardState { HIDDEN, SHOWING, SOLVED };
struct Card {
  int x, y;
  int value;
  CardState state;
};

class Game {
public:
  static Game *Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new Game();
      return s_pInstance;
    }

    return s_pInstance;
  }

  bool init(const char *title, int xpos, int ypos, int g_width, int g_height,
            bool fullscreen);

  Card board[board_sizes][board_sizes];
  int cnt;
  int cnt_win;
  int moves;
  uint lastTime;
  std::vector<Card *> v;
  void load();
  void createBoard();

  void render();
  void update();
  void handleEvents();
  void clean();

  SDL_Renderer *getRenderer() const { return m_pRenderer; }
  SDL_Window *getWindow() const { return m_pWindow; }

  bool running() { return m_bRunning; }
  void quit() { m_bRunning = false; }
  int getGameWidth() const { return m_gameWidth; }
  int getGameHeight() const { return m_gameHeight; }
  void print(const std::string &text, const int x, const int y, const int size);

private:
  Game();
  ~Game();
  Game(const Game &);
  Game &operator=(const Game &);

  TTF_Font *m_font;

  static Game *s_pInstance;
  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;

  bool m_bRunning;

  int m_gameWidth;
  int m_gameHeight;
};

#endif
