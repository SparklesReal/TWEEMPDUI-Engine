#include <SDL.h>
#include <iostream>
#include <vector> 
#include "Engine Functions.hpp"

/*Todo:
* Renderer, Done ig
* Texture Loader. Done, may be changed to another file in the future
* Entity Handeler
* Game Loop, Done ig
*/

int main(int argc, char* args[]) {
	const char GameName[] = "Top Secrete";

	Engine_Functions Engine_Functions;
	Engine_Functions.Init();
	SDL_Window* Game_Window = Engine_Functions.Create_Window(GameName);
	SDL_Renderer* Game_Renderer = Engine_Functions.Create_Renderer(Game_Window);
	
	SDL_Texture* Texture_List[] = {
		Engine_Functions.Load_Texture(Game_Renderer, "res/textures/menu_PlayButton.png"),
		Engine_Functions.Load_Texture(Game_Renderer, "res/textures/Light_Panel/State0.png")
	};

	int Texture_List_Size = sizeof(Texture_List) / sizeof(Texture_List[0]);
	for (int i = 0; i < Texture_List_Size; i++) {
		if (Texture_List[i] = NULL) {
			std::cout << "Texture " << i << " failed to load. Please report this " << SDL_GetError << std::endl;
			Engine_Functions.Cleanup(Game_Window, Game_Renderer, Texture_List);
		}
	} //move to engine functions

	SDL_Event event; 
	SDL_PollEvent(&event);

	bool running = true;
	while (running) {
		if (SDL_WaitEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
		/* for (Entity& e : entities2) {
			window.render(e);
		} */
		SDL_RenderClear(Game_Renderer);
	}

	Engine_Functions.Cleanup(Game_Window, Game_Renderer, Texture_List);
	return 1;
}