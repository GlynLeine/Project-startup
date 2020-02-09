#pragma once
#include "Serialization/Serializable.h"
#include "Utils/Common.h"

namespace Args
{
	struct IComponent : public ISerializable
	{
	protected:
		static uint32 componentTypeCount;
	public:
		const uint32 ownerID;
		const uint32 typeID;

		uint32 id;

		IComponent(uint32 entityId, uint32 typeId) : ownerID(entityId), typeID(typeId), id(0) {}
	};

	template<class Self>
	struct Component : public IComponent
	{
	public:
		static const std::string COMPONENT_TYPE;
		static const size_t COMPONENT_SIZE;
		static uint32 typeId;

		Component(uint32 entityId) : IComponent(entityId, typeId) {}

	protected:
	private:
	};

	template<class Self>
	const size_t Component<Self>::COMPONENT_SIZE(sizeof(Self));

	template<class Self>
	const std::string Component<Self>::COMPONENT_TYPE(GetTypeName<Self>());

	template<class Self>
	uint32 Component<Self>::typeId = componentTypeCount++;
}