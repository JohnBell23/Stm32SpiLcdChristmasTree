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
  // draw the flake
  st7735Adapter.drawPixel(flake.x, flake.y++, 0xff, 0xfa, 0xfa);

  // reset old place of the flake
  if ((flake.y - 2) < 109)
  {
    auto it = sceneColors.find(flake.y - 2);
    if (it != sceneColors.end() && (flake.x >= it->second.minX) && (flake.x <= it->second.maxX))
    {
      // if it is not simple background
      SceneColor sceneColor = it->second;

      st7735Adapter.drawPixel(flake.x, (flake.y - 2), sceneColor.color.r, sceneColor.color.g, sceneColor.color.b); // old color
    }
    else
    {
      // simple background
      st7735Adapter.drawPixel(flake.x, (flake.y - 2), 0x19, 0x19, 0x70); // midnight blue
    }
  }

  if (flake.y >= 128)
  {
    flake.y = 0;
  }
}

St7735ChristmasTree::~St7735ChristmasTree()
{
}

void St7735ChristmasTree::drawScene()
{
  // colors => https://html-color.codes
  st7735Adapter.init(0x19, 0x19, 0x70); // midnight blue

  // draw timber
  st7735Adapter.setDrawingColor(0x7b, 0x3f, 0x00); // tree brown timber
  for (uint16_t y = 80; y <= 108; y++)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 50, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 59, y };
    st7735Adapter.drawLine(start, end);

    sceneColors.insert(std::make_pair(start.y, SceneColor
    { start.x, end.x,
    { 0x7b, 0x3f, 0x00 } }));
  }

  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 49, 108 };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 60, 108 };
    st7735Adapter.drawLine(start, end);

    sceneColors.insert(std::make_pair(start.y, SceneColor
    { start.x, end.x,
    { 0x7b, 0x3f, 0x00 } }));
  }
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 48, 109 };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 61, 109 };
    st7735Adapter.drawLine(start, end);

    sceneColors.insert(std::make_pair(start.y, SceneColor
    { start.x, end.x,
    { 0x7b, 0x3f, 0x00 } }));
  }

  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 47, 110 };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 62, 110 };
    st7735Adapter.drawLine(start, end);

    sceneColors.insert(std::make_pair(start.y, SceneColor
    { start.x, end.x,
    { 0x7b, 0x3f, 0x00 } }));
  }
  // draw branches
  st7735Adapter.setDrawingColor(0x22, 0x8b, 0x22); // green
  uint16_t startx = 25;
  uint16_t stopx = 84;
  for (uint16_t y = 79; y > 59; y--)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0x22, 0x8b, 0x22 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx++, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx--, y };
    st7735Adapter.drawLine(start, end);
  }
  startx = 30;
  stopx = 79;
  for (uint16_t y = 59; y > 38; y--)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0x22, 0x8b, 0x22 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx++, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx--, y };
    st7735Adapter.drawLine(start, end);
  }
  startx = 35;
  stopx = 74;
  for (uint16_t y = 38; y > 18; y--)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0x22, 0x8b, 0x22 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx++, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx--, y };
    st7735Adapter.drawLine(start, end);
  }

  // draw snow on ground
  st7735Adapter.setDrawingColor(0xff, 0xfa, 0xfa); // snow white ground
  for (uint16_t y = 111; y <= 127; y++)
  {
    ST7735Adapter::St7735Adapter::Coordinate start
    { 0, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { 127, y };
    st7735Adapter.drawLine(start, end);
  }

  // draw candles
  st7735Adapter.drawPixel(40, 28, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(41, 28, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(40, 27, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(40, 26, 0xff, 0xd7, 0x00);
  startx = 39;
  stopx = 41;
  st7735Adapter.setDrawingColor(0xed, 0x1c, 0x24); // candle red
  for (uint16_t y = 29; y <= 34; y++)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0xed, 0x1c, 0x24 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx, y };
    st7735Adapter.drawLine(start, end);
  }

  st7735Adapter.drawPixel(35, 48, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(34, 48, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(35, 47, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(35, 46, 0xff, 0xd7, 0x00);
  startx = 34;
  stopx = 36;
  st7735Adapter.setDrawingColor(0xed, 0x1c, 0x24); // candle red
  for (uint16_t y = 49; y <= 54; y++)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0xed, 0x1c, 0x24 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx, y };
    st7735Adapter.drawLine(start, end);
  }

  st7735Adapter.drawPixel(30, 68, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(31, 68, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(30, 67, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(30, 66, 0xff, 0xd7, 0x00);
  startx = 29;
  stopx = 31;
  st7735Adapter.setDrawingColor(0xed, 0x1c, 0x24); // candle red
  for (uint16_t y = 69; y <= 74; y++)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0xed, 0x1c, 0x24 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx, y };
    st7735Adapter.drawLine(start, end);
  }

  st7735Adapter.drawPixel(70, 28, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(69, 28, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(70, 27, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(70, 26, 0xff, 0xd7, 0x00);
  startx = 69;
  stopx = 71;
  st7735Adapter.setDrawingColor(0xed, 0x1c, 0x24); // candle red
  for (uint16_t y = 29; y <= 34; y++)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0xed, 0x1c, 0x24 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx, y };
    st7735Adapter.drawLine(start, end);
  }

  st7735Adapter.drawPixel(75, 48, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(74, 48, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(75, 47, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(75, 46, 0xff, 0xd7, 0x00);
  startx = 74;
  stopx = 76;
  st7735Adapter.setDrawingColor(0xed, 0x1c, 0x24); // candle red
  for (uint16_t y = 49; y <= 54; y++)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0xed, 0x1c, 0x24 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx, y };
    st7735Adapter.drawLine(start, end);
  }

  st7735Adapter.drawPixel(80, 68, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(79, 68, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(80, 67, 0xff, 0xd7, 0x00);
  st7735Adapter.drawPixel(80, 66, 0xff, 0xd7, 0x00);
  startx = 79;
  stopx = 81;
  st7735Adapter.setDrawingColor(0xed, 0x1c, 0x24); // candle red
  for (uint16_t y = 69; y <= 74; y++)
  {
    sceneColors.insert(std::make_pair(y, SceneColor
    { startx, stopx,
    { 0xed, 0x1c, 0x24 } }));

    ST7735Adapter::St7735Adapter::Coordinate start
    { startx, y };
    ST7735Adapter::St7735Adapter::Coordinate end
    { stopx, y };
    st7735Adapter.drawLine(start, end);
  }
}

void St7735ChristmasTree::animate()
{
  for (size_t i = 0; i < flakes.size(); ++i)
  {
    animateFlake(flakes[i]);
  }
}

uint16_t St7735ChristmasTree::randNr(int min, int max)
{
  std::random_device rd;   // random-seed
  std::mt19937 gen(rd());  // Mersenne-Twister-Engine
  std::uniform_int_distribution<> distr(min, max);
  int random_number = distr(gen);

  return random_number;
}

} /* namespace ST7735Adapter */
