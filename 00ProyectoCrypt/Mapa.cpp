#include "Mapa.h"
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include "ResourceManager.h"
#include "InputManager.h"
#include "Video.h"
#include <fstream>

extern InputManager* sInputManager;
extern ResourceManager* sResourceManager;
extern Video* sVideo;

Mapa* Mapa::pInstance = nullptr;

using namespace std;
using namespace tinyxml2;

Mapa::Mapa()
{
	_RectS = { 0, 0, 0, 0};
	_RectT = { 0, 0, 0, 0};
	_cellX = 0;
	_cellY = 0;
	_id = 0;
	_imagen = 0;
	_width = 0;
	_height = 0;
	_length = 0;
	tilewidth = 0;
	tileheight = 0;
	tilespace = 0;
	_offsetX = 0;
	offsetY = 0;
	camaraX = 0;
	camaraY = 0;
	_camaraRemotaX = 0;
	_camaraRemotaY = 0;
	_mapaWidth = 0;
	_mapaHeight = 0;
	_mElement2 = "";
	_mElement3 = "";
	_string = "";
}

void Mapa::init()
{
	tilewidth = 52;
	tileheight = 52;
	tilespace = 0;
	_offsetX = 0;
	offsetY = 0;
	camaraX = 0;
	camaraY = 0;
	if (_doc.LoadFile("mapaFirst.tmx") != XML_SUCCESS) {
		cout << "Error XML: " << _doc.ErrorStr();
	}

	_map = _doc.FirstChildElement();
	_element1 = _map->FirstChildElement()->NextSiblingElement();
	_element2 = _element1->FirstChildElement();
	_element3 = _element1->NextSiblingElement()->FirstChildElement();
	_height = stoi(_element1->Attribute("height"));
	_width = stoi(_element1->Attribute("width"));
	_mElement2 = _element2->GetText();
	_mElement3 = _element3->GetText();

	_background.resize(_height);
	_foreground.resize(_height);
	for (size_t i = 0; i < _height; i++)
	{
		_background[i].resize(_width);
		_foreground[i].resize(_width);
	}
	_mElement2 = _mElement2.substr(1); //ignore del salto de linea
	for (size_t i = 0; i < _height; i++)
	{
		for (size_t j = 0; j < _width; j++)
		{
			_length = _mElement2.find_first_of(',');
			_string = _mElement2.substr(0, _length);
			_mElement2 = _mElement2.substr(_length + 1);
			_background.at(i).at(j) = stoi(_string);
			cout << _background[i][j];

		}
	}

	for (size_t o = 0; o < _height; o++)
	{
		for (size_t p = 0; p < _width; p++)
		{
			_length = _mElement3.find_first_of(',');
			_string = _mElement3.substr(0, _length);
			_mElement3 = _mElement3.substr(_length + 1);
			_foreground.at(o).at(p) = stoi(_string);
			cout << _foreground[o][p];
		}
	}
	_imagen= ResourceManager::getInstance()->loadAndGetGraphicID(Video::getIntance()->getRenderer(), "SueloYParedes.png");
}

void Mapa::update()
{
	camaraX = (instanciaPers->getPositionX() + (instanciaPers->getSizeWidth() / 2) - 30) - (SCREEN_WIDTH / 2);
	if (camaraX < 0) {
		camaraX = 0;
	}
	else if (camaraX > (getMapaWidth() - SCREEN_WIDTH)) {
		camaraX = getMapaWidth() - SCREEN_WIDTH;
	}


	camaraY = (instanciaPers->getPositionY() + (instanciaPers->getSizeHeight() / 2)) - (SCREEN_HEIGHT / 2);
	if (camaraY < 0) {
		camaraY = 0;
	}
	else if (camaraY > (getMapaHeight() - SCREEN_HEIGHT)) {
		camaraY = getMapaHeight() - SCREEN_HEIGHT;
	}

	_offsetX = camaraX / tilewidth;
	offsetY = camaraY / tileheight;
	_camaraRemotaX = SCREEN_WIDTH / tilewidth + _offsetX + 1;
	_camaraRemotaY = SCREEN_HEIGHT / tileheight + offsetY + 1;
}

