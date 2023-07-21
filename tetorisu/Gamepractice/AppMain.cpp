/*****************************************
*プログラミング実習
* マッチ3ゲームの製作
******************************************/

#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"

/*****************************************
*マクロ定義
******************************************/

#define SCREAN_HEIGHT     (480)   //スクリーンサイズ（高さ）
#define SCREAN_WIDTH      (640)   //スクリーンサイズ（幅）
#define SCREAN_COLORBIT   (32)    //スクリーンカラービット
#define FONT_SIZE         (20)    //文字サイズ

/*****************************************
*型定義
******************************************/

/*****************************************
*グローバル変数宣言
******************************************/

/*****************************************
*プロトタイプ宣言
******************************************/

/*****************************************
*プログラムの開始
******************************************/

int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_ int nShowCmd)
{

	//ウィンドウタイトル設定
	SetMainWindowText("Match 3 Puzzle");

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//画面サイズの最大サイズ、カラービット数を設定
	SetGraphMode(SCREAN_WIDTH, SCREAN_HEIGHT, SCREAN_COLORBIT);

	//Dxライブラリの初期化処理
	//エラーが発生したら、終了する
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;

	}

	//各機能の初期化設定
	FreamControl_Initialize();     //フレームレート制御機能
	Input_Initialize();            //入力制御機能

	//シーンマネージャー初期化処理
	//エラーが発生したら、終了する
	if (SceneManager_Initialize(E_TITLE) == D_ERROR)
	{
		return D_ERROR;

	}


	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//文字サイズを設定
	SetFontSize(FONT_SIZE);

	//ゲームループ
	while (ProsessMassage() != D_ERROR && Input_Escape() == FALSE)
	{
		//入力制御機能更新処理
		Input_Update();

		//シーンマネージャー更新処理
		SceneManager_Update();

		//画面クリア
		ClearDrowScrean();

		//シーンマネージャー描画処理
		SceneManager_Draw();

		//フレームレート制御処理
		FreamControl_Update();

		//画面の内容を表画面に反映
		ScreenFlip();

	}


	//Dxライブラリ使用の終了処理
	DxLib_End();

	return 0;
}