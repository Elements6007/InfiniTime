#pragma once

#include "displayapp/screens/Screen.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class joeApp : public Screen {
      public:
        joeApp();
        ~joeApp() override;
      };
    }
  }
}