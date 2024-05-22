#pragma once
#include "Figure.h"

class Triangle : public Figure
{
private:
	struct TriangleData
	{
		vector<pair<double, double>> vertices;
	};
	vector<TriangleData> triangleStruct;
public:
	Triangle() = default;
	void Create(double x1, double y1, double x2, double y2, double x3, double y3);
	void Delete(size_t index) override;
	void Show(size_t index) const override;
	bool Verification(size_t index) const override;
	void MoveO(size_t index, double x, double y) override;
	vector<Point>Intersect(size_t index);
	~Triangle() = default;
};
