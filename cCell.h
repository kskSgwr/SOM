

#ifndef INCLUDE_CCELL
#define INCLUDE_CCELL


#include<vector>
#include<iostream>
#include"DxLib.h"


using namespace std;


class cCell{

private:

	vector<int> vec ;			// ベクトル値
	
	double X, Y ;				// X,Y座標
	double lenX, lenY ;			// X,Yサイズ


public:

	//cCell(int _dim, int _val) ;
	cCell(vector<int> _vec, double _x, double _y, double _lenX, double _lenY) ;
	void randomize() ;

	vector<int> getVec(){ return this->vec ;} ;
	
	double getLenX(){ return this->lenX ;} ;
	double getLenY(){ return this->lenY ;} ;

	double getX(){ return this->X ;} ;
	double getY(){ return this->Y ;} ;
	double getX1(){ return this->X - this->getLenX()/2 ;} ;
	double getX2(){ return this->X + this->getLenX()/2 ;} ;
	double getY1(){ return this->Y - this->getLenY()/2 ;} ;
	double getY2(){ return this->Y + this->getLenY()/2 ;} ;


	void drawCell(int _x, int _y, int _sizeX, int _sizeY) ;
	void markCell(int _x, int _y, int _sizeX, int _sizeY) ;

	int getElem(int _d){ return this->vec.at(_d) ;} ;
	void setElem(int _d, int _val){ this->vec.at(_d) = _val ;} ;

};


#endif 