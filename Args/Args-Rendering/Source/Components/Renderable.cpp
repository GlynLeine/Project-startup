#include "Components/Renderable.h"

void Args::Renderable::SetMaterial(const std::string& materialName)
{
	material = Material::GetMaterial(materialName);
	if (material == NULL)
	{
		Debug::Log(DebugInfo, "THE MATERIAL IS NULL");
	}
}

void Args::Renderable::SetMaterial(Material &mat)
{
	material = &mat;
	if (material == NULL)
	{
		Debug::Log(DebugInfo, "THE MATERIAL IS NULL");
	}
}

void Args::Renderable::SetMesh(const std::string& meshName)
{
	mesh = Mesh::GetMesh(meshName);
	if (mesh == NULL)
	{
		Debug::Log(DebugInfo,"THE MESH IS NULL");
	}
}

std::string Args::Renderable::ObjectType()
{
	return Args::GetTypeName<Renderable>();
}

bool Args::Renderable::SetData(const std::string& name, const std::string& value)
{
	return false;
}

bool Args::Renderable::GetData(const std::string& name, std::string& value)
{
	return false;
}
