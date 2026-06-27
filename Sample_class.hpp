//
//  Sample_class.hpp  
//  Created by Shailesh on 02/11/25.
#ifndef Sample_class_hpp
#define Sample_class_hpp

#include <stdio.h>
#include "GameController.h"
class Sample_class : public Layer {
public:
    static Scene* scene(int value1);
    Sample_class(int value1);
    ~Sample_class(void);

    virtual void onEnter();
    virtual void onExit();

    static Sample_class* getInstance() { return gamePlayObject; }
    void createAllListener();

    EventListenerTouchOneByOne *listener;

    bool onTouchBegan(const std::vector<Touch*>& touches, Event *event);
    void onTouchMoved(const std::vector<Touch*>& touches, Event *event);
    void onTouchEnded(const std::vector<Touch*>& touches, Event *event);
    void onTouchCancel(const std::vector<Touch*>& touches, Event *event);

    virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    inline int getMainLevel() {return mainLevelNo;}

    void addNewHiddenDisObj(int no_pos);
    void checkHiddenComplite();
    void disObjTouch(Ref* pSender);
    void disObjTouchBack(Ref* pSender);
    void timerCounter(Ref *pSender);
    void call_popup_btn(Ref *pSender);
    void call_hint(Ref *pSender);
    void replaybtn1(Ref *pSender);
    void nextbtn(Ref *pSender);

    void level_btn1(Ref *pSender);
    void home_btn1(Ref *pSender);

    void rest_btn1(Ref *pSender);

    void rate(Ref *pSender);
    void Later(Ref *pSender);

    void levelComplite(float dt);
    void StartTimer();
    void StopTimer();
   

    void createGameLayer();
    void createHudLayer();
    void createPauseLayer();
    void createCompLayer();
    void createRateLayer();
    
//    void createReadyLayer();
//    void initHiddenObj();

//    void createlvlLayer();

    void Ready_scene();

    void setTouchOff();
    void setTouchOn();

    void SetOrder(int Order);
    void Set_Puzzel(Point Lst_Point);


    Point locationpoint;
    Point Last_Point;

private:

    int levelObjNo;
    int noOfObjFind;

    bool isAncorpointSet;
    bool isMultitouch;
    //int noTouch;
    cocos2d::Point startLoc;
    cocos2d::Point curLoc;
    cocos2d::Point prevLoc;
    cocos2d::Point location;

    int mainLevelNo;
    int noTap;
    int noHint[5];
    int BunchNo;
    int LevelNo;
    int gameTime;

    int Moveno;
    int lvl_num;

    int CountSc;

    int Put_Cnt,Count_set;

    Sprite *Jigsaw_Border,*Jigsaw_Border1;

    Sprite *Btm_pannel,*Fill_Img;

    Sprite *mainplay_BG;

    Sprite *Jigsaw_Part[30],*Dumy_Jigsaw[30];

    float Prog_score;

    int Rnd_Index[30];

    Sprite *hand;

    ui::LoadingBar *loadingbar;

    ProgressTimer* progressback;

    Sprite *loading_back;


    Label *lblHint[5];
    Label *levelScore;
    Label *lblScore;
    Label *lblHighScore;
    Label *lblTimer;

    Sprite *popupCompliteTaxt;
    Sprite *popupScore;
    Sprite *popupHighScore;
    Sprite *levelStar[8];
    Sprite *ReadyText;


    Sprite *Background;

    Sprite *popupBord;

    Layer *HudLayer;
    Layer *CompLayer;
    Layer *PauseLayer;
    Layer *RateLayer;
    Layer *GameLayer;
    Layer *ReadyLayer;
    Layer *lvlLayer;


    MenuItemSprite *puaseBtn;
    MenuItemSprite *homeBtn;
    MenuItemSprite *replayBtn;
    MenuItemSprite *nextBtn;
    MenuItemSprite *menuBtn;
    MenuItemSprite *rateBtn;
    MenuItemSprite *shareBtn;
    MenuItemSprite *moreBtn;
    MenuItemSprite *resumeBtn;
    MenuItemSprite *hint1Btn;
    MenuItemSprite *hint2Btn;
    MenuItemSprite *hint3Btn;
    MenuItemSprite *ratenowBtn;
    MenuItemSprite *laterBtn;
    MenuItemSprite *rply;
    MenuItemSprite *homeBtn1;

    MenuItemSprite *restart;


    MenuItemSprite *lvlbtn;





    MenuItemSprite *replayBtn1;

    std::vector<cocos2d::Vec2> originalPositions;

    Vec2 disObjPosition[30];
    MenuItemSprite *disObjImg[20];

    ParticleSystemQuad *particleHidden[20];
    Sprite *disObjImgBack[30];
    int NoLeftIteam;
    ParticleSystemQuad *particleHint[20];
    Sprite *Hint2Bg;
    bool isHint3Active;

    static Sample_class *gamePlayObject;
    Size viewSize;
};
#endif /* Sample_class_hpp */
