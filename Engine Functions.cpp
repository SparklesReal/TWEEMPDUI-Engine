#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <array>
#include "Engine Functions.hpp"

void Engine_Functions::Init() {
	if (SDL_INIT_EVERYTHING == 0) {
		std::cout << "Failed to initialize everything, please report this error " << SDL_GetError() << std::endl;
		Engine_Functions::Cleanup(NULL, NULL, NULL);
	}
}

SDL_Window* Engine_Functions::Create_Window(const char* title) {
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, SDL_WINDOW_MAXIMIZED);
	if (window == nullptr) {
		std::cout << "Could not create a window, please report this error " << SDL_GetError() << std::endl;
		Engine_Functions::Cleanup(NULL, NULL, NULL);
	}
	return window;
}

SDL_Renderer* Engine_Functions::Create_Renderer(SDL_Window* window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "Could not create a renderer, please report this error " << SDL_GetError() << std::endl;
		Engine_Functions::Cleanup(NULL, NULL, NULL);
	}
	return renderer;
}

void Engine_Functions::Cleanup(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* array[]) {
	if (window != NULL){
		SDL_DestroyWindow(window);
	}
	if (renderer != NULL){
		SDL_DestroyRenderer(renderer);
	}
	if (array != NULL) {
		int array_size = sizeof(array) / sizeof(array[0]);
		for (int i = 0; i < array_size; i++) {
			SDL_DestroyTexture(array[i]);
		}
	}
	SDL_Quit();
}

SDL_Texture* Engine_Functions::Load_Texture(SDL_Renderer* renderer, const char* path) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, path);
	if (texture == NULL) {
		std::cout << "Could not load texture, please report this errror " << SDL_GetError() << std::endl;
	}
	return texture;
}