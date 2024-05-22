// CoursePaper.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include "Triangle.h"
#include "Hexagon.h"
#include "Figure.h"
#include "include.h"
#include <iostream>

enum
{
    CreateFigure = 1, // добавить фигуру
    DeleteFigure = 2, // удалить фигуру
    ShowFigure = 3, // формирования сведений о фигуре
    VerificationFigure = 4, // проверка существования фигуры
    MoveOFigure = 5,  //  переместить объект на плоскости
    Intersection = 6, // определить факт пересечения объектов О1 и О2
    Exit = 7 // завершить работу программы
};

void Menu()
{
    cout << "---------------------------------------" << endl;
    cout << "             ГЛАВНОЕ МЕНЮ" << endl;
    cout << "---------------------------------------" << endl;

    cout << " 1. Создать фигуру" << endl;
    cout << " 2. Удалить фигуру" << endl;
    cout << " 3. Показать данные о фигуре" << endl;
    cout << " 4. Проверка существования фигуры" << endl;
    cout << " 5. Переместить фигуру" << endl;
    cout << " 6. Проверка пересечения фигур" << endl;
    cout << " 7. Выход" << endl;
    cout << "---------------------------------------" << endl;
}


bool isBetween(double a, double b, double c) {
    return a <= b && b <= c || c <= b && b <= a;
}

bool doLinesIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double d1 = (p4.y - p3.y) * (p1.x - p3.x) - (p4.x - p3.x) * (p1.y - p3.y);
    double d2 = (p4.y - p3.y) * (p2.x - p3.x) - (p4.x - p3.x) * (p2.y - p3.y);
    double d3 = (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y);
    double d4 = (p2.y - p1.y) * (p4.x - p1.x) - (p2.x - p1.x) * (p4.y - p1.y);

    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    if (d1 == 0 && isBetween(p3.x, p1.x, p4.x) && isBetween(p3.y, p1.y, p4.y)) return true;
    if (d2 == 0 && isBetween(p3.x, p2.x, p4.x) && isBetween(p3.y, p2.y, p4.y)) return true;
    if (d3 == 0 && isBetween(p1.x, p3.x, p2.x) && isBetween(p1.y, p3.y, p2.y)) return true;
    if (d4 == 0 && isBetween(p1.x, p4.x, p2.x) && isBetween(p1.y, p4.y, p2.y)) return true;

    return false;
}

