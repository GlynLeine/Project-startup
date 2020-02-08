#include "Serialization/SerializationSystem.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
using namespace rapidjson;
void SerializationSystem::Init()
{
	GetComponents(testComponentA, testComponentB);
	Document document;
	document.Parse("{'name': 'Rowan','age':19}");
	assert(document.HasMember("name"));
	assert(document["name"].IsString());
	printf("name = %s\n", document["name"].GetString());
}

void SerializationSystem::Start()
{
	testInt = 0;
}