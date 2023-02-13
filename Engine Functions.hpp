#pragma once
#include <vector>

class Engine_Functions{
public:
	void Init();
	SDL_Window* Create_Window(const char* title);
	SDL_Renderer* Create_Renderer(SDL_Window* window);
	void Cleanup(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* array[]);
	SDL_Texture* Load_Texture(SDL_Renderer* renderer, const char* path);
	//std::vector<SDL_Texture*> Texture_List(SDL_Renderer* Renderer);
private:
};