#include "Hexagon.h"

void Hexagon::Create(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5, double x6, double y6)
{
	HexagonData H = { {{x1,y1},{x2,y2},{x3,y3},{x4,y4},{x5,y5},{x6,y6}} };
	hexagonStruct.push_back(H);
}

void Hexagon::Delete(size_t index)
{
	if (index >= 0 && index < hexagonStruct.size())
	{
		hexagonStruct.erase(hexagonStruct.begin() + index);
		cout << " Шестиугольник " << index++ << " удалён" << endl;
	}
	else cout << " Выбранная фигура не существует" << endl;
}

void Hexagon::Show(size_t index) const
{
	if (index >= 0 && index < hexagonStruct.size())
	{
		const auto& h = hexagonStruct[index].vertices;
		cout << " Вершина A" << endl;
		cout << " X: " << h[0].first << " Y: " << h[0].second << endl;
		cout << " Вершина B" << endl;
		cout << " X: " << h[1].first << " Y: " << h[1].second << endl;
		cout << " Вершина C" << endl;
		cout << " X: " << h[2].first << " Y: " <<h[2].second << endl;
		cout << " Вершина D" << endl;
		cout << " X: " << h[3].first << " Y: " << h[3].second << endl;
		cout << " Вершина E" << endl;
		cout << " X: " << h[4].first << " Y: " << h[4].second << endl;
		cout << " Вершина F" << endl;
		cout << " X: " << h[5].first << " Y: " << h[5].second << endl;
	}
	else cout << "Выбранная фигура не существует" << endl;
}

bool Hexagon::Verification(size_t index) const
{
	if (index >= 0 && index < hexagonStruct.size())
		return true;
	return false;
}

void Hexagon::MoveO(size_t index, double x, double y)
{
	if (index >= 0 && index < hexagonStruct.size())
	{
		auto& t = hexagonStruct[index].vertices;
		t[0].first += x;t[1].first += x; t[2].first += x;
		t[0].second += y; t[1].second += y; t[2].second += y;
	}
	else cout << " Выбранная фигура не существует" << endl;
}



vector<Point> Hexagon::Intersect(size_t index)
{
	if (index >= 0 && index < hexagonStruct.size())
	{
	const auto& h = hexagonStruct[index].vertices;
	vector<Point> hexagon = { {h[0].first, h[0].second}, {h[1].first, h[1].second}, {h[2].first, h[2].second}, {h[3].first, h[3].second}, {h[4].first, h[4].second}, {h[5].first, h[5].second} };
	return hexagon;
	}
	else 
		cout << " Выбранная фигура не существует" << endl;
}