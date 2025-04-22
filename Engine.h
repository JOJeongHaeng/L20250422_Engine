#pragma once

class UWorld;
class UInput;

class UEngine
{
public:
	UEngine();
	virtual ~UEngine();

	virtual void Initialize();
	virtual void Run();
	virtual void Terminate();
private:
	void Input();
	void Tick();
	void Render();	

	UWorld* World;
	UInput* InputDevice;

};

