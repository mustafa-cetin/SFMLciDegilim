﻿#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

struct FrameData
{
	int id;
	int x;
	int y;
	int width;
	int height;
	float displayTimeSeconds;
};

class Animation
{
public:
	Animation();

	void AddFrame(int textureId, int x, int y, int width, int height, float frameTime);

	const FrameData* GetCurrentFrame() const;

	bool UpdateFrame(float deltaTime);

	void Reset();
private:
	void IncrementFrame();
	
	std::vector<FrameData> frames;

	int currentFrameIndex;

	float currentFrameTime;
};



#endif // !Animation_hpp
