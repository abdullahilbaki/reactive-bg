#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_RGB_VALUE 255

Uint8 randColor() { return rand() % (MAX_RGB_VALUE + 1); }

int main(int argc, char **argv) {
  Uint8 r = 30, g = 30, b = 30;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Click or press key to change color",
                                        800, 600, SDL_WINDOW_RESIZABLE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        running = false;

      if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
          event.type == SDL_EVENT_KEY_DOWN) {
        r = randColor();
        g = randColor();
        b = randColor();
      }
    }

    SDL_SetRenderDrawColor(renderer, r, g, b, MAX_RGB_VALUE);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
