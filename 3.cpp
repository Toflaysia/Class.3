#include <iostream>

using namespace std;

class Point {
public:
    double x;
    double y;

    Point() {                    //конструктор по умалочанию
        this->x = 0.0; 
        this->y = 0.0;
    }

    Point(double x, double y) {  //констурктор не по умолчанию

        this->x = x;
        this->y = y;

    }

    bool operator == (const Point & a) {
        if (this->x == a.x && this->y == a.y) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator != (const Point& a) {
        if (this->x != a.x || this->y != a.y) {
            return true;
        }
        else {
            return false;
        }
    }
    friend ostream& operator << (ostream& stream, const Point& a) {        //перегрузка оператора вывода
        stream << a.x << "," << a.y;

        return stream;
    }

    friend istream& operator >> (istream& in, Point& a) {                  //перегрузка оператора ввода
        int x;
        int y;
        in >> x >> y;
        a.x = x;
        a.y = y;
        return in;
    }

    void vPlane(){
        double x = this->x;
        double y = this->y;
        if (x > 0 && y > 0) {
            cout << "I четверть плоскости" << endl;
        }
        else if (x < 0 && y > 0) {
            cout << "II четверть плоскости" << endl;
        }
        else if (x < 0 && y < 0) {
            cout << "III четверть плоскости" << endl;
        }
        else if (x > 0 && y < 0) {
            cout << "IV четверть плоскости" << endl;
        }
        else {
            cout << "Точка находится на одной из осей" << endl;
        }
    }
    void compare_with_line(double(*fun)(double, double)) {
        double result = fun(this->x, this->y);
        if (result > 0) {
            cout << "Точка лежит выше линии";
        }
        if (result < 0) {
            cout << "Точка лежит ниже линии";
        }
        if (result == 0) {
            cout << "Точка лежит на линии";
        }
    }
};

double f1(double x, double y) {
    return x + 2*y;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Point a;
    Point b;
    cout << "Введите координаты точки " << endl;
    cin >> a; 
    cout << "Введите координаты точки " << endl;
    cin >> b;
    a.vPlane();
    cout << (a != b) << endl;
    cout << (a == b) << endl;
    a.compare_with_line(f1);



    return 0;
}
