#ifndef _ANIMATED_TEXTURE_H
#define _ANIMATED_TEXTURE_H
#include "Texture.h"
#include "Timer.h"

class AnimatedTexture : public Texture
{
public:

	enum WRAP_MODE {once = 0, loop = 1};
	enum ANIM_DIR {horizontal = 0, vertical = 1};

private:

	Timer* mTimer;

	int mStartx;
	int mStarty;

	float mAnimationTimer;
	float mAnimationSpeed;
	float mTimePerFrame;

	int mFrameCount;

	WRAP_MODE mWrapMode;
	ANIM_DIR mAnimationDirection;

	bool mAnimationDone;

public:

	AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDirection);
	~AnimatedTexture();

	void WrapMode(WRAP_MODE mode);

	void Update();
};

#endif
