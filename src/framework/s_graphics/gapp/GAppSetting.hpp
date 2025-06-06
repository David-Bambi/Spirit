#ifndef GAPPSETTING_HPP
#define GAPPSETTING_HPP

#include <string>

struct GAppSetting
{
    std::string APP_NAME;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    bool ENABLE_CURSOR;
    bool ENABLE_DEPTH_TEST;
};

#endif