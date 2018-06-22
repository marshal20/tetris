#pragma once
#include "scene.hpp"
#include <memory>
#include <stack>

class SceneRunner
{
public:
	SceneRunner();
	SceneRunner(std::shared_ptr<Scene> startScene);
	~SceneRunner();

	void addScene(std::shared_ptr<Scene> scene);
	void start(sf::RenderWindow& window);

private:
	std::stack<std::shared_ptr<Scene>> m_sceneStack;
};
