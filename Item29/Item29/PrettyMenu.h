#pragma once


class Image
{
public:
	Image(std::istream& imgSrc);
private:
	std::string buf;
};

class PrettyMenu
{
public:
	PrettyMenu(Image *pImage) : bgImage(pImage) {}
	void changeBackground(std::istream& imgSrc); // change background image
private:
	Mutex mutex;		// mutex for this object
	Image *bgImage;		//current background image
	int imageChanges;	// # of times image has been changed
};