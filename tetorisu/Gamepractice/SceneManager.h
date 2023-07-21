#pragma once

/*****************************************
*�}�N����`
******************************************/
#define D_ERROR   (-1)
#define D_NORMALITY (0)

/*****************************************
*�^��`
******************************************/
enum GAME_MODE
{
	E_TITLE,
	E_GAMEMAIN,
	E_GAME_CLEAR,
	E_GAME_OVER,
	E_END,
	E_MODE_MAX,
};

/*****************************************
*�v���g�^�C�v�錾
******************************************/
int SceneManager_Initialize(GAME_MODE mode);    //����������
void SceneManager_Update(void);                 //�X�V����
void SceneManager_Draw(void);                   //�`�揈��

void Change_Scene(GAME_MODE mode);                   //�V�[���ύX����
