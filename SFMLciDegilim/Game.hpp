#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"
#include "SceneStateMachine.hpp"
#include "SceneGame.hpp"
#include "SceneSplashScreen.hpp"

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

	SceneStateMachine sceneStateMachine;
};

#endif // !Game_hpp
