#include "RankingScene.h"
#include "DxLib.h"
#include "InputControl.h"
#include "SceneManager.h"

/*****************************************
*�}�N����`
******************************************/

#define RANKING_FILE     ("dat/rankingdata.csv")
#define RANKING_MAX           (10)
#define RANKING_NAME_LEN    (11)
/*****************************************
*�^��`
******************************************/

typedef struct
{
	int rank;                      //�����N
	char name[RANKING_NAME_LEN];   //���O
	int score;                     //�X�R�A
}T_RANKING;

typedef struct
{
	int x;
	int y;
}T_CURSOR;

/*****************************************
*�O���[�o���ϐ��錾
******************************************/
T_RANKING Ranking_Data[RANKING_MAX];           //�����L���O�f�[�^
T_RANKING New_Score;                           //�V�����X�R�A�f�[�^
int DispMode;                                   //�\�����[�h

T_CURSOR Cursor;                                //�J�[�\���p�ϐ�
int name_num;
/*****************************************
*�v���g�^�C�v�錾
******************************************/
void file_read(void);                          //�t�@�C���ǂݍ���
void file_write(void);                          //�t�@�C����������
void ranking_sort(void);                          //�����L���O�\�[�g����
void ranking_input_name(void);                          //���O���͏���
void ranking_input_name_draw(void);                          //���O���͕`�揈��

/*****************************************
* �����L���O��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i�|�P�F�ُ�L��A�|1�ȊO�F����I���j
******************************************/
int RankingScene_Initialize(void)
{
	int ret = 0;

	file_read();

	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
			Cursor.x = 0;
			Cursor.y = 0;
			name_num = 0;
			break;
	case RANKING_DISP_MODE:
	default:

		break;
	}

	return ret;
}

