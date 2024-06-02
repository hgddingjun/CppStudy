#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct _Point {
    int x;
    int y;
} Point_t;


class Shape {
public:
    virtual Point_t center() const = 0;
    virtual void move(Point_t to) = 0;
    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle(Point_t p, int rr) : x(p), r(rr) {}
    Point_t centor() const { return x;}
    void move(Point_t to) { x = to; }
    void draw() const;
    void rotate(int angle) {}

private:
    Point_t x;  //center
    int r;      //radius
};


class Smiley : public Circle {
public:
    Smiley(Point_t p, int r) : Circle{p, r}, mouth{ nullptr } {}
    ~Smiley() {
        delete mouth;
        for(auto p : eyes)
            delete p;
    }

    void move(Point_t to);
    void draw() const;
    void rotate(int);
    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i);

private:
    vector<Shape *> eyes;
    Shape* mouth;
};


void Smiley::draw() const
{
    Circle::draw();
    for(auto p : eyes)
        p->draw();
    mouth->draw();
}

class Triangle : public Shape {
public:
    Triangle(Point_t p1, Point_t p2, Point_t p3) : pt1(p1), pt2(p2),pt3(p3) {}
    ~Triangle() {}
    Point_t centor() const {}
    void move(Point_t to) { mp = to; };
    void draw(){};
    void rotate(int angle) {};
private:
    Point_t pt1, pt2, pt3;
    Point_t mp;
};


enum class Kind { circle, triangle, smiley } k;

Shape* read_shape(istream& is)
{
    Point_t p={0,0};
    Point_t p1={1,1};
    Point_t p2={2,2};
    Point_t p3={3,3};
    int r;

    Shape e1, e2, m;
    switch(k) {
    case Kind::circle:
        return new Circle{p, r};
    case Kind::triangle:
        return new Triangle{p1, p2, p3};
    case Kind::smiley:
        Smiley* ps = new Smiley{p, r};
        ps->add_eye(&e1);
        ps->add_eye(&e2);
        ps->set_mouth(&m);
        return ps;
    }
}

void rotate_all(vector<Shape *>& v, int angle)
{
    for(auto p : v)
        p->rotate(angle);
}

void draw_all(vector<Shape *>& v)
{
    for_each(v.begin(), v.end(), [](Shape *p){ p->draw(); });
}

void user()
{
    std::vector<Shape *> v;
    while (cin)
        v.push_back(read_shape(cin));
    rotate_all(v, 45);
    draw_all(v);
    for(auto p : v)
        delete p;
}



int main()
{
    user();
    cout << "Designed shape Class!" << endl;
    return 0;
}
