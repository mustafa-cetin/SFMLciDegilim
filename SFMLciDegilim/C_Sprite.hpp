#ifndef C_Sprite_hpp
#define C_Sprite_hpp

#include "Component.hpp"
#include "ResourceAllocator.hpp"	

class C_Sprite : public Component
{
public:
	C_Sprite(Object* owner);

	void Load(int id);
	void Load(const std::string& path);

	void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

	void LateUpdate(float deltaTime) override;
	void Draw(Window& window) override;

	void SetTextureRect(int x, int y, int width, int height);
	void SetTextureRect(const sf::IntRect& rect);

private:
	ResourceAllocator<sf::Texture>* allocator;
	sf::Sprite sprite;
	
	int currentTextureID;

};

#endif // !C_Sprite_hpp
