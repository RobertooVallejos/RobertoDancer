#pragma once

class ElementoGFX
{
protected:
	struct Cubo
	{
		int x, y;
		int width, h;
	};
	Cubo _Rect;

	int _ID;
	int _ID2;
	int _ID3;
	int _ID4;
	int _vida;
	
public:
	ElementoGFX();
	~ElementoGFX();

	void init();
	void update();
	void render();

	void setPositionX(int value) { _Rect.x = value; };
	void setPositionY(int value) { _Rect.y = value; };
	void setPositionXY(int valueX, int valueY) { _Rect.x = valueX; _Rect.y = valueY; };
	int getPositionY() { return _Rect.y; };
	int getPositionX() { return _Rect.x; };

	void addX(int value) { _Rect.x = value + _Rect.x; };
	void addY(int value) { _Rect.y = value + _Rect.y; };

	void setSizeWidth(int value) { _Rect.width = value; };
	void setSizeHeight(int value) { _Rect.h = value; };
	void setSize(int valueW, int valueH) { _Rect.width = valueW; _Rect.h = valueH; };
	void ponerFoto(const char* img);
	void ponerFoto2(const char* img);
	void ponerFoto3(const char* img);
	void ponerFoto4(const char* img);
	int getSizeWidth() { return _Rect.width; };
	int getSizeHeight() { return _Rect.h; };

	void setID(int id) { _ID = id; };
	int getID() { return _ID; };

	virtual void setVida(int value);
	virtual int getVida();
	virtual void setObjeto(int value);
	virtual int getObjeto();
	virtual void setDano(int value);
	virtual void setObjetoAnterior(int value);
};
