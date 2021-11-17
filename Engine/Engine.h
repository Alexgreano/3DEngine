#pragma once

#define REGISTER_CLASS(class) nc::ObjectFactory::Instance().Register<class>(#class);

//#include "Graphics/ParticleSystem.h"
#include "Audio/AudioSystem.h"

//input
#include "Input/InputSystem.h"

//framework
#include "Framework/EventSystem.h"
#include "Resource/ResourceSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//core
#include "Core/Utilities.h"
#include "Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Serializable.h"

//math
#include "Math/Random.h"
#include "Math/MathUtilis.h"
#include "Math/Transform.h"
#include "Math/MathTypes.h"

//graphics
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"

//objects
#include "Object/Actor.h"
#include "Object/Scene.h"

#include <vector>
#include <memory>
#include <algorithm>

//component
#include "Component/PhysicsComponent.h"
#include "Component/AudioComponent.h"

#define NOMINMAX
//#include "core.h"


namespace nc {
	using ObjectFactory = Singleton<Factory<std::string, Object>>;

	class Engine {
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;
	};
	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems) {
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		return nullptr;
	}
}