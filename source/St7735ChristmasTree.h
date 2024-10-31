/*
 * St7735ChristmasTree.h
 *
 *  Created on: Oct 19, 2024
 *      Author: john bell
 */

#include "St7735Adapter.h"
#include "stdint.h"
#include <random>
#include <map>

#pragma once

namespace ST7735Adapter
{

#define SNOW_FLAKE_COUNT 150

/// Handles drawing of a christmas tree
class St7735ChristmasTree
{
private:

  /// Remembering the colors which are not of background color
  struct SceneColor
  {
    uint16_t minX;
    uint16_t maxX;
    ST7735Adapter::St7735Adapter::DrawingColor color;
  };
  std::map<uint16_t, SceneColor> sceneColors;

  St7735Adapter &st7735Adapter;
  std::vector<ST7735Adapter::St7735Adapter::Coordinate> flakes;

  void animateFlake(ST7735Adapter::St7735Adapter::Coordinate &flake);
  uint16_t randNr(int min, int max);

public:
  St7735ChristmasTree(St7735Adapter &st7735Adapter) :
      st7735Adapter(st7735Adapter)
  {
    // generate snowflakes
    for (int i = 0; i < SNOW_FLAKE_COUNT; i++)
    {
      ST7735Adapter::St7735Adapter::Coordinate newFlake;
      newFlake.x = randNr(0, 127);
      newFlake.y = randNr(0, 127);
      if (!(newFlake.x >= 39 && newFlake.x <= 41) &&  // do not delete candles 
      !(newFlake.x >= 34 && newFlake.x <= 36) && !(newFlake.x >= 29 && newFlake.x <= 31) && !(newFlake.x >= 69 && newFlake.x <= 71) && !(newFlake.x >= 74 && newFlake.x <= 76) && !(newFlake.x >= 79 && newFlake.x <= 81))
      {
        flakes.push_back(newFlake);
      }
    }
  }
  virtual ~St7735ChristmasTree();

  /// generate base picture
  void drawScene();

  /// to be called every 100ms, animates the snow flakes
  void animate();

};

} /* namespace ST7735Adapter */

