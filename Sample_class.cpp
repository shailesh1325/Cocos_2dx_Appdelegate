//
//  Sample_class.hpp
//  Created by Shailesh on 02/11/25.

#include "AllHeaders.h"

#define slice_num 16
Sample_class* Sample_class::gamePlayObject = nullptr;
Sample_class::~Sample_class() {
}

void Sample_class::onEnter() {
    Layer::onEnter();
}

void Sample_class::onExit() {
    Layer::onExit();
}

Scene* Sample_class::scene(int value1) {
    
    Scene *scene = Scene::create();
    Layer* layer = new Sample_class(value1);
    layer->autorelease();
    scene->addChild(layer);
    return scene;
}

Sample_class::Sample_class(int value1) {
    
    Layer::init();
    viewSize = Director::getInstance()->getWinSize();

    Count_set = 0;
    CountSc = 0;
    lvl_num = imagenum1;

    //lvl_num=GameController::getInstance()->getIntegerForKey("CURRENT_LEVEL",1);
    gamePlayObject = nullptr;
    gamePlayObject = this;
     
    createAllListener();// LISTNER

//    initHiddenObj();
    log("11");
    createHudLayer();
    log("12");
    createPauseLayer();
    log("13");
    createCompLayer();
    log("14");
    createRateLayer();
    log("16");
    createlvlLayer();
    log("17");

    //this->schedule(schedule_selector(Sample_class::updateGame));
}


//void Sample_class::initHiddenObj() {
//    //log("Hidden int call,hiddenMain=%d, mainLevelNo=%d,hiddenSub=%d",hiddenMain,mainLevelNo,hiddenSub);
////    GameLayer = nullptr;
////    GameLayer = Layer::create();
////    this->addChild(GameLayer, Z_VAL_OF_GAME_LAYER);
//    //GameLayer->setContentSize(viewSize);
//
//
//
//
//}

