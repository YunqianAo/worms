#pragma once

#include "Common.h"
#include"Util.h"
#include"Math.h"

namespace E3D {
	struct EVector2D {
		static EVector2D ZERO;
		static EVector2D UNIT_X;
		static EVector2D UNIT_Y;
		EFloat x;
		EFloat y;
		EVector2D():x(0),y(0){}
		EVector2D(EFloat xf,EFloat yf):x(xf),y(yf){}
		EVector2D(const EVector2D& v):x(v.x),y(v.y){}
		inline EFloat normalize() {
			EFloat len = length();
			if (len > EPSILON_E6) {
				EFloat invlength = 1.0f / len;
				x *= invlength;
				y *= invlength;
			}
			return len;
		}
		inline EFloat length()const{
			return sqrt(x * x + y * y);
		}
		inline EFloat dotProduct(const EVector2D& right)const {
			return x * right.x + y * right.y;
		}
		inline EFloat angleBetween(const EVector2D& right)const {
			EFloat lenProduct = length() * right.length();
			if (lenProduct < EPSILON_E6) {
				lenProduct = EPSILON_E6;
			}
			EFloat f = dotProduct(right)/lenProduct;
			f = Clamp(f, -1.0f, 1.0f);
			return acos(f);
		}
		inline bool isZero()const {
			return length() < EPSILON_E6;
		}
		inline EFloat squaredLength()const {
			return x * x + y * y;
		}
		inline EVector2D operator*(float right)const {
			return EVector2D(x * right, y * right);
		}
		inline EVector2D operator*(const EVector2D& right)const {
			return EVector2D(x * right.x, y * right.y);
		}
		inline EVector2D operator+(const EVector2D& right)const {
			return EVector2D(x + right.x, y + right.y);
		}
		inline EVector2D operator-(const EVector2D& right)const {
			return EVector2D(x - right.x, y - right.y);
		}
		inline EVector2D operator-() {
			x = -x;
			y = -y;
			return *this;
		}
		inline EVector2D operator+() {
			x = +x;
			y = +y;
			return *this;
		}
		inline bool operator==(const EVector2D& right) {
			return EqualFloat(x, right.x) && EqualFloat(y, right.y);
		}
		inline EVector2D operator=(const EVector2D& right) {
			x = right.x;
			y = right.y;
			return *this;
		}
	};
}