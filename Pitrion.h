
#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

namespace P3 {
    
    sf::Vector2i localPosition;
    sf::Vector2i PositionCursor;
    const int Pressed   = 68521;
    const int InArea     = 68522;
    const int UnPressed = 68523;
    const int ClearSize = 0;
    const int On           = 1;
    const int LOCK       = 10000;
    const int UNLOCK   = 10001;

class Core {
    
public: 
    
    
    
};


class Button {
  sf::Vector2i localClassPosition;
  sf::Vector2i localButtonSize;
  sf::Vector2i localButtonPosition;
  bool inButton          = 0;
  bool PinButton        = 0;
  bool Custom            = 0;
  bool access             = 0;
  bool access2           = 0;
  bool UnPressedPointer = 0;
  int    X                     = 0;
  int    Y                     = 0;
  int    We                  = 0;
  int    He                   = 0;
  int    GlobalSize       = 0;
  int    Pointer            = 0;
  int    Pointer2          = 0;
  


public:
      sf::RectangleShape AreaB;
      
    Button() {    
    }
    
    ~Button() {
    }
    
    void FillColor(int R, int G, int B) {
        AreaB.setFillColor(sf::Color(R,G, B));
    }
    
    void SetSize(int pW, int pH) {
        AreaB.setSize(sf::Vector2f(pW, pH));
        localButtonSize.x = pW;
        localButtonSize.y = pH;
        We = pW;
        He  = pH;
    }
    
    void SetXY(int pX, int pY) {
        AreaB.setPosition(pX,pX);
        localButtonPosition.x = pX;
        localButtonPosition.y = pY;
        X = pX;
        Y = pY;
    }
    
    void Access(int mode, int modefunction = 0) {
        
     if(modefunction == 0)
     {
        if(mode == LOCK) {
          access = 1;  
        }
        if(mode == UNLOCK) {
          access = 0;  
        }
     }
          if(modefunction == 1)
     {
        if(mode == LOCK) {
          access2 = 1;  
        }
        if(mode == UNLOCK) {
          access2 = 0;  
        }
     }
    }
    
    int IfButtonPressed() {
      if(access == 0) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(localPosition.x > X && localPosition.x < We+X && localPosition.y > Y && localPosition.y  < He+Y )
                {
                    UnPressedPointer = 1;
                    return Pressed;
                }
            }
      }
        return 0;
    }
    
    int IfButtonUnPressed() {
        if(access == 0) {
            if(UnPressedPointer == 1) {
                return UnPressed;
            }
        }
        return 0;
    }
    
    int IfinButtonArea() {
     if(access2 == 0) {
       if(PositionCursor.x > X && PositionCursor.x < We+X && PositionCursor.y > Y && PositionCursor.y < He+Y)
       {
         return InArea;
       }
      
     }
      return 0;
    }
    
    void AllotmentButton(int Size, int R, int G, int B, bool switchmode = 0)
    {
   if(switchmode == 1) {
        if(!(PositionCursor.x > X && PositionCursor.x < We+X && PositionCursor.y > Y && PositionCursor.y < He+Y))
        {
            AreaB.setOutlineThickness(ClearSize);
        }
                else
                {
                    AreaB.setOutlineThickness(Size);
                 }
            }
        else
        {
        AreaB.setOutlineThickness(Size);
        }
        AreaB.setOutlineColor(sf::Color(R,G,B));
    }
};

    
}
