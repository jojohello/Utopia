﻿
#pragma once

#include <stdint.h>
#include "GeometryDefine.h"

class Vector2;
class Vector3;

namespace GeometryUtils
{
	float DegToRad(float deg) { return deg * KPiOver180; }
	float RadToDeg(float rad) { return rad * K180OverPi; }
	
	// 逆时针为正
	float DeltaAngle(Vector3 from, Vector3 to);
	float DeltaAngle(Vector2 from, Vector2 to);
	Vector2 CalVector2(Vector2 from, float rotation);

	void IsPointInRect(Vector2 &r1, Vector2 &r2, Vector2 &r3, Vector2 &r4, Vector2 &p1, Vector2 &p2, Vector2 &result);
	bool IsLineSegmentIntersect(Vector2 p1, Vector2 p2, Vector2 q1, Vector2 q2);
	float GetLineIntersectPoint(Vector2 &a1, Vector2 &a2, Vector2 &b1, Vector2 &b2);
	float Cross(Vector2 p1, Vector2 p2);

	bool IsCirlceRectIntersect(const Vector2 &circle_center, float radius, Vector2 rect_center, float length, float width);
};