void Sample_class::createAllListener() {
    // Register for keyboard events
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(Sample_class::onKeyReleased, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    // Register for Touch events

    auto listener2 = EventListenerTouchAllAtOnce::create();
    listener2->onTouchesBegan = CC_CALLBACK_2(Sample_class::onTouchBegan, this);
    listener2->onTouchesMoved = CC_CALLBACK_2(Sample_class::onTouchMoved, this);
    listener2->onTouchesEnded = CC_CALLBACK_2(Sample_class::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, this);
}



void Sample_class::createHudLayer(){
    HudLayer = nullptr;
    HudLayer = Layer::create();
    this->addChild(HudLayer, Z_VAL_OF_HUD);

    //int lvl_num = random(1, 10);

    mainplay_BG=Sprite::create("Main_Screen_bg.png");
    mainplay_BG->setPosition(Vec2(viewSize.width/2, (viewSize.height/2)));
    this->addChild(mainplay_BG,1);
    //mainplay_BG->setScale(1.3);

    Btm_pannel = Sprite::create("puzzle_panel.png");
    Btm_pannel->setPosition(Vec2(viewSize.width/2+8, 280));
    this->addChild(Btm_pannel,2);

    mainplay_BG->runAction(Sequence::create(DelayTime::create(0.5),
                                            CallFunc::create(CC_CALLBACK_0(Sample_class::Ready_scene, this)), NULL));






    Fill_Img  = Sprite::create(StringUtils::format("Back_img_%d.jpg",lvl_num));
    Fill_Img->setPosition(Vec2(viewSize.width/2, viewSize.height/2+85));
    this->addChild(Fill_Img, 5);
    Fill_Img->setVisible(true);



    for(int i=1;i<=slice_num;i++)
    {
        Rnd_Index[i] = i;
    }

    for (int i=1; i<=random(2, slice_num); i++)
    {
        std::random_shuffle(&Rnd_Index[1],&Rnd_Index[slice_num]);
    }

    for (int i=1; i<=slice_num; i++)
    {
        Jigsaw_Part[i] = Sprite::create(StringUtils::format("Panel_pzel_%d_%d.png",lvl_num,Rnd_Index[i]));
        Jigsaw_Part[i]->setTag(100+Rnd_Index[i]);
        Jigsaw_Part[i]->setScale(0);
        this->addChild(Jigsaw_Part[i],10); //Phone_Layer //10

        Dumy_Jigsaw[i] = Sprite::create(StringUtils::format("Panel_pzel_%d_%d.png",lvl_num,i));
        Dumy_Jigsaw[i]->setTag(100+i);
        Dumy_Jigsaw[i]->setOpacity(0);//20
        this->addChild(Dumy_Jigsaw[i],10); // ph

    }

      Dumy_Jigsaw[1]->setPosition(Vec2(145.67+10,1150.33+5));//115.67+10,853.33+5
      Dumy_Jigsaw[2]->setPosition(Vec2(286.04+10,1120.50+5));//246.04+10,868.50+5

      Dumy_Jigsaw[3]->setPosition(Vec2(460.84+10,1150.28+5));
      Dumy_Jigsaw[4]->setPosition(Vec2(635.85+10,1120.61+5));

      Dumy_Jigsaw[5]->setPosition(Vec2(115.49+10,981.44+5));
      Dumy_Jigsaw[6]->setPosition(Vec2(285.05+10,980.81+5));

      Dumy_Jigsaw[7]->setPosition(Vec2(460.94+10,980.34+5));
      Dumy_Jigsaw[8]->setPosition(Vec2(605.90+10,981.50+5));

      Dumy_Jigsaw[9]->setPosition(Vec2(145.75+10,805.44+5));
      Dumy_Jigsaw[10]->setPosition(Vec2(285.90+10,805.44+5));

     Dumy_Jigsaw[11]->setPosition(Vec2(460.78+10,805.54+5));
     Dumy_Jigsaw[12]->setPosition(Vec2(636.41+10,805.59+5));

      Dumy_Jigsaw[13]->setPosition(Vec2(112.84+10 ,664.17+5));
      Dumy_Jigsaw[14]->setPosition(Vec2(285.38+10,633.22+5));

     Dumy_Jigsaw[15]->setPosition(Vec2(461.01+10,663.75+5));
     Dumy_Jigsaw[16]->setPosition(Vec2(605.53+10,635.06+5));


    Jigsaw_Part[1]->setPosition(Vec2(viewSize.width/2-280,viewSize.height/2+Btm_pannel->getContentSize().height-700));
    Jigsaw_Part[2]->setPosition(Vec2(viewSize.width/2-140,viewSize.height/2+Btm_pannel->getContentSize().height-700));
    Jigsaw_Part[3]->setPosition(Vec2(viewSize.width/2,viewSize.height/2+Btm_pannel->getContentSize().height-700));
    Jigsaw_Part[4]->setPosition(Vec2(viewSize.width/2+140,viewSize.height/2+Btm_pannel->getContentSize().height-700));
    Jigsaw_Part[5]->setPosition(Vec2(viewSize.width/2+280,viewSize.height/2+Btm_pannel->getContentSize().height-700));

    Put_Cnt=5;

    for (int i=1; i<=5; i++)
    {
        Jigsaw_Part[i]->runAction(EaseOut::create(ScaleTo::create(0.3, 0.5),0.2));
    }


    loading_back = Sprite::create("P_bar_back.png");
    loading_back->setPosition(Vec2(viewSize.width/2+20,viewSize.height/2+550));
    this->addChild(loading_back,50);
    loading_back->setScale(1.2);


    loadingbar = ui::LoadingBar::create("P_bar_top.png");
    loadingbar->setPosition(Vec2(loading_back->getContentSize()/2));
    loadingbar->setPercent(0);
    loading_back->addChild(loadingbar,50);

 
    hand = Sprite::create("Hand 1.png");
    hand->setPosition(Vec2(10000,10000));
    //hand->setScale(SCALE_RATIO_XY);
    this->addChild(hand,30);
    
    {
        //Previous Button
        Sprite *normalSprite =Sprite::create("level_btn.png");
        Sprite *selectedSprite =Sprite::create("level_btn.png");
        lvlbtn=MenuItemSprite::create(normalSprite, selectedSprite,CC_CALLBACK_1(Sample_class::level_btn1, this));
        lvlbtn->setPosition(Vec2(lvlbtn->getContentSize().width*0.52f+60,viewSize.height-lvlbtn->getContentSize().height/2.0-210));
        //lvlbtn->runAction(Sequence::create(DelayTime::create(1.5),MoveTo::create(0.1, Vec2(visibleSize.width/2-320,visibleSize.height/2+450)),JumpBy::create(1.0, Vec2(0,0), 10, 2), NULL));
        lvlbtn->setTag(60);
        lvlbtn->setScale(0.9);

        Menu *previousmenu=Menu::create(lvlbtn,NULL);
        previousmenu->setPosition(Vec2::ZERO);
        this->addChild(previousmenu,40);
    }
}

void Sample_class::createlvlLayer(){

//    lvlLayer = nullptr;
//    lvlLayer = Layer::create();
//
//    {
//        MenuItemSprite *lvlbtn=MenuItemSprite::create(Sprite::create("back_btn.png"),
//                                                      Sprite::create("back_btn.png"),
//                                                      CC_CALLBACK_1(Sample_class::level_btn1, this));
//        lvlbtn->setPosition(Vec2(lvlbtn->getContentSize().width*0.52f+60,viewSize.height-lvlbtn->getContentSize().height/2.0-225));
//        Menu *backMenu=Menu::create(lvlbtn,NULL);
//        backMenu->setPosition(Vec2::ZERO);
//        lvlbtn->setTag(60);
//        lvlbtn->setScale(0.7);
//        lvlLayer->addChild(backMenu);
//
//        //backImg->setScaleY(GameController::getInstance()->imgScaleX);
//    }
//
//
//
//    lvlLayer->setVisible(true);
//    lvlLayer->setScale(1);
//    this->addChild(lvlLayer, 50);

}

void Sample_class::createPauseLayer(){
//    PauseLayer = nullptr;
//    PauseLayer = Layer::create();

//    LayerColor *darkLayer = LayerColor::create(Color4B(0, 0, 0, 235));
//    PauseLayer->addChild(darkLayer);

//    Sprite *normalImg=Sprite::create(StringUtils::format("mainBG.jpg"));
//    Sprite *selectedImg=Sprite::create(StringUtils::format("mainBG.jpg"));
//    normalImg->setOpacity(0);
//    selectedImg->setOpacity(0);
//    MenuItemSprite *popupBackImg=MenuItemSprite::create(normalImg,selectedImg,CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//    popupBackImg->setPosition(viewSize/2);

//    Menu *popupBack=Menu::create(popupBackImg,nullptr);
//    popupBack->setPosition(Vec2::ZERO);
//    PauseLayer->addChild(popupBack);
//
//    Sprite *popupBord=Sprite::create("paused_box.png");
//    popupBord->setPosition(Vec2(viewSize.width/2,viewSize.height/2+10));//10
//    PauseLayer->addChild(popupBord);

//    Sprite *popupTaxt=Sprite::create("paused_paused.png");
//    popupTaxt->setPosition(Vec2(viewSize.width/2, 570));
//    PauseLayer->addChild(popupTaxt);

//    {
//        homeBtn=MenuItemSprite::create(Sprite::create("homePlay.png"),Sprite::create("homePlay.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//        homeBtn->setPosition(Vec2(viewSize.width / 2, 230));//210
//        homeBtn->setTag(3);
//        homeBtn->setScaleX(GameController::getInstance()->imgScaleX * 1.3);
//        homeBtn->setScaleY(1.3);
//        Menu *okmenu=Menu::create(homeBtn,NULL);
//        okmenu->setPosition(Vec2::ZERO);
//        PauseLayer->addChild(okmenu);
//    }
//    {
//        resumeBtn=MenuItemSprite::create(Sprite::create("resume.png"),Sprite::create("resume.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//        resumeBtn->setPosition(Vec2(viewSize.width/2,435));//440
//        resumeBtn->setTag(4);
//        resumeBtn->setScaleX(GameController::getInstance()->imgScaleX * 1.3);
//        resumeBtn->setScaleY(1.3);
//        Menu *okmenu=Menu::create(resumeBtn,NULL);
//        okmenu->setPosition(Vec2::ZERO);
//        PauseLayer->addChild(okmenu);
//    }
//    {
//        replayBtn=MenuItemSprite::create(Sprite::create("replay.png"),Sprite::create("replay.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//        replayBtn->setPosition(Vec2(viewSize.width/2, 335));//340
//        replayBtn->setTag(5);
//        replayBtn->setScaleX(GameController::getInstance()->imgScaleX * 1.3);
//        replayBtn->setScaleY(1.3);
//        Menu *okmenu=Menu::create(replayBtn,NULL);
//        okmenu->setPosition(Vec2::ZERO);
//        PauseLayer->addChild(okmenu);
//    }
//    {
//        menuBtn=MenuItemSprite::create(Sprite::create("menuBtn.png"),Sprite::create("menuBtn.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//        menuBtn->setPosition(Vec2(viewSize.width/2,260));//290
//        menuBtn->setTag(6);
//        menuBtn->setScaleX(GameController::getInstance()->imgScaleX);
//        Menu *okmenu=Menu::create(menuBtn,NULL);
//        okmenu->setPosition(Vec2::ZERO);
//        PauseLayer->addChild(okmenu);
//    }
//    PauseLayer->setVisible(false);
//    PauseLayer->setScale(0);
//    this->addChild(PauseLayer, Z_VAL_OF_PAUSE);
}
void Sample_class::createRateLayer(){
       RateLayer = nullptr;
       RateLayer = Layer::create();
       this->addChild(RateLayer, 70);
       RateLayer->setVisible(false);

    LayerColor *darkLayer = LayerColor::create(Color4B(0, 0, 0, 150));
    RateLayer->addChild(darkLayer);
    {
        Sprite *normalSprite=Sprite::create(StringUtils::format("mainBG.jpg"));
        Sprite *selectedSprite=Sprite::create(StringUtils::format("mainBG.jpg"));
        normalSprite->setOpacity(0);
        selectedSprite->setOpacity(0);
        MenuItemSprite *backImg1=MenuItemSprite::create(normalSprite,selectedSprite,CC_CALLBACK_1(Sample_class::call_popup_btn, this));
        backImg1->setPosition(viewSize/2);
        backImg1->setOpacity(100);
        Menu *okmenu=Menu::create(backImg1,NULL);
        okmenu->setPosition(Vec2::ZERO);
        RateLayer->addChild(okmenu);
    }

    Sprite *mainText=Sprite::create("rate-bg.png");
    mainText->setPosition(Vec2(viewSize.width/2, viewSize.height/2));
    RateLayer->addChild(mainText);
    mainText->setScale(1.3);

    {
        Sprite *normalSprite=Sprite::create(StringUtils::format("rate_later.png"));
        Sprite *selectedSprite=Sprite::create(StringUtils::format("rate_later.png"));
        laterBtn=MenuItemSprite::create(normalSprite,selectedSprite,CC_CALLBACK_1(Sample_class::Later, this));
        laterBtn->setPosition(Vec2(mainText->getContentSize().width/2+110, laterBtn->getContentSize().height*0.9));
        laterBtn->setTag(7);
        laterBtn->setScale(0.9);

        Menu *okmenu=Menu::create(laterBtn,NULL);
        okmenu->setPosition(Vec2::ZERO);
        mainText->addChild(okmenu);
    }
    {
        Sprite *normalSprite=Sprite::create(StringUtils::format("rate_now.png"));
        Sprite *selectedSprite=Sprite::create(StringUtils::format("rate_now.png"));
        ratenowBtn=MenuItemSprite::create(normalSprite,selectedSprite,CC_CALLBACK_1(Sample_class::rate, this));
        ratenowBtn->setPosition(Vec2(mainText->getContentSize().width/2-110,ratenowBtn->getContentSize().height*0.9));
        ratenowBtn->setTag(8);
        ratenowBtn->setScale(0.9);

        Menu *okmenu=Menu::create(ratenowBtn,NULL);
        okmenu->setPosition(Vec2::ZERO);
        mainText->addChild(okmenu);
    }
    RateLayer->setScale(0);
}
void Sample_class::createCompLayer(){
      CompLayer = nullptr;
      CompLayer = Layer::create();

      LayerColor *darkLayer = LayerColor::create(Color4B(0, 0, 0, 235));
      CompLayer->addChild(darkLayer);

    Sprite *normalImg=Sprite::create(StringUtils::format("LevelBg.jpg"));
    Sprite *selectedImg=Sprite::create(StringUtils::format("LevelBg.jpg"));
    normalImg->setOpacity(0);
    selectedImg->setOpacity(0);
    MenuItemSprite *popupBackImg=MenuItemSprite::create(normalImg,selectedImg,CC_CALLBACK_1(Sample_class::call_popup_btn, this));
    popupBackImg->setPosition(viewSize/2);
    popupBackImg->setScale(1.3);

    Menu *popupBack=Menu::create(popupBackImg,nullptr);
    popupBack->setPosition(Vec2::ZERO);
    CompLayer->addChild(popupBack);

    popupBord=Sprite::create("level_screen_box.png");
    popupBord->setPosition(Vec2(viewSize.width/2,viewSize.height/2+30));
    CompLayer->addChild(popupBord);
    popupBord->setScale(1.3);

    popupCompliteTaxt=Sprite::create("levelcompletedtex.png");
    popupCompliteTaxt->setPosition(Vec2(viewSize.width / 2, viewSize.height / 2+180));//520
    CompLayer->addChild(popupCompliteTaxt);




////    auto lblLevelNo=Label::createWithTTF(StringUtils::format("%d-%d",mainLevelNo,1), TTF_FONT_1, 25);
////    lblLevelNo->setPosition(Vec2(viewSize.width/2,650));//590
///    CompLayer->addChild(lblLevelNo);
//
//    popupScore=Sprite::create("level_screen_score-box.png");
//    popupScore->setPosition(Vec2(viewSize.width/2+3, 440));//40//375
//    CompLayer->addChild(popupScore);
//
//    lblScore=Label::createWithTTF(StringUtils::format("%d"), TTF_FONT_1, 25);
//    lblScore->setPosition(Vec2(viewSize.width/2+3,416));
//    CompLayer->addChild(lblScore);
//
//    popupHighScore=Sprite::create("popup_high-score.png");
//    popupHighScore->setPosition(Vec2(viewSize.width/2+3, 390));//30
//    CompLayer->addChild(popupHighScore);
//
//    lblHighScore=Label::createWithTTF(StringUtils::format("%d"), TTF_FONT_1, 25);
//    lblHighScore->setPosition(Vec2(viewSize.width/2+3,366));
//    CompLayer->addChild(lblHighScore);


    {
        restart=MenuItemSprite::create(Sprite::create("Restart.png"),Sprite::create("Restart.png"),CC_CALLBACK_1(Sample_class::rest_btn1, this));
        restart->setPosition(Vec2(viewSize.width / 2, viewSize.height / 2-50));
        restart->setTag(70);
        restart->setScale(0);
        Menu *okmenu=Menu::create(restart,NULL);
        okmenu->setPosition(Vec2::ZERO);
        CompLayer->addChild(okmenu);
    }

   {
        homeBtn1=MenuItemSprite::create(Sprite::create("home2.png"),Sprite::create("home2.png"),CC_CALLBACK_1(Sample_class::home_btn1, this));
        homeBtn1->setPosition(Vec2(viewSize.width / 2, viewSize.height / 2-190));
        homeBtn1->setTag(15);
        //homeBtn1->setScale(1.2);
        Menu *okmenu=Menu::create(homeBtn1,NULL);
        okmenu->setPosition(Vec2::ZERO);
        CompLayer->addChild(okmenu);
    }
    {
        replayBtn1=MenuItemSprite::create(Sprite::create("replay.png"),Sprite::create("replay.png"),CC_CALLBACK_1(Sample_class::replaybtn1, this));
        replayBtn1->setPosition(Vec2(viewSize.width / 2, viewSize.height / 2+60));
        replayBtn1->setTag(11);
        Menu *okmenu=Menu::create(replayBtn1,NULL);
        okmenu->setPosition(Vec2::ZERO);
        CompLayer->addChild(okmenu);
   }
    {
        Sprite *normalImg=Sprite::create("next.png");
        Sprite *selectedImg=Sprite::create("next.png");
        nextBtn=MenuItemSprite::create(normalImg,selectedImg,CC_CALLBACK_1(Sample_class::nextbtn, this));
        nextBtn->setPosition(Vec2(viewSize.width / 2, viewSize.height / 2-70));
        nextBtn->setTag(2);
        Menu *okmenu=Menu::create(nextBtn,NULL);
        okmenu->setPosition(Vec2::ZERO);
        CompLayer->addChild(okmenu);
   }
////    {
////        auto menuBtn1=MenuItemSprite::create(Sprite::create("menuBtn.png"),Sprite::create("menuBtn.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
////        menuBtn1->setPosition(Vec2(viewSize.width/2+205,230));
////        menuBtn1->setTag(menuBtn->getTag());
////        menuBtn1->setScaleX(GameController::getInstance()->imgScaleX);
////        Menu *okmenu=Menu::create(menuBtn1,NULL);
////        okmenu->setPosition(Vec2::ZERO);
////        CompLayer->addChild(okmenu);
////    }
//    {
//        rateBtn=MenuItemSprite::create(Sprite::create("rate.png"),Sprite::create("rate.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//        rateBtn->setPosition(Vec2(viewSize.width/2-150,305));
//        rateBtn->setTag(8);
//        rateBtn->setScaleX(GameController::getInstance()->imgScaleX*1.3);
//        rateBtn->setScaleY(1.3);
//        rateBtn->setScale(0);
//        Menu *okmenu=Menu::create(rateBtn,NULL);
//        okmenu->setPosition(Vec2::ZERO);
//        CompLayer->addChild(okmenu);
//    }
//    {
//        shareBtn=MenuItemSprite::create(Sprite::create("share.png"),Sprite::create("share.png"),CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//        shareBtn->setPosition(Vec2(viewSize.width/2+170,305));
//        shareBtn->setTag(9);
//        shareBtn->setScaleX(GameController::getInstance()->imgScaleX*1.3);
//        shareBtn->setScaleY(1.3);
//        Menu *okmenu=Menu::create(shareBtn,NULL);
//        okmenu->setPosition(Vec2::ZERO);
//        CompLayer->addChild(okmenu);
//    }
//
////    Sprite *levelImg=Sprite::create(StringUtils::format("level_screen_popup_img_%d.png",0));
////    levelImg->setPosition(Vec2(340,370));//380
////    levelImg->setScale(1.2);
////    CompLayer->addChild(levelImg,0);
//
//    int subLevelStar=0;
//    //UserDefault::getInstance()->getIntegerForKey(StringUtils::format("sub_score%d",i).c_str());
//    for (int j=0; j<5; j++) {
//        if(subLevelStar/20>j){
//            levelStar[j]=Sprite::create(StringUtils::format("level_screen_star_%d.png",1));
//            CompLayer->addChild(levelStar[j]);
//        }
//        else {
//            levelStar[j]=Sprite::create(StringUtils::format("level_screen_star_%d.png",1));
//            CompLayer->addChild(levelStar[j]);
//        }
//        levelStar[j]->setPosition(Vec2(levelStar[j]->getContentSize().width/0.16+j*levelStar[j]->getContentSize().width/0.6,485));
//    }
       CompLayer->setScale(0);
       CompLayer->setVisible(false);
       this->addChild(CompLayer, 60);
}
void Sample_class::createReadyLayer(){

//    Layer = nullptr;
      //ReadyLayer = Layer::create();
//
//    LayerColor *darkLayer = LayerColor::create(Color4B(0, 0, 0, 235));
//    ReadyLayer->addChild(darkLayer);
//
//    Sprite *normalImg=Sprite::create(StringUtils::format("mainBG.jpg"));
//    Sprite *selectedImg=Sprite::create(StringUtils::format("mainBG.jpg"));
//    normalImg->setOpacity(0);
//    selectedImg->setOpacity(0);
//    MenuItemSprite *popupBackImg=MenuItemSprite::create(normalImg,selectedImg,CC_CALLBACK_1(Sample_class::call_popup_btn, this));
//    popupBackImg->setPosition(viewSize/2);
//
//    Menu *popupBack=Menu::create(popupBackImg,nullptr);
//    popupBack->setPosition(Vec2::ZERO);
//    ReadyLayer->addChild(popupBack);
//
//
//    ReadyText=Sprite::create("start_READY.png");
//    ReadyText->setPosition(Vec2(viewSize.width/2,viewSize.height/2));
//    ReadyLayer->addChild(ReadyText);
//
//    this->addChild(ReadyLayer,Z_VAL_OF_PAUSE+2);
}

void Sample_class::Ready_scene(){

    if (tutorial== false){
        hand->setPosition(Jigsaw_Part[1]->getPosition());

        hand->runAction(Repeat::create(Sequence::create(Show::create(),
                                                        MoveTo::create(1.0,Vec2(Dumy_Jigsaw[1]->getPositionX()+30,
                                                                                Dumy_Jigsaw[1]->getPositionY()-30)),
                                                        DelayTime::create(0.5),Hide::create(),
                                                        Place::create(Dumy_Jigsaw[1]->getPosition()),NULL),-1));
        tutorial=true;

    }

//    hand->setPosition(Jigsaw_Part[1]->getPosition());
//
//    hand->runAction(Repeat::create(Sequence::create(Show::create(),
//                                                    MoveTo::create(1.0,Vec2(Dumy_Jigsaw[1]->getPositionX()+30,
//                                                                            Dumy_Jigsaw[1]->getPositionY()-30)),
//                                                    DelayTime::create(0.5),Hide::create(),
//                                                    Place::create(Dumy_Jigsaw[1]->getPosition()),NULL),-1));
}
void Sample_class::setTouchOn()
{
    listener->setEnabled(true);
}
void Sample_class::setTouchOff()
{
    listener->setEnabled(false);
}
bool Sample_class::onTouchBegan(const std::vector<Touch*>& touches, Event *event) {

    startLoc = location = touches.at(0)->getLocation();
    CCLOG("Touch Location: (%f, %f)", location.x, location.y);

    for (int i = 1; i <= slice_num; i++)
    {
        if((Jigsaw_Part[i]->getBoundingBox().containsPoint(location) || Jigsaw_Part[i]->getBoundingBox().containsPoint(location) ) &&
           Jigsaw_Part[i]->getOpacity()==255
           &&Jigsaw_Part[i]->getNumberOfRunningActions()==0)
        {
            GameController::getInstance()->playSFX(OBJ_TAP);
            hand->stopAllActions();
            hand->setVisible(false);
            CCLOG("Touched part: %d", i);
            Jigsaw_Part[i]->runAction(Sequence::create(ScaleTo::create(0.2, 1), NULL));
            Last_Point = Jigsaw_Part[i]->getPosition();
            Jigsaw_Part[i]->setLocalZOrder(50);

            Moveno = i;
            CCLOG("Moveno -->%d", Moveno);
            break;
        }
    }


//   if(lvlbtn->getBoundingBox().containsPoint(location) && lvlbtn->getOpacity()==255){
//     Director::getInstance()->replaceScene(TransitionFade::create(0.5,LevelScreen::createScene(),Color3B::WHITE));
//    }

    return true;

}

void Sample_class::onTouchMoved(const std::vector<Touch*>& touches, Event *event) {
    location = touches.at(0)->getLocation();

    if(Moveno > 0){
        Jigsaw_Part[Moveno]->setPosition(location);

    }
//    noTouch = (int)touches.size();
//    if(isMultitouch&&touches.size()==2){
//        float x = (curLoc.x - prevLoc.x);
//        float y = (curLoc.y - prevLoc.y);
//        float z = sqrtf(x*x + y*y);
//        curLoc= touches.at(0)->getLocation();
//        prevLoc= touches.at(1)->getLocation();
//
//
//        float distance = curLoc.getDistance(prevLoc);
//
//        if (!isAncorpointSet) {
//            isAncorpointSet=true;
//
//            Point point = GameLayer->convertToNodeSpace(Point((curLoc.x+prevLoc.x)/2, (curLoc.y+prevLoc.y)/2));
//
//            Point t_newAnchor = Point(
//                    (point.x/(GameLayer->getContentSize().width)),
//                    (point.y/(GameLayer->getContentSize().height)
//                    ));
//
//            GameLayer->setAnchorPoint(t_newAnchor);
//        }
//
//        float zoom = GameLayer->getScale();
//        CCLOG("distance = %f, z=%f",distance,z);
//        zoom += (distance-z)*0.005f;
//
//        if (zoom > 2.0f) {
//            zoom = 2.0f;
//        }
//        if (zoom < 1.0f) {
//            zoom = 1.0f;
//        }
//        GameLayer->setScale(zoom);
//
//        distance = z;
//        GameLayer->setPosition(GameLayer->getPosition()+location-touches.at(0)->getPreviousLocation());
//        if(GameLayer->getBoundingBox().getMinX()>=0
//           ||GameLayer->getBoundingBox().getMaxX()<=viewSize.width
//           ||GameLayer->getBoundingBox().getMinY()>=0
//           ||GameLayer->getBoundingBox().getMaxY()<=viewSize.height){
//            if(GameLayer->getBoundingBox().getMinX()>=0){
//                GameLayer->setPositionX(GameLayer->getPositionX()+0-GameLayer->getBoundingBox().getMinX());
//            }
//            if (GameLayer->getBoundingBox().getMaxX()<=viewSize.width){
//                GameLayer->setPositionX(GameLayer->getPositionX()+viewSize.width-GameLayer->getBoundingBox().getMaxX());
//            }
//            if(GameLayer->getBoundingBox().getMinY()>=0){
//                GameLayer->setPositionY(GameLayer->getPositionY()+0-GameLayer->getBoundingBox().getMinY());
//            }
//            if (GameLayer->getBoundingBox().getMaxY()<=viewSize.height){
//                GameLayer->setPositionY(GameLayer->getPositionY()+viewSize.height-GameLayer->getBoundingBox().getMaxY());
//            }
//        }
//        else {
//        }
//    }
//    else if(!isMultitouch){
//        isAncorpointSet=false;
//
//        if(noTouch==1){
//            GameLayer->setAnchorPoint(Vec2(0.5f,0.5f));
//            GameLayer->setPosition(GameLayer->getPosition()+location-touches.at(0)->getPreviousLocation());
//            if(GameLayer->getBoundingBox().getMinX()>=0
//               ||GameLayer->getBoundingBox().getMaxX()<=viewSize.width
//               ||GameLayer->getBoundingBox().getMinY()>=0
//               ||GameLayer->getBoundingBox().getMaxY()<=viewSize.height){
//                if(GameLayer->getBoundingBox().getMinX()>=0){
//                    GameLayer->setPositionX(GameLayer->getPositionX()+0-GameLayer->getBoundingBox().getMinX());
//                }
//                if (GameLayer->getBoundingBox().getMaxX()<=viewSize.width){
//                    GameLayer->setPositionX(GameLayer->getPositionX()+viewSize.width-GameLayer->getBoundingBox().getMaxX());
//                }
//                if(GameLayer->getBoundingBox().getMinY()>=0){
//                    GameLayer->setPositionY(GameLayer->getPositionY()+0-GameLayer->getBoundingBox().getMinY());
//                }
//                if (GameLayer->getBoundingBox().getMaxY()<=viewSize.height){
//                    GameLayer->setPositionY(GameLayer->getPositionY()+viewSize.height-GameLayer->getBoundingBox().getMaxY());
//                }
//            }
//        }
//    }
}

void Sample_class::onTouchEnded(const std::vector<Touch*>& touches, Event *event) {
    location = touches.at(0)->getLocation();
    CCLOG("onTouchEnded Location: (%f, %f)", location.x, location.y);
    if(Moveno>0)
    {
        for (int i=1; i<=slice_num; i++)
        {
            if(Dumy_Jigsaw[i]->getPosition().getDistance(Jigsaw_Part[Moveno]->getPosition())<300
               &&
               Dumy_Jigsaw[i]->getTag()-Jigsaw_Part[Moveno]->getTag()==0)
            {
                GameController::getInstance()->playSFX("buttonTiptop.mp3");


                CCLOG("Dmy %d Jigsaw_Part %d",Dumy_Jigsaw[i]->getTag(),
                      Jigsaw_Part[Moveno]->getTag());
                Jigsaw_Part[Moveno]->setLocalZOrder(0);

                auto call_sound_op = CallFunc::create([&](){

                    int rand_vocul = random(1,4);

                    GameController::getInstance()->playSFX(StringUtils::format("praise_%d.mp3",rand_vocul).c_str());

                });

                Dumy_Jigsaw[i]->runAction(Sequence::create(Show::create(),
                                                           ScaleTo::create(0.2,0.9),
                                                           ScaleTo::create(0.3,1.0f),
                                                           call_sound_op,
                                                           NULL));
                Dumy_Jigsaw[i]->setOpacity(255);

                Jigsaw_Part[Moveno]->setVisible(false);
                Jigsaw_Part[Moveno]->setScale(0);
                Count_set++;
                CCLOG("%d --- Count_set" ,Count_set);
                Moveno = 0;
                CCLOG("count-->puzzzel %d",Count_set);
                if (Count_set == slice_num) {

                    // CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("complete_particle.mp3");
                    // ParticleSystem *p1=ParticleSystemQuad::create("Blast_Creck.plist");
                    // p1->setPosition(Vec2(IPAD_WIDTH/2+118, IPAD_HEIGHT/2-12-50));
                    // this->addChild(p1,100);

                    // ParticleSystem *p2=ParticleSystemQuad::create("Blast_Creck.plist");
                    // p2->setPosition(Vec2(IPAD_WIDTH/2-118, IPAD_HEIGHT/2+100));
                    // this->addChild(p2,100);

                     Fill_Img->setVisible(true);
                     //Jigsaw_Border1->setVisible(true);

                    auto calview = CallFunc::create([&](){
                        // this->scheduleOnce(SEL_SCHEDULE(&jigsaw2::GotoNext), 3);
                        if(Prog_score > 95){
                            Prog_score = 0;
                             playCount = playCount+1;
                            loadingbar->setPercent(100);
                            checkHiddenComplite();
//                            Comp_layer->runAction(Sequence::create(Spawn::create(
//                                  EaseBackOut::create(ScaleTo::create(0.3, 1,1)),
//                                   MoveTo::create(0.2, Vec2(0, 0)), NULL),NULL));


                      }
                    });

//                    CountSc = CountSc+1;
//                    Prog_score = CountSc*6;
//                    loadingbar->setPercent(Prog_score);
                    //loadingbar->setPercent(CountSc*6);


//                     Fill_Img->runAction(Sequence::create(DelayTime::create(0.5f),
//                                                         Show::create(),
//                                                        calview, NULL));

                    Fill_Img->runAction(Sequence::create(calview,DelayTime::create(0.5f),Show::create(), NULL));

                }
                CountSc = CountSc+1;
                Prog_score = CountSc*6;
                loadingbar->setPercent(Prog_score);

                if(Put_Cnt<slice_num)
                {
                    Set_Puzzel(Last_Point);
                }
                break;
            }
        }
        if(Moveno>0)
        {
            GameController::getInstance()->playSFX(COM_MOVE);
//        Jigsaw_Part[Moveno]->setGlobalZOrder(10);

            Jigsaw_Part[Moveno]->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(Sample_class::SetOrder, this,Moveno)),
                                                            Spawn::create(
                                                                    ScaleTo::create(0.2, 0.5),
                                                                    MoveTo::create(0.2, Last_Point),NULL), NULL));


            Moveno=0;
            CCLOG("count-->puzzzel %d CountSc %d",Count_set,CountSc);
        }
    }
