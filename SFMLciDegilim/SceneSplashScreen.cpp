#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneStateMachine, Window& window, ResourceAllocator<sf::Texture>& textureAllocator)
	: sceneStateMachine(sceneStateMachine), workingDir(workingDir),window(window),textureAllocator(textureAllocator),switchToState(0),currentSeconds(0.f),showForSeconds(3.f)
{

}

void SceneSplashScreen::OnCreate() {
	int textureID = textureAllocator.Add(workingDir.Get() + "goldenboy.jpg");
	if (textureID>=0)
	{
		std::shared_ptr<sf::Texture> splashTexture = textureAllocator.Get(textureID);
		splashSprite.setTexture(*splashTexture);

		sf::FloatRect spriteSize = splashSprite.getLocalBounds();

		splashSprite.setOrigin(spriteSize.width * .5f,
			spriteSize.height * .5f);
		splashSprite.setScale(.5f, .5f);

		sf::Vector2u windowCentre = window.GetCentre();

		splashSprite.setPosition(windowCentre.x, windowCentre.y);
	}

}

void SceneSplashScreen::OnActivate() {

	currentSeconds = 0.f;
}

void SceneSplashScreen::OnDestroy() {

}

void SceneSplashScreen::SetSwitchToScene(unsigned int id) {
	switchToState = id;
}

void SceneSplashScreen::Update(float deltaTime) {
	currentSeconds += deltaTime;
	if (currentSeconds>=showForSeconds)
	{
		sceneStateMachine.SwitchTo(switchToState);
	}
}

void SceneSplashScreen::Draw(Window& window) {
	window.Draw(splashSprite);
}
