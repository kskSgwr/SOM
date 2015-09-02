
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

// プログラムは WinMain から始まります
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
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
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
	
	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
