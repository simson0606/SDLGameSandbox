#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDirection)
	: Texture(filename, x, y, w, h)
{
	mTimer = Timer::Instance();

	mStartx = x;
	mStarty = y;

	mFrameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimePerFrame = mAnimationSpeed / mFrameCount;
	mAnimationTimer = 0.0f;

	mAnimationDirection = animationDirection;

	mAnimationDone = false;

	mWrapMode = loop;
}

AnimatedTexture::~AnimatedTexture()
{
	
}

void AnimatedTexture::WrapMode(WRAP_MODE mode)
{
	mWrapMode = mode;
}

void AnimatedTexture::Update()
{
	if (!mAnimationDone)
	{
		mAnimationTimer += mTimer->DeltaTime();

		if (mAnimationTimer >= mAnimationSpeed)
		{
			if (mWrapMode == loop)
			{
				mAnimationTimer -= mAnimationSpeed;
			}
			else
			{
				mAnimationDone = true;
				mAnimationTimer = mAnimationSpeed - mTimePerFrame;
			}
		}

		if (mAnimationDirection == horizontal)
		{
			mClippedRect.x = mStartx + int(mAnimationTimer / mTimePerFrame) * mWidth;
		}
		else
		{
			mClippedRect.y = mStarty + int(mAnimationTimer / mTimePerFrame) * mHeight;
		}
	}
}



