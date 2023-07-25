#include "displayapp/screens/joeface.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

LV_IMG_DECLARE(joe);

joeApp::joeApp() {
  lv_obj_t* joeface = lv_img_create(lv_scr_act(), nullptr);
  lv_img_set_src(joeface, &joe);
  lv_obj_align(joeface, nullptr, LV_ALIGN_CENTER, 0, 0);
}

joeApp::~joeApp() {
  lv_obj_clean(lv_scr_act());
}