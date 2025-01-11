#include "Application.h"
#include <iostream>
int main(int argc, char *argv[]) {
  Application application("App", "1.0");
  application.Init();
  return application.Run();
}