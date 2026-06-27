#include "AllHeaders.h"

int SNAP = 0;
int imagenum1 = 1;
int playCount = 0;
int Memory_count = 0;
bool tutorial=false;
bool isMainScreen = false;

float mrXMaxGap = 0.0f;
float mrYMaxGap = 0.0f;
float mrXGap = 0.0f;
float mrYGap = 0.0f;
float mrXscale = 1.0f;
float mrYscale = 1.0f;

Size SCREEN_SIZE = Size::ZERO;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() {
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}
// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
     
    GameController::getInstance()->setVideoAdLoaded(false);
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	glview = GLViewImpl::createWithRect(GAME_NAME, Rect(0, 0, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT), ZOOM_FACTOR, false);
	//glview = GLViewImpl::createWithFullScreen(GAME_NAME);
#else
	glview = GLViewImpl::create(GAME_NAME);
#endif
		director->setOpenGLView(glview);
	}
	//Device::setAccelerometerEnabled(true);

    SCREEN_SIZE = Director::getInstance()->getWinSize();

    glview->setDesignResolutionSize(SCENE_SIZE.width, SCENE_SIZE.height, ResolutionPolicy::EXACT_FIT);
	Size screenSize = glview->getFrameSize();

//    GameController::getInstance()->imgScaleX=screenSize.height/1024;

    director->setDisplayStats(SHOW_FPS);
    director->setAnimationInterval(1.0f / FPS_VALUE);

    register_all_packages();

    mrXscale = (SCENE_SIZE.width * SCREEN_SIZE.height)
               / (SCENE_SIZE.height * SCREEN_SIZE.width);
    if (mrXscale > 1.0f)
    {
        mrYscale = 1.0f / mrXscale;
        mrXscale = 1.0f;
    }


    mrXMaxGap = (SCENE_SIZE.width * ((1.0f / mrXscale) - 1)) / 2.0f;
    mrYMaxGap = (SCENE_SIZE.height * ((1.0f / mrYscale) - 1)) / 2.0f;

    if (mrXMaxGap != 0.0f)
        mrXGap = mrXMaxGap - ((SCENE_SIZE.width) + mrXMaxGap * 2) * 90 / SCREEN_SIZE.width;

    if (mrXMaxGap < mrXGap || mrXGap < 0.0f)
        mrXGap = mrXMaxGap;

    if (mrYMaxGap != 0.0f)
        mrYGap = mrYMaxGap - ((SCENE_SIZE.height) + mrYMaxGap * 2) * 90 / SCREEN_SIZE.height;

    if (mrYMaxGap < mrYGap || mrYGap < 0.0f)
        mrYGap = mrYMaxGap;

    GameController::getInstance()->imgScaleX=mrXscale;
    GameController::getInstance()->imgScaleY=mrYscale;


    CCLOG("AppDelegate  SCREEN_SIZE.width = %f", SCREEN_SIZE.width);
    CCLOG("AppDelegate SCREEN_SIZE.height = %f", SCREEN_SIZE.height);
    CCLOG("AppDelegate mrXscale = %f", mrXscale);
    CCLOG("AppDelegate mrYscale = %f", mrYscale);
    CCLOG("AppDelegate mrXMaxGap = %f", mrXMaxGap);
    CCLOG("AppDelegate mrXGap = %f", mrXGap);
    CCLOG("AppDelegate mrYMaxGap = %f", mrYMaxGap);
    CCLOG("AppDelegate mrYGap = %f", mrYGap);

    CCLOG("AppDelegate IPAD_ORG_WIDTH = %d", IPAD_ORG_WIDTH);
    CCLOG("AppDelegate IPAD_ORG_HEIGHT = %d", IPAD_ORG_HEIGHT);

    register_all_packages();
	// To create SPLASH scene
	GameController::getInstance()->createScene(SCREEN_SPLASH);//SCREEN_SPLASH
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
	
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

//	if (GameController::getInstance()->getCurGameScreen() == SCREEN_GAME_PLAY) {
//		//GamePlay::getInstance()->pauseBtnCallback(GamePlay::GetInstance());
//	}

}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
	
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