void Mapa::render()
{
	for (size_t tmY = offsetY; tmY < _camaraRemotaY; tmY++)
	{
		for (size_t tmX = _offsetX; tmX < _camaraRemotaX; tmX++)
		{
			_RectT.x = tmX * tilewidth - camaraX;
			_RectT.y = tmY * tileheight - camaraY;
			_RectT.w = tilewidth;
			_RectT.h = tileheight;
			_id = _background[tmY][tmX] - 1;
			if (_id >= 0)
			{
				_cellX = _id % 7;  //columna
				_cellY = _id / 7;  //fila
				_RectS.x = _cellX * tilewidth + tilespace * _cellX;
				_RectS.y = _cellY * tilewidth + tilespace * _cellY;
				_RectS.w = tilewidth;
				_RectS.h = tileheight;
				Video::getIntance()->renderGraphic(_imagen, _RectT.x, _RectT.y, _RectS.w, _RectS.h, _RectS.x, _RectS.y);
			}
			_RectT.x = tmX * tilewidth - camaraX;
			_RectT.y = tmY * tileheight - camaraY;
			_RectT.w = tilewidth;
			_RectT.h = tileheight;
			_id = _foreground[tmY][tmX] - 1;
			if (_id >= 0)
			{
				_cellX = _id % 7;  //columna
				_cellY = _id / 7;  //fila
				_RectS.x = _cellX * tilewidth + tilespace * _cellX;
				_RectS.y = _cellY * tilewidth + tilespace * _cellY;
				_RectS.w = tilewidth;
				_RectS.h = tileheight;
				Video::getIntance()->renderGraphic(_imagen, _RectT.x, _RectT.y, _RectS.w, _RectS.h, _RectS.x, _RectS.y);
			}
		}

	}
}


void Mapa::aBinariopapi()
{
	fstream _file("mapaFirst.tmx", ios::in | ios::binary);
	if (_file.is_open()) {
		_file.seekg(0, _file.end);
		size = _file.tellg();
		_file.seekg(0, _file.beg);
		memblock = new char[size];
		_file.read(memblock, size);
		_file.close();

		std::cout << "EL SIZE DEL MAPA ES " << size;
	}
	else {
		cout << "No s'ha pogut obrir el fitxer";
	}
	delete[] memblock;
}

void Mapa::aBinariopapito()
{
	int apoyo = 0;
	fstream _file2("nosequeponerajjajsaludosquierounnombrelargo.ihi", ios::out | ios::binary);
	_file2.write((char*)&_height, 4);
	_file2.write((char*)&_width, 4);
	for (int i = 0; i < sizeof(_background); i++) {
		for (int o = 0; o < sizeof(_background); o++) {
			apoyo = _background[i][o];

			_file2.write((char*)&apoyo, 4);
		}
	}
	_file2.close();
}

int Mapa::getMapaWidth()
{
	_mapaWidth = tilewidth * _width;
	return _mapaWidth;
}

int Mapa::getMapaHeight()
{
	_mapaHeight = _height * tileheight;
	return _mapaHeight;
}


int Mapa::getIDfromLayer(int layer, int posX, int posY)  //Dependiendo de si layer es 0 o 1, checkea el ID del tile.
{
	int TileX = posX / tilewidth;
	int TileY = posY / tileheight;
	int Tile = -1;
	if (layer == 0) {
		Tile = _background[TileY][TileX];
	}
	if (layer == 1) {
		Tile = _foreground[TileY][TileX];
	}
	return Tile;
}

Mapa* Mapa::getInstance()
{
	if (pInstance == nullptr) pInstance = new Mapa();

	return pInstance;
}
