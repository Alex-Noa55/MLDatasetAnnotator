/**
 * @file Annotator.cpp
 * @brief Implémentation de la classe Annotator.
 */

#include "Annotator.hpp"

Annotator::Annotator()
    : mIsDrawing(false),
      mCurrentAnnotation{0, 0, 0, 0}
{
}

void Annotator::HandleEvent(const SDL_Event& event)
{
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        mIsDrawing = true;
        mCurrentAnnotation.x = event.button.x;
        mCurrentAnnotation.y = event.button.y;
        mCurrentAnnotation.width = 0;
        mCurrentAnnotation.height = 0;
    }
    else if (event.type == SDL_EVENT_MOUSE_MOTION && mIsDrawing)
    {
        mCurrentAnnotation.width =
            event.motion.x - mCurrentAnnotation.x;
        mCurrentAnnotation.height =
            event.motion.y - mCurrentAnnotation.y;
    }
    else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
    {
        mIsDrawing = false;
    }
}

void Annotator::Update()
{
    // Réservé pour extensions futures
}

const Annotation& Annotator::GetAnnotation() const
{
    return mCurrentAnnotation;
}

bool Annotator::IsAnnotationComplete() const
{
    return !mIsDrawing;
}
