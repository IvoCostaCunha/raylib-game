#pragma once

struct s_DynamicAsset {
  char *name;
  unsigned int x;
  unsigned int y;
};

int init(unsigned int preferedFps);
void run();