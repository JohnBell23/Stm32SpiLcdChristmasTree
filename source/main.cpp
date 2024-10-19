/*
 * main.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: jb23
 */

#include "main.h"
#include "St7735Adapter.h"

extern "C" void cpp_main();

# define t true
# define f false

void cpp_main(void)
{

  ST7735Adapter::St7735Adapter screen;
  screen.init(0xFF, 0xFF, 0xFF);
  screen.setDrawingColor(0x00, 0x00, 0x00);

//  screen.drawCoordSystem(true);
//  screen.drawSine(true);
//  screen.drawCosine(true);

//  screen.drawLine(
//  { 0, 0 },
//  { 120, 50 });

//  screen.drawCircle(
//  { 20, 20 }, 10);
//  screen.drawCircle(
//  { 100, 20 }, 10);
//  screen.drawCircle(
//  { 20, 100 }, 10);
//  screen.drawCircle(
//  { 100, 100 }, 10);

//  bool matrix[MATRIX_LENGTH][MATRIX_LENGTH] =
//  {
//  { f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f }, // leer
//  { f, t, t, t, t, t, t, t, f, t, t, t, f, t, f, f, t, t, f, t, f, f, f, t, t, t, t, t, t, t, f }, // 1
//  { f, t, f, f, f, f, f, t, f, t, f, t, f, f, t, f, f, f, t, f, f, f, f, t, f, f, f, f, f, t, f }, // 2
//  { f, t, f, t, t, t, f, t, f, t, f, t, f, t, t, f, f, t, f, f, f, f, f, t, f, t, t, t, f, t, f }, // 3
//  { f, t, f, t, t, t, f, t, f, f, t, t, f, f, f, f, t, t, t, t, t, t, f, t, f, t, t, t, f, t, f }, // 4
//  { f, t, f, t, t, t, f, t, f, f, f, t, t, f, t, f, f, t, t, t, t, t, f, t, f, t, t, t, f, t, f }, // 5
//  { f, t, f, f, f, f, f, t, f, t, f, f, f, t, f, f, f, t, t, f, f, t, f, t, f, f, f, f, f, t, f }, // 6
//  { f, t, t, t, t, t, t, t, f, t, f, t, f, t, f, t, f, t, f, t, f, t, f, t, t, t, t, t, t, t, f }, // 7
//  { f, f, f, f, f, f, f, f, f, t, f, t, f, t, t, f, f, f, t, t, t, t, f, f, f, f, f, f, f, f, f }, // 8
//  { f, f, f, t, t, t, f, t, f, t, t, t, t, t, f, t, f, f, f, f, f, f, t, t, t, f, f, t, t, t, f }, // 9
//  { f, f, f, t, f, t, t, f, t, t, t, f, f, f, t, t, f, t, f, t, t, t, f, t, t, t, t, f, f, t, f }, // 10
//  { f, t, t, t, f, t, f, t, f, f, f, t, t, f, t, t, t, f, f, f, f, t, t, t, f, t, t, f, f, f, f }, // 11
//  { f, t, t, f, t, f, f, f, f, f, f, t, t, f, f, f, f, t, f, f, t, f, t, t, t, t, t, f, t, f, f }, // 12
//  { f, f, f, f, f, t, f, t, t, t, f, f, t, t, f, f, f, t, f, f, f, t, t, f, t, f, t, t, t, t, f }, // 13
//  { f, f, t, f, f, f, t, f, t, t, f, f, f, f, f, t, f, f, t, t, t, t, t, t, f, t, t, f, t, t, f }, // 14
//  { f, f, t, f, t, t, t, t, f, t, f, f, t, f, t, f, t, f, t, t, f, t, f, f, t, f, f, f, f, f, f }, // 15
//  { f, f, f, f, f, t, f, f, f, f, t, t, t, f, f, f, f, f, f, t, t, t, t, f, f, t, t, f, t, t, f }, // 16
//  { f, f, t, t, f, t, f, t, f, t, t, f, t, f, f, f, f, t, f, t, f, f, t, f, t, f, t, t, f, t, f }, // 17
//  { f, t, f, f, t, t, f, f, f, t, f, t, t, f, t, f, f, f, f, f, t, t, f, t, t, t, t, f, t, t, f }, // 18
//  { f, t, f, t, t, f, f, t, f, t, t, f, t, t, f, f, f, f, f, f, f, f, f, t, t, t, t, f, f, f, f }, // 19
//  { f, t, f, t, t, f, t, f, t, t, t, f, t, f, f, f, t, f, t, f, t, t, f, t, f, t, t, f, f, t, f }, // 20
//  { f, t, f, t, t, f, t, t, t, f, t, f, f, t, f, f, f, f, t, f, t, t, t, t, t, t, f, t, f, f, f }, // 21
//  { f, f, f, f, f, f, f, f, f, t, t, t, t, t, f, t, t, f, t, f, t, t, f, f, f, t, t, f, t, t, f }, // 22
//  { f, t, t, t, t, t, t, t, f, f, f, t, f, t, f, t, f, t, f, f, t, t, f, t, f, t, f, f, f, f, f }, // 23
//  { f, t, f, f, f, f, f, t, f, f, f, t, t, t, t, t, t, t, f, f, t, t, f, f, f, t, t, f, t, t, f }, // 24
//  { f, t, f, t, t, t, f, t, f, t, t, f, f, f, t, f, t, f, t, t, f, t, t, t, t, t, t, t, f, t, f }, // 25
//  { f, t, f, t, t, t, f, t, f, t, t, f, t, f, f, f, f, t, t, t, t, t, t, f, t, f, t, t, f, f, f }, // 26
//  { f, t, f, t, t, t, f, t, f, t, t, f, t, t, t, t, t, t, f, f, t, t, t, t, t, t, t, f, t, f, f }, // 27
//  { f, t, f, f, f, f, f, t, f, f, f, t, t, t, t, f, f, t, t, t, f, t, t, f, f, t, t, f, t, f, f }, // 28
//  { f, t, t, t, t, t, t, t, f, f, t, f, f, t, t, t, t, t, f, t, f, f, f, f, f, t, f, t, f, f, f }, // 29
//  { f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f } };
//
//  screen.drawMatrix(
//  { 0, 0 }, matrix, 4);

  screen.drawChristmasTree();

  uint32_t counter = 0;
  uint32_t flakeCounter = 0;

  ST7735Adapter::St7735Adapter::Coordinate flake1
  { 120, 0 };
  ST7735Adapter::St7735Adapter::Coordinate flake4
  { 120, 70 };
  ST7735Adapter::St7735Adapter::Coordinate flake2
  { 110, 20 };
  ST7735Adapter::St7735Adapter::Coordinate flake5
  { 110, 55 };
  ST7735Adapter::St7735Adapter::Coordinate flake3
  { 105, 5 };
  ST7735Adapter::St7735Adapter::Coordinate flake6
  { 105, 15 };
  ST7735Adapter::St7735Adapter::Coordinate flake7
  { 105, 35 };
  ST7735Adapter::St7735Adapter::Coordinate flake8
  { 105, 95 };
  ST7735Adapter::St7735Adapter::Coordinate flake851
  { 85, 10 };
  ST7735Adapter::St7735Adapter::Coordinate flake852
  { 85, 50 };
  ST7735Adapter::St7735Adapter::Coordinate flake853
  { 85, 60 };
  ST7735Adapter::St7735Adapter::Coordinate flake854
  { 85, 85 };
  ST7735Adapter::St7735Adapter::Coordinate flake855
  { 85, 100 };
  ST7735Adapter::St7735Adapter::Coordinate flake901
  { 90, 13 };
  ST7735Adapter::St7735Adapter::Coordinate flake902
  { 90, 25 };
  ST7735Adapter::St7735Adapter::Coordinate flake903
  { 90, 40 };
  ST7735Adapter::St7735Adapter::Coordinate flake904
  { 90, 70 };
  ST7735Adapter::St7735Adapter::Coordinate flake905
  { 90, 75 };

  ST7735Adapter::St7735Adapter::Coordinate flake51
  { 5, 7 };
  ST7735Adapter::St7735Adapter::Coordinate flake52
  { 5, 28 };
  ST7735Adapter::St7735Adapter::Coordinate flake53
  { 5, 47 };
  ST7735Adapter::St7735Adapter::Coordinate flake54
  { 5, 60 };
  ST7735Adapter::St7735Adapter::Coordinate flake55
  { 5, 80 };

  ST7735Adapter::St7735Adapter::Coordinate flake101
  { 10, 8 };
  ST7735Adapter::St7735Adapter::Coordinate flake102
  { 10, 18 };
  ST7735Adapter::St7735Adapter::Coordinate flake103
  { 10, 51 };
  ST7735Adapter::St7735Adapter::Coordinate flake104
  { 10, 69 };
  ST7735Adapter::St7735Adapter::Coordinate flake105
  { 10, 90 };

  ST7735Adapter::St7735Adapter::Coordinate flake181
  { 18, 11 };
  ST7735Adapter::St7735Adapter::Coordinate flake182
  { 18, 32 };
  ST7735Adapter::St7735Adapter::Coordinate flake183
  { 18, 49 };
  ST7735Adapter::St7735Adapter::Coordinate flake184
  { 18, 54 };
  ST7735Adapter::St7735Adapter::Coordinate flake185
  { 18, 61 };
  ST7735Adapter::St7735Adapter::Coordinate flake186
  { 18, 66 };
  ST7735Adapter::St7735Adapter::Coordinate flake187
  { 18, 73 };

  while (1)
  {
    if (counter++ % 2 == 0)
    {
      HAL_GPIO_TogglePin(GPIOA, LD2_Pin);  // toggle LED
    }

    if (flakeCounter % 2 == 0)
    {
      screen.animateChristmasTree(flake1);
      screen.animateChristmasTree(flake2);
      screen.animateChristmasTree(flake3);
      screen.animateChristmasTree(flake4);
      screen.animateChristmasTree(flake5);
      screen.animateChristmasTree(flake6);
      screen.animateChristmasTree(flake7);
      screen.animateChristmasTree(flake8);

      screen.animateChristmasTree(flake851);
      screen.animateChristmasTree(flake852);
      screen.animateChristmasTree(flake853);
      screen.animateChristmasTree(flake854);
      screen.animateChristmasTree(flake855);

      screen.animateChristmasTree(flake901);
      screen.animateChristmasTree(flake902);
      screen.animateChristmasTree(flake903);
      screen.animateChristmasTree(flake904);
      screen.animateChristmasTree(flake905);

      screen.animateChristmasTree(flake51);
      screen.animateChristmasTree(flake52);
      screen.animateChristmasTree(flake53);
      screen.animateChristmasTree(flake54);
      screen.animateChristmasTree(flake55);

      screen.animateChristmasTree(flake101);
      screen.animateChristmasTree(flake102);
      screen.animateChristmasTree(flake103);
      screen.animateChristmasTree(flake104);
      screen.animateChristmasTree(flake105);

      screen.animateChristmasTree(flake181);
      screen.animateChristmasTree(flake182);
      screen.animateChristmasTree(flake183);
      screen.animateChristmasTree(flake184);
      screen.animateChristmasTree(flake185);
      screen.animateChristmasTree(flake186);
      screen.animateChristmasTree(flake187);

    }

    HAL_Delay(50);

  }
}
