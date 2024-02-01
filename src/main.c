// TODO: These should be found in the cmake
#define NAME "raylib-game"
#define VERSION "0.1"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "utils/utils.h"
#include "engine/engine.h"
#include "../test/UnitsTests.h"


int main(int argc, char *argv[]) {

#ifdef DEBUG
  printf("* %s (DEBUG build %s)\n", NAME, VERSION);
  printf("* argc : %d\n", argc);
  printf("* argv : %s\n", argv[0]);

  // Assert tests
  initStrArrayTest();
  addToStrArrayTest();
  deleteFromStrArrayTest();

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

  init(preferedFps);
  run();
  
  return EXIT_SUCCESS;
}