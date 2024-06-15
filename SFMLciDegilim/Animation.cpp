#include "Animation.hpp"

Animation::Animation() : frames(0), currentFrameIndex(0), currentFrameTime(0)
{

}

void Animation::AddFrame(int textureId, int x, int y, int width, int height, float frameTime)
{
	FrameData data;
	data.id = textureId;
	data.x = x;
	data.y = y;
	data.width = width;
	data.height = height;
	data.displayTimeSeconds = frameTime;
	frames.push_back(data);
}

const FrameData* Animation::GetCurrentFrame() const
{
	if (frames.size()>0)
	{
		return &frames[currentFrameIndex];
	}
	return nullptr;
}

bool Animation::UpdateFrame(float deltaTime)
{

}