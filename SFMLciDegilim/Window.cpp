#include "Window.hpp"

Window::Window(const std::string& windowName) : window(sf::VideoMode(800,600),windowName,sf::Style::Titlebar){
	window.setVerticalSyncEnabled(true);
}