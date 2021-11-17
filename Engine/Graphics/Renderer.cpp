#include "Renderer.h"
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

namespace nc {


	void Renderer::Startup()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

		}
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
		TTF_Init();
		

	}

	void nc::Renderer::Shutdown()
	{
		IMG_Quit();
		TTF_Quit();
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	void nc::Renderer::Update(float dt)
	{
	}

	void nc::Renderer::Create(const std::string& name, int width, int height)
	{
		window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}

	void nc::Renderer::BegineFrame()
	{
		SDL_RenderClear(renderer);
	}

	void nc::Renderer::EndFrame()
	{
		SDL_RenderPresent(renderer);
	}
	
}