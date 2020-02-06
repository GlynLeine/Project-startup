#pragma once

#include <cinttypes>
#include <memory>
#include <string>

#include "Debug.h"

#define INHERITS_FROM(type, base_type) \
	typename = std::enable_if_t<std::is_base_of_v<base_type, type>>

#define CONCAT2(a, b) a ## b

#define CONCAT(a, b) CONCAT2(a, b)

#define TextureDir			std::string("assets/textures/")
#define MissingTextureDir	std::string("assets/textures/missing-texture.png")
#define FontDir				std::string("assets/fonts/")
#define SceneDir			std::string("assets/scenes/")
#define ObjectDir			std::string("assets/objects/")
#define DataDir				std::string("assets/data/")
#define AssetDir			std::string("assets/")

#define InvalidID 0

using uint = unsigned int;

using int8 = std::int8_t;
using int16 = std::int16_t;
using int32 = std::int32_t;
using int64 = std::int64_t;
using uint8 = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;

template<class OwnerType, typename ReturnType, typename ...Arguments>
using FuncPtr = ReturnType(OwnerType::*)(Arguments...);

template<class OwnerType>
using UpdateFunc = FuncPtr<OwnerType, void, float>;

template<class OwnerType>
using InitFunc = FuncPtr<OwnerType, void>;


template<typename T>
std::string GetTypeName()
{
	std::string typeName = typeid(T).name();
	size_t structToken;
	if (structToken = typeName.find("struct ") != std::string::npos)
		return typeName.substr(structToken + 6);
	else if (structToken = typeName.find("class ") != std::string::npos)
		return typeName.substr(structToken + 5);

	return "";
}

template<typename T>
std::string GetTypeName(T expr)
{
	std::string typeName = typeid(T).name();
	size_t structToken;
	if (structToken = typeName.find("struct ") != std::string::npos)
		return typeName.substr(structToken + 6);
	else if if (structToken = typeName.find("class ") != std::string::npos)
		return typeName.substr(structToken + 5);

	return "";
}