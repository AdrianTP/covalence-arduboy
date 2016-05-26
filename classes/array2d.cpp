// Taken from http://stackoverflow.com/a/16978836

#include "../headers/array2d.h"

Array2D::Array2D(int w, int h) {
	array = new int[w * h];
	height = h;
	width = w;
}

Array2D::~Array2D() {
	delete[] array;
}

int& Array2D::at(int x, int y) {
	return array[x * width + y];
}
