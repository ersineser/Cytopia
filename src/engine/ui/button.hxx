#ifndef BUTTON_HXX_
#define BUTTON_HXX_

#include "uiElement.hxx"

class Button : public UiElement
{
public:
  Button(const SDL_Rect &uiElementRect, int uiSpriteID) : UiElement(uiElementRect, uiSpriteID){};
  Button(const SDL_Rect &uiElementRect, const std::string &text);

  ~Button() = default;

  virtual void draw();

private:
  SDL_Rect rect;

  bool _isPressed = false;
  bool _isMouseOver = false;
};

#endif