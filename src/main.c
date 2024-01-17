// TODO: These should be found in the cmake
#define NAME "raylib-game"
#define VERSION "0.1"

#include <stdio.h>
#include <stdlib.h>

#include "CUnit/CUnit.h"
#include "raylib.h"
#include "raymath.h"

struct DynamicAsset {
  char *name;
  unsigned int x;
  unsigned int y;
};

int main(int argc, char *argv[]) {

#ifdef DEBUG
  printf("* %s (DEBUG build %s)\n", NAME, VERSION);
  printf("* argc : %d\n", argc);
  printf("* argv : %s\n", argv[0]);
#endif

#ifdef RELEASE
  printf("* %s (RELEASE build %s)\n", NAME, VERSION);
#endif

  unsigned int preferedFps = 0;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "--set-fps") == 0 && argv[i + 1] != NULL) {
        if (atoi(argv[i + 1]) == 0) {
          printf("Parameter -fps must be of int type, defaulted to 60\n");
        } else {
          preferedFps = atoi(argv[i + 1]);
          printf("FPS set to %d\n", preferedFps);
        }
      }
      if (strcmp(argv[i], "-h") == 0) {
        printf("Usage: raylib-game [OPTION]...\n\n");
        printf("  --set-fps      Set the fps\n");
        return EXIT_SUCCESS;
      }
    }
  }

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

  ShowCursor();
  EnableCursor();

  struct DynamicAsset player = {"player", 20, 20};

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
  return EXIT_SUCCESS;
}