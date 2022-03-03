#include "Mapa.h"
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include "ResourceManager.h"
#include "Video.h"

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
	_mElement2 = "";
	_mElement3 = "";
	_string = "";
}

void Mapa::init()
{
	tilewidth = 52;
	tileheight = 52;
	tilespace = 0;
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

void Mapa::render()
{
	for (size_t tmY = 0; tmY < 31; tmY++)
	{
		for (size_t tmX = 0; tmX < 41; tmX++)
		{
			_RectT.x = tmX * tilewidth;
			_RectT.y = tmY * tileheight;
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
			_RectT.x = tmX * tilewidth;
			_RectT.y = tmY * tileheight;
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
