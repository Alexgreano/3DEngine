#pragma once
#include <string>
#include <filesystem>
#include <SDL_log.h>

namespace nc {
	void SetFilePath(const std::string& pathname);
	bool ReadFileToString(const std::string& filename, std::string& filestring);
	std::string GetFilePath();
}