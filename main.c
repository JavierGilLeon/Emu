#include<stdio.h>
#include <SDL3/SDL.h>

int main(void)
{
	int done = 0;

	if(!SDL_Init(SDL_INIT_VIDEO)) 
	{
		printf("Error al inicializar SDL");
		return -1;
	}
	SDL_Window* window = SDL_CreateWindow("Prueba",700, 500, SDL_WINDOW_FULLSCREEN);

	if(!window) 
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create a window: %s\n",SDL_GetError());
		return 1;
	}

	while(!done)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_EVENT_QUIT) done = 1;
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}



