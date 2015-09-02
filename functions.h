

#ifndef INCLUDE_FUNCTIONS
#define INCLUDE_FUNCTIONS

#include<vector>

using namespace std;

//namespace std{

int innerProduct(vector<int> _vec1, vector<int> _vec2);
int eucDist(vector<int> _vec1, vector<int> _vec2);
int manhatDist(int _x1, int _y1, int _x2, int _y2);
double dLength(double _x1, double _y1, double _x2, double _y2) ;

vector<int> addVector(vector<int> _vec1, vector<int> _vec2);
vector<int> multiVector(vector<int> _vec1, int _k);
//}


#endif



