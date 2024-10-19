/*
 * St7735ChristmasTree.cpp
 *
 *  Created on: Oct 19, 2024
 *      Author: jlue4
 */

#include "St7735ChristmasTree.h"

namespace ST7735Adapter
{

void St7735ChristmasTree::animateFlake(ST7735Adapter::St7735Adapter::Coordinate &flake)
{
  m_st7735Adapter.setDrawingColor(0xff, 0xfa, 0xfa); // snow white ground

  m_st7735Adapter.drawPixel(flake.x, flake.y++, 0xff, 0xfa, 0xfa);

  if ((flake.y - 2) < 109)
    m_st7735Adapter.drawPixel(flake.x, (flake.y - 2), 0x19, 0x19, 0x70);

  if (flake.y >= 128)
  {
    flake.y = 0;
  }
}

St7735ChristmasTree::~St7735ChristmasTree()
{
  // TODO Auto-generated destructor stub
}

void St7735ChristmasTree::drawScene()
{
  // colors => https://html-color.codes
  m_st7735Adapter.init(0x19, 0x19, 0x70); // midnight blue

  // draw timber
  m_st7735Adapter.setDrawingColor(0x7b, 0x3f, 0x00); // tree brown timber
  for (uint16_t y = 80; y < 110; y++)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 50, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 59, y };
    m_st7735Adapter.drawLine(start, end);
  }

  // draw branches
  m_st7735Adapter.setDrawingColor(0x22, 0x8b, 0x22); // green
  uint16_t startx = 25;
  uint16_t stopx = 84;
  for (uint16_t y = 79; y > 59; y--)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { startx++, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx--, y };
    m_st7735Adapter.drawLine(start, end);
  }
  startx = 30;
  stopx = 79;
  for (uint16_t y = 59; y > 38; y--)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { startx++, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx--, y };
    m_st7735Adapter.drawLine(start, end);
  }
  startx = 35;
  stopx = 74;
  for (uint16_t y = 38; y > 18; y--)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { startx++, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx--, y };
    m_st7735Adapter.drawLine(start, end);
  }

  // draw snow on ground
  m_st7735Adapter.setDrawingColor(0xff, 0xfa, 0xfa); // snow white ground
  for (uint16_t y = 109; y < 127; y++)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 0, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 127, y };
    m_st7735Adapter.drawLine(start, end);
  }
}

void St7735ChristmasTree::animate()
{
  animateFlake(flake1);
  animateFlake(flake2);
  animateFlake(flake3);
  animateFlake(flake4);
  animateFlake(flake5);
  animateFlake(flake6);
  animateFlake(flake7);
  animateFlake(flake8);

  animateFlake(flake851);
  animateFlake(flake852);
  animateFlake(flake853);
  animateFlake(flake854);
  animateFlake(flake855);

  animateFlake(flake901);
  animateFlake(flake902);
  animateFlake(flake903);
  animateFlake(flake904);
  animateFlake(flake905);

  animateFlake(flake51);
  animateFlake(flake52);
  animateFlake(flake53);
  animateFlake(flake54);
  animateFlake(flake55);

  animateFlake(flake101);
  animateFlake(flake102);
  animateFlake(flake103);
  animateFlake(flake104);
  animateFlake(flake105);

  animateFlake(flake181);
  animateFlake(flake182);
  animateFlake(flake183);
  animateFlake(flake184);
  animateFlake(flake185);
  animateFlake(flake186);
  animateFlake(flake187);

}

} /* namespace ST7735Adapter */
