#pragma once
#include <vector>
#include "tinyxml2.h"
#include <string>


using namespace std;
using namespace tinyxml2;

class Mapa
{
	struct Rect
	{
		int x, y, w, h;
	};

	Rect _RectS;
	Rect _RectT;
	int _cellX;
	int _cellY;
	int _id;
	int _imagen;
	int _width;
	int _height;
	int tilewidth;
	int tilespace;
	int tileheight;
	int _length;
	string _mElement2;
	string _mElement3;
	string _string;
	vector<vector<int>> _background;
	vector<vector<int>> _foreground;
	XMLDocument _doc;
	

	XMLElement* _map;
	XMLElement* _element1;
	XMLElement* _element2;
	XMLElement* _element3;
public:
	Mapa();

	void init();
	void render();
};