bool doShapesIntersect(const std::vector<Point>& hexagon, const std::vector<Point>& triangle) {
    for (size_t i = 0; i < hexagon.size(); ++i) {
        for (size_t j = 0; j < triangle.size(); ++j) {
            if (doLinesIntersect(hexagon[i], hexagon[(i + 1) % hexagon.size()], triangle[j], triangle[(j + 1) % triangle.size()])) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    system("chcp 1251");
    system("cls");
    Hexagon h;
    Triangle t;    
   while (true)
    {
    size_t index1, index2;
        int choice1, choice2;
        double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
        Menu();
        cout << " Ваш выбор: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
        {
            do
            {
                cout << "---------------------------------------" << endl;
                cout << " Что создаём " << endl;
                cout << " 1. Шестиугольник" << endl;
                cout << " 2. Треугольник" << endl;
                cout << " 3. Выйти " << endl;
                cout << " Ваш выбор: ";
                cin >> choice2;
                cout << "---------------------------------------" << endl;
                if (choice2 == 1)
                {
                    cout << " Введите координаты:" << endl;
                    cout << " Ввершина A:" << endl;
                    cout << " X: ";
                    cin >> x1;
                    cout << " Y: ";
                    cin >> y1;
                    cout << " Ввершина B:" << endl;
                    cout << " X: ";
                    cin >> x2;
                    cout << " Y: ";
                    cin >> y2;
                    cout << " Ввершина C:" << endl;
                    cout << " X: ";
                    cin >> x3;
                    cout << " Y: ";
                    cin >> y3;
                    cout << " Ввершина D:" << endl;
                    cout << " X: ";
                    cin >> x4;
                    cout << " Y: ";
                    cin >> y4;
                    cout << " Ввершина E:" << endl;
                    cout << " X: ";
                    cin >> x5;
                    cout << " Y: ";
                    cin >> y5;
                    cout << " Ввершина F:" << endl;
                    cout << " X: ";
                    cin >> x6;
                    cout << " Y: ";
                    cin >> y6;
                    h.Create(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6);
                    cout << " Шестиугольник создан" << endl;
                    break;

                }
                else if (choice2 == 2)
                {
                    cout << " Введите координаты:" << endl;
                    cout << " Ввершина A:" << endl;
                    cout << " X: ";
                    cin >> x1;
                    cout << " Y: ";
                    cin >> y1;
                    cout << " Ввершина B:" << endl;
                    cout << " X: ";
                    cin >> x2;
                    cout << " Y: ";
                    cin >> y2;
                    cout << " Ввершина C:" << endl;
                    cout << " X: ";
                    cin >> x3;
                    cout << " Y: ";
                    cin >> y3;
                    t.Create(x1, y1, x2, y2, x3, y3);
                    cout << " Треугольник создан" << endl;
                    break;
                }
               else if (choice2 == 3)
                {
                    break;
                }
                else
                {                  
                    cout << " Неверный выбор" << endl;
                }
            } while (choice2 != 3);
            break;
        }
        case 2:
        {
            do
            {
                cout << "---------------------------------------" << endl;
                cout << " Что удаляем:" << endl;
                cout << " 1. Шестиугольник" << endl;
                cout << " 2. Треугольник" << endl;
                cout << " 3. Выйти" << endl;
                cout << " Ваш выбор: ";
                cin >> choice2;
                cout << "---------------------------------------" << endl;
                if (choice2 == 1)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1;
                    index1--; 
                    h.Delete(index1); 
                    break;
                }
                else if (choice2 == 2)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1;
                    index1--;
                    t.Delete(index1);
                    break;
                }
                else if (choice2 == 3)
                {
                    break;
                }
                else
                {
                    cout << " Неверный выбор" << endl;
                }
            } while (choice2 != 3);
            break;
        }
        case 3:
        {
            do
            {
                cout << "---------------------------------------" << endl;
                cout << " Какую фигуру выводим:" << endl;
                cout << " 1. Шестиугольник" << endl;
                cout << " 2. Треугольник" << endl;
                cout << " 3. Выйти" << endl;
                cout << " Ваш выбор: ";
                cin >> choice2;
                cout << "---------------------------------------" << endl;
                if (choice2 == 1)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1; 
                    index1--; 
                    cout << " Координаты шестиугольника:" << endl;
                    h.Show(index1);
                }
                else if (choice2 == 2)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1; 
                    index1--;
                    cout << " Координаты треугольника: " << endl;
                    t.Show(index1);
                }
                else if (choice2 == 3)
                {                   
                    break;
                }
                else
                {
                    cout << " Неверный выбор" << endl;                 
                }
            } while (choice2 != 3);
            break;
        }
        case 4:
        {
            do
            {
                cout << "---------------------------------------" << endl;
                cout << " Проверить существование какой фигуры: " << endl;
                cout << " 1. Шестиугольник" << endl;
                cout << " 2. Треугольник" << endl;
                cout << " 3. Выйти" << endl;
                cout << " Ваш выбор: ";
                cin >> choice2;
                cout << "---------------------------------------" << endl;
                if (choice2 == 1)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1; 
                    index1--; 
                    if (h.Verification(index1))
                    {
                        cout << " Выбранный шестиугольник есть в списке" << endl;
                    }
                    else
                        cout << " Выбранного шестиугольника нет в списке" << endl;
                }
                else if (choice2 == 2)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1; 
                    index1--;
                    if (t.Verification(index1))
                    {
                        cout << " Выбранный треугольник есть в списке" << endl;
                    }
                    else
                        cout << " Выбранного теругольника нет в списке" << endl;
                }
                else if (choice2 == 3)
                {                   
                    break;
                }
                else
                {
                    cout << " Неверный выбор" << endl;
                }
            } while (choice2 != 3);
            break;
        }
        case 5:
        {
            do
            {
                cout << "---------------------------------------" << endl;
                cout << " Какую фигуру двигаем: " << endl;
                cout << " 1. Шестиугольник" << endl;
                cout << " 2. Треугольник" << endl;
                cout << " 3. Выйти" << endl;
                cout << " Ваш выбор: ";
                cin >> choice2;
                cout << "---------------------------------------" << endl;
                if (choice2 == 1)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1;
                    index1--;
                    if (h.Verification(index1))
                    {
                        cout << " На сколько передвигаем:" << endl;
                        cout << " X: ";
                        cin >> x1;
                        cout << " Y: ";
                        cin >> y1;
                        h.MoveO(index1, x1, y1);
                        cout << " Шестиугольник передвинут. Выведены новые координаты:" << endl;
                        h.Show(index1);
                    }
                    else cout << " Выбранного шестиугольника не существует.\n";

                }
                else if (choice2 == 2)
                {
                    cout << " Какая по счёту фигура: ";
                    cin >> index1; 
                    index1--; 
                    if (t.Verification(index1))
                    {
                        cout << " На сколько передвигаем:" << endl;
                        cout << " X: ";
                        cin >> x1;
                        cout << " Y: ";
                        cin >> y1;
                        t.MoveO(index1, x1, y1);
                        cout << " Треугольник передвинут. Выведены новые координаты:" << endl;
                        t.Show(index1);
                    }
                    else cout << " Выбранного треугольника не существует.\n";
                }
                else if (choice2 == 3)
                {                   
                    break;
                }
                else
                {
                    cout << " Неверный выбор" << endl;
                }
            } while (choice2 != 3);
            break;
        }
        case 6:
        {
            cout << " Введите номер выбранного шестиугольника: ";
            cin >> index1;
            index1--;
            cout << " Введите номер выбранного теругольника: ";
            cin >> index2;
            index2--;
            if (h.Verification(index1))
            {
                if (t.Verification(index2))
                {
                    if (doShapesIntersect(h.Intersect(index1), t.Intersect(index2))) {
                        cout << " Фигуры пересекаются.\n";
                    }
                    else {
                        cout << " Фигуры не пересекаются.\n";
                    }
                }
                else cout << " Выбранного треугольника не существует.\n";
            }
            else cout << " Выбранного шестиугольника не существует.\n";
            break;
        }
        case 7:
        {
            cout << "---------------------------------------" << endl;
            cout << "        ВЫ ВЫШЛИ ИЗ ПРОГРАММЫ" << endl;
            cout << "---------------------------------------" << endl;
            exit(0);
        }
        default:
            break;
        }
   }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
