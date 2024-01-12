#include "SceneManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"
#include "EndScene.h"
#include "DxLib.h"

/*****************************************
*�}�N����`
******************************************/

/*****************************************
*�^��`
******************************************/

/*****************************************
*�ϐ���`
******************************************/
GAME_MODE game_mode;        //�Q�[�����[�h���
GAME_MODE next_mode;        //���̃Q�[�����[�h���
int read_error;                   //�ǂݍ��݃G���[�m�F

/*****************************************
*�v���g�^�C�v�錾
******************************************/

/*****************************************
* �V�[���Ǘ��@�\�F����������
* ���@���F�Q�[�����[�h���
* �߂�l�F�Ȃ�
******************************************/
void SceneManager_Initialize(GAME_MODE mode)
{
	read_error = D_NORMALITY;
	switch (mode)
	{
	case E_TITLE:
		read_error = TitleScene_Initialize();        //�^�C�g����ʂ̏�����
		break;
	case E_GAMEMAIN:
		read_error = GameMainScene_Initialize();     //�Q�[�����C����ʂ̏�����
		break;
	case E_RANKING:
		if (game_mode == E_GAMEMAIN)
		{
			Set_RankingMode(RANKING_INPUT_MODE);     //�����L���O���[�h�ŋN��
		}

	}
}