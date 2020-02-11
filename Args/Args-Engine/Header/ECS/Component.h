#pragma once
#include "Serialisation/Serialisable.h"
#include "Utils/Common.h"

namespace Args
{
	struct IComponent : public ISerialisable
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
		static const std::string componentName;
		static uint32 typeId;

		Component(uint32 entityId) : IComponent(entityId, typeId) {}

	protected:
	private:
	};

	struct IGlobalComponent : public ISerialisable
	{
	public:
		const uint32 typeID;

		uint32 id;

		IGlobalComponent(uint32 typeId) : typeID(typeId), id(0) {}
	};


	template<class Self>
	struct GlobalComponent : public IGlobalComponent
	{
	public:
		static const std::string componentName;
		static uint32 typeId;

		GlobalComponent() : IGlobalComponent(typeId) {}

	protected:
	private:
	};

	template<class Self>
	const std::string GlobalComponent<Self>::componentName(GetTypeName<Self>());

	template<class Self>
	uint32 GlobalComponent<Self>::typeId = 0;

	template<class Self>
	const std::string Component<Self>::componentName(GetTypeName<Self>());

	template<class Self>
	uint32 Component<Self>::typeId = componentTypeCount++;
}