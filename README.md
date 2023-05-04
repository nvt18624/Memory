[![Video demo](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://youtube.com/shorts/IVZt1hyKuTI?feature=share)

# Memory
This is a simple memory game created using C++ and SDL2 lib. The objective of the game is to match all the pairs of cards in the least number of moves and in the shortest amount of time possible.
## How to play
+ Click on any card to reveal the hidden image.
+ Click on another card to reveal the hidden image. If the two images match, they will stay face up. If they don't match, they will be flipped back over.
+ Repeat the above steps until all pairs are matched within the specified number of steps.
## Features
+ Randomly generated cards each time you play the game.
+ A timer to track the amount of time taken to complete the game.
+ A move counter to keep track of the number of moves made.
+ A pop-up modal that appears when the game is completed, displaying the time taken and the number of moves made.
## Prerequisites
+ SDL2 (https://www.libsdl.org/)
+ SDL2_image (https://www.libsdl.org/projects/SDL_image/)
+ SDL2_mixer (https://www.libsdl.org/projects/SDL_mixer/)
+ SDL2_ttf (https://www.libsdl.org/projects/SDL_ttf/)
### Linux
To install the prerequisites on Ubuntu, run the following commands in your terminal:
```
  sudo apt-get update
  sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
 ```
 ### macOS
 On macOS, you can use Homebrew to install these libraries.
 ```
 brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf
 ```
### Windows
On Windows, you can download the precompiled binaries for each library and install them manually. You can find the binaries on the respective library's website.
git clone
## Installation
To build and run the game, follow these steps:
+ Clone this repository to your local machine by running the following command in a terminal or command prompt: 
``` 
  git clone https://github.com/nvt18624/Memory.git 
```
+ Navigate to the Memory directory in a terminal or command prompt. Make sure you have installed all the prerequisites, then run the following command to build the game:
``` 
  make
  ```
+ Run the game by executing the following command:
```
  make run
  ```
## Contributions
Contributions to this project are welcome! If you'd like to contribute to this project, please follow these steps:
+ Fork this repository
+ Create a new branch (`git checkout -b feature/new-feature`).
+ Commit your changes (`git commit -am 'Added some new feature`).
+ Push to the branch (`git push origin feature/new-feature`).
+ Create a new Pull Request.
## Contact
+ Email: thiennguyen01052004@gmail.com
