/*
 * main.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: john bell
 */

#include "main.h"
#include "St7735Adapter.h"
#include "St7735ChristmasTree.h"

extern "C" void cpp_main();

void cpp_main(void)
{
  ST7735Adapter::St7735Adapter screen;
  ST7735Adapter::St7735ChristmasTree ct
  { screen };

  ct.drawScene();

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOA, LD2_Pin);  // toggle LED
    ct.animate();
    HAL_Delay(100);
  }
}
