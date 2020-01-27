#include "FFFButton.h"

//早押しボタンクラスのインスタンス作成
FastestFingerFirstButton FFFB;

void setup()
{
    FFFB.PinSettingButton1(2, 8);       //(pin, LED)
    FFFB.PinSettingButton2(3, 9);
    FFFB.PinSettingButton3(4, 10);
    FFFB.PinSettingButton4(5, 11);
    FFFB.PinSettingButton5(6, 12);
    FFFB.PinSettingButton6(7, 13);
    
    FFFB.PinSettingExternalButton(A0);
    FFFB.PinSettingExternalCommunicating(A1);

    FFFB.PinSettingResetButton(A2);
    FFFB.PinSettingCorrectButton(A3);
    FFFB.PinSettingIncorrectButton(A4);

    FFFB.PinSettingSpeaker(A5);

    //初期化完了、待受開始を知らせる
    FFFB.PlayYesSound();
}

void loop()
{
    FFFB.CheckIfButtonPushed();
}