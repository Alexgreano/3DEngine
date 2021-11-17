#pragma once
#include "Framework/System.h"
#include "Texture.h"
#include "Math/MathTypes.h"
#include "Math/MathUtilis.h"
#include <SDL.h>
#include <string>

namespace nc {
	class Renderer : public System {
	public:
		virtual void Startup() override;
		virtual void Shutdown() override;
		virtual void Update(float dt) override;

		void Create(const std::string& name, int width, int height);
		void BegineFrame();
		void EndFrame();

		friend class Texture;

	private:
		SDL_Renderer* renderer{ nullptr };
		SDL_Window* window{ nullptr };

	};
}