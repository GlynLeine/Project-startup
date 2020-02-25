#include "Data/Material.h"

std::unordered_map<std::string, Args::Material>  Args::Material::materials;


Args::Material* Args::Material::CreateMaterial(const std::string& name, Shader* shader)
{
	if (shader == nullptr)
		return nullptr;

	materials[name].shader = shader;
	return &materials[name];
}

Args::Material* Args::Material::GetMaterial(const std::string& name)
{
	return &materials[name];
}
