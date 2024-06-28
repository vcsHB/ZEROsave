#pragma once
enum class SceneTypeEnum {
	Title,
	InGame,
	Exit
};

struct SceneState {
	bool IsProblem;
	bool IsExit;
	SceneTypeEnum NextScene;
};


