
#ifndef __CMATH_MAT4_HPP__
#define __CMATH_MAT4_HPP__ 1

namespace cmath {

template<typename T>
struct Mat4
{
	union
	{
		T data[16];
		struct
		{
			T m00, m01, m02, m03;
			T m10, m11, m12, m13;
			T m20, m21, m22, m23;
			T m30, m31, m32, m33;
		};
	};
  

		Mat4() : data{	
								T(0), T(0), T(0), T(0),
								T(0), T(0), T(0), T(0),
								T(0), T(0), T(0), T(0),
								T(0), T(0), T(0), T(0)
							}
			{
			}

		Mat4(T m00_, T m01_, T m02_, T m03_,
					T m10_, T m11_, T m12_, T m13_,
					T m20_, T m21_, T m22_, T m23_,
					T m30_, T m31_, T m32_, T m33_) :
			m00(m00_), m01(m01_), m02(m02_), m03(m03_),
			m10(m10_), m11(m11_), m12(m12_), m13(m13_),
			m20(m20_), m21(m21_), m22(m22_), m23(m23_),
			m30(m30_), m31(m31_), m32(m32_), m33(m33_)
		{
		}

		~Mat4() = default;

		operator T*() { return data; }
		operator const T*() const { return data; }

		Mat4<T>& operator*=(const Mat4<T>& other)
		{
			*this = *this * other;
			return *this;
		}
};

template<typename T>
Mat4<T> operator*(const Mat4<T>& mat1, const Mat4<T>& mat2)
{
	return Mat4<T> {
				mat1.m00 * mat2.m00 + mat1.m01 * mat2.m10 + mat1.m02 * mat2.m20 + mat1.m03 * mat2.m30,
				mat1.m00 * mat2.m01 + mat1.m01 * mat2.m11 + mat1.m02 * mat2.m21 + mat1.m03 * mat2.m31,
				mat1.m00 * mat2.m02 + mat1.m01 * mat2.m12 + mat1.m02 * mat2.m22 + mat1.m03 * mat2.m32,
				mat1.m00 * mat2.m03 + mat1.m01 * mat2.m13 + mat1.m02 * mat2.m23 + mat1.m03 * mat2.m33,

				mat1.m10 * mat2.m00 + mat1.m11 * mat2.m10 + mat1.m12 * mat2.m20 + mat1.m13 * mat2.m30,
				mat1.m10 * mat2.m01 + mat1.m11 * mat2.m11 + mat1.m12 * mat2.m21 + mat1.m13 * mat2.m31,
				mat1.m10 * mat2.m02 + mat1.m11 * mat2.m12 + mat1.m12 * mat2.m22 + mat1.m13 * mat2.m32,
				mat1.m10 * mat2.m03 + mat1.m11 * mat2.m13 + mat1.m12 * mat2.m23 + mat1.m13 * mat2.m33,

				mat1.m20 * mat2.m00 + mat1.m21 * mat2.m10 + mat1.m22 * mat2.m20 + mat1.m23 * mat2.m30,
				mat1.m20 * mat2.m01 + mat1.m21 * mat2.m11 + mat1.m22 * mat2.m21 + mat1.m23 * mat2.m31,
				mat1.m20 * mat2.m02 + mat1.m21 * mat2.m12 + mat1.m22 * mat2.m22 + mat1.m23 * mat2.m32,
				mat1.m20 * mat2.m03 + mat1.m21 * mat2.m13 + mat1.m22 * mat2.m23 + mat1.m23 * mat2.m33,

				mat1.m30 * mat2.m00 + mat1.m31 * mat2.m10 + mat1.m32 * mat2.m20 + mat1.m33 * mat2.m30,
				mat1.m30 * mat2.m01 + mat1.m31 * mat2.m11 + mat1.m32 * mat2.m21 + mat1.m33 * mat2.m31,
				mat1.m30 * mat2.m02 + mat1.m31 * mat2.m12 + mat1.m32 * mat2.m22 + mat1.m33 * mat2.m32,
				mat1.m30 * mat2.m03 + mat1.m31 * mat2.m13 + mat1.m32 * mat2.m23 + mat1.m33 * mat2.m33
	};
}

template<typename T>
static Mat4<T> Identity()
{
	Mat4<T> result;

	result.m00 = T(1);
	result.m11 = T(1);
	result.m22 = T(1);
	result.m33 = T(1);

	return result;
}

template<typename T>
static Mat4<T> Ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
{
	Mat4<T> result;

	result.m00 = T(2) / (right - left);
	result.m11 = T(2) / (top - bottom);
	result.m22 = T(-2) / (farVal - nearVal);
	result.m03 = -(right + left) / (right - left);
	result.m13 = -(top + bottom) / (top - bottom);
	result.m23 = -(farVal + nearVal) / (farVal - nearVal);
	result.m33 = T(1);

	return result;
}

typedef Mat4<float> Mat4f;
typedef Mat4<double> Mat4d;

static_assert(sizeof(Mat4f) == 16 * sizeof(float), "Mat4<float> size incorrect");
static_assert(sizeof(Mat4d) == 16 * sizeof(double), "Mat4<double> size incorrect");


} // namespace cmath

#endif // __CMATH_MAT4_HPP__