#include "Scene.h"
#include "Resource/Components/Tag.h"

namespace Soarscape
{
	Scene::Scene()
	{
	}
	void Scene::renderTick()
	{
		
	}
	void Scene::initialize()
	{
	}
	SceneObject Scene::CreateObject(const std::string& name)
	{
		SceneObject entity = { m_Registry.create(), this};
		auto& Tag = entity.AddComponent<TagComponent>();
		Tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}
}
