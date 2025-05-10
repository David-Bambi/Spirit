#ifndef APPSETTING_HPP
#define APPSETTING_HPP

struct AppSetting
{
    const char* APP_NAME;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    bool ENABLE_CURSOR;
    bool ENABLE_DEPTH_TEST;
};

#endif