#pragma once

#pragma once
#include <cmath>

constexpr double pi = 3.14;

template <typename T> T rad_to_deg(const T rad) {
	return rad * 180.0 / pi;
}

template <typename T> T deg_to_rad(const T deg) {
	return deg * pi / 180.0;
}

template <typename T> T mm_to_cm(const T mm) {
	return mm / 10.0;
}

template <typename T> T cm_to_mm(const T mm) {
	return mm * 10.0;
}
