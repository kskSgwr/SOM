
#include "DxLib.h"

#include "cCell.h"
#include "cSOM.h"

#include <Windows.h>
#include <time.h>

/*
void Main(){
	cSOM SOM(3, 0, 16, 16);
	SOM.randomizeAll();
}
*/

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//==============================================================

	srand(time(NULL));

	vector<int> sampleVec(3,100) ;

	cSOM SOM(sampleVec, 32, 32);
	//unit.showAllUnit();

	//unit.showAllUnit();
	SOM.randomizeAll();

	//unit.showAllUnit();

	
	//unit.unit[25].divide(4,4);
	//unit.unit[25].randomize();

	//unit.unit[8].divide(2, 2);
	//unit.unit[8].randomize();
	

	vector<int> pracVector(3,0); 



	//==============================================================



	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	DrawBox(0, 0, 500, 300, GetColor(0, 0, 0), TRUE);

	SOM.drawAllCell(0,0,480,480) ;
	
	
	int timeMax = 300 ;
	
	SOM.learningStart(0.15, 0.5, timeMax) ;

	for (int i = 0; i<timeMax; i++){

		SOM.drawAllCell(0, 0, 480, 480);

		for (int c=0; c<3; c++)
			pracVector[c] = rand()%255 ;
		SOM.learning(pracVector);

		WaitTimer(20);
	}
	
	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
