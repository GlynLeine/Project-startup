#pragma once
#include "Shader.h"
#include <unordered_map>
#include <string>

namespace Args
{
	class Material
	{
	private:
		Shader* shader;
		
		static std::unordered_map<std::string, Material> materials;

	public:

		static Material* CreateMaterial(const std::string& name, Shader* shader);
		static Material* GetMaterial(const std::string& name);

		void Bind(Mesh* mesh) const;
		void Render(const std::vector<Matrix4>& instances, Mesh* mesh, Camera* camera) const;
		void Release(Mesh* mesh) const;
	};
}