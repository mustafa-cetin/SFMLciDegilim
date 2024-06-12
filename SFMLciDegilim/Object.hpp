#ifndef Object_hpp
#define Object_hpp

#include "Window.hpp"

class Object
{
public:
	template <typename T> std::shared_ptr<T> AddComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		for ()
		{

		}

	};


	void Awake();

	void Start();


	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);
};


#endif // !Object_hpp
