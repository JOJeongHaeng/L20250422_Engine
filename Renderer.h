#pragma once
#include <Windows.h>
#include "Vector2D.h"

class URenderer
{
protected:
	URenderer();
	virtual ~URenderer();
	static URenderer* Instance;

	HANDLE ScreenHandles[2];
	int CurrentScreenIndex = 0;

public:
	static URenderer* GetInstance();

	void Clear();
	void Render(const FVector2D& Location, char Shape);
	void Flip();


};

