#include "ECS/Managers/ComponentManager.h"

std::unordered_map<std::string, std::unique_ptr<Args::IComponentFamily>> Args::ComponentManager::componentFamilies = std::unordered_map<std::string, std::unique_ptr<Args::IComponentFamily>>();
std::unordered_map<uint32, std::string> Args::ComponentManager::componentTypeIds = std::unordered_map<uint32, std::string>();
