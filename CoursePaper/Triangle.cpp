#include "Triangle.h"

void Triangle::Create(double x1, double y1, double x2, double y2, double x3, double y3)
{
	TriangleData T = { {{x1,y1},{x2,y2},{x3,y3}} };
	triangleStruct.push_back(T);
}

void Triangle::Delete(size_t index)
{
	if (index >= 0 && index < triangleStruct.size())
	{
		triangleStruct.erase(triangleStruct.begin() + index);
		cout << " Треугольник " << index++ << " удалён" << endl;
	}
	else cout << " Выбранная фигура не существует" << endl;
}

void Triangle::Show(size_t index) const
{
	if (index >= 0 && index < triangleStruct.size())
	{
		const auto& t = triangleStruct[index].vertices;
		cout << " Вершина A" << endl;
		cout << " X: " << t[0].first<<" Y: " << t[0].second << endl;
		cout << " Вершина B" << endl;
		cout << " X: " << t[1].first << " Y: " << t[1].second << endl;
		cout << " Вершина C" << endl;
		cout << " X: " << t[2].first << " Y: " << t[2].second << endl;
	}
	else cout << " Выбранная фигура не существует" << endl;
}

bool Triangle::Verification(size_t index) const
{
	if (index >= 0 && index < triangleStruct.size())
		return true;
	return false;
}

void Triangle::MoveO(size_t index, double x, double y)
{
	if (index >= 0 && index < triangleStruct.size())
	{
		auto& t = triangleStruct[index].vertices;
		t[0].first += x;t[1].first += x; t[2].first += x;
		t[0].second += y; t[1].second += y; t[2].second += y;
	}
	else cout << " Выбранная фигура не существует" << endl;
}


vector<Point> Triangle::Intersect(size_t index)
{
	if (index >= 0 && index < triangleStruct.size())
	{
	const auto& t = triangleStruct[index].vertices;
	vector<Point> triangle = { {t[0].first, t[0].second}, {t[1].first, t[1].second}, {t[2].first, t[2].second} };
	return triangle;
	}
	else cout << " Выбранная фигура не существует" << endl;
}