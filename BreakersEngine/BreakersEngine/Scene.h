#pragma once
#include "ObjectManager.h"
#include <memory>
#include "SceneState.h"

namespace BE
{
	/*!
	 * @brief Scene class for your scenes to inherit from
	 *
	 * Much like in unity engine scene in the Breakers Engine is a unique canvas to fill,
	 * every scene has its own ObjectManager, tag and SceneStateMachine
	 *
	 */
	class Scene
	{
		std::string tag{ "New scene" };

		SceneStateMachine stateMachine{ std::unique_ptr<Scene>(this), std::make_unique<SceneState>() };

	public:
		/*!
		 * @brief Get the scene name
		 *
		 * @return Scene name
		 */
		std::string getTag() { return tag; }
		/*!
		 * @brief ObjectManager of the scene
		 */
		std::unique_ptr<ObjectManager> objectManager;

		/*!
		 * @brief Initiate the scene
		 *
		 */
		virtual void initScene() { Logger::log(tag + " Init"); }
		/*!
		 * @brief Called when the scene is about to change
		 *
		 */
		virtual void onChangeScene() { Logger::log(tag + " SceneChange"); }
		/*!
		 * @brief Construct the scene with given tag
		 * @param tag_ - name of a scene
		 */
		Scene(std::string tag_);
		~Scene() {
			Logger::log(tag + " destroyed");
		}


	};

} //End namespace BE