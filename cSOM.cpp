

#include"cSOM.h"

using namespace std;


cSOM::cSOM(vector<int> _vec, int _numX, int _numY){
	this->vecDim = _vec.size() ;
	cCell tmp(_vec, 0.5, 0.5, 1.0, 1.0) ;
	this->cell.push_back(tmp) ;
	list<cCell>::iterator it = cell.begin() ;
	this->divide(it, _numX, _numY) ;

	/*
	vector<int> pracData(3,200) ;

	list<cCell>::iterator winIt = this->cell.begin() ;
	int winIp = eucDist(winIt->getVec(), pracData);
	int cur_ip;

	// 勝者ユニットの探索
	//for (int i = 1; i < this->getCellSize(); i++){
	for (list<cCell>::iterator it = this->cell.begin()++; it != this->cell.end(); it++){
		cur_ip = eucDist(it->getVec(), pracData);
		if (winIp > cur_ip){
			winIp = cur_ip;
			winIt = it;
		}
	}

	this->divide(winIt, 4,4) ;
	*/
}



void cSOM::randomizeAll(){
	
	for (list<cCell>::iterator it = this->cell.begin(); it != this->cell.end(); it++){
		it->randomize() ;
	}
}


// セルを分割
//void cSOM::divide(vector<cCell>::iterator _it, int _x, int _y){
void cSOM::divide(list<cCell>::iterator _it, int _x, int _y){
	
	if (_x == 1 && _y == 1)
		return;
	
	// 一時的にセルを複製
	cCell curCell = *_it; //(_it->getX, ) ;

	// 分割後の各セルの大きさ
	double lenX = curCell.getLenX()/_x ;
	double lenY = curCell.getLenY()/_y ;

	for (int x = 0; x < _x; x++){
		for (int y = 0; y < _y; y++){
			cCell tmp(curCell.getVec(), curCell.getX1()+lenX*x+lenX/2, curCell.getY1()+lenY*y+lenY/2, lenX, lenY) ;
			this->cell.push_back(tmp) ;
		}
	}
	
	this->cell.erase(_it) ;
	
	}



// ■□■　学習を開始　■□■
void cSOM::learningStart(double _pracRatio0, double _viciArea0, int _timeMax){

	// 学習率係数などの初期値を設定
	this->setPracRatio0(_pracRatio0);
	this->setViciArea0(_viciArea0);
	this->setTimeMax(_timeMax) ;

	this->time = 0 ;

}



// ■□■　訓練データを入力し、学習　■□■
// vector<int> _pracData	: 訓練データ
void cSOM::learning(vector<int> _pracData){

	if (this->time==this->timeMax)
		return ;


	this->time++ ;
	
	// 勝者ユニットを仮定
	list<cCell>::iterator winIt = this->cell.begin() ;
	int winIp = eucDist(winIt->getVec(), _pracData);
	int cur_ip;

	// 勝者ユニットの探索
	//for (int i = 1; i < this->getCellSize(); i++){
	for (list<cCell>::iterator it = this->cell.begin()++; it != this->cell.end(); it++){
		cur_ip = eucDist(it->getVec(), _pracData);
		if (winIp > cur_ip){
			winIp = cur_ip;
			winIt = it;
		}
	}
	//DxLib::DrawCircle(30,30,10, GetColor(255,255,255), FALSE, TRUE);
	winIt->markCell(0,0,480,480) ;
	//DxLib::DrawCircle(winner_id%this->get()*30+15, winner_id/this->getCellSizeY()*30+15,10, GetColor(255,255,255), FALSE, TRUE);

	// 暴露
	double dist = 0;	// 勝者ユニットとの距離
	vector<int> color_balance(this->getVecDim()) ;		// 学習データと各タイルの色の差
	for (list<cCell>::iterator it = this->cell.begin(); it != this->cell.end(); it++){
		dist = dLength(it->getX(), it->getY(), winIt->getX(), winIt->getY()) ;
		if (dist<this->getViciArea()){
			for (int d=0; d<this->getVecDim(); d++){
				color_balance[d] = _pracData[d] - it->getElem(d) ;
				it->setElem(d, it->getElem(d)+color_balance[d]*this->getPracRatio() ) ;
				//char *c ;
				//sprintf(c, "%lf", dist) ;
				//DxLib::DrawString(it->getX(), it->getY(), c, GetColor(0,0,0)) ;
			}
		}
	}
	
}



/*
void cSOM::showAllCell(){
	//cout << "us" << getCellSize();
	// セルが単一の場合
	if (this->getCellSize() == 1){
		cout << "(" ;
		for (int i = 0; i < this->getCellDim(); i++){
			cout << this->aveCell[i] << ",";
		}
		cout << ")";
		return;
	}

	// セルが分割されている場合
	for (int y = 0; y < this->getCellSizeY(); y++){
		for (int x = 0; x < this->getCellSizeX(); x++){
			cout << "[" << x << "," << y << "]";
			this->cell[x+y*this->getCellSizeX()].showAllCell();
		}
		cout << "\n";
	}
}
*/



// ■□■　DxLibを使用して可視化　■□■
void cSOM::drawAllCell(int _x, int _y, int _sizeX, int _sizeY){

	DxLib::DrawBox(_x, _y, _x + _sizeX, _y + _sizeY, DxLib::GetColor(0,0,0), TRUE) ;

	for (list<cCell>::iterator it = this->cell.begin(); it != this->cell.end(); it++){
		it->drawCell(_x, _y, _sizeX, _sizeY) ;
	}
}


