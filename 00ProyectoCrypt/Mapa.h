#pragma once
#include <vector>
#include "tinyxml2.h"
#include <string>
#include "Cadence.h"


using namespace std;
using namespace tinyxml2;

class Mapa
{
private:
	static Mapa* pInstance;

	Cadence *instanciaPers;

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
	int _offsetX; //posicion X donde empieza el mapa
	int offsetY; //posicion Y donde empieza el mapa
	int camaraX;
	int camaraY;
	int _camaraRemotaX;
	int _camaraRemotaY;
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

	streampos size;
	char* memblock;
public:
	Mapa();

	void init();
	void update();
	void render();
	
	void aBinariopapi();
	void aBinariopapito();

	int getMapaX() { return camaraX; };
	int getMapaY() { return camaraY; };

	void setPunteroPos(Cadence* param) { instanciaPers = param; }; //Coge el personaje

	static Mapa* getInstance();
};