/*****************************************
* �����L���O��ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void RankingScene_Update(void)
{
	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
		ranking_input_name();
		break;
	case RANKING_DISP_MODE:
	default:
		if (GetButtonDown(XINPUT_BUTTON_B))
		{
			Change_Scene(E_TITLE);
		}
		break;
	}
}

/*****************************************
* �����L���O��ʁF�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void RankingScene_Draw(void)
{
	int i;
	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
		ranking_input_name_draw();
		break;
	case RANKING_DISP_MODE:
	default:
		for (i = 0; i < RANKING_MAX; i++)
		{
			DrawFormatString(20, 10 + (i * 25), GetColor(255, 255, 255), "%2d,%10s,%10d",
				Ranking_Data[i].rank, Ranking_Data[i].name, Ranking_Data[i].score);
		}
		break;
	}
}

/*****************************************
* �����L���O��ʁF�X�R�A��������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void SetRankingScore(int score)
{
	New_Score.score = score;
}

/*****************************************
* �����L���O��ʁF�t�@�C���ǂݍ��ݏ���
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void file_read(void)
{
	FILE* fp = NULL;
	int i;

	OutputDebugString("�t�@�C����ǂݍ��݂܂�");
		fopen_s(&fp, RANKING_FILE, "r");

		if (fp == NULL)
		{
			OutputDebugString("�t�@�C�����ǂݍ��݂܂���");
			OutputDebugString("�t�@�C���𐶐����܂�");
			file_write();
		}
		else
		{
			for (i = 0; i < RANKING_MAX; i++)
			{
				fscanf_s(fp, "%2d,%[^,],%10d\n", &Ranking_Data[i].rank,
			Ranking_Data[i].name, RANKING_NAME_LEN, &Ranking_Data[i].score);
			}

			fclose(fp);
		}
}

/*****************************************
* �����L���O��ʁF�t�@�C���������ݏ���
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void file_write(void)
{
	FILE* fp = NULL;
	int i;

	OutputDebugString("�t�@�C�����������݂܂�");
	fopen_s(&fp, RANKING_FILE, "w");

	if (fp == NULL)
	{
		OutputDebugString("�t�@�C�����������߂܂���");
	}
	else
	{
		for (i = 0; i < RANKING_MAX; i++)
		{
			fprintf(fp, "%2d,%[^,],%10d\n", &Ranking_Data[i].rank,
				Ranking_Data[i].name, Ranking_Data[i].score);
		}

		fclose(fp);
	}
}

/*****************************************
* �����L���O��ʁF�����L���O�\�[�g����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void ranking_sort(void)
{
	int i, j;    //���[�v�J�E���^
	T_RANKING tmp;  //�ޔ�̈�

	//��ԉ��̃X�R�A���X�V����
	Ranking_Data[RANKING_MAX - 1] = New_Score;

	//�f�[�^�̃\�[�g���s��
	for (i = 0; i < RANKING_MAX; i++)
	{
		for (j = i + 1; j < RANKING_MAX; j++)
		{
			if (Ranking_Data[i].score < Ranking_Data[j].score)
			{
				tmp = Ranking_Data[i];
				Ranking_Data[i] = Ranking_Data[j];
				Ranking_Data[j] = tmp;
			}
		}
	}

	//���ʂ��ォ��ӂ��Ă���
	for (i = 0; i < RANKING_MAX; i++)
	{
		Ranking_Data[i].rank = i + 1;
	}
		//�t�@�C���ɏ������݂��s��
		file_write();
	
}

/*****************************************
* �����L���O��ʁF���O���͏���
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void ranking_input_name(void)
{
	int c;

	//�J�[�\�����쏈��
	if (GetButtonDown(XINPUT_BUTTON_DPAD_LEFT) == TRUE)
	{
		if (Cursor.x > 0)
		{
			Cursor.x--;
		}
	}
	if (GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT) == TRUE)
	{
		if (Cursor.x < 12)
		{
			Cursor.x++;
		}
	}
	if (GetButtonDown(XINPUT_BUTTON_DPAD_UP) == TRUE)
	{
		if (Cursor.y > 0)
		{
			Cursor.y--;
		}
	}
	if (GetButtonDown(XINPUT_BUTTON_DPAD_DOWN) == TRUE)
	{
		if (Cursor.y < 4)
		{
			Cursor.y++;
		}
	}

	//������I������
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		if (Cursor.y < 2)
		{
			c = 'a' + Cursor.x + (Cursor.y * 13);
			New_Score.name[name_num++] = c;
		}
		else if (Cursor.y < 4)
		{
			c = 'A' + Cursor.x + ((Cursor.y - 2) * 13);
			New_Score.name[name_num++] = c;
		}
		else
		{
			if (Cursor.x < 10)
			{
				c = '0' + Cursor.x;
				New_Score.name[name_num++] = c;
			}
			else if (Cursor.x == 10)
			{
				name_num--;
				New_Score.name[name_num] = '\0';
			}
			else
			{
				DispMode = RANKING_DISP_MODE;
				ranking_sort();
			}
		}
	}
}

/*****************************************
* �����L���O��ʁF���O���͕`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
******************************************/
void ranking_input_name_draw(void)
{
	int i;

	SetFontSize(40);
	DrawFormatString(300, 150, GetColor(255, 255, 255), "���O����͂��Ă�������");

	//�I��p������`��
	for (i = 0; i < 26; i++)
	{
		DrawFormatString((i % 13 * 50) + 300, (i / 13 * 50) + 330, GetColor(255, 255, 255),
			"%-3c", 'a' + i);
		DrawFormatString((i % 13 * 50) + 300, (i / 13 * 50) + 430, GetColor(255, 255, 255),
			"%-3c", 'A' + i);
	}
	for (i = 0; i < 10; i++)
	{
		DrawFormatString((i % 13 * 50) + 300, (i / 13 * 50) + 530, GetColor(255, 255, 255),
			"%-3c", '0' + i);
	}

	DrawFormatString(300, 200, GetColor(255, 255, 255), ">%s", New_Score.name);

	SetFontSize(20);

	//�I�����Ă��镶�����t�H�[�J�X���Ă���
	DrawBox((Cursor.x * 50) + 290, (Cursor.y * 50) + 330,
		(Cursor.x * 50) + 330, (Cursor.y * 50) + 370,
		GetColor(255, 255, 255), FALSE);
}