#include "sceneRunner.hpp"

SceneRunner::SceneRunner()
{
}

SceneRunner::SceneRunner(std::shared_ptr<Scene> startScene)
{
	addScene(startScene);
}

SceneRunner::~SceneRunner()
{
}

void SceneRunner::addScene(std::shared_ptr<Scene> scene)
{
	m_sceneStack.push(scene);
}

void SceneRunner::start(sf::RenderWindow & window)
{
	while (m_sceneStack.size())
	{
		std::shared_ptr<Scene> curScene = m_sceneStack.top();
		if (!curScene) {
			m_sceneStack.pop();
			continue;
		}
		curScene->run(window);
		if (curScene->isDone())
			m_sceneStack.pop();
		m_sceneStack.push(curScene->getNextScene());
	}
}
