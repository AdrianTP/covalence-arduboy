#ifndef array2d_H
#define array2d_H

// Taken from http://stackoverflow.com/a/16978836

class Array2D {
	private:
	int *array;
	int width;
	int height;

	public:
	Array2D(int width, int height);

	~Array2D();

	int& at(int x, int y);
};

#endif
