#pragma once
#include <Args-Core.h>
#include "Data/Mesh.h"
#include "Data/Material.h"

namespace Args
{
	struct Renderable : public Component<Renderable>
	{
		Renderable(uint32 entityId) : Component(entityId) {}

		Mesh* mesh;
		Material material;

		// Inherited via Component
		virtual std::string ObjectType() override;
		virtual bool SetData(const std::string& name, const std::string& value) override;
		virtual bool GetData(const std::string& name, std::string& value) override;
	};
} 