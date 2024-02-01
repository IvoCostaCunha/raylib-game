#include "engine.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>
#include <raymath.h>

#include "../utils/utils.h"



int init(unsigned int preferedFps) {
#ifdef RELEASE
  SetTraceLogLevel(LOG_ERROR);
#endif

  // Color blue = GetColor(strtol("6495ed", NULL, 16));
  InitWindow(800, 600, "raylib-game");
  if (!IsWindowReady()) {
    printf("Initialisation of raylib failed\n");
    return EXIT_FAILURE;
  }

  printf("* Connected monitors : %d (Current monitor : [%d] %s)\n",
         GetMonitorCount(), GetCurrentMonitor(), GetMonitorName(0));
  printf("* Monitor resolution : %d*%d\n", GetMonitorWidth(0),
         GetMonitorHeight(0));
  printf("* Render resolution (HiDPI): %d*%d\n", GetRenderWidth(),
         GetRenderHeight());
  printf("* Screen resolution : %d*%d\n", GetScreenWidth(), GetScreenHeight());

  preferedFps > 0 ? SetTargetFPS(preferedFps) : SetTargetFPS(60);

  return EXIT_SUCCESS;
}

void run() {

  struct s_DynamicAsset player = {"player", 20, 20};

  ShowCursor();
  EnableCursor();

  while (!WindowShouldClose()) {

    char infoText[50];
    sprintf(infoText, "FPS: %d\nFrame time : %f", GetFPS(), GetFrameTime());

    if (IsKeyDown(KEY_LEFT)) {
      player.x -= 10;
    }

    if (IsKeyDown(KEY_RIGHT)) {
      player.x += 10;
    }

    if (IsKeyDown(KEY_UP)) {
      player.y -= 10;
    }

    if (IsKeyDown(KEY_DOWN)) {
      player.y += 10;
    }

    BeginDrawing();

    ClearBackground(WHITE);
    // DrawFPS(GetRenderWidth() - 100, 10);
    DrawText(infoText, 10, 5, 14, BLACK);
    DrawCircle(player.x, player.y, 25.00, BLUE);

    EndDrawing();
  }

  CloseWindow();
}