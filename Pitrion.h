
#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

namespace P3 {
    
    sf::Vector2i localPosition;
    sf::Vector2i PositionCursor;
    const int Pressed    = 68521;
    const int InArea     = 68522;
    const int ClearSize  = 0;
    const int On         = 1;

class Core {
    
public: 
};

class Button {
  bool inButton        = 0;
  bool PinButton       = 0;
  bool Custom          = 0;
  int    X             = 0;
  int    Y             = 0;
  int    We            = 0;
  int    He            = 0;
  int    GlobalSize    = 0;
  int    Pointer       = 0;

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
        We = pW;
        He  = pH;
    }
    
    void SetXY(int pX, int pY) {
        AreaB.setPosition(pX,pX);
        X = pX;
        Y = pY;
    }
    
    int IfButtonPressed() {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(localPosition.x > X && localPosition.x < We+X && localPosition.y > Y && localPosition.y  < He+Y )
                {
                    return 68521;
                }
            }
    return 0;
    }
    
    int IfinButtonArea() {
      if(PositionCursor.x > X && PositionCursor.x < We+X && PositionCursor.y > Y && PositionCursor.y < He+Y)
      {
        return 68522;
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
