#include "GameMainScene.h"
#include "DxLib.h"
#include "Block.h"
#include "SceneManager.h"

/*****************************************
*�}�N����`
******************************************/

/*****************************************
*�^��`
******************************************/

/*****************************************
*�O���[�o���ϐ��錾
******************************************/
int BackGround_image;        //�w�i�摜�C���[�W
int BackGround_sound;        //BGM
int GameOver_sound;                //�Q�[���I�[�o�[SE
int Score;                                 //�X�R�A

/*****************************************
*�v���g�^�C�v�錾
******************************************/

/*****************************************
* �Q�[�����C����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���
******************************************/
int GameMainScene_Initialize(void)
{
	int ret = 0;

	ret = Block_Initialize();
	BackGround_image = LoadGraph("images/stage.png");
	BackGround_sound = LoadSoundMem("sounds/BGM017.ogg");
	GameOver_sound = LoadSoundMem("sounds/GameOver.mp3");

	//�G���[�`�F�b�N
	if (BackGround_image == -1)
	{
		ret = -1;
	}

	if (BackGround_sound == -1)
	{
		ret = -1;
	}

	return ret;
}

/*****************************************
* �Q�[�����C����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void GameMainScene_Update(void)
{
	//BGM�̍Đ�
	PlaySoundMem(BackGround_sound, DX_PLAYTYPE_LOOP, FALSE);

	//�u���b�N�@�\�̍X�V
	Score = Get_Line() * 50;

	//�����ł��Ȃ��Ȃ�����
	if (Get_GenerateFlg() != TRUE)
	{
		PlaySoundMem(GameOver_sound, DX_PLAYTYPE_BACK, FALSE);
		Change_Scene(E_RANKING);
		StopSoundMem(BackGround_sound);
	}
}


/*****************************************
* �Q�[�����C����ʁF�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void GameMainScene_Draw(void)
{
	//�w�i�̕`��
	DrawGraph(0,0, BackGround_image,TRUE);
	//�u���b�N�̕`��
	Block_Draw();
	SetFontSize(100);
	//�X�R�A��`��
	DrawFormatString(800, 100, GetColor(255, 255, 255), "%d", Score);
	SetFontSize(20);
}

/*****************************************
* �Q�[�����C����ʁF�X�R�A�擾����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
int Get_Score(void)
{
	return Score;
}