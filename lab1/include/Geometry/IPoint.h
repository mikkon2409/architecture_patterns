#pragma once

namespace Geometry
{

	class IPoint {
	public:
		virtual double getX() = 0;
		virtual double getY() = 0;
		virtual void setX(double x) = 0;
		virtual void setY(double y) = 0;
	};

}
