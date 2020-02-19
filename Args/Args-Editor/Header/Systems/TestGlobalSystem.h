#pragma once
#include <Args-Core.h>

using namespace std;

class TestGlobalSystem : public Args::GlobalSystem<TestGlobalSystem>
{
private:
	int testInt = 0;

public:
	TestGlobalSystem() : Args::GlobalSystem<TestGlobalSystem>() {}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);
	void Print(float deltaTime);
};
