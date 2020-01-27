#include "FFFButton.h"
//#include <Arduino.h>
FastestFingerFirstButton::FastestFingerFirstButton()
{
    button1Pin = PIN_IS_NOT_CONNECTED;
    button2Pin = PIN_IS_NOT_CONNECTED;
    button3Pin = PIN_IS_NOT_CONNECTED;
    button4Pin = PIN_IS_NOT_CONNECTED;
    button5Pin = PIN_IS_NOT_CONNECTED;
    button6Pin = PIN_IS_NOT_CONNECTED;
    LED1Pin = PIN_IS_NOT_CONNECTED;
    LED2Pin = PIN_IS_NOT_CONNECTED;
    LED3Pin = PIN_IS_NOT_CONNECTED;
    LED4Pin = PIN_IS_NOT_CONNECTED;
    LED5Pin = PIN_IS_NOT_CONNECTED;
    LED6Pin = PIN_IS_NOT_CONNECTED;

    externalButtonPin = PIN_IS_NOT_CONNECTED;
    externalCommunicatingPin = PIN_IS_NOT_CONNECTED;

    resetButtonPin = PIN_IS_NOT_CONNECTED;
    correctButtonPin = PIN_IS_NOT_CONNECTED;
    incorrectButtonPin = PIN_IS_NOT_CONNECTED;

    speakerPin = PIN_IS_NOT_CONNECTED;
}

void FastestFingerFirstButton::CheckIfButtonPushed()
{    
    //回答者ボタンの判定
    CheckIfPlayerButtonPushed(button1Pin, LED1Pin, ButtonPushedStatus::button1);
    CheckIfPlayerButtonPushed(button2Pin, LED2Pin, ButtonPushedStatus::button2);
    CheckIfPlayerButtonPushed(button3Pin, LED3Pin, ButtonPushedStatus::button3);
    CheckIfPlayerButtonPushed(button4Pin, LED4Pin, ButtonPushedStatus::button4);
    CheckIfPlayerButtonPushed(button5Pin, LED5Pin, ButtonPushedStatus::button5);
    CheckIfPlayerButtonPushed(button6Pin, LED6Pin, ButtonPushedStatus::button6);
    CheckIfPlayerButtonPushed(externalButtonPin, PIN_IS_NOT_CONNECTED, ButtonPushedStatus::externalButton);
    //回答者ボタンの判定ここまで

    //正解ボタンの判定
    if (digitalRead(correctButtonPin) == LOW){
        PlayCorrectSound();
    }
    //不正解ボタンの判定
    if (digitalRead(incorrectButtonPin) == LOW){
        PlayIncorrectSound();
    }
    //リセットボタンの判定
    if (digitalRead(resetButtonPin) == LOW){
        Reset();
    }
}

void FastestFingerFirstButton::CheckIfPlayerButtonPushed(int buttonPin, int LEDPin, ButtonPushedStatus stateusToSet)
{
    //待機状態で無い時終了
    if (status != ButtonPushedStatus::standby){
        return;
    }
    
    //ピン番号がマイナスであった場合終了
    if (buttonPin < 0){
        return;
    }

    if (digitalRead(buttonPin) == LOW){

        if (LEDPin > -1){
            digitalWrite(LEDPin, HIGH);
        }        

        if (externalCommunicatingPin > -1){
            digitalWrite(externalCommunicatingPin, HIGH);
        }        
        PlayYesSound();
        if (externalCommunicatingPin > -1){
            digitalWrite(externalCommunicatingPin, LOW);
        }        
        status = stateusToSet;
    }
}

ButtonPushedStatus FastestFingerFirstButton::GetButtonStatus()
{
    return status;
}

void FastestFingerFirstButton::PinSettingButton1(int buttonPin, int LEDPin)
{
    button1Pin = buttonPin;
    LED1Pin = LEDPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LEDPin, OUTPUT);
}
void FastestFingerFirstButton::PinSettingButton2(int buttonPin, int LEDPin)
{
    button2Pin = buttonPin;
    LED2Pin = LEDPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LEDPin, OUTPUT);
}
void FastestFingerFirstButton::PinSettingButton3(int buttonPin, int LEDPin)
{
    button3Pin = buttonPin;
    LED3Pin = LEDPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LEDPin, OUTPUT);
}
void FastestFingerFirstButton::PinSettingButton4(int buttonPin, int LEDPin)
{
    button4Pin = buttonPin;
    LED4Pin = LEDPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LEDPin, OUTPUT);
}
void FastestFingerFirstButton::PinSettingButton5(int buttonPin, int LEDPin)
{
    button5Pin = buttonPin;
    LED5Pin = LEDPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LEDPin, OUTPUT);
}
void FastestFingerFirstButton::PinSettingButton6(int buttonPin, int LEDPin)
{
    button6Pin = buttonPin;
    LED6Pin = LEDPin;
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LEDPin, OUTPUT);
}
    
void FastestFingerFirstButton::PinSettingExternalButton(int pin)
{
    externalButtonPin = pin;
    pinMode(pin, INPUT_PULLUP);
}
void FastestFingerFirstButton::PinSettingExternalCommunicating(int pin)
{
    externalCommunicatingPin = pin;
    pinMode(pin, OUTPUT);
}

void FastestFingerFirstButton::PinSettingResetButton(int pin)
{
    resetButtonPin = pin;
    pinMode(pin, INPUT_PULLUP);
}
void FastestFingerFirstButton::PinSettingCorrectButton(int pin)
{
    correctButtonPin = pin;
    pinMode(pin, INPUT_PULLUP);
}
void FastestFingerFirstButton::PinSettingIncorrectButton(int pin)
{
    incorrectButtonPin = pin;
    pinMode(pin, INPUT_PULLUP);
}
void FastestFingerFirstButton::PinSettingSpeaker(int pin)
{
    speakerPin = pin;
    pinMode(pin, OUTPUT);
}
void FastestFingerFirstButton::PlayYesSound()
{
    if (speakerPin < 0)
    {
        return;
    }
    
}
void FastestFingerFirstButton::PlayCorrectSound()
{

}
void FastestFingerFirstButton::PlayIncorrectSound()
{

}
void FastestFingerFirstButton::Reset()
{
    //全LEDの消灯
    if (LED1Pin > -1){
        digitalWrite(LED1Pin, LOW);
    }        
    if (LED2Pin > -1){
        digitalWrite(LED2Pin, LOW);
    }        
    if (LED3Pin > -1){
        digitalWrite(LED3Pin, LOW);
    }        
    if (LED4Pin > -1){
        digitalWrite(LED4Pin, LOW);
    }        
    if (LED5Pin > -1){
        digitalWrite(LED5Pin, LOW);
    }        
    if (LED6Pin > -1){
        digitalWrite(LED6Pin, LOW);
    }

    //外部ボードへ通知
    if (externalCommunicatingPin > -1){
        digitalWrite(externalCommunicatingPin, LOW);
    }

    //ステータスを待ち受けに変更
    status = ButtonPushedStatus::standby;

}