//    if(noTouch>0){
//        noTouch = noTouch-(int)touches.size();
//    }
//    if(noTouch==0||noTouch==1){
//        isMultitouch=false;
//    }
//
//    if(location.y>90&&location.y<viewSize.height-90&&startLoc==location){
//        noTap++;
//        GameController::getInstance()->playSFX(SFX_RONG);
//        if(noTap%5==0) {
//
//            Label *notificationTex=Label::createWithTTF(StringUtils::format("-5 Sec"), TTF_FONT_1, 25);
//            notificationTex->setPosition(location);
//            GameLayer->addChild(notificationTex);
//            gameTime=gameTime-5;
//            notificationTex->runAction(Sequence::create(Spawn::create(FadeOut::create(1),MoveBy::create(1.0f, Vec2(0,50)), NULL),RemoveSelf::create(), NULL));
//
//            if (gameTime<0) {
//                gameTime=0;
//            }
//        }
//    }

}
void Sample_class::SetOrder(int moveitem)
{
    Jigsaw_Part[moveitem]->setLocalZOrder(3);//1
}
//void Sample_class::GotoNext()
//{
//    Director::getInstance()->replaceScene(TransitionFade::create(0.4, jigsaw2::createScene(), Color3B::WHITE));
//
//}
void Sample_class::Set_Puzzel(Point Lst_Point)
{
    Put_Cnt++;
    Jigsaw_Part[Put_Cnt]->setPosition(Lst_Point);
    Jigsaw_Part[Put_Cnt]->runAction(EaseOut::create(ScaleTo::create(0.3, 0.5),0.2));

    CCLOG("Put_Cnt %d",Put_Cnt);
}
void Sample_class::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
    GameController::getInstance()->playSFX(SFX_BTN_TAP);
    if (keyCode == EventKeyboard::KeyCode::KEY_BACK || keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE) {
        GameController::getInstance()->createScene(SCREEN_LEVEL);
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
        
    }
}
void Sample_class::disObjTouch(Ref* pSender) {
//    MenuItemSprite *Img=(MenuItemSprite *)pSender;
//    int tag=Img->getTag();
//    if(disObjImg[tag]->isVisible()){
//        GameController::getInstance()->playSFX(SFX_OBJ_TAP);
//        noTap=0;
//        levelObjNo++;
//        levelScore->setString(StringUtils::format("%d/%d",levelObjNo,10));
//        Img->setEnabled(false);
//        Img->runAction(Sequence::create(ScaleTo::create(0.2, 1.1f),ScaleTo::create(0.3, 0.0f),CallFuncN::create(CC_CALLBACK_1(Sample_class::checkHiddenComplite,this)), NULL));
//        particleHidden[tag]->resetSystem();
//        disObjImg[tag]->runAction(Sequence::create(EaseBackInOut::create(ScaleTo::create(0.3, 0.0f)), NULL));
//        //GameLayer->removeChild(particleHint[tag]);
//        addNewHiddenDisObj(disObjImg[tag]->getTag());
//    }
}
void Sample_class::disObjTouchBack(Ref* pSender) {
//    MenuItemSprite *Img=(MenuItemSprite *)pSender;
//    int tag=Img->getTag();
//    if(isHint3Active) {
//        if(particleHint[disObjImgBack[tag]->getTag()]){
//            if(!particleHint[disObjImgBack[tag]->getTag()]->isVisible()) {
//                isHint3Active=false;
//                particleHint[disObjImgBack[tag]->getTag()]->setVisible(true);
//                particleHint[disObjImgBack[tag]->getTag()]->resetSystem();
////                particleHint[disObjImgBack[tag]->getTag()]->setPosition(Vec2(GameLayer->convertToNodeSpace(Img->getPosition())));
////                particleHint[disObjImgBack[tag]->getTag()]->runAction(Sequence::create(MoveTo::create(1.0f, originalPositions.at(disObjImgBack[tag]->getTag())),nullptr));
//            }
//        }
//    }
}
void Sample_class::addNewHiddenDisObj(int no_pos) {
//    bool isNewObj=false;
//    for (int i=0; i<10; i++) {
//        if(!disObjImg[i]->isVisible() && disObjImg[i]->getScale()==0){
//            isNewObj=true;
//        }
//    }
//
//    if(!isNewObj){
//        disObjImgBack[no_pos]->runAction(EaseBackInOut::create(ScaleTo::create(0.5, 0.0f)));
//    }
//
//    while (isNewObj) {
//        int rand_no=GameController::getInstance()->getRandom(0, 9);
//        if(!disObjImg[rand_no]->isVisible() && disObjImg[rand_no]->getScale()==0) {
//            isNewObj=false;
//            disObjImg[rand_no]->setVisible(true);
//            disObjImgBack[no_pos]->setTag(rand_no);
//            disObjImg[rand_no]->setTag(no_pos);
//            disObjImg[rand_no]->setPosition(disObjPosition[no_pos]);
//            disObjImg[rand_no]->runAction(EaseBackInOut::create(ScaleTo::create(0.5, 1.0f)));
//        }
//    }
}
void Sample_class::checkHiddenComplite() {
    bool levelComplitaed=true;
    for (int i=1; i<=slice_num; i++) {
        CCLOG("%d !Dumy_Jigsaw[%d]->isVisible() && Dumy_Jigsaw[%D]->getPosition()==Dumy_Jigsaw[%d]->getPosition()",i,!Dumy_Jigsaw[i]->isVisible(),Dumy_Jigsaw[i]->getPosition(),Dumy_Jigsaw[i]->getPosition());
        if(Jigsaw_Part[i]->isVisible()){
            levelComplitaed=false;
            //break;
        }
    }

    if(levelComplitaed) {
        //levelComplite(0.0f);
//        StopTimer();
//        Sprite *popupTaxt=Sprite::create("start_EXX.png");
//        popupTaxt->setPosition(viewSize/2);
//        popupTaxt->setScale(0);
//       // GameLayer->addChild(popupTaxt,10);

//        ParticleSystemQuad *particle=ParticleSystemQuad::create("exx_particale_.plist");
//        CompLayer->addChild(particle,-1);
//        particle->setPosition(CompLayer->getContentSize()/2);


        //CompLayer->runAction(EaseBackInOut::create(ScaleTo::create(0.5, 1.0f)));
//        CompLayer->runAction(Sequence::create(Spawn::create(
//                                 EaseBackOut::create(ScaleTo::create(0.3, 1,1)),
//                                  MoveTo::create(0.2, Vec2(0, 0)), NULL),NULL));

        auto staticUpdatePtr = static_cast<cocos2d::SEL_SCHEDULE>(&Sample_class::levelComplite);
        this->scheduleOnce(staticUpdatePtr,1.0f);
    }
}
void Sample_class::StartTimer() {
    StopTimer();
    RepeatForever *action=RepeatForever::create(Sequence::create(DelayTime::create(1.0f),CallFuncN::create(CC_CALLBACK_1(Sample_class::timerCounter, this)), NULL));
    action->setTag(5594);
    this->runAction(action);
}
void Sample_class::StopTimer() {
    this->stopActionByTag(5594);
}
void Sample_class::timerCounter(Ref *pSender){
    gameTime--;
    if (gameTime<0) {
        gameTime=0;
    }
    int min=(float)gameTime/60;
    lblTimer->setString(StringUtils::format("%02d:%02d",min,gameTime%60));

    if(gameTime>0&&gameTime<=5){
        GameController::getInstance()->playSFX(SFX_TIME_LOW);
    }
    if(gameTime<=0){
        GameController::getInstance()->playSFX(SFX_GAME_OVER);
//        Vec2 menuPos=menuBtn->getPosition();
//
//        menuBtn->setPosition(Vec2(replayBtn->getPositionX()+30,replayBtn->getPositionY()));
//        shareBtn->setPositionX(shareBtn->getPositionX()-30);
        rateBtn->setPositionX(rateBtn->getPositionX()-30);
//        replayBtn->setPosition(Vec2(menuPos.x-30,menuPos.y));
       // popupCompliteTaxt->setTexture("popup_gameover.png");
        replayBtn1->setScale(1);
        replayBtn1->setPosition(Vec2(viewSize.width/2+3,305));
//        replayBtn1->setScaleX(GameController::getInstance()->imgScaleX*1.3);
//        replayBtn1->setScaleY(1.3);
        //popupBord->setTexture("popup_gameover.png");
        for (int j=0; j<5; j++)
        {
            levelStar[j]->setScale(0);
        }
        nextBtn->setScale(0);
        popupScore->setScale(0);
        popupHighScore->setScale(0);
        lblScore->setScale(0);
        lblHighScore->setScale(0);
        this->stopActionByTag(5594);
        CompLayer->setVisible(true);
        CompLayer->setScale(0);
        CompLayer->runAction(Sequence::create(DelayTime::create(1),EaseBackOut::create(ScaleTo::create(0.5, 1.0f)), NULL));
        GameController::getInstance()->getExtras()->showAds(2);
        GameController::getInstance()->getExtras()->loadAds(2);
        this->runAction(Sequence::create(DelayTime::create(3.0f),CallFuncN::create(CC_CALLBACK_0(Extras::loadAds, GameController::getInstance()->getExtras(),2)), NULL));
    }
}
void Sample_class::levelComplite(float dt) {
     GameController::getInstance()->playSFX(SFX_LEVEL_COMPLITE);
    //GameController::getInstance()->getExtras()->showAds(2);
    //GameController::getInstance()->getExtras()->loadAds(2);
    //this->runAction(Sequence::create(DelayTime::create(3.0f),CallFuncN::create(CC_CALLBACK_0(Extras::loadAds, GameController::getInstance()->getExtras(),2)), NULL));
//    int score=0;
//    score = (9.0f)*gameTime;
//
//    int subLevelStar=GameController::getInstance()->getIntegerForKey(StringUtils::format("%d_sub_score%d",mainLevelNo,1).c_str(),score);
//    if(subLevelStar<=score){
//        subLevelStar=score;
//        GameController::getInstance()->setIntegerForKey(StringUtils::format("%d_sub_score%d",mainLevelNo,1).c_str(),score);
//    }
//
//    for (int i=0; i<5; i++) {
//        if((float)subLevelStar>i*200+5) {
//            levelStar[i]->setSpriteFrame(Sprite::create(StringUtils::format("level_screen_star_%d.png",1))->getSpriteFrame());
//            levelStar[i]->setScale(0.0f);
//            levelStar[i]->runAction(Sequence::create(DelayTime::create(1.5f+i*0.2f),ScaleTo::create(0.3f, 1.2f),Spawn::create(ScaleTo::create(0.3f, 1.0f),CallFuncN::create(CC_CALLBACK_0(GameController::playSFX, GameController::getInstance(),"star.mp3")), NULL), NULL));
//        }
//        else {
//            levelStar[i]->setSpriteFrame(Sprite::create(StringUtils::format("level_screen_star_%d.png",0))->getSpriteFrame());
//            levelStar[i]->setScale(0.0f);
//            levelStar[i]->runAction(Sequence::create(DelayTime::create(1.5f+i*0.2f),ScaleTo::create(0.3f, 1.2f),Spawn::create(ScaleTo::create(0.3f, 1.0f), NULL), NULL));
//        }
//    }
////    DEFAULT_LEVEL=UserDefault::getInstance()->getIntegerForKey("DEFAULT_LEVEL");
////    log("DEFAULT_LEVEL=======%d",DEFAULT_LEVEL);
////    DEFAULT_LEVEL=DEFAULT_LEVEL+1;
////    UserDefault::getInstance()->setIntegerForKey("DEFAULT_LEVEL",DEFAULT_LEVEL);
////    UserDefault::getInstance()->flush();
//
//    int userLevel=GameController::getInstance()->getIntegerForKey("level",0);
//
//    if((mainLevelNo-1)*2==userLevel) {
//        GameController::getInstance()->setIntegerForKey("level",GameController::getInstance()->getIntegerForKey("level",0)+1);
//    }

    //lblScore->setString(StringUtils::format("%d",score));
    //lblHighScore->setString(StringUtils::format("%d",subLevelStar));
    CompLayer->setVisible(true);
    CompLayer->setScale(0);
    CompLayer->runAction(
            Sequence::create(DelayTime::create(1), EaseBackOut::create(ScaleTo::create(0.5, 1.0f)),
                             NULL));
    //nextBtn->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(0.5, 0.9f),ScaleTo::create(0.5, 0.85f), NULL)));

    //ScaleTo *scaleP=ScaleTo::create(0.5, 1.05*GameController::getInstance()->imgScaleX,1.05);
    //ScaleTo *scaleM=ScaleTo::create(0.5, 0.95*GameController::getInstance()->imgScaleX,0.95);

    //nextBtn->runAction(RepeatForever::create(Sequence::create(scaleP,scaleM ,NULL)));


    if(lvl_num==61){
        popupCompliteTaxt->setTexture("Game-complete.png");
        nextBtn->setScale(0);
        replayBtn1->setScale(0);
        homeBtn1->setScale(0);
        restart->setScale(1);

    }


    if (lvl_num % 10 == 0) {
        if (!UserDefault::getInstance()->getBoolForKey("RateDone", false)) {
            RateLayer->setVisible(true);
            RateLayer->runAction(Sequence::create(ScaleTo::create(0.0f, 0.0f), Show::create(),
                                                  DelayTime::create(0.8f),
                                                  ScaleTo::create(0.2f, 1.0f), NULL));
        }
    }
}
void Sample_class::call_popup_btn(Ref *pSender){
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    GameController::getInstance()->playSFX(SFX_BTN_TAP);
    if(tag==homeBtn->getTag()) {
        GameController::getInstance()->createScene(SCREEN_LEVEL);
    }
//    else if(tag==replayBtn->getTag()){
//        GameController::getInstance()->createScene(SCREEN_HIDDEN_PLAY);
//    }
//    else if(tag==nextBtn->getTag()) {
//        GameController::getInstance()->setIntegerForKey("CURRENT_LEVEL",lvl_num + 1);
//        GameController::getInstance()->createScene(SCREEN_HIDDEN_PLAY);
//    }
//    else if(tag==menuBtn->getTag()) {
//        GameController::getInstance()->createScene(SCREEN_LEVEL);
//    }
//    else if(tag==rateBtn->getTag()) {
//        GameController::getInstance()->getExtras()->openAppStore();
//    }
    else if(tag==shareBtn->getTag()) {
        GameController::getInstance()->getExtras()->showShareContent();
    }
//    else if(tag==laterBtn->getTag()) {
//        RateLayer->setScale(0);
//    }
    else if(tag==resumeBtn->getTag()){
        this->stopActionByTag(5594);
        StartTimer();
       // PauseLayer->setVisible(false);
        //PauseLayer->runAction(Sequence::create(DelayTime::create(0),EaseBackOut::create(ScaleTo::create(0.1, 0.0f)), NULL));
        //SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);
        GameController::getInstance()->pauseSounds();
    }
    else if(tag == puaseBtn->getTag()){
      //  PauseLayer->setVisible(true);
       // PauseLayer->runAction(Sequence::create(DelayTime::create(0),EaseBackOut::create(ScaleTo::create(0.1, 1.0f)), NULL));
        this->stopActionByTag(5594);
        //SimpleAudioEngine::getInstance()-
        GameController::getInstance()->resumeSounds();
    }
}
void Sample_class::call_hint(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();

    if(tag==hint1Btn->getTag()){
        if(noHint[1]>0){
            GameController::getInstance()->playSFX(SFX_HINT_1);
            noHint[1]--;
            lblHint[0]->setString(StringUtils::format("%d",noHint[1]));
            for (int i=0; i<10; i++) {
                if(particleHint[i]){
                    if(disObjImg[i]->isVisible()&&disObjImg[i]->getScale()!=0&&!particleHint[i]->isVisible()) {
                        particleHint[i]->setVisible(true);
                        particleHint[i]->resetSystem();
//                        particleHint[i]->setPosition(hint1Btn->getPosition());
//                        particleHint[i]->runAction(Sequence::create(MoveTo::create(1.0f, originalPositions.at(i)),nullptr));
                        break;
                    }
                }
            }
        }
    }
    else if (tag==hint2Btn->getTag()){
        if(noHint[2]>0){
            --noHint[2];
            GameController::getInstance()->playSFX(SFX_HINT_2);
            lblHint[1]->setString(StringUtils::format("%i",noHint[2]));
            Hint2Bg->runAction(Sequence::create(ScaleTo::create(0.0, 1.0f),FadeIn::create(0.01f),DelayTime::create(2),FadeOut::create(1.5f), NULL));
        }
    }
    else if (tag==hint3Btn->getTag()){
        if(noHint[3]>0){
            --noHint[3];
            GameController::getInstance()->playSFX(SFX_HINT_3);
            lblHint[2]->setString(StringUtils::format("%i",noHint[3]));
            hint3Btn->setNormalImage(Sprite::create("hint33.png"));
            hint3Btn->setSelectedImage(Sprite::create("hint33.png"));
            isHint3Active=true;
        }
    }
}
void Sample_class::replaybtn1(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    if(tag==replayBtn1->getTag()){
        //GameController::getInstance()->setIntegerForKey("CURRENT_LEVEL",lvl_num);
        GameController::getInstance()->createScene(SCREEN_HIDDEN_PLAY);
    }
}
void Sample_class::nextbtn(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    if(tag==nextBtn->getTag()){
        GameController::getInstance()->getExtras()->showAds(2);
        GameController::getInstance()->getExtras()->loadAds(2);
//        lvl_num = imagenum1+1;
        imagenum1=imagenum1+1;
        //GameController::getInstance()->setIntegerForKey("CURRENT_LEVEL",lvl_num + 1);
        GameController::getInstance()->createScene(SCREEN_HIDDEN_PLAY);
    }
}
void Sample_class::rate(Ref *pSender) {
   MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
   if(tag==ratenowBtn->getTag()){
//        GameController::getInstance()->setIntegerForKey("CURRENT_LEVEL",lvl_num);
//        GameController::getInstance()->createScene(SCREEN_HIDDEN_PLAY);
       GameController::getInstance()->getExtras()->openAppStore();

    }
}
void Sample_class::level_btn1(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    if(tag==lvlbtn->getTag()) {
        GameController::getInstance()->getExtras()->showAds(2);
        GameController::getInstance()->getExtras()->loadAds(2);
        GameController::getInstance()->createScene(SCREEN_LEVEL);
    }
}
#pragma -mark- homw1


void Sample_class::home_btn1(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    if(tag==homeBtn1->getTag()){
        GameController::getInstance()->getExtras()->showAds(2);
        GameController::getInstance()->getExtras()->loadAds(2);
        GameController::getInstance()->createScene(SCREEN_LEVEL);
    }
}
void Sample_class::rest_btn1(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    if(tag==restart->getTag()){
        GameController::getInstance()->getExtras()->showAds(2);
        GameController::getInstance()->getExtras()->loadAds(2);
        GameController::getInstance()->createScene(SCREEN_LEVEL);
    }
}
void Sample_class::Later(Ref *pSender) {
    MenuItemSprite *Img=(MenuItemSprite *)pSender;
    int tag=Img->getTag();
    if(tag==laterBtn->getTag()) {
        RateLayer->setScale(0);
    }
}
