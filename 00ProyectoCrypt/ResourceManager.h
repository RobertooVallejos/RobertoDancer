#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <vector>
#include <string>
#include "SDL.h"

//! ResourceManager class
/*!
	Handles the load and management of the graphics in the game.
*/
class ResourceManager
{
public:

	//! Destructor.
	~ResourceManager();

	//! Gets the graphic ID from file name. Use addGraphic if it needs to load image from disc
	/*!
		\param file Filepath to the graphic
		\return ID of the graphic
	*/
	Sint32 loadAndGetGraphicID(SDL_Renderer* gRenderer, const char* file);

	//! Returns width of a Surface
/*!
 *	\param img ID texture
 * 	\return Width of Texture
 */
	Uint16 getGraphicWidth(Sint32 img);

	//! Returns Height of a Texture
	/*!
	 *	\param img ID texture
	 *  \return Height of Texture
	 */
	Uint16 getGraphicHeight(Sint32 img);

	//! Returns the SDL_Surface of the graphic. Only for render methods.
	/*!
		\param ID ID of the graphic
		\return SDL_Surface
	*/
	SDL_Texture* getGraphicByID(Sint32 ID);

	//! Gets Singleton instance
	/*!
		\return Instance of ResourceManager (Singleton).
	*/
	static ResourceManager* getInstance();

protected:
	//! Constructor of an empty ResourceManager.
	ResourceManager();

private:

	//! Loads from disc and adds a graphic to the ResourceManager 
	/*!
		\param file Filepath to the graphic
		\return -1 if there's an error when loading
	*/
	Sint32 addGraphic(SDL_Renderer* gRenderer, const char* file);

	std::vector<SDL_Texture*>	_graphicsVector;	/*!<  Vector that stores Surfaces. Useful in render methods and sequential access*/
	std::map<std::string, Sint32>	mIDMap;			/*!<  Map that stores ID. Links strings to ID, Useful for check if graphic is has been loaded previously*/
	Uint32				mFirstFreeSlot;		/*!<  First free slot in the mGraphicsVector*/
	static ResourceManager* pInstance;		/*!<  Singleton instance*/
};

#endif