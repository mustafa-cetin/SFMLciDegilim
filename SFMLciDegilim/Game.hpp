#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"

class Game
{
public:
	Game();

	void Update();
	void LateUpdate();
	void Draw();
	void CalculateDeltaTime();
	void CaptureInput();
	bool IsRunning() const;
private:
	sf::Clock clock;
	float deltaTime;
	Window window;
	WorkingDirectory workingDir;
	Input input;

	sf::Texture vikingTexture;
	sf::Sprite vikingSprite;
};

#endif // !Game_hpp
