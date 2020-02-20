#pragma once
#include <Args-Core.h>

using namespace std;

class TestGlobalSystem : public Args::MonoUpdateSystem<TestGlobalSystem>
{
private:
	int testInt = 0;
	float accumDeltaTime = 0;
	int updatesSincePrint = 0;
	float elapsedTime = 0;

public:
	TestGlobalSystem() : Args::MonoUpdateSystem<TestGlobalSystem>() {}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);
	void Print(float deltaTime);
	void Shutdown(float deltaTime);

};
