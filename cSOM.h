


#ifndef INCLUDE_CSOM
#define INCLUDE_CSOM


#include"cCell.h"
#include"functions.h"

#include<map>
#include<list>
#include<vector>
#include<string>



class cSOM{


private:
	
	list<cCell> cell ;		// 構成するユニットたち
	int vecDim ;				// 各セルのベクトルの次元
	//int cellNumX, cellNumY ;	// X,Y方向のcellの数


	//vector<int> aveCell ;	// 構成するユニットの平均値
	
	//int cellSize;


	double pracRatio0, pracRatio ;			// 学習率係数
	double viciArea0, viciArea ;			// 近傍領域

	int timeMax, time  ;					// 学習回数


public:

	// コンストラクタ
	cSOM(vector<int> _vec, int _x, int _y);

	//cCell &cell(int _x, int _y){ return cells[_x+_y*this->cellSizeX] ;} ;
	//cCell &cell(int _n){ return cells[_n] ;} ;

	// ユニットサイズを取得（縦×横）
	int getCellSize(){ return this->cell.size(); };
	// ユニットサイズを取得（横）
	//int getCellSizeX(){ return cellSizeX; };
	// ユニットサイズを取得（縦）
	//int getCellSizeY(){ return cellSizeY; };

	// ユニットサイズを設定（縦×横）
	//void setCellSize(int _cellSize){ this->cellSize = _cellSize; };

	// ユニットサイズを設定（横）
	//void setCellSizeX(int _cellSizeX){ this->cellSizeX = _cellSizeX; };
	// ユニットサイズを設定（縦）
	//void setCellSizeY(int _cellSizeY){ this->cellSizeY = _cellSizeY; };

	// ユニットベクトルの次元数を返す
	int getVecDim(){ return this->vecDim; };



	// ユニットの平均値を更新
	//vector<int> calcAveCell();

	// ユニットの平均値を取得
	//vector<int> getAveCell(){ return this->aveCell; };


	void randomizeAll();
	//void divide(vector<cCell>::iterator _it, int _x, int _y);
	void divide(list<cCell>::iterator _it, int _x, int _y);

	void showAllCell();
	void drawAllCell(int _x, int _y, int _sizeX, int _sizeY);

	
	
	// 学習率係数の初期値を設定
	void setPracRatio0(double _pracRatio0){ this->pracRatio0 = _pracRatio0; };
	// 学習率係数の初期値を得る
	double getPracRatio0(){ return this->pracRatio0 ; };
	// 学習率係数を設定
	void setPracRatio(double _pracRatio){ this->pracRatio = _pracRatio; };
	// 学習率係数を得る
	double getPracRatio(){ return this->pracRatio0*(1.0-double(this->time)/this->timeMax) ; };

	// 近傍領域の初期値を設定
	void setViciArea0(double _viciArea0){ this->viciArea0 = _viciArea0; };
	// 近傍領域の初期値を得る
	double getViciArea0(){ return this->viciArea0 ; };
	// 近傍領域を設定
	void setViciArea(double _viciArea){ this->viciArea = _viciArea; };
	// 近傍領域を得る
	double getViciArea(){ return this->viciArea0*(1.0-double(this->time)/this->timeMax) ; };

	// 学習回数を決定
	void setTimeMax(int _timeMax){ this->timeMax = _timeMax ;} ;


	
	void learningStart(double _pracRatio0, double _viciArea0, int _timeMax);
	void learning(vector<int> _pracData);
	void learningEnd();

	//void dye(double _winCellX, double _winCellY) ;




};


#endif


