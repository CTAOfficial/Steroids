#pragma once
#include <map>
#include <string>
#include "../Entities/Object.h"

class Assets {
private:
	static std::map<std::string, Object*> assets;

	//static bool AddAsset(std::string path, Object* asset);
	static void CheckFolder(std::string path);

public:
	static void Load(std::string root);

	//static bool Add(std::string path);
	//template<class Object>
	//static Object* Get(std::string path);
};