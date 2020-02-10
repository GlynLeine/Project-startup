#include "Serialisation/SerialisationSystem.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"

using namespace rapidjson;

void SerialisationSystem::Init()
{
	//Document document;
	//document.Parse("{'name': 'Rowan','age':19}");
	//assert(document.HasMember("name"));
	//assert(document["name"].IsString());
	//printf("name = %s\n", document["name"].GetString());
	Debug::Log(DebugInfo, "Init SerialisationSystem");
}