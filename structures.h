#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

#include <cmath>
#include <ctgmath>

//Structure repr�sentant un vecteur
struct Vec {
	union {
		float coords[3];
		struct {
			float x, y, z;
		};
	};

	int operator[] (int index) { return coords[index]; }
	Vec operator- (Vec v2) { 
		return { 
			v2.x - x, 
			v2.y - y, 
			v2.z - z 
		}; 
	}

	Vec operator^ (Vec v2) {
		return {
			y * v2.z - z * v2.y,
			z * v2.x - x * v2.z,
			x * v2.y - y * v2.x
		};
	}

	float operator*(Vec v2) {
		return (x * v2.x + y * v2.y + z * v2.z);
	}

	void normalize() {
		float a = std::sqrt((x * x) + (y * y) + (z * z));
		x = x / a;
		y = y / a;
		z = z / a;
	}

	void toImageSize(int width, int height) {
		x = (x + 1) * width;
		y = (y + 1) * height;
	}
};

//Structure repr�sentant une face
struct Face {
	union {
		int sommets[3];
		struct {
			int a, b, c;
		};
	};

	int operator[] (int index) { return sommets[index]; }
};

#endif