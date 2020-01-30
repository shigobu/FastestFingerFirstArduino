#define PIN_IS_NOT_CONNECTED -1

/*
//早押しボタン判定クラス

*/

//現在の状態を表す列挙型
enum ButtonPushedStatus
{
    standby,
    button1,
    button2,
    button3,
    button4,
    button5,
    button6,
    externalButton
};

class FastestFingerFirstButton
{
//変数
public:
    //公開する変数は無い。

private:
    ButtonPushedStatus status;

    int button1Pin;
    int button2Pin;
    int button3Pin;
    int button4Pin;
    int button5Pin;
    int button6Pin;
    int LED1Pin;
    int LED2Pin;
    int LED3Pin;
    int LED4Pin;
    int LED5Pin;
    int LED6Pin;

    //外部拡張ボードからの入力ピン
    //LOWになったら外部拡張ボードのボタンが押された。
    int externalButtonPin;

    //外部拡張ボードへの出力ピン
    //このボードのボタンが押されたときにHIGHにする
    int externalCommunicatingPin;

    int resetButtonPin;
    int correctButtonPin;
    int incorrectButtonPin;

    int speakerPin;

//関数
public:
    //デフォルトコンストラクタ
    FastestFingerFirstButton();

    //ボタンの入力状態をチェックします。loop内で継続的に呼び出して使用します。
    void CheckIfButtonPushed();
    //ボタンの状態を返します。（待受中か否か）
    ButtonPushedStatus GetButtonStatus();

    //ボタン1の使用するピンを設定します。
    void PinSettingButton1(int buttonPin, int LEDPin);
    //ボタン2の使用するピンを設定します。
    void PinSettingButton2(int buttonPin, int LEDPin);
    //ボタン3の使用するピンを設定します。
    void PinSettingButton3(int buttonPin, int LEDPin);
    //ボタン4の使用するピンを設定します。
    void PinSettingButton4(int buttonPin, int LEDPin);
    //ボタン5の使用するピンを設定します。
    void PinSettingButton5(int buttonPin, int LEDPin);
    //ボタン6の使用するピンを設定します。
    void PinSettingButton6(int buttonPin, int LEDPin);
    
    //外部ボタンの使用するピンを設定します。
    void PinSettingExternalButton(int pin);
    //外部ボタンの切り替えを行うピンを設定します。
    void PinSettingExternalCommunicating(int pin);

    //リセットボタンの使用するピンを設定します。
    void PinSettingResetButton(int pin);
    //正解ボタンの使用するピンを設定します。
    void PinSettingCorrectButton(int pin);
    //不正解ボタンの使用するピンを設定します。
    void PinSettingIncorrectButton(int pin);

    //スピーカーのピンを設定します。
    void PinSettingSpeaker(int pin);

    //ボタンが押された時の「ピンポン」音を再生します。
    void PlayYesSound();
private:
    //正解音を再生します。
    void PlayCorrectSound();
    //不正解音を再生します。
    void PlayIncorrectSound();
    //リセットします。
    void Reset();

    //一個づつのボタンの判定を行います。
    //引数 buttonPin       判定するボタンのピン番号
    //     LEDPin          点灯させるLEDのピン番号
    //     stateusToSet    設定する状態
    void CheckIfPlayerButtonPushed(int buttonPin, int LEDPin, ButtonPushedStatus stateusToSet);
};