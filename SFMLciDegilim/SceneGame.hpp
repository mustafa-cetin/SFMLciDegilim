#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Scene.hpp"
#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_KeyboardMovement.hpp"
#include "ObjectCollection.hpp"
#include "C_Animation.hpp"

class SceneGame : public Scene {
public:
	SceneGame(WorkingDirectory& workingDir,ResourceAllocator<sf::Texture>& textureAllocator);

	void OnCreate() override;
	void OnDestroy() override;

	void ProcessInput() override;
	void Update(float deltaTime) override;
	void LateUpdate(float deltaTime) override;
	void Draw(Window& window) override;

private:
	ObjectCollection objects;

	WorkingDirectory& workingDir;
	ResourceAllocator<sf::Texture>& textureAllocator;
	Input input;
};


#endif // !SceneGame_hpp
