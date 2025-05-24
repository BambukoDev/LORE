#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("L.O.R.E.", 800, 600, 0);
    if (window == NULL) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_FRect rect = {0, 0, 50, 50};

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.key.key == SDLK_ESCAPE || event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.key.down) {
                switch (event.key.key) {
                    case SDLK_W: {
                        rect.y -= 10;
                        break;
                    }
                    case SDLK_S: {
                        rect.y += 10;
                        break;
                    }
                    case SDLK_A: {
                        rect.x -= 10;
                        break;
                    }
                    case SDLK_D: {
                        rect.x += 10;
                        break;
                    }
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderPresent(renderer);
    }

    // quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
