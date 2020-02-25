#pragma once
#include "Shader.h"
#include <unordered_map>
#include <string>

namespace Args
{
	class Material;

	class IMaterialParameter
	{
	protected:
		std::string name;
	public:
		IMaterialParameter(const std::string& name) : name(name) {}

		virtual void Apply(Shader* shader) = 0;

		static IMaterialParameter* CreateParam(std::pair<std::string, GLenum> info);
	};

	template<typename T>
	class MaterialParameter : public IMaterialParameter
	{
	private:
		T value;
	public:
		MaterialParameter(const std::string& name) : IMaterialParameter(name) {}

		void SetValue(const T& value) { this->value = value; }
		const T& GetValue() const { return value; }

		virtual void Apply(Shader* shader) override
		{
			shader->GetUniform<T>(name)->SetValue(value);
		}
	};

	class MaterialTexture : public IMaterialParameter
	{
	private:
		const Texture* texture;
	public:
		MaterialTexture(const std::string& name) : IMaterialParameter(name) {}

		void SetTexture(const Texture* texture) { this->texture = texture; }
		const Texture* GetTexture() const { return texture; }

		// Inherited via IMaterialParameter
		virtual void Apply(Shader* shader) override
		{
			shader->GetSampler(name)->SetTexture(texture);
		}
	};

	class Material
	{
	private:
		Shader* shader;

		static std::unordered_map<std::string, Material> materials;

		void Init(Shader* shader);

		std::unordered_map<std::string, IMaterialParameter*> parameters;
		std::unordered_map<std::string, MaterialTexture*> textures;
	public:
		static Material* CreateMaterial(const std::string& name, Shader* shader);
		static Material* GetMaterial(const std::string& name);

		template<typename T>
		void SetParam(const std::string& name, const T& value)
		{
			dynamic_cast<MaterialParameter<T>*>(parameters[name])->SetValue(value);
		}

		void SetTexture(const std::string& name, const Texture* texture);

		void Bind(Mesh* mesh) const;
		void Render(const std::vector<Matrix4>& instances, Mesh* mesh, Camera* camera) const;
		void Release(Mesh* mesh) const;
	};
}