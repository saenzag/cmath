
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

};

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

static_assert(sizeof(Mat4f) == 16 * sizeof(float), "Mat4 size incorrect");
static_assert(sizeof(Mat4d) == 16 * sizeof(double), "Mat4 size incorrect");


} // namespace cmath

#endif // __CMATH_MAT4_HPP__