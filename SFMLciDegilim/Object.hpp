#ifndef Object_hpp
#define Object_hpp

#include "Window.hpp"
#include <vector>
#include "Component.hpp"

class Object
{
public:


	void Awake();

	void Start();


	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);



	template <typename T> std::shared_ptr<T> AddComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		for (auto& existingComponent : components)
		{
			if (std::dynamic_pointer_cast<T>(existingComponent))
			{
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}

		std::shared_ptr<T> newComponent = std::make_shared<T>(this);
		components.push_back(newComponent);

		return newComponent;
	};

	template <typename T> std::shared_ptr<T> GetComponent() {
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
		for (auto& existingComponent : components)
		{
			if (std::dynamic_pointer_cast<T>(existingComponent))
			{
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}
		return nullptr;
	};

private:
	std::vector<std::shared_ptr<Component>> components;
};


#endif // !Object_hpp
