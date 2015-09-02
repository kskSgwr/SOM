


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
	
	list<cCell> cell ;		// �\�����郆�j�b�g����
	int vecDim ;				// �e�Z���̃x�N�g���̎���
	//int cellNumX, cellNumY ;	// X,Y������cell�̐�


	//vector<int> aveCell ;	// �\�����郆�j�b�g�̕��ϒl
	
	//int cellSize;


	double pracRatio0, pracRatio ;			// �w�K���W��
	double viciArea0, viciArea ;			// �ߖT�̈�

	int timeMax, time  ;					// �w�K��


public:

	// �R���X�g���N�^
	cSOM(vector<int> _vec, int _x, int _y);

	//cCell &cell(int _x, int _y){ return cells[_x+_y*this->cellSizeX] ;} ;
	//cCell &cell(int _n){ return cells[_n] ;} ;

	// ���j�b�g�T�C�Y���擾�i�c�~���j
	int getCellSize(){ return this->cell.size(); };
	// ���j�b�g�T�C�Y���擾�i���j
	//int getCellSizeX(){ return cellSizeX; };
	// ���j�b�g�T�C�Y���擾�i�c�j
	//int getCellSizeY(){ return cellSizeY; };

	// ���j�b�g�T�C�Y��ݒ�i�c�~���j
	//void setCellSize(int _cellSize){ this->cellSize = _cellSize; };

	// ���j�b�g�T�C�Y��ݒ�i���j
	//void setCellSizeX(int _cellSizeX){ this->cellSizeX = _cellSizeX; };
	// ���j�b�g�T�C�Y��ݒ�i�c�j
	//void setCellSizeY(int _cellSizeY){ this->cellSizeY = _cellSizeY; };

	// ���j�b�g�x�N�g���̎�������Ԃ�
	int getVecDim(){ return this->vecDim; };



	// ���j�b�g�̕��ϒl���X�V
	//vector<int> calcAveCell();

	// ���j�b�g�̕��ϒl���擾
	//vector<int> getAveCell(){ return this->aveCell; };


	void randomizeAll();
	//void divide(vector<cCell>::iterator _it, int _x, int _y);
	void divide(list<cCell>::iterator _it, int _x, int _y);

	void showAllCell();
	void drawAllCell(int _x, int _y, int _sizeX, int _sizeY);

	
	
	// �w�K���W���̏����l��ݒ�
	void setPracRatio0(double _pracRatio0){ this->pracRatio0 = _pracRatio0; };
	// �w�K���W���̏����l�𓾂�
	double getPracRatio0(){ return this->pracRatio0 ; };
	// �w�K���W����ݒ�
	void setPracRatio(double _pracRatio){ this->pracRatio = _pracRatio; };
	// �w�K���W���𓾂�
	double getPracRatio(){ return this->pracRatio0*(1.0-double(this->time)/this->timeMax) ; };

	// �ߖT�̈�̏����l��ݒ�
	void setViciArea0(double _viciArea0){ this->viciArea0 = _viciArea0; };
	// �ߖT�̈�̏����l�𓾂�
	double getViciArea0(){ return this->viciArea0 ; };
	// �ߖT�̈��ݒ�
	void setViciArea(double _viciArea){ this->viciArea = _viciArea; };
	// �ߖT�̈�𓾂�
	double getViciArea(){ return this->viciArea0*(1.0-double(this->time)/this->timeMax) ; };

	// �w�K�񐔂�����
	void setTimeMax(int _timeMax){ this->timeMax = _timeMax ;} ;


	
	void learningStart(double _pracRatio0, double _viciArea0, int _timeMax);
	void learning(vector<int> _pracData);
	void learningEnd();

	//void dye(double _winCellX, double _winCellY) ;




};


#endif


