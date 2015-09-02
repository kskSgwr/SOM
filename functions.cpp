

#include"functions.h"

//using namespace std;

	int innerProduct(vector<int> _vec1, vector<int> _vec2){

		// 内積の値
		int ip = 0;

		for (int i = 0; i < _vec1.size(); i++){
			ip = ip + _vec1[i] * _vec2[i];
		}
		return ip;
	}



	// 2つのベクトルのユークリッド距離
	int eucDist(vector<int> _vec1, vector<int> _vec2){
		
		int dist = 0;
		for (int i = 0; i < _vec1.size(); i++){
			dist = dist + (_vec1[i] - _vec2[i])*(_vec1[i] - _vec2[i]) ;
		}
		return dist;
	}

	int manhatDist(int _x1, int _y1, int _x2, int _y2){
		return (abs(_x1-_x2) + abs(_y1-_y2)) ;
	}

	// ベクトルの加算
	vector<int> addVector(vector<int> _vec1, vector<int> _vec2){

		vector<int> result ;
		for (int i=0; i<_vec1.size(); i++){
			result.push_back(_vec1[i] + _vec2[i]) ;
		}

		return result ;
	}

	// ベクトルの定数倍
	vector<int> multiVector(vector<int> _vec1, double _k){

		vector<int> result ;
		for (int i=0; i<_vec1.size(); i++){
			result.push_back((int)(_k*_vec1[i])) ;
		}
		return result ;
	}

	// 2点間の距離をdouble型で返す
	double dLength(double _x1, double _y1, double _x2, double _y2){
		return hypot(_x1-_x2, _y1-_y2) ;
		// sqrt((_x1-_x2)*(_x1-_x2) + (_y1-_y2)*(_y1-_y2))
	}