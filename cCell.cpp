
#include"cCell.h"
#include"functions.h"
#include"DxLib.h"

#include<vector>

using namespace std;


// コンストラクタ
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
// ユニットの平均値を更新
vector<int> cCell::calcAveCell(){

	// セルが単一の場合
	if (this->getCellSize() == 1){
		return this->aveCell;
	}

	// 新しい平均値(0で初期化)
	vector<int> newAveCell(this->getCellDim(), 0);

	// 各ユニットに対し再帰的に平均ベクトルを求める
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



// セルをランダムにする
void cCell::randomize(){

	//cout << "rand cellsize:" << this->getCellSize() << endl;
	// セルが単一の場合
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
// コンストラクタ
// _x   : SOMのx要素数
// _y   : SOMのy要素数
// _dim : SOMの各ユニットベクトルの次元
// _val : 初期化する値
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
