#pragma once
#include <Args-Core.h>
#include "Data/Mesh.h"
#include "Data/Material.h"

namespace Args
{
	class Renderer;

	struct Renderable : public Component<Renderable>
	{
		friend class Args::Renderer;
	private:
		Mesh* mesh;
		Material* material;

	public:
		Renderable(Entity* entity) : Component(entity), mesh(), material() {}

		void SetMaterial(const std::string& materialName);

		void SetMesh(const std::string& meshName);

		// Inherited via Component
		virtual std::string ObjectType() override;
		virtual bool SetData(const std::string& name, const std::string& value) override;
		virtual bool GetData(const std::string& name, std::string& value) override;
	};
}