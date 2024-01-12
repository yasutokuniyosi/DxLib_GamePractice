#include "SceneManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"
#include "EndScene.h"
#include "DxLib.h"

/*****************************************
*マクロ定義
******************************************/

/*****************************************
*型定義
******************************************/

/*****************************************
*変数定義
******************************************/
GAME_MODE game_mode;        //ゲームモード情報
GAME_MODE next_mode;        //次のゲームモード情報
int read_error;                   //読み込みエラー確認

/*****************************************
*プロトタイプ宣言
******************************************/

/*****************************************
* シーン管理機能：初期化処理
* 引　数：ゲームモード情報
* 戻り値：なし
******************************************/
void SceneManager_Initialize(GAME_MODE mode)
{
	read_error = D_NORMALITY;
	switch (mode)
	{
	case E_TITLE:
		read_error = TitleScene_Initialize();        //タイトル画面の初期化
		break;
	case E_GAMEMAIN:
		read_error = GameMainScene_Initialize();     //ゲームメイン画面の初期化
		break;
	case E_RANKING:
		if (game_mode == E_GAMEMAIN)
		{
			Set_RankingMode(RANKING_INPUT_MODE);     //ランキングモードで起動
		}

	}
}