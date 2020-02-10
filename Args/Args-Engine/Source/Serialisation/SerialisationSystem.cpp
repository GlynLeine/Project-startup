#include "Serialisation/SerialisationSystem.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"

using namespace rapidjson;

void SerialisationSystem::Init()
{

	Debug::Log(DebugInfo, "Init SerialisationSystem");
	Document document;
	document.Parse("{\"name\" : \"Rowan\",\"age\":19}");
	assert(document.HasMember("name"));
	assert(document.HasMember("age"));
	assert(document["name"].IsString());
	assert(document["age"].IsInt());
	Debug::Log(DebugInfo,document["name"].GetString());
	Debug::Log(DebugInfo, "%i", document["age"].GetInt());
}