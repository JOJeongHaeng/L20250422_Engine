#include "Renderer.h"

URenderer* URenderer::Instance = nullptr;

URenderer::URenderer()
{
	ScreenHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CurrentScreenIndex = 0;
}

URenderer::~URenderer()
{
	CloseHandle(ScreenHandles[0]);
	CloseHandle(ScreenHandles[1]);
}

URenderer* URenderer::GetInstance()
{
	if (!Instance)
	{
		Instance = new URenderer();
	}

	return Instance;
}

void URenderer::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenHandles[CurrentScreenIndex], ' ', 100 * 40, COORD{ 0, 0 }, &DW);
}

void URenderer::Render(const FVector2D& Location, char Shape)
{
	char Shapes[2] = { Shape, '\0' };
	SetConsoleCursorPosition(ScreenHandles[CurrentScreenIndex], COORD{ (short)(Location.X), (short)(Location.Y) });

	WriteConsole(ScreenHandles[CurrentScreenIndex], Shapes, 1, NULL, NULL);
}

void URenderer::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenHandles[CurrentScreenIndex]);

	CurrentScreenIndex++;
	CurrentScreenIndex %= 2;
}
