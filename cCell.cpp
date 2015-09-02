
#include"cCell.h"
#include"functions.h"
#include"DxLib.h"

#include<vector>

using namespace std;


// �R���X�g���N�^
//cCell::cCell(int _dim, int _val){
//	this->vec.assign(_dim, _val) ;
//}
cCell::cCell(vector<int> _vec, double _x, double _y, double _lenX, double _lenY){
	this->vec.assign(_vec.begin(), _vec.end()) ;
	this->X = _x ;
	this->Y = _y ;
	this->lenX = _lenX ;
	this->lenY = _lenY ;
}

/*
// ���j�b�g�̕��ϒl���X�V
vector<int> cCell::calcAveCell(){

	// �Z�����P��̏ꍇ
	if (this->getCellSize() == 1){
		return this->aveCell;
	}

	// �V�������ϒl(0�ŏ�����)
	vector<int> newAveCell(this->getCellDim(), 0);

	// �e���j�b�g�ɑ΂��ċA�I�ɕ��σx�N�g�������߂�
	for (int d = 0; d < this->getCellDim(); d++){
		for (int i = 0; i < this->getCellSize(); i++){
			newAveCell.at(d) += this->cell[i].calcAveCell().at(d);
		}
	}
	for (int d = 0; d < this->getCellDim(); d++){
		newAveCell[d] = newAveCell[d] / this->getCellSize();
	}

	return newAveCell;
}
*/



// �Z���������_���ɂ���
void cCell::randomize(){

	//cout << "rand cellsize:" << this->getCellSize() << endl;
	// �Z�����P��̏ꍇ
	for (int i = 0; i < this->vec.size(); i++){
		this->vec[i] = rand() % 256;
		//cout << this->aveCell[i] << ",";
	}
}



void cCell::drawCell(int _x, int _y, int _sizeX, int _sizeY){
	
	int cr = DxLib::GetColor(this->vec[0], this->vec[1], this->vec[2]);
	DxLib::DrawBox(
		_x+this->getX1()*_sizeX+1,
		_y+this->getY1()*_sizeY+1,
		_x+this->getX2()*_sizeX,
		_y+this->getY2()*_sizeY,
		cr,
		TRUE
		) ;
}



void cCell::markCell(int _x, int _y, int _sizeX, int _sizeY){

	DxLib::DrawCircle(
		_x + this->getX()*_sizeX+1,
		_y + this->getY()*_sizeY+1,
		(this->lenX*_sizeX + this->lenY*_sizeY)/2,
		GetColor(255,255,255),
		FALSE,
		TRUE
		) ;
}
/*





*/





/*
// �R���X�g���N�^
// _x   : SOM��x�v�f��
// _y   : SOM��y�v�f��
// _dim : SOM�̊e���j�b�g�x�N�g���̎���
// _val : ����������l
cCell::cCell(int _x, int _y, int _dim, int _val){

	this->cellSizeX = _x;
	this->cellSizeY = _y;
	this->cellSize = this->getCellSizeX()*this->getCellSizeY();

	for (int i = 0; i < _x*_y; i++){
		if (this->getCellSize() == 1){
			
		}
		this->cell.assign(_x*_y,)
	}
}
*/
