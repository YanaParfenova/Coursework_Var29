#pragma once
#include "Figure.h"

class Hexagon :public Figure
{
private:
	struct HexagonData
	{
		vector<pair<double, double>> vertices;
	};
	vector<HexagonData> hexagonStruct;
public:
	Hexagon() = default;
	void Create(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5, double x6, double y6);
	void Delete(size_t index) override;
	void Show(size_t index) const override;
	bool Verification(size_t index) const override;
	void MoveO(size_t index, double x, double y) override;
	vector<Point>Intersect(size_t index);
	~Hexagon() = default;
};
