/*****************************************
*�v���O���~���O���K (�e�g���X�ҁj
******************************************/
#include "Dxlib.h"
#include "FreamControl.h"
#include "SceneManager.h"
#include "InputControl.h"

/*****************************************
*�}�N����`
******************************************/
#define SCREEN_HEIGHT (720)
#define SCREEN_WIDTH (1280)
#define SCREEN_COLORBIT (32)
#define FONT_SIZE (20)

/*****************************************
*�^��`
******************************************/

/*****************************************
*�O���[�o���ϐ��錾
******************************************/

/*****************************************
*�v���g�^�C�v�錾
******************************************/

/*****************************************
*�v���O�����̊J�n
******************************************/

int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�^�C�g����ύX
	SetMainWindowText("�e�g���X");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�̌���
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		return -1;

	}

	//�t���[������@�\����������
	FreamControl_Initialize();

	//

	// ���͑ҋ@
	WaitKey();

	DxLib_End();

	return 0;
}